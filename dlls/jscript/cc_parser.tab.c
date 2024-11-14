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
#define YYSTYPE         CC_PARSER_STYPE
/* Substitute the variable and function names.  */
#define yyparse         cc_parser_parse
#define yylex           cc_parser_lex
#define yyerror         cc_parser_error
#define yydebug         cc_parser_debug
#define yynerrs         cc_parser_nerrs

/* First part of user prologue.  */
#line 19 "dlls/jscript/cc_parser.y"


#include "jscript.h"
#include "engine.h"
#include "parser.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(jscript);


#line 89 "dlls/jscript/cc_parser.tab.c"

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
#ifndef CC_PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CC_PARSER_DEBUG 1
#  else
#   define CC_PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CC_PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CC_PARSER_DEBUG */
#if CC_PARSER_DEBUG
extern int cc_parser_debug;
#endif

/* Token kinds.  */
#ifndef CC_PARSER_TOKENTYPE
# define CC_PARSER_TOKENTYPE
  enum cc_parser_tokentype
  {
    CC_PARSER_EMPTY = -2,
    CC_PARSER_EOF = 0,             /* "end of file"  */
    CC_PARSER_error = 256,         /* error  */
    CC_PARSER_UNDEF = 257,         /* "invalid token"  */
    tEQ = 258,                     /* tEQ  */
    tEQEQ = 259,                   /* tEQEQ  */
    tNEQ = 260,                    /* tNEQ  */
    tNEQEQ = 261,                  /* tNEQEQ  */
    tLSHIFT = 262,                 /* tLSHIFT  */
    tRSHIFT = 263,                 /* tRSHIFT  */
    tRRSHIFT = 264,                /* tRRSHIFT  */
    tOR = 265,                     /* tOR  */
    tAND = 266,                    /* tAND  */
    tLEQ = 267,                    /* tLEQ  */
    tGEQ = 268,                    /* tGEQ  */
    tCCValue = 269                 /* tCCValue  */
  };
  typedef enum cc_parser_tokentype cc_parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined CC_PARSER_STYPE && ! defined CC_PARSER_STYPE_IS_DECLARED
union CC_PARSER_STYPE
{
#line 37 "dlls/jscript/cc_parser.y"

    ccval_t ccval;

#line 162 "dlls/jscript/cc_parser.tab.c"

};
typedef union CC_PARSER_STYPE CC_PARSER_STYPE;
# define CC_PARSER_STYPE_IS_TRIVIAL 1
# define CC_PARSER_STYPE_IS_DECLARED 1
#endif




int cc_parser_parse (parser_ctx_t *ctx);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tEQ = 3,                        /* tEQ  */
  YYSYMBOL_tEQEQ = 4,                      /* tEQEQ  */
  YYSYMBOL_tNEQ = 5,                       /* tNEQ  */
  YYSYMBOL_tNEQEQ = 6,                     /* tNEQEQ  */
  YYSYMBOL_tLSHIFT = 7,                    /* tLSHIFT  */
  YYSYMBOL_tRSHIFT = 8,                    /* tRSHIFT  */
  YYSYMBOL_tRRSHIFT = 9,                   /* tRRSHIFT  */
  YYSYMBOL_tOR = 10,                       /* tOR  */
  YYSYMBOL_tAND = 11,                      /* tAND  */
  YYSYMBOL_tLEQ = 12,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 13,                      /* tGEQ  */
  YYSYMBOL_tCCValue = 14,                  /* tCCValue  */
  YYSYMBOL_15_ = 15,                       /* '('  */
  YYSYMBOL_16_ = 16,                       /* ')'  */
  YYSYMBOL_17_ = 17,                       /* '!'  */
  YYSYMBOL_18_ = 18,                       /* '~'  */
  YYSYMBOL_19_ = 19,                       /* '+'  */
  YYSYMBOL_20_ = 20,                       /* '-'  */
  YYSYMBOL_21_ = 21,                       /* '|'  */
  YYSYMBOL_22_ = 22,                       /* '^'  */
  YYSYMBOL_23_ = 23,                       /* '&'  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_CCExpr = 30,                    /* CCExpr  */
  YYSYMBOL_CCUnaryExpression = 31,         /* CCUnaryExpression  */
  YYSYMBOL_CCLogicalORExpression = 32,     /* CCLogicalORExpression  */
  YYSYMBOL_CCLogicalANDExpression = 33,    /* CCLogicalANDExpression  */
  YYSYMBOL_CCBitwiseORExpression = 34,     /* CCBitwiseORExpression  */
  YYSYMBOL_CCBitwiseXORExpression = 35,    /* CCBitwiseXORExpression  */
  YYSYMBOL_CCBitwiseANDExpression = 36,    /* CCBitwiseANDExpression  */
  YYSYMBOL_CCEqualityExpression = 37,      /* CCEqualityExpression  */
  YYSYMBOL_CCRelationalExpression = 38,    /* CCRelationalExpression  */
  YYSYMBOL_CCShiftExpression = 39,         /* CCShiftExpression  */
  YYSYMBOL_CCAdditiveExpression = 40,      /* CCAdditiveExpression  */
  YYSYMBOL_CCMultiplicativeExpression = 41 /* CCMultiplicativeExpression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 48 "dlls/jscript/cc_parser.y"


static int cc_parser_error(parser_ctx_t *ctx, const char *str)
{
    if(SUCCEEDED(ctx->hres)) {
        WARN("%s\n", str);
        ctx->hres = JS_E_SYNTAX;
    }

    return 0;
}

static int cc_parser_lex(void *lval, parser_ctx_t *ctx)
{
    int r;

    r = try_parse_ccval(ctx, lval);
    if(r)
        return r > 0 ? tCCValue : -1;

    switch(*ctx->ptr) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '~':
    case '%':
    case '^':
        return *ctx->ptr++;
    case '=':
         if(*++ctx->ptr == '=') {
             if(*++ctx->ptr == '=') {
                 ctx->ptr++;
                 return tEQEQ;
             }
             return tEQ;
         }
         break;
    case '!':
        if(*++ctx->ptr == '=') {
            if(*++ctx->ptr == '=') {
                ctx->ptr++;
                return tNEQEQ;
            }
            return tNEQ;
        }
        return '!';
    case '<':
        switch(*++ctx->ptr) {
        case '<':
            ctx->ptr++;
            return tLSHIFT;
        case '=':
            ctx->ptr++;
            return tLEQ;
        default:
            return '<';
        }
    case '>':
        switch(*++ctx->ptr) {
        case '>':
            if(*++ctx->ptr == '>') {
                ctx->ptr++;
                return tRRSHIFT;
            }
            return tRSHIFT;
        case '=':
            ctx->ptr++;
            return tGEQ;
        default:
            return '>';
        }
    case '|':
        if(*++ctx->ptr == '|') {
            ctx->ptr++;
            return tOR;
        }
        return '|';
    case '&':
        if(*++ctx->ptr == '&') {
            ctx->ptr++;
            return tAND;
        }
        return '&';
    }

    WARN("Failed to interpret %s\n", debugstr_w(ctx->ptr));
    return -1;
}


#line 322 "dlls/jscript/cc_parser.tab.c"


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
         || (defined CC_PARSER_STYPE_IS_TRIVIAL && CC_PARSER_STYPE_IS_TRIVIAL)))

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
#define YYLAST   57

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  69

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   269


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
       2,     2,     2,    17,     2,     2,     2,    28,    23,     2,
      15,    16,    26,    19,     2,    20,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,     2,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,    18,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if CC_PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   147,   147,   150,   151,   152,   153,   154,   155,   158,
     159,   163,   164,   168,   169,   173,   174,   178,   179,   183,
     184,   186,   188,   190,   194,   195,   197,   199,   201,   205,
     206,   208,   210,   214,   215,   217,   221,   222,   224,   226
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if CC_PARSER_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tEQ", "tEQEQ", "tNEQ",
  "tNEQEQ", "tLSHIFT", "tRSHIFT", "tRRSHIFT", "tOR", "tAND", "tLEQ",
  "tGEQ", "tCCValue", "'('", "')'", "'!'", "'~'", "'+'", "'-'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'*'", "'/'", "'%'", "$accept", "CCExpr",
  "CCUnaryExpression", "CCLogicalORExpression", "CCLogicalANDExpression",
  "CCBitwiseORExpression", "CCBitwiseXORExpression",
  "CCBitwiseANDExpression", "CCEqualityExpression",
  "CCRelationalExpression", "CCShiftExpression", "CCAdditiveExpression",
  "CCMultiplicativeExpression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       3,   -17,     3,     3,     3,     3,     3,    16,   -17,   -17,
      -1,   -17,   -13,    32,    -4,    21,   -11,    30,    31,   -16,
     -17,   -17,   -17,   -17,   -17,     3,   -17,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   -17,    32,     9,
       9,   -13,    21,   -11,   -11,   -11,   -11,    30,    30,    30,
      30,    31,    31,    31,   -16,   -16,   -17,   -17,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     0,     0,     0,     0,     2,    36,
       0,     9,    11,    13,    15,    17,    19,    24,    29,    33,
       5,     6,     7,     8,     1,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    14,    15,
      16,    12,    18,    20,    22,    21,    23,    26,    28,    25,
      27,    30,    31,    32,    34,    35,    37,    38,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,     0,   -17,    18,    26,    29,    13,    27,    -3,
      -2,     8,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    35,    36,    20,    21,    22,    23,    29,    27,    25,
      44,    45,    46,    37,    38,    26,    24,     1,     2,    30,
       3,     4,     5,     6,    31,    32,    33,    34,    53,    54,
      55,    56,    30,    57,    58,    59,    60,    39,    40,    41,
      49,    50,    49,    47,    66,    67,    68,    61,    62,    63,
      42,    43,    64,    65,    28,    51,    48,    52
};

static const yytype_int8 yycheck[] =
{
       0,    12,    13,     3,     4,     5,     6,    11,    21,    10,
      26,    27,    28,    24,    25,    16,     0,    14,    15,    23,
      17,    18,    19,    20,     3,     4,     5,     6,    31,    32,
      33,    34,    23,    35,    36,    37,    38,     7,     8,     9,
      27,    28,    29,    25,    44,    45,    46,    39,    40,    41,
      19,    20,    42,    43,    22,    29,    27,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    17,    18,    19,    20,    30,    31,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      31,    31,    31,    31,     0,    10,    16,    21,    22,    11,
      23,     3,     4,     5,     6,    12,    13,    24,    25,     7,
       8,     9,    19,    20,    26,    27,    28,    33,    35,    36,
      36,    34,    37,    38,    38,    38,    38,    39,    39,    39,
      39,    40,    40,    40,    41,    41,    31,    31,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    31,    31,    31,    31,    32,
      32,    33,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    37,    37,    38,    38,    38,    38,    38,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    41,    41
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     2,     2,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = CC_PARSER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == CC_PARSER_EMPTY)                                        \
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
   Use CC_PARSER_error or CC_PARSER_UNDEF. */
#define YYERRCODE CC_PARSER_UNDEF


/* Enable debugging if requested.  */
#if CC_PARSER_DEBUG

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
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, parser_ctx_t *ctx)
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, parser_ctx_t *ctx)
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
                 int yyrule, parser_ctx_t *ctx)
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
#else /* !CC_PARSER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !CC_PARSER_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, parser_ctx_t *ctx)
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
yyparse (parser_ctx_t *ctx)
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

  yychar = CC_PARSER_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == CC_PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, ctx);
    }

  if (yychar <= CC_PARSER_EOF)
    {
      yychar = CC_PARSER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == CC_PARSER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = CC_PARSER_UNDEF;
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
  yychar = CC_PARSER_EMPTY;
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
  case 2: /* CCExpr: CCUnaryExpression  */
#line 147 "dlls/jscript/cc_parser.y"
                        { ctx->ccval = (yyvsp[0].ccval); YYACCEPT; }
#line 1318 "dlls/jscript/cc_parser.tab.c"
    break;

  case 3: /* CCUnaryExpression: tCCValue  */
#line 150 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1324 "dlls/jscript/cc_parser.tab.c"
    break;

  case 4: /* CCUnaryExpression: '(' CCLogicalORExpression ')'  */
#line 151 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[-1].ccval); }
#line 1330 "dlls/jscript/cc_parser.tab.c"
    break;

  case 5: /* CCUnaryExpression: '!' CCUnaryExpression  */
#line 152 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(!get_ccbool((yyvsp[0].ccval))); }
#line 1336 "dlls/jscript/cc_parser.tab.c"
    break;

  case 6: /* CCUnaryExpression: '~' CCUnaryExpression  */
#line 153 "dlls/jscript/cc_parser.y"
                                    { FIXME("'~' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1342 "dlls/jscript/cc_parser.tab.c"
    break;

  case 7: /* CCUnaryExpression: '+' CCUnaryExpression  */
#line 154 "dlls/jscript/cc_parser.y"
                                    { FIXME("'+' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1348 "dlls/jscript/cc_parser.tab.c"
    break;

  case 8: /* CCUnaryExpression: '-' CCUnaryExpression  */
#line 155 "dlls/jscript/cc_parser.y"
                                    { FIXME("'-' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1354 "dlls/jscript/cc_parser.tab.c"
    break;

  case 9: /* CCLogicalORExpression: CCLogicalANDExpression  */
#line 158 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1360 "dlls/jscript/cc_parser.tab.c"
    break;

  case 10: /* CCLogicalORExpression: CCLogicalORExpression tOR CCLogicalANDExpression  */
#line 160 "dlls/jscript/cc_parser.y"
                                    { FIXME("'||' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1366 "dlls/jscript/cc_parser.tab.c"
    break;

  case 11: /* CCLogicalANDExpression: CCBitwiseORExpression  */
#line 163 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1372 "dlls/jscript/cc_parser.tab.c"
    break;

  case 12: /* CCLogicalANDExpression: CCBitwiseANDExpression tAND CCBitwiseORExpression  */
#line 165 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccbool((yyvsp[-2].ccval)) && get_ccbool((yyvsp[0].ccval))); }
#line 1378 "dlls/jscript/cc_parser.tab.c"
    break;

  case 13: /* CCBitwiseORExpression: CCBitwiseXORExpression  */
#line 168 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1384 "dlls/jscript/cc_parser.tab.c"
    break;

  case 14: /* CCBitwiseORExpression: CCBitwiseORExpression '|' CCBitwiseXORExpression  */
#line 170 "dlls/jscript/cc_parser.y"
                                    { FIXME("'|' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1390 "dlls/jscript/cc_parser.tab.c"
    break;

  case 15: /* CCBitwiseXORExpression: CCBitwiseANDExpression  */
#line 173 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1396 "dlls/jscript/cc_parser.tab.c"
    break;

  case 16: /* CCBitwiseXORExpression: CCBitwiseXORExpression '^' CCBitwiseANDExpression  */
#line 175 "dlls/jscript/cc_parser.y"
                                    { FIXME("'^' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1402 "dlls/jscript/cc_parser.tab.c"
    break;

  case 17: /* CCBitwiseANDExpression: CCEqualityExpression  */
#line 178 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1408 "dlls/jscript/cc_parser.tab.c"
    break;

  case 18: /* CCBitwiseANDExpression: CCBitwiseANDExpression '&' CCEqualityExpression  */
#line 180 "dlls/jscript/cc_parser.y"
                                    { FIXME("'&' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1414 "dlls/jscript/cc_parser.tab.c"
    break;

  case 19: /* CCEqualityExpression: CCRelationalExpression  */
#line 183 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1420 "dlls/jscript/cc_parser.tab.c"
    break;

  case 20: /* CCEqualityExpression: CCEqualityExpression tEQ CCRelationalExpression  */
#line 185 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) == get_ccnum((yyvsp[0].ccval))); }
#line 1426 "dlls/jscript/cc_parser.tab.c"
    break;

  case 21: /* CCEqualityExpression: CCEqualityExpression tNEQ CCRelationalExpression  */
#line 187 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) != get_ccnum((yyvsp[0].ccval))); }
#line 1432 "dlls/jscript/cc_parser.tab.c"
    break;

  case 22: /* CCEqualityExpression: CCEqualityExpression tEQEQ CCRelationalExpression  */
#line 189 "dlls/jscript/cc_parser.y"
                                    { FIXME("'===' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1438 "dlls/jscript/cc_parser.tab.c"
    break;

  case 23: /* CCEqualityExpression: CCEqualityExpression tNEQEQ CCRelationalExpression  */
#line 191 "dlls/jscript/cc_parser.y"
                                    { FIXME("'!==' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1444 "dlls/jscript/cc_parser.tab.c"
    break;

  case 24: /* CCRelationalExpression: CCShiftExpression  */
#line 194 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1450 "dlls/jscript/cc_parser.tab.c"
    break;

  case 25: /* CCRelationalExpression: CCRelationalExpression '<' CCShiftExpression  */
#line 196 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) < get_ccnum((yyvsp[0].ccval))); }
#line 1456 "dlls/jscript/cc_parser.tab.c"
    break;

  case 26: /* CCRelationalExpression: CCRelationalExpression tLEQ CCShiftExpression  */
#line 198 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) <= get_ccnum((yyvsp[0].ccval))); }
#line 1462 "dlls/jscript/cc_parser.tab.c"
    break;

  case 27: /* CCRelationalExpression: CCRelationalExpression '>' CCShiftExpression  */
#line 200 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) > get_ccnum((yyvsp[0].ccval))); }
#line 1468 "dlls/jscript/cc_parser.tab.c"
    break;

  case 28: /* CCRelationalExpression: CCRelationalExpression tGEQ CCShiftExpression  */
#line 202 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_bool(get_ccnum((yyvsp[-2].ccval)) >= get_ccnum((yyvsp[0].ccval))); }
#line 1474 "dlls/jscript/cc_parser.tab.c"
    break;

  case 29: /* CCShiftExpression: CCAdditiveExpression  */
#line 205 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1480 "dlls/jscript/cc_parser.tab.c"
    break;

  case 30: /* CCShiftExpression: CCShiftExpression tLSHIFT CCAdditiveExpression  */
#line 207 "dlls/jscript/cc_parser.y"
                                    { FIXME("'<<' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1486 "dlls/jscript/cc_parser.tab.c"
    break;

  case 31: /* CCShiftExpression: CCShiftExpression tRSHIFT CCAdditiveExpression  */
#line 209 "dlls/jscript/cc_parser.y"
                                    { FIXME("'>>' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1492 "dlls/jscript/cc_parser.tab.c"
    break;

  case 32: /* CCShiftExpression: CCShiftExpression tRRSHIFT CCAdditiveExpression  */
#line 211 "dlls/jscript/cc_parser.y"
                                    { FIXME("'>>>' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1498 "dlls/jscript/cc_parser.tab.c"
    break;

  case 33: /* CCAdditiveExpression: CCMultiplicativeExpression  */
#line 214 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1504 "dlls/jscript/cc_parser.tab.c"
    break;

  case 34: /* CCAdditiveExpression: CCAdditiveExpression '+' CCMultiplicativeExpression  */
#line 216 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_num(get_ccnum((yyvsp[-2].ccval)) + get_ccnum((yyvsp[0].ccval))); }
#line 1510 "dlls/jscript/cc_parser.tab.c"
    break;

  case 35: /* CCAdditiveExpression: CCAdditiveExpression '-' CCMultiplicativeExpression  */
#line 218 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_num(get_ccnum((yyvsp[-2].ccval)) - get_ccnum((yyvsp[0].ccval))); }
#line 1516 "dlls/jscript/cc_parser.tab.c"
    break;

  case 36: /* CCMultiplicativeExpression: CCUnaryExpression  */
#line 221 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = (yyvsp[0].ccval); }
#line 1522 "dlls/jscript/cc_parser.tab.c"
    break;

  case 37: /* CCMultiplicativeExpression: CCMultiplicativeExpression '*' CCUnaryExpression  */
#line 223 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_num(get_ccnum((yyvsp[-2].ccval)) * get_ccnum((yyvsp[0].ccval))); }
#line 1528 "dlls/jscript/cc_parser.tab.c"
    break;

  case 38: /* CCMultiplicativeExpression: CCMultiplicativeExpression '/' CCUnaryExpression  */
#line 225 "dlls/jscript/cc_parser.y"
                                    { (yyval.ccval) = ccval_num(get_ccnum((yyvsp[-2].ccval)) / get_ccnum((yyvsp[0].ccval))); }
#line 1534 "dlls/jscript/cc_parser.tab.c"
    break;

  case 39: /* CCMultiplicativeExpression: CCMultiplicativeExpression '%' CCUnaryExpression  */
#line 227 "dlls/jscript/cc_parser.y"
                                    { FIXME("'%%' expression not implemented\n"); ctx->hres = E_NOTIMPL; YYABORT; }
#line 1540 "dlls/jscript/cc_parser.tab.c"
    break;


#line 1544 "dlls/jscript/cc_parser.tab.c"

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
  yytoken = yychar == CC_PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (ctx, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= CC_PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == CC_PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, ctx);
          yychar = CC_PARSER_EMPTY;
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
  if (yychar != CC_PARSER_EMPTY)
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

  return yyresult;
}

#line 229 "dlls/jscript/cc_parser.y"


BOOL parse_cc_expr(parser_ctx_t *ctx)
{
    ctx->hres = S_OK;
    cc_parser_parse(ctx);
    return SUCCEEDED(ctx->hres);
}
