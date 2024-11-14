/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         WQL_STYPE
/* Substitute the variable and function names.  */
#define yyparse         wql_parse
#define yylex           wql_lex
#define yyerror         wql_error
#define yydebug         wql_debug
#define yynerrs         wql_nerrs

/* First part of user prologue.  */
#line 1 "dlls/wbemprox/wql.y"


/*
 * Copyright 2012 Hans Leidekker for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "wbemcli.h"
#include "wbemprox_private.h"

#include "wine/list.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(wbemprox);

struct parser
{
    const WCHAR *cmd;
    UINT idx;
    UINT len;
    HRESULT error;
    struct view **view;
    struct list *mem;
    enum wbm_namespace ns;
};

struct string
{
    const WCHAR *data;
    int len;
};

static void *alloc_mem( struct parser *parser, UINT size )
{
    struct list *mem = malloc( sizeof(struct list) + size );
    list_add_tail( parser->mem, mem );
    return &mem[1];
}

static struct property *alloc_property( struct parser *parser, const WCHAR *class, const WCHAR *name )
{
    struct property *prop = alloc_mem( parser, sizeof(*prop) );
    if (prop)
    {
        prop->name  = name;
        prop->class = class;
        prop->next  = NULL;
    }
    return prop;
}

static struct keyword *alloc_keyword( struct parser *parser, const WCHAR *name, const WCHAR *value )
{
    struct keyword *keyword = alloc_mem( parser, sizeof(*keyword) );
    if (keyword)
    {
        keyword->name  = name;
        keyword->value = value;
        keyword->next  = NULL;
    }
    return keyword;
}

static WCHAR *get_string( struct parser *parser, const struct string *str )
{
    const WCHAR *p = str->data;
    int len = str->len;
    WCHAR *ret;

    if ((p[0] == '\"' && p[len - 1] != '\"') ||
        (p[0] == '\'' && p[len - 1] != '\'')) return NULL;
    if ((p[0] == '\"' && p[len - 1] == '\"') ||
        (p[0] == '\'' && p[len - 1] == '\''))
    {
        p++;
        len -= 2;
    }
    if (!(ret = alloc_mem( parser, (len + 1) * sizeof(WCHAR) ))) return NULL;
    memcpy( ret, p, len * sizeof(WCHAR) );
    ret[len] = 0;
    return ret;
}

static WCHAR *get_path( struct parser *parser, const struct string *str )
{
    const WCHAR *p = str->data;
    int len = str->len;
    WCHAR *ret;

    if (p[0] == '{' && p[len - 1] == '}')
    {
        p++;
        len -= 2;
    }

    if (!(ret = alloc_mem( parser, (len + 1) * sizeof(WCHAR) ))) return NULL;
    memcpy( ret, p, len * sizeof(WCHAR) );
    ret[len] = 0;
    return ret;
}

static int get_int( struct parser *parser )
{
    const WCHAR *p = &parser->cmd[parser->idx];
    int i, ret = 0;

    for (i = 0; i < parser->len; i++)
    {
        if (p[i] < '0' || p[i] > '9')
        {
            ERR("should only be numbers here!\n");
            break;
        }
        ret = (p[i] - '0') + ret * 10;
    }
    return ret;
}

static struct expr *expr_complex( struct parser *parser, struct expr *l, UINT op, struct expr *r )
{
    struct expr *e = alloc_mem( parser, sizeof(*e) );
    if (e)
    {
        e->type = EXPR_COMPLEX;
        e->u.expr.left = l;
        e->u.expr.op = op;
        e->u.expr.right = r;
    }
    return e;
}

static struct expr *expr_unary( struct parser *parser, struct expr *l, UINT op )
{
    struct expr *e = alloc_mem( parser, sizeof(*e) );
    if (e)
    {
        e->type = EXPR_UNARY;
        e->u.expr.left = l;
        e->u.expr.op = op;
        e->u.expr.right = NULL;
    }
    return e;
}

static struct expr *expr_ival( struct parser *parser, int val )
{
    struct expr *e = alloc_mem( parser, sizeof *e );
    if (e)
    {
        e->type = EXPR_IVAL;
        e->u.ival = val;
    }
    return e;
}

static struct expr *expr_sval( struct parser *parser, const struct string *str )
{
    struct expr *e = alloc_mem( parser, sizeof *e );
    if (e)
    {
        e->type = EXPR_SVAL;
        e->u.sval = get_string( parser, str );
        if (!e->u.sval)
            return NULL; /* e will be freed by query destructor */
    }
    return e;
}

static struct expr *expr_bval( struct parser *parser, int val )
{
    struct expr *e = alloc_mem( parser, sizeof *e );
    if (e)
    {
        e->type = EXPR_BVAL;
        e->u.ival = val;
    }
    return e;
}

static struct expr *expr_propval( struct parser *parser, const struct property *prop )
{
    struct expr *e = alloc_mem( parser, sizeof *e );
    if (e)
    {
        e->type = EXPR_PROPVAL;
        e->u.propval = prop;
    }
    return e;
}

static int wql_error( struct parser *parser, const char *str );
static int wql_lex( void *val, struct parser *parser );

#define PARSER_BUBBLE_UP_VIEW( parser, result, current_view ) \
    *parser->view = current_view; \
    result = current_view


#line 293 "dlls/wbemprox/wql.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef WQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define WQL_DEBUG 1
#  else
#   define WQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define WQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined WQL_DEBUG */
#if WQL_DEBUG
extern int wql_debug;
#endif

/* Token kinds.  */
#ifndef WQL_TOKENTYPE
# define WQL_TOKENTYPE
  enum wql_tokentype
  {
    WQL_EMPTY = -2,
    WQL_EOF = 0,                   /* "end of file"  */
    WQL_error = 256,               /* error  */
    WQL_UNDEF = 257,               /* "invalid token"  */
    TK_SELECT = 258,               /* TK_SELECT  */
    TK_FROM = 259,                 /* TK_FROM  */
    TK_STAR = 260,                 /* TK_STAR  */
    TK_COMMA = 261,                /* TK_COMMA  */
    TK_DOT = 262,                  /* TK_DOT  */
    TK_IS = 263,                   /* TK_IS  */
    TK_LP = 264,                   /* TK_LP  */
    TK_RP = 265,                   /* TK_RP  */
    TK_NULL = 266,                 /* TK_NULL  */
    TK_FALSE = 267,                /* TK_FALSE  */
    TK_TRUE = 268,                 /* TK_TRUE  */
    TK_INTEGER = 269,              /* TK_INTEGER  */
    TK_WHERE = 270,                /* TK_WHERE  */
    TK_SPACE = 271,                /* TK_SPACE  */
    TK_MINUS = 272,                /* TK_MINUS  */
    TK_ILLEGAL = 273,              /* TK_ILLEGAL  */
    TK_BY = 274,                   /* TK_BY  */
    TK_ASSOCIATORS = 275,          /* TK_ASSOCIATORS  */
    TK_OF = 276,                   /* TK_OF  */
    TK_STRING = 277,               /* TK_STRING  */
    TK_ID = 278,                   /* TK_ID  */
    TK_PATH = 279,                 /* TK_PATH  */
    TK_OR = 280,                   /* TK_OR  */
    TK_AND = 281,                  /* TK_AND  */
    TK_NOT = 282,                  /* TK_NOT  */
    TK_EQ = 283,                   /* TK_EQ  */
    TK_NE = 284,                   /* TK_NE  */
    TK_LT = 285,                   /* TK_LT  */
    TK_GT = 286,                   /* TK_GT  */
    TK_LE = 287,                   /* TK_LE  */
    TK_GE = 288,                   /* TK_GE  */
    TK_LIKE = 289                  /* TK_LIKE  */
  };
  typedef enum wql_tokentype wql_token_kind_t;
#endif

/* Value type.  */
#if ! defined WQL_STYPE && ! defined WQL_STYPE_IS_DECLARED
union WQL_STYPE
{
#line 224 "dlls/wbemprox/wql.y"

    struct string str;
    WCHAR *string;
    struct property *proplist;
    struct keyword *keywordlist;
    struct view *view;
    struct expr *expr;
    int integer;

#line 392 "dlls/wbemprox/wql.tab.c"

};
typedef union WQL_STYPE WQL_STYPE;
# define WQL_STYPE_IS_TRIVIAL 1
# define WQL_STYPE_IS_DECLARED 1
#endif




int wql_parse (struct parser *ctx);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_SELECT = 3,                  /* TK_SELECT  */
  YYSYMBOL_TK_FROM = 4,                    /* TK_FROM  */
  YYSYMBOL_TK_STAR = 5,                    /* TK_STAR  */
  YYSYMBOL_TK_COMMA = 6,                   /* TK_COMMA  */
  YYSYMBOL_TK_DOT = 7,                     /* TK_DOT  */
  YYSYMBOL_TK_IS = 8,                      /* TK_IS  */
  YYSYMBOL_TK_LP = 9,                      /* TK_LP  */
  YYSYMBOL_TK_RP = 10,                     /* TK_RP  */
  YYSYMBOL_TK_NULL = 11,                   /* TK_NULL  */
  YYSYMBOL_TK_FALSE = 12,                  /* TK_FALSE  */
  YYSYMBOL_TK_TRUE = 13,                   /* TK_TRUE  */
  YYSYMBOL_TK_INTEGER = 14,                /* TK_INTEGER  */
  YYSYMBOL_TK_WHERE = 15,                  /* TK_WHERE  */
  YYSYMBOL_TK_SPACE = 16,                  /* TK_SPACE  */
  YYSYMBOL_TK_MINUS = 17,                  /* TK_MINUS  */
  YYSYMBOL_TK_ILLEGAL = 18,                /* TK_ILLEGAL  */
  YYSYMBOL_TK_BY = 19,                     /* TK_BY  */
  YYSYMBOL_TK_ASSOCIATORS = 20,            /* TK_ASSOCIATORS  */
  YYSYMBOL_TK_OF = 21,                     /* TK_OF  */
  YYSYMBOL_TK_STRING = 22,                 /* TK_STRING  */
  YYSYMBOL_TK_ID = 23,                     /* TK_ID  */
  YYSYMBOL_TK_PATH = 24,                   /* TK_PATH  */
  YYSYMBOL_TK_OR = 25,                     /* TK_OR  */
  YYSYMBOL_TK_AND = 26,                    /* TK_AND  */
  YYSYMBOL_TK_NOT = 27,                    /* TK_NOT  */
  YYSYMBOL_TK_EQ = 28,                     /* TK_EQ  */
  YYSYMBOL_TK_NE = 29,                     /* TK_NE  */
  YYSYMBOL_TK_LT = 30,                     /* TK_LT  */
  YYSYMBOL_TK_GT = 31,                     /* TK_GT  */
  YYSYMBOL_TK_LE = 32,                     /* TK_LE  */
  YYSYMBOL_TK_GE = 33,                     /* TK_GE  */
  YYSYMBOL_TK_LIKE = 34,                   /* TK_LIKE  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_query = 36,                     /* query  */
  YYSYMBOL_path = 37,                      /* path  */
  YYSYMBOL_keyword = 38,                   /* keyword  */
  YYSYMBOL_keywordlist = 39,               /* keywordlist  */
  YYSYMBOL_associatorsof = 40,             /* associatorsof  */
  YYSYMBOL_select = 41,                    /* select  */
  YYSYMBOL_proplist = 42,                  /* proplist  */
  YYSYMBOL_prop = 43,                      /* prop  */
  YYSYMBOL_id = 44,                        /* id  */
  YYSYMBOL_number = 45,                    /* number  */
  YYSYMBOL_expr = 46,                      /* expr  */
  YYSYMBOL_string_val = 47,                /* string_val  */
  YYSYMBOL_prop_val = 48,                  /* prop_val  */
  YYSYMBOL_const_val = 49                  /* const_val  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined WQL_STYPE_IS_TRIVIAL && WQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if WQL_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   250,   250,   252,   256,   265,   271,   280,   281,   288,
     306,   324,   339,   354,   372,   373,   377,   384,   390,   399,
     408,   415,   421,   427,   433,   439,   445,   451,   457,   463,
     469,   475,   481,   487,   493,   499,   505,   511,   517,   523,
     529,   535,   541,   547,   556,   565,   574,   580,   586,   592
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_SELECT", "TK_FROM",
  "TK_STAR", "TK_COMMA", "TK_DOT", "TK_IS", "TK_LP", "TK_RP", "TK_NULL",
  "TK_FALSE", "TK_TRUE", "TK_INTEGER", "TK_WHERE", "TK_SPACE", "TK_MINUS",
  "TK_ILLEGAL", "TK_BY", "TK_ASSOCIATORS", "TK_OF", "TK_STRING", "TK_ID",
  "TK_PATH", "TK_OR", "TK_AND", "TK_NOT", "TK_EQ", "TK_NE", "TK_LT",
  "TK_GT", "TK_LE", "TK_GE", "TK_LIKE", "$accept", "query", "path",
  "keyword", "keywordlist", "associatorsof", "select", "proplist", "prop",
  "id", "number", "expr", "string_val", "prop_val", "const_val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,     8,   -13,    15,   -25,   -25,    10,   -25,   -25,    38,
      37,    42,    26,   -25,   -25,    10,     9,    10,   -25,    57,
      58,   -25,   -25,    10,    25,    10,   -25,    23,    25,   -24,
     -25,   -25,   -25,   -25,    25,   -25,   -25,   -19,    -7,    51,
     -25,    10,    20,    10,    10,   -25,    25,    25,    -9,    49,
      53,    56,    56,    56,    56,    52,    10,    10,    10,    10,
      10,    10,   -25,   -25,   -25,   -25,   -25,   -25,   -25,    65,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     2,     0,    16,    19,     0,
      14,    18,     0,     1,    11,     0,     0,     0,     4,     9,
      12,    15,    17,     0,     0,     7,    10,     5,     0,     0,
      49,    48,    20,    47,     0,    45,    46,    13,     0,     0,
       8,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,    21,    41,    43,    23,    22,    38,     0,
      40,    25,    42,    30,    27,    26,    28,    29,    44,    37,
      31,    36,    33,    32,    34,    35,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,    66,   -25,   -25,    61,    43,    -6,
     -25,   -18,   -25,    -3,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    19,    25,    26,     4,     5,     9,    35,    11,
      36,    37,    79,    38,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    48,    68,     1,    43,    44,    46,    47,    12,    20,
      42,    22,     6,     7,     7,    13,    45,    27,    69,    27,
       2,    49,    50,    51,    52,    53,    54,    55,    66,    67,
      63,     8,     8,     8,    28,    62,    29,    30,    31,    32,
      64,    65,    15,    16,    10,    46,    47,    33,     8,    17,
      18,    41,    34,    80,    81,    82,    83,    84,    85,    10,
      70,    30,    31,    32,    72,    30,    31,    32,    30,    31,
      32,    33,    23,    24,    78,    33,    86,    21,    33,    56,
      57,    58,    59,    60,    61,    71,    73,    74,    75,    76,
      77,    40
};

static const yytype_int8 yycheck[] =
{
       6,     8,    11,     3,    28,    29,    25,    26,    21,    15,
      28,    17,     4,     5,     5,     0,    34,    23,    27,    25,
      20,    28,    29,    30,    31,    32,    33,    34,    46,    47,
      10,    23,    23,    23,     9,    41,    11,    12,    13,    14,
      43,    44,     4,     6,     1,    25,    26,    22,    23,     7,
      24,    28,    27,    56,    57,    58,    59,    60,    61,    16,
      11,    12,    13,    14,    11,    12,    13,    14,    12,    13,
      14,    22,    15,    15,    22,    22,    11,    16,    22,    28,
      29,    30,    31,    32,    33,    49,    50,    51,    52,    53,
      54,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    20,    36,    40,    41,     4,     5,    23,    42,
      43,    44,    21,     0,    44,     4,     6,     7,    24,    37,
      44,    42,    44,    15,    15,    38,    39,    44,     9,    11,
      12,    13,    14,    22,    27,    43,    45,    46,    48,    49,
      39,    28,    46,    28,    29,    46,    25,    26,     8,    28,
      29,    30,    31,    32,    33,    34,    28,    29,    30,    31,
      32,    33,    44,    10,    48,    48,    46,    46,    11,    27,
      11,    49,    11,    49,    49,    49,    49,    49,    22,    47,
      48,    48,    48,    48,    48,    48,    11
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    36,    37,    38,    38,    39,    39,    40,
      40,    41,    41,    41,    42,    42,    42,    43,    43,    44,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    48,    49,    49,    49,    49
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     2,     3,
       5,     3,     4,     6,     1,     3,     1,     3,     1,     1,
       1,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = WQL_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == WQL_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use WQL_error or WQL_UNDEF. */
#define YYERRCODE WQL_UNDEF


/* Enable debugging if requested.  */
#if WQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ctx);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, struct parser *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ctx);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, struct parser *ctx)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !WQL_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !WQL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, struct parser *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (ctx);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct parser *ctx)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = WQL_EMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == WQL_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, ctx);
    }

  if (yychar <= WQL_EOF)
    {
      yychar = WQL_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == WQL_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = WQL_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = WQL_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* path: TK_PATH  */
#line 257 "dlls/wbemprox/wql.y"
        {
            (yyval.string) = get_path( ctx, &(yyvsp[0].str) );
            if (!(yyval.string))
                YYABORT;
        }
#line 1752 "dlls/wbemprox/wql.tab.c"
    break;

  case 5: /* keyword: id  */
#line 266 "dlls/wbemprox/wql.y"
        {
            (yyval.keywordlist) = alloc_keyword( ctx, (yyvsp[0].string), NULL );
            if (!(yyval.keywordlist))
                YYABORT;
        }
#line 1762 "dlls/wbemprox/wql.tab.c"
    break;

  case 6: /* keyword: id TK_EQ id  */
#line 272 "dlls/wbemprox/wql.y"
        {
            (yyval.keywordlist) = alloc_keyword( ctx, (yyvsp[-2].string), (yyvsp[0].string) );
            if (!(yyval.keywordlist))
                YYABORT;
        }
#line 1772 "dlls/wbemprox/wql.tab.c"
    break;

  case 8: /* keywordlist: keyword keywordlist  */
#line 282 "dlls/wbemprox/wql.y"
        {
            (yyvsp[-1].keywordlist)->next = (yyvsp[0].keywordlist);
        }
#line 1780 "dlls/wbemprox/wql.tab.c"
    break;

  case 9: /* associatorsof: TK_ASSOCIATORS TK_OF path  */
#line 289 "dlls/wbemprox/wql.y"
        {
            HRESULT hr;
            struct parser *parser = ctx;
            struct view *view;

            hr = create_view( VIEW_TYPE_ASSOCIATORS, ctx->ns, (yyvsp[0].string), NULL, NULL, NULL, NULL, &view );
            if (hr != S_OK)
            {
                ctx->error = hr;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( parser, (yyval.view), view );
#if YYBISON >= 30704
            (void)yysymbol_name; /* avoid unused function warning */
#endif
        }
#line 1802 "dlls/wbemprox/wql.tab.c"
    break;

  case 10: /* associatorsof: TK_ASSOCIATORS TK_OF path TK_WHERE keywordlist  */
#line 307 "dlls/wbemprox/wql.y"
        {
            HRESULT hr;
            struct parser *parser = ctx;
            struct view *view;

            hr = create_view( VIEW_TYPE_ASSOCIATORS, ctx->ns, (yyvsp[-2].string), (yyvsp[0].keywordlist), NULL, NULL, NULL, &view );
            if (hr != S_OK)
            {
                ctx->error = hr;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( parser, (yyval.view), view );
        }
#line 1821 "dlls/wbemprox/wql.tab.c"
    break;

  case 11: /* select: TK_SELECT TK_FROM id  */
#line 325 "dlls/wbemprox/wql.y"
        {
            HRESULT hr;
            struct parser *parser = ctx;
            struct view *view;

            hr = create_view( VIEW_TYPE_SELECT, ctx->ns, NULL, NULL, (yyvsp[0].string), NULL, NULL, &view );
            if (hr != S_OK)
            {
                ctx->error = hr;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( parser, (yyval.view), view );
        }
#line 1840 "dlls/wbemprox/wql.tab.c"
    break;

  case 12: /* select: TK_SELECT proplist TK_FROM id  */
#line 340 "dlls/wbemprox/wql.y"
        {
            HRESULT hr;
            struct parser *parser = ctx;
            struct view *view;

            hr = create_view( VIEW_TYPE_SELECT, ctx->ns, NULL, NULL, (yyvsp[0].string), (yyvsp[-2].proplist), NULL, &view );
            if (hr != S_OK)
            {
                ctx->error = hr;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( parser, (yyval.view), view );
        }
#line 1859 "dlls/wbemprox/wql.tab.c"
    break;

  case 13: /* select: TK_SELECT proplist TK_FROM id TK_WHERE expr  */
#line 355 "dlls/wbemprox/wql.y"
        {
            HRESULT hr;
            struct parser *parser = ctx;
            struct view *view;

            hr = create_view( VIEW_TYPE_SELECT, ctx->ns, NULL, NULL, (yyvsp[-2].string), (yyvsp[-4].proplist), (yyvsp[0].expr), &view );
            if (hr != S_OK)
            {
                ctx->error = hr;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( parser, (yyval.view), view );
        }
#line 1878 "dlls/wbemprox/wql.tab.c"
    break;

  case 15: /* proplist: prop TK_COMMA proplist  */
#line 374 "dlls/wbemprox/wql.y"
        {
            (yyvsp[-2].proplist)->next = (yyvsp[0].proplist);
        }
#line 1886 "dlls/wbemprox/wql.tab.c"
    break;

  case 16: /* proplist: TK_STAR  */
#line 378 "dlls/wbemprox/wql.y"
        {
            (yyval.proplist) = NULL;
        }
#line 1894 "dlls/wbemprox/wql.tab.c"
    break;

  case 17: /* prop: id TK_DOT id  */
#line 385 "dlls/wbemprox/wql.y"
        {
            (yyval.proplist) = alloc_property( ctx, (yyvsp[-2].string), (yyvsp[0].string) );
            if (!(yyval.proplist))
                YYABORT;
        }
#line 1904 "dlls/wbemprox/wql.tab.c"
    break;

  case 18: /* prop: id  */
#line 391 "dlls/wbemprox/wql.y"
        {
            (yyval.proplist) = alloc_property( ctx, NULL, (yyvsp[0].string) );
            if (!(yyval.proplist))
                YYABORT;
        }
#line 1914 "dlls/wbemprox/wql.tab.c"
    break;

  case 19: /* id: TK_ID  */
#line 400 "dlls/wbemprox/wql.y"
        {
            (yyval.string) = get_string( ctx, &(yyvsp[0].str) );
            if (!(yyval.string))
                YYABORT;
        }
#line 1924 "dlls/wbemprox/wql.tab.c"
    break;

  case 20: /* number: TK_INTEGER  */
#line 409 "dlls/wbemprox/wql.y"
        {
            (yyval.integer) = get_int( ctx );
        }
#line 1932 "dlls/wbemprox/wql.tab.c"
    break;

  case 21: /* expr: TK_LP expr TK_RP  */
#line 416 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);
            if (!(yyval.expr))
                YYABORT;
        }
#line 1942 "dlls/wbemprox/wql.tab.c"
    break;

  case 22: /* expr: expr TK_AND expr  */
#line 422 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_AND, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 1952 "dlls/wbemprox/wql.tab.c"
    break;

  case 23: /* expr: expr TK_OR expr  */
#line 428 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_OR, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 1962 "dlls/wbemprox/wql.tab.c"
    break;

  case 24: /* expr: TK_NOT expr  */
#line 434 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[0].expr), OP_NOT );
            if (!(yyval.expr))
                YYABORT;
        }
#line 1972 "dlls/wbemprox/wql.tab.c"
    break;

  case 25: /* expr: prop_val TK_EQ const_val  */
#line 440 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_EQ, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 1982 "dlls/wbemprox/wql.tab.c"
    break;

  case 26: /* expr: prop_val TK_GT const_val  */
#line 446 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_GT, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 1992 "dlls/wbemprox/wql.tab.c"
    break;

  case 27: /* expr: prop_val TK_LT const_val  */
#line 452 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_LT, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2002 "dlls/wbemprox/wql.tab.c"
    break;

  case 28: /* expr: prop_val TK_LE const_val  */
#line 458 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_LE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2012 "dlls/wbemprox/wql.tab.c"
    break;

  case 29: /* expr: prop_val TK_GE const_val  */
#line 464 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_GE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2022 "dlls/wbemprox/wql.tab.c"
    break;

  case 30: /* expr: prop_val TK_NE const_val  */
#line 470 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_NE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2032 "dlls/wbemprox/wql.tab.c"
    break;

  case 31: /* expr: const_val TK_EQ prop_val  */
#line 476 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_EQ, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2042 "dlls/wbemprox/wql.tab.c"
    break;

  case 32: /* expr: const_val TK_GT prop_val  */
#line 482 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_GT, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2052 "dlls/wbemprox/wql.tab.c"
    break;

  case 33: /* expr: const_val TK_LT prop_val  */
#line 488 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_LT, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2062 "dlls/wbemprox/wql.tab.c"
    break;

  case 34: /* expr: const_val TK_LE prop_val  */
#line 494 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_LE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2072 "dlls/wbemprox/wql.tab.c"
    break;

  case 35: /* expr: const_val TK_GE prop_val  */
#line 500 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_GE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2082 "dlls/wbemprox/wql.tab.c"
    break;

  case 36: /* expr: const_val TK_NE prop_val  */
#line 506 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_NE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2092 "dlls/wbemprox/wql.tab.c"
    break;

  case 37: /* expr: prop_val TK_LIKE string_val  */
#line 512 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_complex( ctx, (yyvsp[-2].expr), OP_LIKE, (yyvsp[0].expr) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2102 "dlls/wbemprox/wql.tab.c"
    break;

  case 38: /* expr: prop_val TK_IS TK_NULL  */
#line 518 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[-2].expr), OP_ISNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2112 "dlls/wbemprox/wql.tab.c"
    break;

  case 39: /* expr: prop_val TK_IS TK_NOT TK_NULL  */
#line 524 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[-3].expr), OP_NOTNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2122 "dlls/wbemprox/wql.tab.c"
    break;

  case 40: /* expr: prop_val TK_EQ TK_NULL  */
#line 530 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[-2].expr), OP_ISNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2132 "dlls/wbemprox/wql.tab.c"
    break;

  case 41: /* expr: TK_NULL TK_EQ prop_val  */
#line 536 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[0].expr), OP_ISNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2142 "dlls/wbemprox/wql.tab.c"
    break;

  case 42: /* expr: prop_val TK_NE TK_NULL  */
#line 542 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[-2].expr), OP_NOTNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2152 "dlls/wbemprox/wql.tab.c"
    break;

  case 43: /* expr: TK_NULL TK_NE prop_val  */
#line 548 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_unary( ctx, (yyvsp[0].expr), OP_NOTNULL );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2162 "dlls/wbemprox/wql.tab.c"
    break;

  case 44: /* string_val: TK_STRING  */
#line 557 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_sval( ctx, &(yyvsp[0].str) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2172 "dlls/wbemprox/wql.tab.c"
    break;

  case 45: /* prop_val: prop  */
#line 566 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_propval( ctx, (yyvsp[0].proplist) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2182 "dlls/wbemprox/wql.tab.c"
    break;

  case 46: /* const_val: number  */
#line 575 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_ival( ctx, (yyvsp[0].integer) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2192 "dlls/wbemprox/wql.tab.c"
    break;

  case 47: /* const_val: TK_STRING  */
#line 581 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_sval( ctx, &(yyvsp[0].str) );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2202 "dlls/wbemprox/wql.tab.c"
    break;

  case 48: /* const_val: TK_TRUE  */
#line 587 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_bval( ctx, -1 );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2212 "dlls/wbemprox/wql.tab.c"
    break;

  case 49: /* const_val: TK_FALSE  */
#line 593 "dlls/wbemprox/wql.y"
        {
            (yyval.expr) = expr_bval( ctx, 0 );
            if (!(yyval.expr))
                YYABORT;
        }
#line 2222 "dlls/wbemprox/wql.tab.c"
    break;


#line 2226 "dlls/wbemprox/wql.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == WQL_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (ctx, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= WQL_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == WQL_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ctx);
          yychar = WQL_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != WQL_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 600 "dlls/wbemprox/wql.y"


HRESULT parse_query( enum wbm_namespace ns, const WCHAR *str, struct view **view, struct list *mem )
{
    struct parser parser;
    int ret;

    *view = NULL;

    parser.cmd   = str;
    parser.idx   = 0;
    parser.len   = 0;
    parser.error = WBEM_E_INVALID_QUERY;
    parser.view  = view;
    parser.mem   = mem;
    parser.ns    = ns;

    ret = wql_parse( &parser );
    TRACE("wql_parse returned %d\n", ret);
    if (ret)
    {
        if (*parser.view)
        {
            destroy_view( *parser.view );
            *parser.view = NULL;
        }
        return parser.error;
    }
    return S_OK;
}

static const char id_char[] =
{
    0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

static int is_idchar(WCHAR chr)
{
    return chr >= ARRAY_SIZE(id_char) || id_char[chr];
}

struct wql_keyword
{
    const WCHAR *name;
    unsigned int len;
    int type;
};

#define MIN_TOKEN_LEN 2
#define MAX_TOKEN_LEN 11

#define X(str)  str, ARRAY_SIZE(str) - 1
static const struct wql_keyword keyword_table[] =
{
    { X(L"AND"),         TK_AND },
    { X(L"ASSOCIATORS"), TK_ASSOCIATORS },
    { X(L"BY"),          TK_BY },
    { X(L"FALSE"),       TK_FALSE },
    { X(L"FROM"),        TK_FROM },
    { X(L"IS"),          TK_IS },
    { X(L"LIKE"),        TK_LIKE },
    { X(L"NOT"),         TK_NOT },
    { X(L"NULL"),        TK_NULL },
    { X(L"OF"),          TK_OF },
    { X(L"OR"),          TK_OR },
    { X(L"SELECT"),      TK_SELECT },
    { X(L"TRUE"),        TK_TRUE },
    { X(L"WHERE"),       TK_WHERE }
};
#undef X

static int __cdecl cmp_keyword( const void *arg1, const void *arg2 )
{
    const struct wql_keyword *key1 = arg1, *key2 = arg2;
    int len = min( key1->len, key2->len );
    int ret;

    if ((ret = wcsnicmp( key1->name, key2->name, len ))) return ret;
    if (key1->len < key2->len) return -1;
    else if (key1->len > key2->len) return 1;
    return 0;
}

static int keyword_type( const WCHAR *str, unsigned int len )
{
    struct wql_keyword key, *ret;

    if (len < MIN_TOKEN_LEN || len > MAX_TOKEN_LEN) return TK_ID;

    key.name = str;
    key.len  = len;
    key.type = 0;
    ret = bsearch( &key, keyword_table, ARRAY_SIZE(keyword_table), sizeof(struct wql_keyword), cmp_keyword );
    if (ret) return ret->type;
    return TK_ID;
}

static int get_token( const WCHAR *s, int *token )
{
    int i;

    switch (*s)
    {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
        for (i = 1; iswspace( s[i] ); i++) {}
        *token = TK_SPACE;
        return i;
    case '-':
        if (!s[1]) return -1;
        *token = TK_MINUS;
        return 1;
    case '(':
        *token = TK_LP;
        return 1;
    case ')':
        *token = TK_RP;
        return 1;
    case '{':
        for (i = 1; s[i] && s[i] != '}'; i++) {}
        if (s[i] != '}')
        {
            *token = TK_ILLEGAL;
            return i;
        }
        *token = TK_PATH;
        return i + 1;
    case '*':
        *token = TK_STAR;
        return 1;
    case '=':
        *token = TK_EQ;
        return 1;
    case '<':
        if (s[1] == '=' )
        {
            *token = TK_LE;
            return 2;
        }
        else if (s[1] == '>')
        {
            *token = TK_NE;
            return 2;
        }
        else
        {
            *token = TK_LT;
            return 1;
        }
    case '>':
        if (s[1] == '=')
        {
            *token = TK_GE;
            return 2;
        }
        else
        {
            *token = TK_GT;
            return 1;
        }
    case '!':
        if (s[1] != '=')
        {
            *token = TK_ILLEGAL;
            return 2;
        }
        else
        {
            *token = TK_NE;
            return 2;
        }
    case ',':
        *token = TK_COMMA;
        return 1;
    case '\"':
    case '\'':
        for (i = 1; s[i]; i++)
        {
            if (s[i] == s[0]) break;
        }
        if (s[i]) i++;
        *token = TK_STRING;
        return i;
    case '.':
        if (!is_digit( s[1] ))
        {
            *token = TK_DOT;
            return 1;
        }
        /* fall through */
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        *token = TK_INTEGER;
        for (i = 1; is_digit( s[i] ); i++) {}
        return i;
    default:
        if (!is_idchar(*s)) break;

        for (i = 1; is_idchar(s[i]); i++) {}
        *token = keyword_type( s, i );
        return i;
    }
    *token = TK_ILLEGAL;
    return 1;
}

static int wql_lex( void *p, struct parser *parser )
{
    struct string *str = p;
    int token = -1;
    do
    {
        parser->idx += parser->len;
        if (!parser->cmd[parser->idx]) return 0;
        parser->len = get_token( &parser->cmd[parser->idx], &token );
        if (!parser->len) break;

        str->data = &parser->cmd[parser->idx];
        str->len = parser->len;
    } while (token == TK_SPACE);
    return token;
}

static int wql_error( struct parser *parser, const char *str )
{
    ERR("%s\n", str);
    return 0;
}
