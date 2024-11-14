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
#define YYSTYPE         COND_STYPE
/* Substitute the variable and function names.  */
#define yyparse         cond_parse
#define yylex           cond_lex
#define yyerror         cond_error
#define yydebug         cond_debug
#define yynerrs         cond_nerrs

/* First part of user prologue.  */
#line 1 "dlls/msi/cond.y"


/*
 * Implementation of the Microsoft Installer (msi.dll)
 *
 * Copyright 2003 Mike McCormack for CodeWeavers
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

#define COBJMACROS

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "msi.h"
#include "msiquery.h"
#include "objbase.h"
#include "oleauto.h"

#include "msipriv.h"
#include "winemsi.h"
#include "wine/debug.h"
#include "wine/exception.h"
#include "wine/list.h"

WINE_DEFAULT_DEBUG_CHANNEL(msi);

typedef struct tag_yyinput
{
    MSIPACKAGE *package;
    LPCWSTR str;
    INT    n;
    MSICONDITION result;
    struct list mem;
} COND_input;

struct cond_str {
    LPCWSTR data;
    INT len;
};

struct value {
    enum value_type {
        VALUE_INTEGER,
        VALUE_LITERAL,
        VALUE_SYMBOL
    } type;
    union {
        INT integer;
        WCHAR *string;
    } u;
};

static LPWSTR COND_GetString( COND_input *info, const struct cond_str *str );
static LPWSTR COND_GetLiteral( COND_input *info, const struct cond_str *str );
static int cond_lex( void *COND_lval, COND_input *info);
static int cond_error( COND_input *info, const char *str);

static void *cond_alloc( COND_input *cond, unsigned int sz );
static void *cond_track_mem( COND_input *cond, void *ptr, unsigned int sz );
static void cond_free( void *ptr );

static INT compare_int( INT a, INT operator, INT b );
static INT compare_string( LPCWSTR a, INT operator, LPCWSTR b, BOOL convert );

static BOOL num_from_prop( LPCWSTR p, INT *val )
{
    INT ret = 0, sign = 1;

    if (!p)
        return FALSE;
    if (*p == '-')
    {
        sign = -1;
        p++;
    }
    if (!*p)
        return FALSE;
    while (*p)
    {
        if( *p < '0' || *p > '9' )
            return FALSE;
        ret = ret*10 + (*p - '0');
        p++;
    }
    *val = ret*sign;
    return TRUE;
}

static void value_free( struct value val )
{
    if (val.type != VALUE_INTEGER)
        cond_free( val.u.string );
}


#line 191 "dlls/msi/cond.tab.c"

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
#ifndef COND_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define COND_DEBUG 1
#  else
#   define COND_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define COND_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined COND_DEBUG */
#if COND_DEBUG
extern int cond_debug;
#endif

/* Token kinds.  */
#ifndef COND_TOKENTYPE
# define COND_TOKENTYPE
  enum cond_tokentype
  {
    COND_EMPTY = -2,
    COND_EOF = 0,                  /* "end of file"  */
    COND_error = 256,              /* error  */
    COND_UNDEF = 257,              /* "invalid token"  */
    COND_SPACE = 258,              /* COND_SPACE  */
    COND_OR = 259,                 /* COND_OR  */
    COND_AND = 260,                /* COND_AND  */
    COND_NOT = 261,                /* COND_NOT  */
    COND_XOR = 262,                /* COND_XOR  */
    COND_IMP = 263,                /* COND_IMP  */
    COND_EQV = 264,                /* COND_EQV  */
    COND_LT = 265,                 /* COND_LT  */
    COND_GT = 266,                 /* COND_GT  */
    COND_EQ = 267,                 /* COND_EQ  */
    COND_NE = 268,                 /* COND_NE  */
    COND_GE = 269,                 /* COND_GE  */
    COND_LE = 270,                 /* COND_LE  */
    COND_ILT = 271,                /* COND_ILT  */
    COND_IGT = 272,                /* COND_IGT  */
    COND_IEQ = 273,                /* COND_IEQ  */
    COND_INE = 274,                /* COND_INE  */
    COND_IGE = 275,                /* COND_IGE  */
    COND_ILE = 276,                /* COND_ILE  */
    COND_LPAR = 277,               /* COND_LPAR  */
    COND_RPAR = 278,               /* COND_RPAR  */
    COND_TILDA = 279,              /* COND_TILDA  */
    COND_SS = 280,                 /* COND_SS  */
    COND_ISS = 281,                /* COND_ISS  */
    COND_ILHS = 282,               /* COND_ILHS  */
    COND_IRHS = 283,               /* COND_IRHS  */
    COND_LHS = 284,                /* COND_LHS  */
    COND_RHS = 285,                /* COND_RHS  */
    COND_PERCENT = 286,            /* COND_PERCENT  */
    COND_DOLLARS = 287,            /* COND_DOLLARS  */
    COND_QUESTION = 288,           /* COND_QUESTION  */
    COND_AMPER = 289,              /* COND_AMPER  */
    COND_EXCLAM = 290,             /* COND_EXCLAM  */
    COND_IDENT = 291,              /* COND_IDENT  */
    COND_NUMBER = 292,             /* COND_NUMBER  */
    COND_LITER = 293,              /* COND_LITER  */
    COND_ERROR = 294               /* COND_ERROR  */
  };
  typedef enum cond_tokentype cond_token_kind_t;
#endif

/* Value type.  */
#if ! defined COND_STYPE && ! defined COND_STYPE_IS_DECLARED
union COND_STYPE
{
#line 121 "dlls/msi/cond.y"

    struct cond_str str;
    struct value value;
    LPWSTR identifier;
    INT operator;
    BOOL bool;

#line 293 "dlls/msi/cond.tab.c"

};
typedef union COND_STYPE COND_STYPE;
# define COND_STYPE_IS_TRIVIAL 1
# define COND_STYPE_IS_DECLARED 1
#endif




int cond_parse (COND_input *info);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COND_SPACE = 3,                 /* COND_SPACE  */
  YYSYMBOL_COND_OR = 4,                    /* COND_OR  */
  YYSYMBOL_COND_AND = 5,                   /* COND_AND  */
  YYSYMBOL_COND_NOT = 6,                   /* COND_NOT  */
  YYSYMBOL_COND_XOR = 7,                   /* COND_XOR  */
  YYSYMBOL_COND_IMP = 8,                   /* COND_IMP  */
  YYSYMBOL_COND_EQV = 9,                   /* COND_EQV  */
  YYSYMBOL_COND_LT = 10,                   /* COND_LT  */
  YYSYMBOL_COND_GT = 11,                   /* COND_GT  */
  YYSYMBOL_COND_EQ = 12,                   /* COND_EQ  */
  YYSYMBOL_COND_NE = 13,                   /* COND_NE  */
  YYSYMBOL_COND_GE = 14,                   /* COND_GE  */
  YYSYMBOL_COND_LE = 15,                   /* COND_LE  */
  YYSYMBOL_COND_ILT = 16,                  /* COND_ILT  */
  YYSYMBOL_COND_IGT = 17,                  /* COND_IGT  */
  YYSYMBOL_COND_IEQ = 18,                  /* COND_IEQ  */
  YYSYMBOL_COND_INE = 19,                  /* COND_INE  */
  YYSYMBOL_COND_IGE = 20,                  /* COND_IGE  */
  YYSYMBOL_COND_ILE = 21,                  /* COND_ILE  */
  YYSYMBOL_COND_LPAR = 22,                 /* COND_LPAR  */
  YYSYMBOL_COND_RPAR = 23,                 /* COND_RPAR  */
  YYSYMBOL_COND_TILDA = 24,                /* COND_TILDA  */
  YYSYMBOL_COND_SS = 25,                   /* COND_SS  */
  YYSYMBOL_COND_ISS = 26,                  /* COND_ISS  */
  YYSYMBOL_COND_ILHS = 27,                 /* COND_ILHS  */
  YYSYMBOL_COND_IRHS = 28,                 /* COND_IRHS  */
  YYSYMBOL_COND_LHS = 29,                  /* COND_LHS  */
  YYSYMBOL_COND_RHS = 30,                  /* COND_RHS  */
  YYSYMBOL_COND_PERCENT = 31,              /* COND_PERCENT  */
  YYSYMBOL_COND_DOLLARS = 32,              /* COND_DOLLARS  */
  YYSYMBOL_COND_QUESTION = 33,             /* COND_QUESTION  */
  YYSYMBOL_COND_AMPER = 34,                /* COND_AMPER  */
  YYSYMBOL_COND_EXCLAM = 35,               /* COND_EXCLAM  */
  YYSYMBOL_COND_IDENT = 36,                /* COND_IDENT  */
  YYSYMBOL_COND_NUMBER = 37,               /* COND_NUMBER  */
  YYSYMBOL_COND_LITER = 38,                /* COND_LITER  */
  YYSYMBOL_COND_ERROR = 39,                /* COND_ERROR  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_condition = 41,                 /* condition  */
  YYSYMBOL_expression = 42,                /* expression  */
  YYSYMBOL_boolean_term = 43,              /* boolean_term  */
  YYSYMBOL_boolean_factor = 44,            /* boolean_factor  */
  YYSYMBOL_operator = 45,                  /* operator  */
  YYSYMBOL_value = 46,                     /* value  */
  YYSYMBOL_identifier = 47                 /* identifier  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined COND_STYPE_IS_TRIVIAL && COND_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   67

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  56

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if COND_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   154,   161,   165,   169,   173,   177,   184,
     188,   195,   199,   207,   242,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   271,   285,   300,   308,   318,   335,   352,
     369,   389
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if COND_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "COND_SPACE",
  "COND_OR", "COND_AND", "COND_NOT", "COND_XOR", "COND_IMP", "COND_EQV",
  "COND_LT", "COND_GT", "COND_EQ", "COND_NE", "COND_GE", "COND_LE",
  "COND_ILT", "COND_IGT", "COND_IEQ", "COND_INE", "COND_IGE", "COND_ILE",
  "COND_LPAR", "COND_RPAR", "COND_TILDA", "COND_SS", "COND_ISS",
  "COND_ILHS", "COND_IRHS", "COND_LHS", "COND_RHS", "COND_PERCENT",
  "COND_DOLLARS", "COND_QUESTION", "COND_AMPER", "COND_EXCLAM",
  "COND_IDENT", "COND_NUMBER", "COND_LITER", "COND_ERROR", "$accept",
  "condition", "expression", "boolean_term", "boolean_factor", "operator",
  "value", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -6,    -6,    -6,   -35,   -35,   -35,   -35,   -35,   -45,   -45,
     -45,     2,     5,     6,   -45,    24,   -45,   -45,    -1,   -45,
     -45,   -45,   -45,   -45,   -45,    -6,    -6,    -6,    -6,    -6,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    25,   -45,
       6,     6,     6,     6,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,    41,    36,
      35,     0,     2,     4,     9,    12,    33,    11,     0,    34,
      37,    38,    39,    40,     1,     0,     0,     0,     0,     0,
      17,    18,    15,    16,    20,    19,    24,    25,    22,    23,
      27,    26,    21,    28,    31,    32,    29,    30,     0,    14,
       5,     7,     6,     8,    10,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,     8,    39,     4,   -45,   -44,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    48,    15,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     8,    24,    25,    55,    17,    26,    27,    28,    25,
      18,    29,    26,    27,    28,     0,     2,    19,    20,    21,
      22,    23,    49,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    54,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    50,    51,    52,    53
};

static const yytype_int8 yycheck[] =
{
       6,    36,     0,     4,    48,     1,     7,     8,     9,     4,
       2,     5,     7,     8,     9,    -1,    22,     3,     4,     5,
       6,     7,    23,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    29,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    22,    31,    32,    33,    34,    35,    36,    37,
      38,    41,    42,    43,    44,    46,    47,    44,    42,    47,
      47,    47,    47,    47,     0,     4,     7,     8,     9,     5,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    25,    26,    27,    28,    29,    30,    45,    23,
      43,    43,    43,    43,    44,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    42,    42,    42,    43,
      43,    44,    44,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    46,    46,    46,
      46,    47
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     3,     3,     3,     3,     1,
       3,     2,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     2,     2,
       2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = COND_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == COND_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (info, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use COND_error or COND_UNDEF. */
#define YYERRCODE COND_UNDEF


/* Enable debugging if requested.  */
#if COND_DEBUG

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
                  Kind, Value, info); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, COND_input *info)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (info);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, COND_input *info)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, info);
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
                 int yyrule, COND_input *info)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], info);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, info); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !COND_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !COND_DEBUG */


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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, COND_input *info)
{
  YY_USE (yyvaluep);
  YY_USE (info);
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
yyparse (COND_input *info)
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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = COND_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == COND_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, info);
    }

  if (yychar <= COND_EOF)
    {
      yychar = COND_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == COND_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = COND_UNDEF;
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
  yychar = COND_EMPTY;
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
  case 2: /* condition: expression  */
#line 149 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            cond->result = (yyvsp[0].bool);
        }
#line 1366 "dlls/msi/cond.tab.c"
    break;

  case 3: /* condition: %empty  */
#line 154 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            cond->result = MSICONDITION_NONE;
        }
#line 1375 "dlls/msi/cond.tab.c"
    break;

  case 4: /* expression: boolean_term  */
#line 162 "dlls/msi/cond.y"
        {
            (yyval.bool) = (yyvsp[0].bool);
        }
#line 1383 "dlls/msi/cond.tab.c"
    break;

  case 5: /* expression: expression COND_OR boolean_term  */
#line 166 "dlls/msi/cond.y"
        {
            (yyval.bool) = (yyvsp[-2].bool) || (yyvsp[0].bool);
        }
#line 1391 "dlls/msi/cond.tab.c"
    break;

  case 6: /* expression: expression COND_IMP boolean_term  */
#line 170 "dlls/msi/cond.y"
        {
            (yyval.bool) = !(yyvsp[-2].bool) || (yyvsp[0].bool);
        }
#line 1399 "dlls/msi/cond.tab.c"
    break;

  case 7: /* expression: expression COND_XOR boolean_term  */
#line 174 "dlls/msi/cond.y"
        {
            (yyval.bool) = ( (yyvsp[-2].bool) || (yyvsp[0].bool) ) && !( (yyvsp[-2].bool) && (yyvsp[0].bool) );
        }
#line 1407 "dlls/msi/cond.tab.c"
    break;

  case 8: /* expression: expression COND_EQV boolean_term  */
#line 178 "dlls/msi/cond.y"
        {
            (yyval.bool) = ( (yyvsp[-2].bool) && (yyvsp[0].bool) ) || ( !(yyvsp[-2].bool) && !(yyvsp[0].bool) );
        }
#line 1415 "dlls/msi/cond.tab.c"
    break;

  case 9: /* boolean_term: boolean_factor  */
#line 185 "dlls/msi/cond.y"
        {
            (yyval.bool) = (yyvsp[0].bool);
        }
#line 1423 "dlls/msi/cond.tab.c"
    break;

  case 10: /* boolean_term: boolean_term COND_AND boolean_factor  */
#line 189 "dlls/msi/cond.y"
        {
            (yyval.bool) = (yyvsp[-2].bool) && (yyvsp[0].bool);
        }
#line 1431 "dlls/msi/cond.tab.c"
    break;

  case 11: /* boolean_factor: COND_NOT boolean_factor  */
#line 196 "dlls/msi/cond.y"
        {
            (yyval.bool) = !(yyvsp[0].bool);
        }
#line 1439 "dlls/msi/cond.tab.c"
    break;

  case 12: /* boolean_factor: value  */
#line 200 "dlls/msi/cond.y"
        {
            if ((yyvsp[0].value).type == VALUE_INTEGER)
                (yyval.bool) = (yyvsp[0].value).u.integer ? 1 : 0;
            else
                (yyval.bool) = (yyvsp[0].value).u.string && (yyvsp[0].value).u.string[0];
            value_free( (yyvsp[0].value) );
        }
#line 1451 "dlls/msi/cond.tab.c"
    break;

  case 13: /* boolean_factor: value operator value  */
#line 208 "dlls/msi/cond.y"
        {
            if ((yyvsp[-2].value).type == VALUE_INTEGER && (yyvsp[0].value).type == VALUE_INTEGER)
            {
                (yyval.bool) = compare_int((yyvsp[-2].value).u.integer, (yyvsp[-1].operator), (yyvsp[0].value).u.integer);
            }
            else if ((yyvsp[-2].value).type != VALUE_INTEGER && (yyvsp[0].value).type != VALUE_INTEGER)
            {
                (yyval.bool) = compare_string((yyvsp[-2].value).u.string, (yyvsp[-1].operator), (yyvsp[0].value).u.string,
                        (yyvsp[-2].value).type == VALUE_SYMBOL || (yyvsp[0].value).type == VALUE_SYMBOL);
            }
            else if ((yyvsp[-2].value).type == VALUE_LITERAL || (yyvsp[0].value).type == VALUE_LITERAL)
            {
                (yyval.bool) = ((yyvsp[-1].operator) == COND_NE || (yyvsp[-1].operator) == COND_INE );
            }
            else if ((yyvsp[-2].value).type == VALUE_SYMBOL) /* symbol operator integer */
            {
                int num;
                if (num_from_prop( (yyvsp[-2].value).u.string, &num ))
                    (yyval.bool) = compare_int( num, (yyvsp[-1].operator), (yyvsp[0].value).u.integer );
                else
                    (yyval.bool) = ((yyvsp[-1].operator) == COND_NE || (yyvsp[-1].operator) == COND_INE );
            }
            else /* integer operator symbol */
            {
                int num;
                if (num_from_prop( (yyvsp[0].value).u.string, &num ))
                    (yyval.bool) = compare_int( (yyvsp[-2].value).u.integer, (yyvsp[-1].operator), num );
                else
                    (yyval.bool) = ((yyvsp[-1].operator) == COND_NE || (yyvsp[-1].operator) == COND_INE );
            }

            value_free( (yyvsp[-2].value) );
            value_free( (yyvsp[0].value) );
        }
#line 1490 "dlls/msi/cond.tab.c"
    break;

  case 14: /* boolean_factor: COND_LPAR expression COND_RPAR  */
#line 243 "dlls/msi/cond.y"
        {
            (yyval.bool) = (yyvsp[-1].bool);
        }
#line 1498 "dlls/msi/cond.tab.c"
    break;

  case 15: /* operator: COND_EQ  */
#line 250 "dlls/msi/cond.y"
            { (yyval.operator) = COND_EQ; }
#line 1504 "dlls/msi/cond.tab.c"
    break;

  case 16: /* operator: COND_NE  */
#line 251 "dlls/msi/cond.y"
            { (yyval.operator) = COND_NE; }
#line 1510 "dlls/msi/cond.tab.c"
    break;

  case 17: /* operator: COND_LT  */
#line 252 "dlls/msi/cond.y"
            { (yyval.operator) = COND_LT; }
#line 1516 "dlls/msi/cond.tab.c"
    break;

  case 18: /* operator: COND_GT  */
#line 253 "dlls/msi/cond.y"
            { (yyval.operator) = COND_GT; }
#line 1522 "dlls/msi/cond.tab.c"
    break;

  case 19: /* operator: COND_LE  */
#line 254 "dlls/msi/cond.y"
            { (yyval.operator) = COND_LE; }
#line 1528 "dlls/msi/cond.tab.c"
    break;

  case 20: /* operator: COND_GE  */
#line 255 "dlls/msi/cond.y"
            { (yyval.operator) = COND_GE; }
#line 1534 "dlls/msi/cond.tab.c"
    break;

  case 21: /* operator: COND_SS  */
#line 256 "dlls/msi/cond.y"
            { (yyval.operator) = COND_SS; }
#line 1540 "dlls/msi/cond.tab.c"
    break;

  case 22: /* operator: COND_IEQ  */
#line 257 "dlls/msi/cond.y"
             { (yyval.operator) = COND_IEQ; }
#line 1546 "dlls/msi/cond.tab.c"
    break;

  case 23: /* operator: COND_INE  */
#line 258 "dlls/msi/cond.y"
             { (yyval.operator) = COND_INE; }
#line 1552 "dlls/msi/cond.tab.c"
    break;

  case 24: /* operator: COND_ILT  */
#line 259 "dlls/msi/cond.y"
             { (yyval.operator) = COND_ILT; }
#line 1558 "dlls/msi/cond.tab.c"
    break;

  case 25: /* operator: COND_IGT  */
#line 260 "dlls/msi/cond.y"
             { (yyval.operator) = COND_IGT; }
#line 1564 "dlls/msi/cond.tab.c"
    break;

  case 26: /* operator: COND_ILE  */
#line 261 "dlls/msi/cond.y"
             { (yyval.operator) = COND_ILE; }
#line 1570 "dlls/msi/cond.tab.c"
    break;

  case 27: /* operator: COND_IGE  */
#line 262 "dlls/msi/cond.y"
             { (yyval.operator) = COND_IGE; }
#line 1576 "dlls/msi/cond.tab.c"
    break;

  case 28: /* operator: COND_ISS  */
#line 263 "dlls/msi/cond.y"
             { (yyval.operator) = COND_ISS; }
#line 1582 "dlls/msi/cond.tab.c"
    break;

  case 29: /* operator: COND_LHS  */
#line 264 "dlls/msi/cond.y"
             { (yyval.operator) = COND_LHS; }
#line 1588 "dlls/msi/cond.tab.c"
    break;

  case 30: /* operator: COND_RHS  */
#line 265 "dlls/msi/cond.y"
             { (yyval.operator) = COND_RHS; }
#line 1594 "dlls/msi/cond.tab.c"
    break;

  case 31: /* operator: COND_ILHS  */
#line 266 "dlls/msi/cond.y"
              { (yyval.operator) = COND_ILHS; }
#line 1600 "dlls/msi/cond.tab.c"
    break;

  case 32: /* operator: COND_IRHS  */
#line 267 "dlls/msi/cond.y"
              { (yyval.operator) = COND_IRHS; }
#line 1606 "dlls/msi/cond.tab.c"
    break;

  case 33: /* value: identifier  */
#line 272 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            UINT len;

            (yyval.value).type = VALUE_SYMBOL;
            (yyval.value).u.string = msi_dup_property( cond->package->db, (yyvsp[0].identifier) );
            if ((yyval.value).u.string)
            {
                len = (lstrlenW((yyval.value).u.string) + 1) * sizeof (WCHAR);
                (yyval.value).u.string = cond_track_mem( cond, (yyval.value).u.string, len );
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1624 "dlls/msi/cond.tab.c"
    break;

  case 34: /* value: COND_PERCENT identifier  */
#line 286 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            UINT len = GetEnvironmentVariableW( (yyvsp[0].identifier), NULL, 0 );
            (yyval.value).type = VALUE_SYMBOL;
            (yyval.value).u.string = NULL;
            if (len++)
            {
                (yyval.value).u.string = cond_alloc( cond, len*sizeof (WCHAR) );
                if( !(yyval.value).u.string )
                    YYABORT;
                GetEnvironmentVariableW( (yyvsp[0].identifier), (yyval.value).u.string, len );
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1643 "dlls/msi/cond.tab.c"
    break;

  case 35: /* value: COND_LITER  */
#line 301 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            (yyval.value).type = VALUE_LITERAL;
            (yyval.value).u.string = COND_GetLiteral( cond, &(yyvsp[0].str) );
            if( !(yyval.value).u.string )
                YYABORT;
        }
#line 1655 "dlls/msi/cond.tab.c"
    break;

  case 36: /* value: COND_NUMBER  */
#line 309 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            LPWSTR szNum = COND_GetString( cond, &(yyvsp[0].str) );
            if( !szNum )
                YYABORT;
            (yyval.value).type = VALUE_INTEGER;
            (yyval.value).u.integer = wcstol( szNum, NULL, 10 );
            cond_free( szNum );
        }
#line 1669 "dlls/msi/cond.tab.c"
    break;

  case 37: /* value: COND_DOLLARS identifier  */
#line 319 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            INSTALLSTATE install = INSTALLSTATE_UNKNOWN, action = INSTALLSTATE_UNKNOWN;

            if(MSI_GetComponentStateW(cond->package, (yyvsp[0].identifier), &install, &action ) != ERROR_SUCCESS)
            {
                (yyval.value).type = VALUE_LITERAL;
                (yyval.value).u.string = NULL;
            }
            else
            {
                (yyval.value).type = VALUE_INTEGER;
                (yyval.value).u.integer = action;
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1690 "dlls/msi/cond.tab.c"
    break;

  case 38: /* value: COND_QUESTION identifier  */
#line 336 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            INSTALLSTATE install = INSTALLSTATE_UNKNOWN, action = INSTALLSTATE_UNKNOWN;

            if(MSI_GetComponentStateW(cond->package, (yyvsp[0].identifier), &install, &action ) != ERROR_SUCCESS)
            {
                (yyval.value).type = VALUE_LITERAL;
                (yyval.value).u.string = NULL;
            }
            else
            {
                (yyval.value).type = VALUE_INTEGER;
                (yyval.value).u.integer = install;
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1711 "dlls/msi/cond.tab.c"
    break;

  case 39: /* value: COND_AMPER identifier  */
#line 353 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            INSTALLSTATE install, action;

            if (MSI_GetFeatureStateW(cond->package, (yyvsp[0].identifier), &install, &action ) != ERROR_SUCCESS)
            {
                (yyval.value).type = VALUE_LITERAL;
                (yyval.value).u.string = NULL;
            }
            else
            {
                (yyval.value).type = VALUE_INTEGER;
                (yyval.value).u.integer = action;
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1732 "dlls/msi/cond.tab.c"
    break;

  case 40: /* value: COND_EXCLAM identifier  */
#line 370 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            INSTALLSTATE install = INSTALLSTATE_UNKNOWN, action = INSTALLSTATE_UNKNOWN;

            if(MSI_GetFeatureStateW(cond->package, (yyvsp[0].identifier), &install, &action ) != ERROR_SUCCESS)
            {
                (yyval.value).type = VALUE_LITERAL;
                (yyval.value).u.string = NULL;
            }
            else
            {
                (yyval.value).type = VALUE_INTEGER;
                (yyval.value).u.integer = install;
            }
            cond_free( (yyvsp[0].identifier) );
        }
#line 1753 "dlls/msi/cond.tab.c"
    break;

  case 41: /* identifier: COND_IDENT  */
#line 390 "dlls/msi/cond.y"
        {
            COND_input* cond = (COND_input*) info;
            (yyval.identifier) = COND_GetString( cond, &(yyvsp[0].str) );
            if( !(yyval.identifier) )
                YYABORT;
        }
#line 1764 "dlls/msi/cond.tab.c"
    break;


#line 1768 "dlls/msi/cond.tab.c"

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
  yytoken = yychar == COND_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (info, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= COND_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == COND_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, info);
          yychar = COND_EMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, info);
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
  yyerror (info, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != COND_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, info);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, info);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 398 "dlls/msi/cond.y"



static int COND_IsAlpha( WCHAR x )
{
    return( ( ( x >= 'A' ) && ( x <= 'Z' ) ) ||
            ( ( x >= 'a' ) && ( x <= 'z' ) ) ||
            ( ( x == '_' ) ) );
}

static int COND_IsNumber( WCHAR x )
{
    return( (( x >= '0' ) && ( x <= '9' ))  || (x =='-') || (x =='.') );
}

static WCHAR *strstriW( const WCHAR *str, const WCHAR *sub )
{
    LPWSTR strlower, sublower, r;
    strlower = CharLowerW( wcsdup( str ) );
    sublower = CharLowerW( wcsdup( sub ) );
    r = wcsstr( strlower, sublower );
    if (r)
        r = (LPWSTR)str + (r - strlower);
    free( strlower );
    free( sublower );
    return r;
}

static BOOL str_is_number( LPCWSTR str )
{
    int i;

    if (!*str)
        return FALSE;

    for (i = 0; i < lstrlenW( str ); i++)
        if (!iswdigit(str[i]))
            return FALSE;

    return TRUE;
}

static INT compare_substring( LPCWSTR a, INT operator, LPCWSTR b )
{
    int lhs, rhs;

    /* substring operators return 0 if LHS is missing */
    if (!a || !*a)
        return 0;

    /* substring operators return 1 if RHS is missing */
    if (!b || !*b)
        return 1;

    /* if both strings contain only numbers, use integer comparison */
    lhs = wcstol(a, NULL, 10);
    rhs = wcstol(b, NULL, 10);
    if (str_is_number(a) && str_is_number(b))
        return compare_int( lhs, operator, rhs );

    switch (operator)
    {
    case COND_SS:
        return wcsstr( a, b ) != 0;
    case COND_ISS:
        return strstriW( a, b ) != 0;
    case COND_LHS:
    {
        int l = lstrlenW( a );
        int r = lstrlenW( b );
        if (r > l) return 0;
        return !wcsncmp( a, b, r );
    }
    case COND_RHS:
    {
        int l = lstrlenW( a );
        int r = lstrlenW( b );
        if (r > l) return 0;
        return !wcsncmp( a + (l - r), b, r );
    }
    case COND_ILHS:
    {
        int l = lstrlenW( a );
        int r = lstrlenW( b );
        if (r > l) return 0;
        return !wcsnicmp( a, b, r );
    }
    case COND_IRHS:
    {
        int l = lstrlenW( a );
        int r = lstrlenW( b );
        if (r > l) return 0;
        return !wcsnicmp( a + (l - r), b, r );
    }
    default:
        ERR("invalid substring operator\n");
        return 0;
    }
    return 0;
}

static INT compare_string( LPCWSTR a, INT operator, LPCWSTR b, BOOL convert )
{
    if (operator >= COND_SS && operator <= COND_RHS)
        return compare_substring( a, operator, b );

    /* null and empty string are equivalent */
    if (!a) a = L"";
    if (!b) b = L"";

    if (convert && str_is_number(a) && str_is_number(b))
        return compare_int( wcstol(a, NULL, 10), operator, wcstol(b, NULL, 10) );

    /* a or b may be NULL */
    switch (operator)
    {
    case COND_LT:
        return wcscmp( a, b ) < 0;
    case COND_GT:
        return wcscmp( a, b ) > 0;
    case COND_EQ:
        return wcscmp( a, b ) == 0;
    case COND_NE:
        return wcscmp( a, b ) != 0;
    case COND_GE:
        return wcscmp( a, b ) >= 0;
    case COND_LE:
        return wcscmp( a, b ) <= 0;
    case COND_ILT:
        return wcsicmp( a, b ) < 0;
    case COND_IGT:
        return wcsicmp( a, b ) > 0;
    case COND_IEQ:
        return wcsicmp( a, b ) == 0;
    case COND_INE:
        return wcsicmp( a, b ) != 0;
    case COND_IGE:
        return wcsicmp( a, b ) >= 0;
    case COND_ILE:
        return wcsicmp( a, b ) <= 0;
    default:
        ERR("invalid string operator\n");
        return 0;
    }
    return 0;
}


static INT compare_int( INT a, INT operator, INT b )
{
    switch (operator)
    {
    case COND_LT:
    case COND_ILT:
        return a < b;
    case COND_GT:
    case COND_IGT:
        return a > b;
    case COND_EQ:
    case COND_IEQ:
        return a == b;
    case COND_NE:
    case COND_INE:
        return a != b;
    case COND_GE:
    case COND_IGE:
        return a >= b;
    case COND_LE:
    case COND_ILE:
        return a <= b;
    case COND_SS:
    case COND_ISS:
        return ( a & b ) ? 1 : 0;
    case COND_RHS:
        return ( ( a & 0xffff ) == b ) ? 1 : 0;
    case COND_LHS:
        return ( ( (a>>16) & 0xffff ) == b ) ? 1 : 0;
    default:
        ERR("invalid integer operator\n");
        return 0;
    }
    return 0;
}


static int COND_IsIdent( WCHAR x )
{
    return( COND_IsAlpha( x ) || COND_IsNumber( x ) || ( x == '_' )
            || ( x == '#' ) || (x == '.') );
}

static int COND_GetOperator( COND_input *cond )
{
    static const struct {
        const WCHAR str[4];
        int id;
    } table[] = {
        { L"~<=", COND_ILE },
        { L"~><", COND_ISS },
        { L"~>>", COND_IRHS },
        { L"~<>", COND_INE },
        { L"~>=", COND_IGE },
        { L"~<<", COND_ILHS },
        { L"~=",  COND_IEQ },
        { L"~<",  COND_ILT },
        { L"~>",  COND_IGT },
        { L">=",  COND_GE },
        { L"><",  COND_SS },
        { L"<<",  COND_LHS },
        { L"<>",  COND_NE },
        { L"<=",  COND_LE },
        { L">>",  COND_RHS },
        { L">",   COND_GT },
        { L"<",   COND_LT },
        { L"",    0 }
    };
    LPCWSTR p = &cond->str[cond->n];
    int i = 0, len;

    while ( 1 )
    {
        len = lstrlenW( table[i].str );
        if ( !len || 0 == wcsncmp( table[i].str, p, len ) )
            break;
        i++;
    }
    cond->n += len;
    return table[i].id;
}

static int COND_GetOne( struct cond_str *str, COND_input *cond )
{
    int rc, len = 1;
    WCHAR ch;

    str->data = &cond->str[cond->n];

    ch = str->data[0];

    switch( ch )
    {
    case 0: return 0;
    case '(': rc = COND_LPAR; break;
    case ')': rc = COND_RPAR; break;
    case '&': rc = COND_AMPER; break;
    case '!': rc = COND_EXCLAM; break;
    case '$': rc = COND_DOLLARS; break;
    case '?': rc = COND_QUESTION; break;
    case '%': rc = COND_PERCENT; break;
    case ' ': rc = COND_SPACE; break;
    case '=': rc = COND_EQ; break;

    case '~':
    case '<':
    case '>':
        rc = COND_GetOperator( cond );
        if (!rc)
            rc = COND_ERROR;
        return rc;
    default:
        rc = 0;
    }

    if ( rc )
    {
        cond->n += len;
        return rc;
    }

    if (ch == '"' )
    {
        LPCWSTR p = wcschr( str->data + 1, '"' );
        if (!p) return COND_ERROR;
        len = p - str->data + 1;
        rc = COND_LITER;
    }
    else if( COND_IsAlpha( ch ) )
    {
        while( COND_IsIdent( str->data[len] ) )
            len++;
        rc = COND_IDENT;

        if ( len == 3 )
        {
            if ( !wcsnicmp( str->data, L"NOT", len ) )
                rc = COND_NOT;
            else if( !wcsnicmp( str->data, L"AND", len ) )
                rc = COND_AND;
            else if( !wcsnicmp( str->data, L"XOR", len ) )
                rc = COND_XOR;
            else if( !wcsnicmp( str->data, L"EQV", len ) )
                rc = COND_EQV;
            else if( !wcsnicmp( str->data, L"IMP", len ) )
                rc = COND_IMP;
        }
        else if( (len == 2) && !wcsnicmp( str->data, L"OR", len ) )
            rc = COND_OR;
    }
    else if( COND_IsNumber( ch ) )
    {
        while( COND_IsNumber( str->data[len] ) )
            len++;
        rc = COND_NUMBER;
    }
    else
    {
        ERR("Got unknown character %c(%x)\n",ch,ch);
        return COND_ERROR;
    }

    cond->n += len;
    str->len = len;

    return rc;
}

static int cond_lex( void *COND_lval, COND_input *cond )
{
    int rc;
    struct cond_str *str = COND_lval;

    do {
        rc = COND_GetOne( str, cond );
    } while (rc == COND_SPACE);

    return rc;
}

static LPWSTR COND_GetString( COND_input *cond, const struct cond_str *str )
{
    LPWSTR ret;

    ret = cond_alloc( cond, (str->len+1) * sizeof (WCHAR) );
    if( ret )
    {
        memcpy( ret, str->data, str->len * sizeof(WCHAR));
        ret[str->len]=0;
    }
    TRACE("Got identifier %s\n",debugstr_w(ret));
    return ret;
}

static LPWSTR COND_GetLiteral( COND_input *cond, const struct cond_str *str )
{
    LPWSTR ret;

    ret = cond_alloc( cond, (str->len-1) * sizeof (WCHAR) );
    if( ret )
    {
        memcpy( ret, str->data+1, (str->len-2) * sizeof(WCHAR) );
        ret[str->len - 2]=0;
    }
    TRACE("Got literal %s\n",debugstr_w(ret));
    return ret;
}

static void *cond_alloc( COND_input *cond, unsigned int sz )
{
    struct list *mem;

    mem = malloc( sizeof (struct list) + sz );
    if( !mem )
        return NULL;

    list_add_head( &(cond->mem), mem );
    return mem + 1;
}

static void *cond_track_mem( COND_input *cond, void *ptr, unsigned int sz )
{
    void *new_ptr;

    if( !ptr )
        return ptr;

    new_ptr = cond_alloc( cond, sz );
    if( !new_ptr )
    {
        free( ptr );
        return NULL;
    }

    memcpy( new_ptr, ptr, sz );
    free( ptr );
    return new_ptr;
}

static void cond_free( void *ptr )
{
    struct list *mem = (struct list *)ptr - 1;

    if( ptr )
    {
        list_remove( mem );
        free( mem );
    }
}

static int cond_error( COND_input *info, const char *str )
{
    TRACE("%s\n", str );
    return 0;
}

MSICONDITION MSI_EvaluateConditionW( MSIPACKAGE *package, LPCWSTR szCondition )
{
    COND_input cond;
    MSICONDITION r;
    struct list *mem, *safety;

    TRACE("%s\n", debugstr_w( szCondition ) );

    if (szCondition == NULL) return MSICONDITION_NONE;

    cond.package = package;
    cond.str   = szCondition;
    cond.n     = 0;
    cond.result = MSICONDITION_ERROR;

    list_init( &cond.mem );

    if ( !cond_parse( &cond ) )
        r = cond.result;
    else
        r = MSICONDITION_ERROR;

    LIST_FOR_EACH_SAFE( mem, safety, &cond.mem )
    {
        /* The tracked memory lives directly after the list struct */
        void *ptr = mem + 1;
        if ( r != MSICONDITION_ERROR )
            WARN( "condition parser failed to free up some memory: %p\n", ptr );
        cond_free( ptr );
    }

    TRACE("%i <- %s\n", r, debugstr_w(szCondition));
    return r;
}

MSICONDITION WINAPI MsiEvaluateConditionW( MSIHANDLE hInstall, LPCWSTR szCondition )
{
    MSIPACKAGE *package;
    UINT ret;

    package = msihandle2msiinfo( hInstall, MSIHANDLETYPE_PACKAGE);
    if( !package )
    {
        MSIHANDLE remote;

        if (!(remote = msi_get_remote(hInstall)))
            return MSICONDITION_ERROR;

        if (!szCondition)
            return MSICONDITION_NONE;

        __TRY
        {
            ret = remote_EvaluateCondition(remote, szCondition);
        }
        __EXCEPT(rpc_filter)
        {
            ret = GetExceptionCode();
        }
        __ENDTRY

        return ret;
    }

    ret = MSI_EvaluateConditionW( package, szCondition );
    msiobj_release( &package->hdr );
    return ret;
}

MSICONDITION WINAPI MsiEvaluateConditionA( MSIHANDLE hInstall, LPCSTR szCondition )
{
    LPWSTR szwCond = NULL;
    MSICONDITION r;

    szwCond = strdupAtoW( szCondition );
    if( szCondition && !szwCond )
        return MSICONDITION_ERROR;

    r = MsiEvaluateConditionW( hInstall, szwCond );
    free( szwCond );
    return r;
}
