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
#define YYSTYPE         SQL_STYPE
/* Substitute the variable and function names.  */
#define yyparse         sql_parse
#define yylex           sql_lex
#define yyerror         sql_error
#define yydebug         sql_debug
#define yynerrs         sql_nerrs

/* First part of user prologue.  */
#line 1 "dlls/msi/sql.y"


/*
 * Implementation of the Microsoft Installer (msi.dll)
 *
 * Copyright 2002-2004 Mike McCormack for CodeWeavers
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
#include <stdio.h>
#include <stdlib.h>

#include "windef.h"
#include "winbase.h"
#include "query.h"
#include "wine/list.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(msi);

static UINT SQL_getstring( void *info, const struct sql_str *strdata, LPWSTR *str );
static INT SQL_getint( void *info );
static int sql_lex( void *SQL_lval, SQL_input *info );
static int sql_error( SQL_input *info, const char *str);

static LPWSTR parser_add_table( void *info, LPCWSTR list, LPCWSTR table );
static void *parser_alloc( void *info, unsigned int sz );
static column_info *parser_alloc_column( void *info, LPCWSTR table, LPCWSTR column );

static BOOL SQL_MarkPrimaryKeys( column_info **cols, column_info *keys);

static struct expr * EXPR_complex( void *info, struct expr *l, UINT op, struct expr *r );
static struct expr * EXPR_unary( void *info, struct expr *l, UINT op );
static struct expr * EXPR_column( void *info, const column_info *column );
static struct expr * EXPR_ival( void *info, int val );
static struct expr * EXPR_sval( void *info, const struct sql_str *str );
static struct expr * EXPR_wildcard( void *info );

#define PARSER_BUBBLE_UP_VIEW( sql, result, current_view ) \
    *sql->view = current_view; \
    result = current_view


#line 135 "dlls/msi/sql.tab.c"

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
#ifndef SQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define SQL_DEBUG 1
#  else
#   define SQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define SQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined SQL_DEBUG */
#if SQL_DEBUG
extern int sql_debug;
#endif

/* Token kinds.  */
#ifndef SQL_TOKENTYPE
# define SQL_TOKENTYPE
  enum sql_tokentype
  {
    SQL_EMPTY = -2,
    SQL_EOF = 0,                   /* "end of file"  */
    SQL_error = 256,               /* error  */
    SQL_UNDEF = 257,               /* "invalid token"  */
    TK_ALTER = 258,                /* TK_ALTER  */
    TK_AND = 259,                  /* TK_AND  */
    TK_BY = 260,                   /* TK_BY  */
    TK_CHAR = 261,                 /* TK_CHAR  */
    TK_COMMA = 262,                /* TK_COMMA  */
    TK_CREATE = 263,               /* TK_CREATE  */
    TK_DELETE = 264,               /* TK_DELETE  */
    TK_DROP = 265,                 /* TK_DROP  */
    TK_DISTINCT = 266,             /* TK_DISTINCT  */
    TK_DOT = 267,                  /* TK_DOT  */
    TK_EQ = 268,                   /* TK_EQ  */
    TK_FREE = 269,                 /* TK_FREE  */
    TK_FROM = 270,                 /* TK_FROM  */
    TK_GE = 271,                   /* TK_GE  */
    TK_GT = 272,                   /* TK_GT  */
    TK_HOLD = 273,                 /* TK_HOLD  */
    TK_ADD = 274,                  /* TK_ADD  */
    TK_ID = 275,                   /* TK_ID  */
    TK_ILLEGAL = 276,              /* TK_ILLEGAL  */
    TK_INSERT = 277,               /* TK_INSERT  */
    TK_INT = 278,                  /* TK_INT  */
    TK_INTEGER = 279,              /* TK_INTEGER  */
    TK_INTO = 280,                 /* TK_INTO  */
    TK_IS = 281,                   /* TK_IS  */
    TK_KEY = 282,                  /* TK_KEY  */
    TK_LE = 283,                   /* TK_LE  */
    TK_LONG = 284,                 /* TK_LONG  */
    TK_LONGCHAR = 285,             /* TK_LONGCHAR  */
    TK_LP = 286,                   /* TK_LP  */
    TK_LT = 287,                   /* TK_LT  */
    TK_LOCALIZABLE = 288,          /* TK_LOCALIZABLE  */
    TK_MINUS = 289,                /* TK_MINUS  */
    TK_NE = 290,                   /* TK_NE  */
    TK_NOT = 291,                  /* TK_NOT  */
    TK_NULL = 292,                 /* TK_NULL  */
    TK_OBJECT = 293,               /* TK_OBJECT  */
    TK_OR = 294,                   /* TK_OR  */
    TK_ORDER = 295,                /* TK_ORDER  */
    TK_PRIMARY = 296,              /* TK_PRIMARY  */
    TK_RP = 297,                   /* TK_RP  */
    TK_SELECT = 298,               /* TK_SELECT  */
    TK_SET = 299,                  /* TK_SET  */
    TK_SHORT = 300,                /* TK_SHORT  */
    TK_SPACE = 301,                /* TK_SPACE  */
    TK_STAR = 302,                 /* TK_STAR  */
    TK_STRING = 303,               /* TK_STRING  */
    TK_TABLE = 304,                /* TK_TABLE  */
    TK_TEMPORARY = 305,            /* TK_TEMPORARY  */
    TK_UPDATE = 306,               /* TK_UPDATE  */
    TK_VALUES = 307,               /* TK_VALUES  */
    TK_WHERE = 308,                /* TK_WHERE  */
    TK_WILDCARD = 309,             /* TK_WILDCARD  */
    END_OF_FILE = 310,             /* END_OF_FILE  */
    ILLEGAL = 311,                 /* ILLEGAL  */
    SPACE = 312,                   /* SPACE  */
    UNCLOSED_STRING = 313,         /* UNCLOSED_STRING  */
    COMMENT = 314,                 /* COMMENT  */
    FUNCTION = 315,                /* FUNCTION  */
    COLUMN = 316,                  /* COLUMN  */
    TK_LIKE = 318,                 /* TK_LIKE  */
    TK_NEGATION = 319              /* TK_NEGATION  */
  };
  typedef enum sql_tokentype sql_token_kind_t;
#endif

/* Value type.  */
#if ! defined SQL_STYPE && ! defined SQL_STYPE_IS_DECLARED
union SQL_STYPE
{
#line 65 "dlls/msi/sql.y"

    struct sql_str str;
    LPWSTR string;
    column_info *column_list;
    MSIVIEW *query;
    struct expr *expr;
    USHORT column_type;
    int integer;

#line 263 "dlls/msi/sql.tab.c"

};
typedef union SQL_STYPE SQL_STYPE;
# define SQL_STYPE_IS_TRIVIAL 1
# define SQL_STYPE_IS_DECLARED 1
#endif




int sql_parse (SQL_input *info);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_ALTER = 3,                   /* TK_ALTER  */
  YYSYMBOL_TK_AND = 4,                     /* TK_AND  */
  YYSYMBOL_TK_BY = 5,                      /* TK_BY  */
  YYSYMBOL_TK_CHAR = 6,                    /* TK_CHAR  */
  YYSYMBOL_TK_COMMA = 7,                   /* TK_COMMA  */
  YYSYMBOL_TK_CREATE = 8,                  /* TK_CREATE  */
  YYSYMBOL_TK_DELETE = 9,                  /* TK_DELETE  */
  YYSYMBOL_TK_DROP = 10,                   /* TK_DROP  */
  YYSYMBOL_TK_DISTINCT = 11,               /* TK_DISTINCT  */
  YYSYMBOL_TK_DOT = 12,                    /* TK_DOT  */
  YYSYMBOL_TK_EQ = 13,                     /* TK_EQ  */
  YYSYMBOL_TK_FREE = 14,                   /* TK_FREE  */
  YYSYMBOL_TK_FROM = 15,                   /* TK_FROM  */
  YYSYMBOL_TK_GE = 16,                     /* TK_GE  */
  YYSYMBOL_TK_GT = 17,                     /* TK_GT  */
  YYSYMBOL_TK_HOLD = 18,                   /* TK_HOLD  */
  YYSYMBOL_TK_ADD = 19,                    /* TK_ADD  */
  YYSYMBOL_TK_ID = 20,                     /* TK_ID  */
  YYSYMBOL_TK_ILLEGAL = 21,                /* TK_ILLEGAL  */
  YYSYMBOL_TK_INSERT = 22,                 /* TK_INSERT  */
  YYSYMBOL_TK_INT = 23,                    /* TK_INT  */
  YYSYMBOL_TK_INTEGER = 24,                /* TK_INTEGER  */
  YYSYMBOL_TK_INTO = 25,                   /* TK_INTO  */
  YYSYMBOL_TK_IS = 26,                     /* TK_IS  */
  YYSYMBOL_TK_KEY = 27,                    /* TK_KEY  */
  YYSYMBOL_TK_LE = 28,                     /* TK_LE  */
  YYSYMBOL_TK_LONG = 29,                   /* TK_LONG  */
  YYSYMBOL_TK_LONGCHAR = 30,               /* TK_LONGCHAR  */
  YYSYMBOL_TK_LP = 31,                     /* TK_LP  */
  YYSYMBOL_TK_LT = 32,                     /* TK_LT  */
  YYSYMBOL_TK_LOCALIZABLE = 33,            /* TK_LOCALIZABLE  */
  YYSYMBOL_TK_MINUS = 34,                  /* TK_MINUS  */
  YYSYMBOL_TK_NE = 35,                     /* TK_NE  */
  YYSYMBOL_TK_NOT = 36,                    /* TK_NOT  */
  YYSYMBOL_TK_NULL = 37,                   /* TK_NULL  */
  YYSYMBOL_TK_OBJECT = 38,                 /* TK_OBJECT  */
  YYSYMBOL_TK_OR = 39,                     /* TK_OR  */
  YYSYMBOL_TK_ORDER = 40,                  /* TK_ORDER  */
  YYSYMBOL_TK_PRIMARY = 41,                /* TK_PRIMARY  */
  YYSYMBOL_TK_RP = 42,                     /* TK_RP  */
  YYSYMBOL_TK_SELECT = 43,                 /* TK_SELECT  */
  YYSYMBOL_TK_SET = 44,                    /* TK_SET  */
  YYSYMBOL_TK_SHORT = 45,                  /* TK_SHORT  */
  YYSYMBOL_TK_SPACE = 46,                  /* TK_SPACE  */
  YYSYMBOL_TK_STAR = 47,                   /* TK_STAR  */
  YYSYMBOL_TK_STRING = 48,                 /* TK_STRING  */
  YYSYMBOL_TK_TABLE = 49,                  /* TK_TABLE  */
  YYSYMBOL_TK_TEMPORARY = 50,              /* TK_TEMPORARY  */
  YYSYMBOL_TK_UPDATE = 51,                 /* TK_UPDATE  */
  YYSYMBOL_TK_VALUES = 52,                 /* TK_VALUES  */
  YYSYMBOL_TK_WHERE = 53,                  /* TK_WHERE  */
  YYSYMBOL_TK_WILDCARD = 54,               /* TK_WILDCARD  */
  YYSYMBOL_END_OF_FILE = 55,               /* END_OF_FILE  */
  YYSYMBOL_ILLEGAL = 56,                   /* ILLEGAL  */
  YYSYMBOL_SPACE = 57,                     /* SPACE  */
  YYSYMBOL_UNCLOSED_STRING = 58,           /* UNCLOSED_STRING  */
  YYSYMBOL_COMMENT = 59,                   /* COMMENT  */
  YYSYMBOL_FUNCTION = 60,                  /* FUNCTION  */
  YYSYMBOL_COLUMN = 61,                    /* COLUMN  */
  YYSYMBOL_62_AGG_FUNCTION_ = 62,          /* AGG_FUNCTION.  */
  YYSYMBOL_TK_LIKE = 63,                   /* TK_LIKE  */
  YYSYMBOL_TK_NEGATION = 64,               /* TK_NEGATION  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_query = 66,                     /* query  */
  YYSYMBOL_onequery = 67,                  /* onequery  */
  YYSYMBOL_oneinsert = 68,                 /* oneinsert  */
  YYSYMBOL_onecreate = 69,                 /* onecreate  */
  YYSYMBOL_oneupdate = 70,                 /* oneupdate  */
  YYSYMBOL_onedelete = 71,                 /* onedelete  */
  YYSYMBOL_onealter = 72,                  /* onealter  */
  YYSYMBOL_alterop = 73,                   /* alterop  */
  YYSYMBOL_onedrop = 74,                   /* onedrop  */
  YYSYMBOL_table_def = 75,                 /* table_def  */
  YYSYMBOL_column_def = 76,                /* column_def  */
  YYSYMBOL_column_and_type = 77,           /* column_and_type  */
  YYSYMBOL_column_type = 78,               /* column_type  */
  YYSYMBOL_data_type_l = 79,               /* data_type_l  */
  YYSYMBOL_data_type = 80,                 /* data_type  */
  YYSYMBOL_data_count = 81,                /* data_count  */
  YYSYMBOL_oneselect = 82,                 /* oneselect  */
  YYSYMBOL_selectfrom = 83,                /* selectfrom  */
  YYSYMBOL_selcollist = 84,                /* selcollist  */
  YYSYMBOL_collist = 85,                   /* collist  */
  YYSYMBOL_from = 86,                      /* from  */
  YYSYMBOL_unorderdfrom = 87,              /* unorderdfrom  */
  YYSYMBOL_tablelist = 88,                 /* tablelist  */
  YYSYMBOL_expr = 89,                      /* expr  */
  YYSYMBOL_val = 90,                       /* val  */
  YYSYMBOL_constlist = 91,                 /* constlist  */
  YYSYMBOL_update_assign_list = 92,        /* update_assign_list  */
  YYSYMBOL_column_assignment = 93,         /* column_assignment  */
  YYSYMBOL_const_val = 94,                 /* const_val  */
  YYSYMBOL_column_val = 95,                /* column_val  */
  YYSYMBOL_column = 96,                    /* column  */
  YYSYMBOL_selcolumn = 97,                 /* selcolumn  */
  YYSYMBOL_table = 98,                     /* table  */
  YYSYMBOL_id = 99,                        /* id  */
  YYSYMBOL_string = 100,                   /* string  */
  YYSYMBOL_number = 101                    /* number  */
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
typedef yytype_uint8 yy_state_t;

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
         || (defined SQL_STYPE_IS_TRIVIAL && SQL_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if SQL_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   122,   123,   124,   125,   126,   127,   128,
     132,   143,   157,   174,   190,   201,   215,   229,   240,   251,
     265,   269,   276,   291,   301,   311,   318,   326,   330,   334,
     341,   345,   352,   356,   360,   364,   368,   372,   376,   383,
     392,   396,   411,   431,   432,   436,   443,   444,   448,   455,
     467,   480,   484,   496,   511,   515,   524,   530,   536,   542,
     548,   554,   560,   566,   572,   578,   584,   593,   594,   598,
     605,   616,   617,   625,   633,   639,   645,   651,   657,   666,
     675,   681,   690,   696,   702,   711,   718,   726,   734
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if SQL_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_ALTER", "TK_AND",
  "TK_BY", "TK_CHAR", "TK_COMMA", "TK_CREATE", "TK_DELETE", "TK_DROP",
  "TK_DISTINCT", "TK_DOT", "TK_EQ", "TK_FREE", "TK_FROM", "TK_GE", "TK_GT",
  "TK_HOLD", "TK_ADD", "TK_ID", "TK_ILLEGAL", "TK_INSERT", "TK_INT",
  "TK_INTEGER", "TK_INTO", "TK_IS", "TK_KEY", "TK_LE", "TK_LONG",
  "TK_LONGCHAR", "TK_LP", "TK_LT", "TK_LOCALIZABLE", "TK_MINUS", "TK_NE",
  "TK_NOT", "TK_NULL", "TK_OBJECT", "TK_OR", "TK_ORDER", "TK_PRIMARY",
  "TK_RP", "TK_SELECT", "TK_SET", "TK_SHORT", "TK_SPACE", "TK_STAR",
  "TK_STRING", "TK_TABLE", "TK_TEMPORARY", "TK_UPDATE", "TK_VALUES",
  "TK_WHERE", "TK_WILDCARD", "END_OF_FILE", "ILLEGAL", "SPACE",
  "UNCLOSED_STRING", "COMMENT", "FUNCTION", "COLUMN", "AGG_FUNCTION.",
  "TK_LIKE", "TK_NEGATION", "$accept", "query", "onequery", "oneinsert",
  "onecreate", "oneupdate", "onedelete", "onealter", "alterop", "onedrop",
  "table_def", "column_def", "column_and_type", "column_type",
  "data_type_l", "data_type", "data_count", "oneselect", "selectfrom",
  "selcollist", "collist", "from", "unorderdfrom", "tablelist", "expr",
  "val", "constlist", "update_assign_list", "column_assignment",
  "const_val", "column_val", "column", "selcolumn", "table", "id",
  "string", "number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -44,   -39,    -1,   -24,    25,    65,    34,    59,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    34,    34,    34,
     -81,    41,    34,    34,     9,   -81,   -81,   -81,   -81,    -1,
      27,    58,    74,   -81,    51,   -81,   -81,    86,    67,    48,
      23,    97,   -81,    84,   -81,   -81,     9,    34,    34,   -81,
     -81,    34,   -81,    34,   -16,    34,   -12,   -12,   -81,   -81,
      63,   111,   106,   109,    74,   107,    45,    82,     2,   -81,
     -16,     3,    94,   -81,   -81,   123,   -81,   -81,   126,    95,
     -16,    34,    69,    34,   -81,   108,   -81,   -81,   -81,   -81,
     -81,   -81,    32,   102,   122,    34,   114,    22,   -16,   -16,
      60,    60,    60,    52,    60,    60,    60,   -12,    90,     3,
     -81,   -81,   119,   -81,   -81,   -81,   -81,   -81,   -81,   119,
     -81,   -81,   110,   -81,   -81,   -12,   -81,   -81,   140,   -81,
     -81,   -81,   -81,   -81,   112,   -81,   -81,   -81,   -81,   -81,
     115,   -81,   103,   -81,   -81,   -81,   -81,    69,   -81,   113,
     141,   100,    69,   -81,   -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       5,     4,     6,     7,     8,     9,     3,     0,     0,     0,
      16,    51,     0,     0,     0,    86,    45,    87,    40,     0,
      43,     0,    83,    84,     0,    85,     1,     0,     0,    52,
      54,     0,    22,     0,    41,    42,     0,     0,     0,    21,
      20,     0,    17,     0,     0,     0,     0,     0,    44,    82,
      15,    71,     0,     0,    81,    18,     0,     0,     0,    25,
       0,    53,     0,    79,    55,    54,    48,    50,    46,     0,
       0,     0,     0,     0,    19,    32,    36,    37,    34,    38,
      35,    26,    27,    30,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      72,    88,     0,    78,    76,    77,    73,    74,    80,     0,
      28,    29,     0,    13,    24,     0,    56,    57,    58,    59,
      68,    67,    63,    60,     0,    65,    62,    61,    64,    47,
       0,    75,     0,    39,    31,    23,    66,     0,    33,     0,
      69,    10,     0,    11,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -47,   -81,   -81,   -81,   -81,   -81,   127,   116,
     -54,   124,   -81,    99,    29,    30,     0,    75,   -81,   -80,
      -7,   -29,   -81,    14,    -6,   -81,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,    14,    52,    15,
      67,    68,    65,    91,    92,    93,   142,    16,    28,    29,
      77,    20,    21,    39,    71,   129,   149,    60,    61,   130,
     131,    73,    30,    63,    64,    33,   117
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    35,   116,    79,    25,    17,    69,    98,    25,    95,
      18,    35,    35,    35,    19,    70,    35,    35,    32,    62,
      31,    34,    66,   -49,    66,    22,    98,    78,    78,    25,
      55,    37,    38,    40,    46,    76,    42,    43,    31,     1,
      32,    59,    99,    96,     2,     3,     4,    72,   124,    35,
      23,    85,    62,   139,    25,   141,    26,    27,     5,    36,
      31,    99,   143,    72,   126,   120,    66,   150,    86,    75,
      47,   145,   150,    72,    87,    88,    24,   118,    78,     6,
      25,    41,   121,    89,   111,    25,   -85,     7,   134,   135,
      90,    72,    72,   111,   112,    48,    78,   113,    53,    97,
      49,    54,    56,   112,    50,    51,   113,   100,   114,   109,
     101,   102,    26,    27,   115,    57,    80,   114,    81,    82,
     103,    83,   104,   115,    94,    84,   105,   127,   128,   106,
      55,   132,   133,   107,   136,   137,   138,   108,   122,   119,
     123,   125,   140,   111,    98,   148,   147,   144,   152,   146,
     153,    44,   154,    45,    74,   151,   110,     0,     0,     0,
       0,     0,    58
};

static const yytype_int16 yycheck[] =
{
       6,     7,    82,    57,    20,    49,    53,     4,    20,     7,
      49,    17,    18,    19,    15,    31,    22,    23,    24,    48,
       6,     7,    51,     0,    53,    49,     4,    56,    57,    20,
       7,    17,    18,    19,     7,    47,    22,    23,    24,     3,
      46,    47,    39,    41,     8,     9,    10,    54,    95,    55,
      25,     6,    81,   107,    20,   112,    47,    48,    22,     0,
      46,    39,   119,    70,    42,    33,    95,   147,    23,    55,
      12,   125,   152,    80,    29,    30,    11,    83,   107,    43,
      20,    40,    50,    38,    24,    20,    12,    51,    36,    37,
      45,    98,    99,    24,    34,    44,   125,    37,    31,    70,
      14,    53,     5,    34,    18,    19,    37,    13,    48,    80,
      16,    17,    47,    48,    54,    31,    53,    48,     7,    13,
      26,    12,    28,    54,    42,    18,    32,    98,    99,    35,
       7,   101,   102,     7,   104,   105,   106,    42,    36,    31,
      18,    27,    52,    24,     4,    42,    31,    37,     7,    37,
      50,    24,   152,    29,    55,    42,    81,    -1,    -1,    -1,
      -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,     9,    10,    22,    43,    51,    66,    67,
      68,    69,    70,    71,    72,    74,    82,    49,    49,    15,
      86,    87,    49,    25,    11,    20,    47,    48,    83,    84,
      97,    98,    99,   100,    98,    99,     0,    98,    98,    88,
      98,    40,    98,    98,    83,    86,     7,    12,    44,    14,
      18,    19,    73,    31,    53,     7,     5,    31,    84,    99,
      92,    93,    96,    98,    99,    77,    96,    75,    76,    77,
      31,    89,    95,    96,    88,    98,    47,    85,    96,    85,
      53,     7,    13,    12,    18,     6,    23,    29,    30,    38,
      45,    78,    79,    80,    42,     7,    41,    89,     4,    39,
      13,    16,    17,    26,    28,    32,    35,     7,    42,    89,
      92,    24,    34,    37,    48,    54,    94,   101,    99,    31,
      33,    50,    36,    18,    77,    27,    42,    89,    89,    90,
      94,    95,    90,    90,    36,    37,    90,    90,    90,    85,
      52,   101,    81,   101,    37,    85,    37,    31,    42,    91,
      94,    42,     7,    50,    91
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    72,    72,
      73,    73,    74,    75,    76,    76,    77,    78,    78,    78,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    81,
      82,    82,    83,    84,    84,    84,    85,    85,    85,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    94,    94,    94,    94,    94,    95,
      96,    96,    97,    97,    97,    98,    99,   100,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
      10,    11,     6,     7,     6,     4,     2,     4,     5,     6,
       1,     1,     3,     4,     3,     1,     2,     1,     2,     2,
       1,     3,     1,     4,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     1,     3,     1,     1,     3,     1,     2,
       4,     1,     2,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     1,     1,
       3,     1,     3,     3,     1,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = SQL_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == SQL_EMPTY)                                        \
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
   Use SQL_error or SQL_UNDEF. */
#define YYERRCODE SQL_UNDEF


/* Enable debugging if requested.  */
#if SQL_DEBUG

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
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, SQL_input *info)
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, SQL_input *info)
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
                 int yyrule, SQL_input *info)
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
#else /* !SQL_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !SQL_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, SQL_input *info)
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
yyparse (SQL_input *info)
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

  yychar = SQL_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == SQL_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, info);
    }

  if (yychar <= SQL_EOF)
    {
      yychar = SQL_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == SQL_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = SQL_UNDEF;
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
  yychar = SQL_EMPTY;
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
  case 2: /* query: onequery  */
#line 115 "dlls/msi/sql.y"
    {
        SQL_input* sql = (SQL_input*) info;
        *sql->view = (yyvsp[0].query);
    }
#line 1469 "dlls/msi/sql.tab.c"
    break;

  case 10: /* oneinsert: TK_INSERT TK_INTO table TK_LP collist TK_RP TK_VALUES TK_LP constlist TK_RP  */
#line 133 "dlls/msi/sql.y"
        {
            SQL_input *sql = (SQL_input*) info;
            MSIVIEW *insert = NULL;

            INSERT_CreateView( sql->db, &insert, (yyvsp[-7].string), (yyvsp[-5].column_list), (yyvsp[-1].column_list), FALSE );
            if( !insert )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  insert );
        }
#line 1484 "dlls/msi/sql.tab.c"
    break;

  case 11: /* oneinsert: TK_INSERT TK_INTO table TK_LP collist TK_RP TK_VALUES TK_LP constlist TK_RP TK_TEMPORARY  */
#line 144 "dlls/msi/sql.y"
        {
            SQL_input *sql = (SQL_input*) info;
            MSIVIEW *insert = NULL;

            INSERT_CreateView( sql->db, &insert, (yyvsp[-8].string), (yyvsp[-6].column_list), (yyvsp[-2].column_list), TRUE );
            if( !insert )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  insert );
        }
#line 1499 "dlls/msi/sql.tab.c"
    break;

  case 12: /* onecreate: TK_CREATE TK_TABLE table TK_LP table_def TK_RP  */
#line 158 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *create = NULL;
            UINT r;

            if( !(yyvsp[-1].column_list) )
                YYABORT;
            r = CREATE_CreateView( sql->db, &create, (yyvsp[-3].string), (yyvsp[-1].column_list), FALSE );
            if( !create )
            {
                sql->r = r;
                YYABORT;
            }

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  create );
        }
#line 1520 "dlls/msi/sql.tab.c"
    break;

  case 13: /* onecreate: TK_CREATE TK_TABLE table TK_LP table_def TK_RP TK_HOLD  */
#line 175 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *create = NULL;

            if( !(yyvsp[-2].column_list) )
                YYABORT;
            CREATE_CreateView( sql->db, &create, (yyvsp[-4].string), (yyvsp[-2].column_list), TRUE );
            if( !create )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  create );
        }
#line 1537 "dlls/msi/sql.tab.c"
    break;

  case 14: /* oneupdate: TK_UPDATE table TK_SET update_assign_list TK_WHERE expr  */
#line 191 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *update = NULL;

            UPDATE_CreateView( sql->db, &update, (yyvsp[-4].string), (yyvsp[-2].column_list), (yyvsp[0].expr) );
            if( !update )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  update );
        }
#line 1552 "dlls/msi/sql.tab.c"
    break;

  case 15: /* oneupdate: TK_UPDATE table TK_SET update_assign_list  */
#line 202 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *update = NULL;

            UPDATE_CreateView( sql->db, &update, (yyvsp[-2].string), (yyvsp[0].column_list), NULL );
            if( !update )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query),  update );
        }
#line 1567 "dlls/msi/sql.tab.c"
    break;

  case 16: /* onedelete: TK_DELETE from  */
#line 216 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *delete = NULL;

            DELETE_CreateView( sql->db, &delete, (yyvsp[0].query) );
            if( !delete )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), delete );
        }
#line 1582 "dlls/msi/sql.tab.c"
    break;

  case 17: /* onealter: TK_ALTER TK_TABLE table alterop  */
#line 230 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW *alter = NULL;

            ALTER_CreateView( sql->db, &alter, (yyvsp[-1].string), NULL, (yyvsp[0].integer) );
            if( !alter )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), alter );
        }
#line 1597 "dlls/msi/sql.tab.c"
    break;

  case 18: /* onealter: TK_ALTER TK_TABLE table TK_ADD column_and_type  */
#line 241 "dlls/msi/sql.y"
        {
            SQL_input *sql = (SQL_input *)info;
            MSIVIEW *alter = NULL;

            ALTER_CreateView( sql->db, &alter, (yyvsp[-2].string), (yyvsp[0].column_list), 0 );
            if (!alter)
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), alter );
        }
#line 1612 "dlls/msi/sql.tab.c"
    break;

  case 19: /* onealter: TK_ALTER TK_TABLE table TK_ADD column_and_type TK_HOLD  */
#line 252 "dlls/msi/sql.y"
        {
            SQL_input *sql = (SQL_input *)info;
            MSIVIEW *alter = NULL;

            ALTER_CreateView( sql->db, &alter, (yyvsp[-3].string), (yyvsp[-1].column_list), 1 );
            if (!alter)
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), alter );
        }
#line 1627 "dlls/msi/sql.tab.c"
    break;

  case 20: /* alterop: TK_HOLD  */
#line 266 "dlls/msi/sql.y"
        {
            (yyval.integer) = 1;
        }
#line 1635 "dlls/msi/sql.tab.c"
    break;

  case 21: /* alterop: TK_FREE  */
#line 270 "dlls/msi/sql.y"
        {
            (yyval.integer) = -1;
        }
#line 1643 "dlls/msi/sql.tab.c"
    break;

  case 22: /* onedrop: TK_DROP TK_TABLE table  */
#line 277 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* drop = NULL;
            UINT r;

            r = DROP_CreateView( sql->db, &drop, (yyvsp[0].string) );
            if( r != ERROR_SUCCESS || !(yyval.query) )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), drop );
        }
#line 1659 "dlls/msi/sql.tab.c"
    break;

  case 23: /* table_def: column_def TK_PRIMARY TK_KEY collist  */
#line 292 "dlls/msi/sql.y"
        {
            if( SQL_MarkPrimaryKeys( &(yyvsp[-3].column_list), (yyvsp[0].column_list) ) )
                (yyval.column_list) = (yyvsp[-3].column_list);
            else
                (yyval.column_list) = NULL;
        }
#line 1670 "dlls/msi/sql.tab.c"
    break;

  case 24: /* column_def: column_def TK_COMMA column_and_type  */
#line 302 "dlls/msi/sql.y"
        {
            column_info *ci;

            for( ci = (yyvsp[-2].column_list); ci->next; ci = ci->next )
                ;

            ci->next = (yyvsp[0].column_list);
            (yyval.column_list) = (yyvsp[-2].column_list);
        }
#line 1684 "dlls/msi/sql.tab.c"
    break;

  case 25: /* column_def: column_and_type  */
#line 312 "dlls/msi/sql.y"
        {
            (yyval.column_list) = (yyvsp[0].column_list);
        }
#line 1692 "dlls/msi/sql.tab.c"
    break;

  case 26: /* column_and_type: column column_type  */
#line 319 "dlls/msi/sql.y"
        {
            (yyval.column_list) = (yyvsp[-1].column_list);
            (yyval.column_list)->type = ((yyvsp[0].column_type) | MSITYPE_VALID);
        }
#line 1701 "dlls/msi/sql.tab.c"
    break;

  case 27: /* column_type: data_type_l  */
#line 327 "dlls/msi/sql.y"
        {
            (yyval.column_type) = (yyvsp[0].column_type);
        }
#line 1709 "dlls/msi/sql.tab.c"
    break;

  case 28: /* column_type: data_type_l TK_LOCALIZABLE  */
#line 331 "dlls/msi/sql.y"
        {
            (yyval.column_type) = (yyvsp[-1].column_type) | MSITYPE_LOCALIZABLE;
        }
#line 1717 "dlls/msi/sql.tab.c"
    break;

  case 29: /* column_type: data_type_l TK_TEMPORARY  */
#line 335 "dlls/msi/sql.y"
        {
            (yyval.column_type) = (yyvsp[-1].column_type) | MSITYPE_TEMPORARY;
        }
#line 1725 "dlls/msi/sql.tab.c"
    break;

  case 30: /* data_type_l: data_type  */
#line 342 "dlls/msi/sql.y"
        {
            (yyval.column_type) |= MSITYPE_NULLABLE;
        }
#line 1733 "dlls/msi/sql.tab.c"
    break;

  case 31: /* data_type_l: data_type TK_NOT TK_NULL  */
#line 346 "dlls/msi/sql.y"
        {
            (yyval.column_type) = (yyvsp[-2].column_type);
        }
#line 1741 "dlls/msi/sql.tab.c"
    break;

  case 32: /* data_type: TK_CHAR  */
#line 353 "dlls/msi/sql.y"
        {
            (yyval.column_type) = MSITYPE_STRING | 0x400;
        }
#line 1749 "dlls/msi/sql.tab.c"
    break;

  case 33: /* data_type: TK_CHAR TK_LP data_count TK_RP  */
#line 357 "dlls/msi/sql.y"
        {
            (yyval.column_type) = MSITYPE_STRING | 0x400 | (yyvsp[-1].column_type);
        }
#line 1757 "dlls/msi/sql.tab.c"
    break;

  case 34: /* data_type: TK_LONGCHAR  */
#line 361 "dlls/msi/sql.y"
        {
            (yyval.column_type) = MSITYPE_STRING | 0x400;
        }
#line 1765 "dlls/msi/sql.tab.c"
    break;

  case 35: /* data_type: TK_SHORT  */
#line 365 "dlls/msi/sql.y"
        {
            (yyval.column_type) = 2 | 0x400;
        }
#line 1773 "dlls/msi/sql.tab.c"
    break;

  case 36: /* data_type: TK_INT  */
#line 369 "dlls/msi/sql.y"
        {
            (yyval.column_type) = 2 | 0x400;
        }
#line 1781 "dlls/msi/sql.tab.c"
    break;

  case 37: /* data_type: TK_LONG  */
#line 373 "dlls/msi/sql.y"
        {
            (yyval.column_type) = 4;
        }
#line 1789 "dlls/msi/sql.tab.c"
    break;

  case 38: /* data_type: TK_OBJECT  */
#line 377 "dlls/msi/sql.y"
        {
            (yyval.column_type) = MSITYPE_STRING | MSITYPE_VALID;
        }
#line 1797 "dlls/msi/sql.tab.c"
    break;

  case 39: /* data_count: number  */
#line 384 "dlls/msi/sql.y"
        {
            if( ( (yyvsp[0].integer) > 255 ) || ( (yyvsp[0].integer) < 0 ) )
                YYABORT;
            (yyval.column_type) = (yyvsp[0].integer);
        }
#line 1807 "dlls/msi/sql.tab.c"
    break;

  case 40: /* oneselect: TK_SELECT selectfrom  */
#line 393 "dlls/msi/sql.y"
        {
            (yyval.query) = (yyvsp[0].query);
        }
#line 1815 "dlls/msi/sql.tab.c"
    break;

  case 41: /* oneselect: TK_SELECT TK_DISTINCT selectfrom  */
#line 397 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* distinct = NULL;
            UINT r;

            r = DISTINCT_CreateView( sql->db, &distinct, (yyvsp[0].query) );
            if (r != ERROR_SUCCESS)
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), distinct );
        }
#line 1831 "dlls/msi/sql.tab.c"
    break;

  case 42: /* selectfrom: selcollist from  */
#line 412 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* select = NULL;
            UINT r;

            if( (yyvsp[-1].column_list) )
            {
                r = SELECT_CreateView( sql->db, &select, (yyvsp[0].query), (yyvsp[-1].column_list) );
                if (r != ERROR_SUCCESS)
                    YYABORT;

                PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), select );
            }
            else
                (yyval.query) = (yyvsp[0].query);
        }
#line 1852 "dlls/msi/sql.tab.c"
    break;

  case 44: /* selcollist: selcolumn TK_COMMA selcollist  */
#line 433 "dlls/msi/sql.y"
        {
            (yyvsp[-2].column_list)->next = (yyvsp[0].column_list);
        }
#line 1860 "dlls/msi/sql.tab.c"
    break;

  case 45: /* selcollist: TK_STAR  */
#line 437 "dlls/msi/sql.y"
        {
            (yyval.column_list) = NULL;
        }
#line 1868 "dlls/msi/sql.tab.c"
    break;

  case 47: /* collist: column TK_COMMA collist  */
#line 445 "dlls/msi/sql.y"
        {
            (yyvsp[-2].column_list)->next = (yyvsp[0].column_list);
        }
#line 1876 "dlls/msi/sql.tab.c"
    break;

  case 48: /* collist: TK_STAR  */
#line 449 "dlls/msi/sql.y"
        {
            (yyval.column_list) = NULL;
        }
#line 1884 "dlls/msi/sql.tab.c"
    break;

  case 49: /* from: TK_FROM table  */
#line 456 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* table = NULL;
            UINT r;

            r = TABLE_CreateView( sql->db, (yyvsp[0].string), &table );
            if( r != ERROR_SUCCESS || !(yyval.query) )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), table );
        }
#line 1900 "dlls/msi/sql.tab.c"
    break;

  case 50: /* from: unorderdfrom TK_ORDER TK_BY collist  */
#line 468 "dlls/msi/sql.y"
        {
            UINT r;

            if( (yyvsp[0].column_list) )
            {
                r = (yyvsp[-3].query)->ops->sort( (yyvsp[-3].query), (yyvsp[0].column_list) );
                if ( r != ERROR_SUCCESS)
                    YYABORT;
            }

            (yyval.query) = (yyvsp[-3].query);
        }
#line 1917 "dlls/msi/sql.tab.c"
    break;

  case 52: /* unorderdfrom: TK_FROM tablelist  */
#line 485 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* where = NULL;
            UINT r;

            r = WHERE_CreateView( sql->db, &where, (yyvsp[0].string), NULL );
            if( r != ERROR_SUCCESS )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), where );
        }
#line 1933 "dlls/msi/sql.tab.c"
    break;

  case 53: /* unorderdfrom: TK_FROM tablelist TK_WHERE expr  */
#line 497 "dlls/msi/sql.y"
        {
            SQL_input* sql = (SQL_input*) info;
            MSIVIEW* where = NULL;
            UINT r;

            r = WHERE_CreateView( sql->db, &where, (yyvsp[-2].string), (yyvsp[0].expr) );
            if( r != ERROR_SUCCESS )
                YYABORT;

            PARSER_BUBBLE_UP_VIEW( sql, (yyval.query), where );
        }
#line 1949 "dlls/msi/sql.tab.c"
    break;

  case 54: /* tablelist: table  */
#line 512 "dlls/msi/sql.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 1957 "dlls/msi/sql.tab.c"
    break;

  case 55: /* tablelist: table TK_COMMA tablelist  */
#line 516 "dlls/msi/sql.y"
        {
            (yyval.string) = parser_add_table( info, (yyvsp[0].string), (yyvsp[-2].string) );
            if (!(yyval.string))
                YYABORT;
        }
#line 1967 "dlls/msi/sql.tab.c"
    break;

  case 56: /* expr: TK_LP expr TK_RP  */
#line 525 "dlls/msi/sql.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);
            if( !(yyval.expr) )
                YYABORT;
        }
#line 1977 "dlls/msi/sql.tab.c"
    break;

  case 57: /* expr: expr TK_AND expr  */
#line 531 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_AND, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 1987 "dlls/msi/sql.tab.c"
    break;

  case 58: /* expr: expr TK_OR expr  */
#line 537 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_OR, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 1997 "dlls/msi/sql.tab.c"
    break;

  case 59: /* expr: column_val TK_EQ val  */
#line 543 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_EQ, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2007 "dlls/msi/sql.tab.c"
    break;

  case 60: /* expr: column_val TK_GT val  */
#line 549 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_GT, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2017 "dlls/msi/sql.tab.c"
    break;

  case 61: /* expr: column_val TK_LT val  */
#line 555 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_LT, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2027 "dlls/msi/sql.tab.c"
    break;

  case 62: /* expr: column_val TK_LE val  */
#line 561 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_LE, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2037 "dlls/msi/sql.tab.c"
    break;

  case 63: /* expr: column_val TK_GE val  */
#line 567 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_GE, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2047 "dlls/msi/sql.tab.c"
    break;

  case 64: /* expr: column_val TK_NE val  */
#line 573 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_complex( info, (yyvsp[-2].expr), OP_NE, (yyvsp[0].expr) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2057 "dlls/msi/sql.tab.c"
    break;

  case 65: /* expr: column_val TK_IS TK_NULL  */
#line 579 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_unary( info, (yyvsp[-2].expr), OP_ISNULL );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2067 "dlls/msi/sql.tab.c"
    break;

  case 66: /* expr: column_val TK_IS TK_NOT TK_NULL  */
#line 585 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_unary( info, (yyvsp[-3].expr), OP_NOTNULL );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2077 "dlls/msi/sql.tab.c"
    break;

  case 69: /* constlist: const_val  */
#line 599 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, NULL, NULL );
            if( !(yyval.column_list) )
                YYABORT;
            (yyval.column_list)->val = (yyvsp[0].expr);
        }
#line 2088 "dlls/msi/sql.tab.c"
    break;

  case 70: /* constlist: const_val TK_COMMA constlist  */
#line 606 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, NULL, NULL );
            if( !(yyval.column_list) )
                YYABORT;
            (yyval.column_list)->val = (yyvsp[-2].expr);
            (yyval.column_list)->next = (yyvsp[0].column_list);
        }
#line 2100 "dlls/msi/sql.tab.c"
    break;

  case 72: /* update_assign_list: column_assignment TK_COMMA update_assign_list  */
#line 618 "dlls/msi/sql.y"
        {
            (yyval.column_list) = (yyvsp[-2].column_list);
            (yyval.column_list)->next = (yyvsp[0].column_list);
        }
#line 2109 "dlls/msi/sql.tab.c"
    break;

  case 73: /* column_assignment: column TK_EQ const_val  */
#line 626 "dlls/msi/sql.y"
        {
            (yyval.column_list) = (yyvsp[-2].column_list);
            (yyval.column_list)->val = (yyvsp[0].expr);
        }
#line 2118 "dlls/msi/sql.tab.c"
    break;

  case 74: /* const_val: number  */
#line 634 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_ival( info, (yyvsp[0].integer) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2128 "dlls/msi/sql.tab.c"
    break;

  case 75: /* const_val: TK_MINUS number  */
#line 640 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_ival( info, -(yyvsp[0].integer) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2138 "dlls/msi/sql.tab.c"
    break;

  case 76: /* const_val: TK_STRING  */
#line 646 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_sval( info, &(yyvsp[0].str) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2148 "dlls/msi/sql.tab.c"
    break;

  case 77: /* const_val: TK_WILDCARD  */
#line 652 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_wildcard( info );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2158 "dlls/msi/sql.tab.c"
    break;

  case 78: /* const_val: TK_NULL  */
#line 658 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_sval( info, NULL );
            if ( !(yyval.expr) )
                YYABORT;
        }
#line 2168 "dlls/msi/sql.tab.c"
    break;

  case 79: /* column_val: column  */
#line 667 "dlls/msi/sql.y"
        {
            (yyval.expr) = EXPR_column( info, (yyvsp[0].column_list) );
            if( !(yyval.expr) )
                YYABORT;
        }
#line 2178 "dlls/msi/sql.tab.c"
    break;

  case 80: /* column: table TK_DOT id  */
#line 676 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, (yyvsp[-2].string), (yyvsp[0].string) );
            if( !(yyval.column_list) )
                YYABORT;
        }
#line 2188 "dlls/msi/sql.tab.c"
    break;

  case 81: /* column: id  */
#line 682 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, NULL, (yyvsp[0].string) );
            if( !(yyval.column_list) )
                YYABORT;
        }
#line 2198 "dlls/msi/sql.tab.c"
    break;

  case 82: /* selcolumn: table TK_DOT id  */
#line 691 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, (yyvsp[-2].string), (yyvsp[0].string) );
            if( !(yyval.column_list) )
                YYABORT;
        }
#line 2208 "dlls/msi/sql.tab.c"
    break;

  case 83: /* selcolumn: id  */
#line 697 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, NULL, (yyvsp[0].string) );
            if( !(yyval.column_list) )
                YYABORT;
        }
#line 2218 "dlls/msi/sql.tab.c"
    break;

  case 84: /* selcolumn: string  */
#line 703 "dlls/msi/sql.y"
        {
            (yyval.column_list) = parser_alloc_column( info, NULL, (yyvsp[0].string) );
            if( !(yyval.column_list) )
                YYABORT;
        }
#line 2228 "dlls/msi/sql.tab.c"
    break;

  case 85: /* table: id  */
#line 712 "dlls/msi/sql.y"
        {
            (yyval.string) = (yyvsp[0].string);
        }
#line 2236 "dlls/msi/sql.tab.c"
    break;

  case 86: /* id: TK_ID  */
#line 719 "dlls/msi/sql.y"
        {
            if ( SQL_getstring( info, &(yyvsp[0].str), &(yyval.string) ) != ERROR_SUCCESS || !(yyval.string) )
                YYABORT;
        }
#line 2245 "dlls/msi/sql.tab.c"
    break;

  case 87: /* string: TK_STRING  */
#line 727 "dlls/msi/sql.y"
        {
            if ( SQL_getstring( info, &(yyvsp[0].str), &(yyval.string) ) != ERROR_SUCCESS || !(yyval.string) )
                YYABORT;
        }
#line 2254 "dlls/msi/sql.tab.c"
    break;

  case 88: /* number: TK_INTEGER  */
#line 735 "dlls/msi/sql.y"
        {
            (yyval.integer) = SQL_getint( info );
        }
#line 2262 "dlls/msi/sql.tab.c"
    break;


#line 2266 "dlls/msi/sql.tab.c"

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
  yytoken = yychar == SQL_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= SQL_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == SQL_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, info);
          yychar = SQL_EMPTY;
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
  if (yychar != SQL_EMPTY)
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

#line 740 "dlls/msi/sql.y"


static LPWSTR parser_add_table( void *info, LPCWSTR list, LPCWSTR table )
{
    DWORD len = lstrlenW( list ) + lstrlenW( table ) + 2;
    LPWSTR ret;

    ret = parser_alloc( info, len * sizeof(WCHAR) );
    if( ret )
    {
        lstrcpyW( ret, list );
        lstrcatW( ret, L" " );
        lstrcatW( ret, table );
    }
    return ret;
}

static void *parser_alloc( void *info, unsigned int sz )
{
    SQL_input* sql = (SQL_input*) info;
    struct list *mem;

    mem = malloc( sizeof (struct list) + sz );
    list_add_tail( sql->mem, mem );
    return &mem[1];
}

static column_info *parser_alloc_column( void *info, LPCWSTR table, LPCWSTR column )
{
    column_info *col;

    col = parser_alloc( info, sizeof (*col) );
    if( col )
    {
        col->table = table;
        col->column = column;
        col->val = NULL;
        col->type = 0;
        col->next = NULL;
    }

    return col;
}

static int sql_lex( void *SQL_lval, SQL_input *sql )
{
    int token, skip;
    struct sql_str * str = SQL_lval;

    do
    {
        sql->n += sql->len;
        if( ! sql->command[sql->n] )
            return 0;  /* end of input */

        /* TRACE("string : %s\n", debugstr_w(&sql->command[sql->n])); */
        sql->len = sqliteGetToken( &sql->command[sql->n], &token, &skip );
        if( sql->len==0 )
            break;
        str->data = &sql->command[sql->n];
        str->len = sql->len;
        sql->n += skip;
    }
    while( token == TK_SPACE );

    /* TRACE("token : %d (%s)\n", token, debugstr_wn(&sql->command[sql->n], sql->len)); */

    return token;
}

UINT SQL_getstring( void *info, const struct sql_str *strdata, LPWSTR *str )
{
    LPCWSTR p = strdata->data;
    UINT len = strdata->len;

    /* match quotes */
    if( ( (p[0]=='`') && (p[len-1]!='`') ) ||
        ( (p[0]=='\'') && (p[len-1]!='\'') ) )
        return ERROR_FUNCTION_FAILED;

    /* if there are quotes, remove them */
    if( ( (p[0]=='`') && (p[len-1]=='`') ) ||
        ( (p[0]=='\'') && (p[len-1]=='\'') ) )
    {
        p++;
        len -= 2;
    }
    *str = parser_alloc( info, (len + 1)*sizeof(WCHAR) );
    if( !*str )
        return ERROR_OUTOFMEMORY;
    memcpy( *str, p, len*sizeof(WCHAR) );
    (*str)[len]=0;

    return ERROR_SUCCESS;
}

INT SQL_getint( void *info )
{
    SQL_input* sql = (SQL_input*) info;
    LPCWSTR p = &sql->command[sql->n];
    INT i, r = 0;

    for( i=0; i<sql->len; i++ )
    {
        if( '0' > p[i] || '9' < p[i] )
        {
            ERR("should only be numbers here!\n");
            break;
        }
        r = (p[i]-'0') + r*10;
    }

    return r;
}

static int sql_error( SQL_input *info, const char *str )
{
    return 0;
}

static struct expr * EXPR_wildcard( void *info )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_WILDCARD;
    }
    return e;
}

static struct expr * EXPR_complex( void *info, struct expr *l, UINT op, struct expr *r )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_COMPLEX;
        e->u.expr.left = l;
        e->u.expr.op = op;
        e->u.expr.right = r;
    }
    return e;
}

static struct expr * EXPR_unary( void *info, struct expr *l, UINT op )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_UNARY;
        e->u.expr.left = l;
        e->u.expr.op = op;
        e->u.expr.right = NULL;
    }
    return e;
}

static struct expr * EXPR_column( void *info, const column_info *column )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_COLUMN;
        e->u.column.unparsed.column = column->column;
        e->u.column.unparsed.table = column->table;
    }
    return e;
}

static struct expr * EXPR_ival( void *info, int val )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_IVAL;
        e->u.ival = val;
    }
    return e;
}

static struct expr * EXPR_sval( void *info, const struct sql_str *str )
{
    struct expr *e = parser_alloc( info, sizeof *e );
    if( e )
    {
        e->type = EXPR_SVAL;
        if( !str) e->u.sval = NULL;
        else if( SQL_getstring( info, str, (LPWSTR *)&e->u.sval ) != ERROR_SUCCESS )
            return NULL; /* e will be freed by query destructor */
    }
    return e;
}

static void swap_columns( column_info **cols, column_info *A, int idx )
{
    column_info *preA = NULL, *preB = NULL, *B, *ptr;
    int i = 0;

    B = NULL;
    ptr = *cols;
    while( ptr )
    {
        if( i++ == idx )
            B = ptr;
        else if( !B )
            preB = ptr;

        if( ptr->next == A )
            preA = ptr;

        ptr = ptr->next;
    }

    if( preB ) preB->next = A;
    if( preA ) preA->next = B;
    ptr = A->next;
    A->next = B->next;
    B->next = ptr;
    if( idx == 0 )
      *cols = A;
}

static BOOL SQL_MarkPrimaryKeys( column_info **cols,
                                 column_info *keys )
{
    column_info *k;
    BOOL found = TRUE;
    int count;

    for( k = keys, count = 0; k && found; k = k->next, count++ )
    {
        column_info *c;
        int idx;

        found = FALSE;
        for( c = *cols, idx = 0; c && !found; c = c->next, idx++ )
        {
            if( wcscmp( k->column, c->column ) )
                continue;
            c->type |= MSITYPE_KEY;
            found = TRUE;
            if (idx != count)
                swap_columns( cols, c, count );
        }
    }

    return found;
}

UINT MSI_ParseSQL( MSIDATABASE *db, LPCWSTR command, MSIVIEW **phview,
                   struct list *mem )
{
    SQL_input sql;
    int r;

    *phview = NULL;

    sql.db = db;
    sql.command = command;
    sql.n = 0;
    sql.len = 0;
    sql.r = ERROR_BAD_QUERY_SYNTAX;
    sql.view = phview;
    sql.mem = mem;

    r = sql_parse(&sql);

    TRACE("Parse returned %d\n", r);
    if( r )
    {
        if (*sql.view)
        {
            (*sql.view)->ops->delete(*sql.view);
            *sql.view = NULL;
        }
        return sql.r;
    }

    return ERROR_SUCCESS;
}
