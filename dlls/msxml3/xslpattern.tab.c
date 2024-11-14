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
#define YYSTYPE         XSLPATTERN_STYPE
/* Substitute the variable and function names.  */
#define yyparse         xslpattern_parse
#define yylex           xslpattern_lex
#define yyerror         xslpattern_error
#define yydebug         xslpattern_debug
#define yynerrs         xslpattern_nerrs

/* First part of user prologue.  */
#line 21 "dlls/msxml3/xslpattern.y"

#include "xslpattern.h"
#include <libxml/xpathInternals.h>
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(msxml);


static const xmlChar NameTest_mod_pre[] = "*[name()='";
static const xmlChar NameTest_mod_post[] = "']";

#define U(str) BAD_CAST str

static inline BOOL is_literal(xmlChar const* tok)
{
    return (tok && tok[0] && tok[1] &&
            tok[0]== tok[xmlStrlen(tok)-1] &&
            (tok[0] == '\'' || tok[0] == '"'));
}

static void xslpattern_error(parser_param* param, void const* scanner, char const* msg)
{
    param->err++;
    FIXME("%s:\n"
          "  param {\n"
          "    yyscanner=%p\n"
          "    ctx=%p\n"
          "    in=\"%s\"\n"
          "    pos=%i\n"
          "    len=%i\n"
          "    out=\"%s\"\n"
          "    err=%i\n"
          "  }\n"
          "  scanner=%p\n",
          msg, param->yyscanner, param->ctx, param->in, param->pos,
          param->len, param->out, param->err, scanner);
}


#line 117 "dlls/msxml3/xslpattern.tab.c"

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
#ifndef XSLPATTERN_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define XSLPATTERN_DEBUG 1
#  else
#   define XSLPATTERN_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define XSLPATTERN_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined XSLPATTERN_DEBUG */
#if XSLPATTERN_DEBUG
extern int xslpattern_debug;
#endif

/* Token kinds.  */
#ifndef XSLPATTERN_TOKENTYPE
# define XSLPATTERN_TOKENTYPE
  enum xslpattern_tokentype
  {
    XSLPATTERN_EMPTY = -2,
    XSLPATTERN_EOF = 0,            /* "end of file"  */
    XSLPATTERN_error = 256,        /* error  */
    XSLPATTERN_UNDEF = 257,        /* "invalid token"  */
    TOK_Parent = 258,              /* TOK_Parent  */
    TOK_Self = 259,                /* TOK_Self  */
    TOK_DblFSlash = 260,           /* TOK_DblFSlash  */
    TOK_FSlash = 261,              /* TOK_FSlash  */
    TOK_Axis = 262,                /* TOK_Axis  */
    TOK_Colon = 263,               /* TOK_Colon  */
    TOK_OpAnd = 264,               /* TOK_OpAnd  */
    TOK_OpOr = 265,                /* TOK_OpOr  */
    TOK_OpNot = 266,               /* TOK_OpNot  */
    TOK_OpEq = 267,                /* TOK_OpEq  */
    TOK_OpIEq = 268,               /* TOK_OpIEq  */
    TOK_OpNEq = 269,               /* TOK_OpNEq  */
    TOK_OpINEq = 270,              /* TOK_OpINEq  */
    TOK_OpLt = 271,                /* TOK_OpLt  */
    TOK_OpILt = 272,               /* TOK_OpILt  */
    TOK_OpGt = 273,                /* TOK_OpGt  */
    TOK_OpIGt = 274,               /* TOK_OpIGt  */
    TOK_OpLEq = 275,               /* TOK_OpLEq  */
    TOK_OpILEq = 276,              /* TOK_OpILEq  */
    TOK_OpGEq = 277,               /* TOK_OpGEq  */
    TOK_OpIGEq = 278,              /* TOK_OpIGEq  */
    TOK_OpAll = 279,               /* TOK_OpAll  */
    TOK_OpAny = 280,               /* TOK_OpAny  */
    TOK_NCName = 281,              /* TOK_NCName  */
    TOK_Literal = 282,             /* TOK_Literal  */
    TOK_Number = 283               /* TOK_Number  */
  };
  typedef enum xslpattern_tokentype xslpattern_token_kind_t;
#endif

/* Value type.  */
#if ! defined XSLPATTERN_STYPE && ! defined XSLPATTERN_STYPE_IS_DECLARED
typedef int XSLPATTERN_STYPE;
# define XSLPATTERN_STYPE_IS_TRIVIAL 1
# define XSLPATTERN_STYPE_IS_DECLARED 1
#endif




int xslpattern_parse (parser_param* p, void* scanner);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_Parent = 3,                 /* TOK_Parent  */
  YYSYMBOL_TOK_Self = 4,                   /* TOK_Self  */
  YYSYMBOL_TOK_DblFSlash = 5,              /* TOK_DblFSlash  */
  YYSYMBOL_TOK_FSlash = 6,                 /* TOK_FSlash  */
  YYSYMBOL_TOK_Axis = 7,                   /* TOK_Axis  */
  YYSYMBOL_TOK_Colon = 8,                  /* TOK_Colon  */
  YYSYMBOL_TOK_OpAnd = 9,                  /* TOK_OpAnd  */
  YYSYMBOL_TOK_OpOr = 10,                  /* TOK_OpOr  */
  YYSYMBOL_TOK_OpNot = 11,                 /* TOK_OpNot  */
  YYSYMBOL_TOK_OpEq = 12,                  /* TOK_OpEq  */
  YYSYMBOL_TOK_OpIEq = 13,                 /* TOK_OpIEq  */
  YYSYMBOL_TOK_OpNEq = 14,                 /* TOK_OpNEq  */
  YYSYMBOL_TOK_OpINEq = 15,                /* TOK_OpINEq  */
  YYSYMBOL_TOK_OpLt = 16,                  /* TOK_OpLt  */
  YYSYMBOL_TOK_OpILt = 17,                 /* TOK_OpILt  */
  YYSYMBOL_TOK_OpGt = 18,                  /* TOK_OpGt  */
  YYSYMBOL_TOK_OpIGt = 19,                 /* TOK_OpIGt  */
  YYSYMBOL_TOK_OpLEq = 20,                 /* TOK_OpLEq  */
  YYSYMBOL_TOK_OpILEq = 21,                /* TOK_OpILEq  */
  YYSYMBOL_TOK_OpGEq = 22,                 /* TOK_OpGEq  */
  YYSYMBOL_TOK_OpIGEq = 23,                /* TOK_OpIGEq  */
  YYSYMBOL_TOK_OpAll = 24,                 /* TOK_OpAll  */
  YYSYMBOL_TOK_OpAny = 25,                 /* TOK_OpAny  */
  YYSYMBOL_TOK_NCName = 26,                /* TOK_NCName  */
  YYSYMBOL_TOK_Literal = 27,               /* TOK_Literal  */
  YYSYMBOL_TOK_Number = 28,                /* TOK_Number  */
  YYSYMBOL_29_ = 29,                       /* '@'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '['  */
  YYSYMBOL_32_ = 32,                       /* ']'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_XSLPattern = 39,                /* XSLPattern  */
  YYSYMBOL_QName = 40,                     /* QName  */
  YYSYMBOL_PrefixedName = 41,              /* PrefixedName  */
  YYSYMBOL_UnprefixedName = 42,            /* UnprefixedName  */
  YYSYMBOL_LocationPath = 43,              /* LocationPath  */
  YYSYMBOL_AbsoluteLocationPath = 44,      /* AbsoluteLocationPath  */
  YYSYMBOL_RelativeLocationPath = 45,      /* RelativeLocationPath  */
  YYSYMBOL_Step = 46,                      /* Step  */
  YYSYMBOL_AxisSpecifier = 47,             /* AxisSpecifier  */
  YYSYMBOL_Attribute = 48,                 /* Attribute  */
  YYSYMBOL_NodeTest = 49,                  /* NodeTest  */
  YYSYMBOL_NameTest = 50,                  /* NameTest  */
  YYSYMBOL_Predicates = 51,                /* Predicates  */
  YYSYMBOL_Predicate = 52,                 /* Predicate  */
  YYSYMBOL_PredicateExpr = 53,             /* PredicateExpr  */
  YYSYMBOL_AbbreviatedAbsoluteLocationPath = 54, /* AbbreviatedAbsoluteLocationPath  */
  YYSYMBOL_AbbreviatedRelativeLocationPath = 55, /* AbbreviatedRelativeLocationPath  */
  YYSYMBOL_AbbreviatedStep = 56,           /* AbbreviatedStep  */
  YYSYMBOL_Expr = 57,                      /* Expr  */
  YYSYMBOL_BoolExpr = 58,                  /* BoolExpr  */
  YYSYMBOL_PrimaryExpr = 59,               /* PrimaryExpr  */
  YYSYMBOL_FunctionCall = 60,              /* FunctionCall  */
  YYSYMBOL_Arguments = 61,                 /* Arguments  */
  YYSYMBOL_Argument = 62,                  /* Argument  */
  YYSYMBOL_UnionExpr = 63,                 /* UnionExpr  */
  YYSYMBOL_PathExpr = 64,                  /* PathExpr  */
  YYSYMBOL_FilterExpr = 65,                /* FilterExpr  */
  YYSYMBOL_OrExpr = 66,                    /* OrExpr  */
  YYSYMBOL_BoolOrExpr = 67,                /* BoolOrExpr  */
  YYSYMBOL_AndExpr = 68,                   /* AndExpr  */
  YYSYMBOL_BoolAndExpr = 69,               /* BoolAndExpr  */
  YYSYMBOL_EqualityExpr = 70,              /* EqualityExpr  */
  YYSYMBOL_BoolEqualityExpr = 71,          /* BoolEqualityExpr  */
  YYSYMBOL_RelationalExpr = 72,            /* RelationalExpr  */
  YYSYMBOL_BoolRelationalExpr = 73,        /* BoolRelationalExpr  */
  YYSYMBOL_UnaryExpr = 74,                 /* UnaryExpr  */
  YYSYMBOL_BoolUnaryExpr = 75,             /* BoolUnaryExpr  */
  YYSYMBOL_AllExpr = 76                    /* AllExpr  */
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
         || (defined XSLPATTERN_STYPE_IS_TRIVIAL && XSLPATTERN_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,    35,     2,     2,     2,     2,     2,     2,
      33,    34,    30,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    37,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if XSLPATTERN_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    94,    95,    97,   106,   117,   118,   120,
     127,   132,   134,   135,   143,   146,   155,   162,   169,   170,
     171,   173,   180,   187,   195,   196,   198,   203,   209,   228,
     236,   242,   244,   253,   259,   260,   261,   264,   272,   281,
     286,   295,   297,   298,   299,   300,   301,   302,   304,   312,
     320,   321,   324,   383,   414,   421,   423,   426,   427,   436,
     437,   445,   453,   455,   456,   465,   466,   468,   477,   478,
     480,   489,   490,   492,   500,   511,   519,   531,   532,   534,
     542,   553,   561,   572,   580,   591,   599,   613,   614,   616,
     624,   632,   640,   646,   653,   660,   667,   674,   681,   688,
     698,   708,   718,   728,   738
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if XSLPATTERN_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_Parent",
  "TOK_Self", "TOK_DblFSlash", "TOK_FSlash", "TOK_Axis", "TOK_Colon",
  "TOK_OpAnd", "TOK_OpOr", "TOK_OpNot", "TOK_OpEq", "TOK_OpIEq",
  "TOK_OpNEq", "TOK_OpINEq", "TOK_OpLt", "TOK_OpILt", "TOK_OpGt",
  "TOK_OpIGt", "TOK_OpLEq", "TOK_OpILEq", "TOK_OpGEq", "TOK_OpIGEq",
  "TOK_OpAll", "TOK_OpAny", "TOK_NCName", "TOK_Literal", "TOK_Number",
  "'@'", "'*'", "'['", "']'", "'('", "')'", "'!'", "','", "'|'", "$accept",
  "XSLPattern", "QName", "PrefixedName", "UnprefixedName", "LocationPath",
  "AbsoluteLocationPath", "RelativeLocationPath", "Step", "AxisSpecifier",
  "Attribute", "NodeTest", "NameTest", "Predicates", "Predicate",
  "PredicateExpr", "AbbreviatedAbsoluteLocationPath",
  "AbbreviatedRelativeLocationPath", "AbbreviatedStep", "Expr", "BoolExpr",
  "PrimaryExpr", "FunctionCall", "Arguments", "Argument", "UnionExpr",
  "PathExpr", "FilterExpr", "OrExpr", "BoolOrExpr", "AndExpr",
  "BoolAndExpr", "EqualityExpr", "BoolEqualityExpr", "RelationalExpr",
  "BoolRelationalExpr", "UnaryExpr", "BoolUnaryExpr", "AllExpr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,   -34,   -34,    25,    25,    20,   106,    20,     0,   -34,
     -34,   -21,   -34,    20,    10,   -17,   -34,   -12,   -34,   -34,
      52,   -34,    -8,   -34,    28,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -10,    27,    35,    55,   -34,    21,   -34,    58,
     -34,   136,   -34,   -34,   -34,    52,    52,   -34,   128,   -34,
     -34,   -34,    26,    59,   -34,   -34,   -34,    40,   -34,     9,
      25,    25,   105,    28,    97,    28,   -34,   106,    88,    25,
      25,   -34,    20,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,    82,   -34,
      90,   -34,   -34,   -34,    83,    84,   -34,   -34,    28,    99,
      86,    87,    96,   -34,   129,    55,   119,   130,   132,   133,
     134,   -34,    27,   -34,    52,    52,   -34,    58,   136,   136,
     136,   136,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,   -34,   -34,    20,   -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    39,    40,     0,    10,     0,    92,     0,     6,    50,
      51,     0,    26,     0,     0,     0,     3,    29,    59,     8,
       7,    12,     0,    19,    18,    24,    11,    14,    20,     2,
      63,    25,    87,    57,    62,    41,    66,    65,    69,    68,
      72,    71,    78,    77,    88,    37,     9,    89,     0,    91,
      90,    21,     0,     6,    23,    22,     4,     0,     1,     0,
       0,     0,     6,    17,     0,    16,    31,     0,     0,     0,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    27,
       0,    48,    53,    56,     0,    55,    38,    13,    15,     6,
      51,    19,     0,    34,    25,     0,    47,    69,    72,    78,
      88,    30,    58,    49,    61,    60,    67,    70,    73,    74,
      75,    76,    79,    80,    81,    82,    83,    84,    85,    86,
      93,    99,    94,   100,    95,   101,    97,   103,    96,   102,
      98,   104,     5,    52,     0,    32,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,   126,   -34,    -5,   -34,   -34,    -1,    44,   -34,
      74,   138,   -34,   104,   -33,   -34,   -34,   -34,   -34,     4,
     -34,   -34,    -4,    15,   -34,   -34,    -6,   -34,   107,   108,
      98,   109,    95,   110,     2,   111,    14,   112,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    65,    66,   112,    26,    27,    28,   103,
     113,    30,    31,   104,   105,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    71,    45,    46,    29,    53,    56,    51,    52,    54,
      58,    50,     1,     2,     3,     4,    59,    57,    62,    47,
       5,    -4,    12,     1,     2,     3,     4,    67,     1,     2,
      73,     5,   121,     6,     7,     8,     9,    10,    11,    12,
      69,    70,    13,   102,     6,     7,     8,     9,    10,    11,
      12,     8,    98,    13,    11,    12,    99,    60,    61,    64,
     114,   122,    68,    56,   123,    72,    64,   100,   124,   125,
      74,    75,    76,    77,   101,   121,   128,   129,   130,   131,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   132,   133,   134,   135,   136,   137,   138,   139,
       1,     2,     3,     4,   106,   107,    51,    52,     5,     1,
       2,     3,     4,    52,    53,    -5,   152,   153,   -33,   -35,
     154,     6,     7,   109,     9,   110,    11,    12,   155,   -66,
      13,   -36,     8,     9,    10,    11,    12,    55,   111,    13,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    78,    79,    80,    81,    82,    83,    84,    85,
      63,   -42,   -46,    68,   -45,   -44,   -43,   108,   127,   156,
     126,   115,   116,   117,   118,   119,   120
};

static const yytype_uint8 yycheck[] =
{
       6,    34,     3,     4,     0,    26,    11,     7,     8,    30,
       0,     7,     3,     4,     5,     6,    33,    13,    26,     5,
      11,    33,    30,     3,     4,     5,     6,    37,     3,     4,
       9,    11,    65,    24,    25,    26,    27,    28,    29,    30,
       5,     6,    33,    34,    24,    25,    26,    27,    28,    29,
      30,    26,    26,    33,    29,    30,    30,     5,     6,    31,
      64,    67,    35,    68,    68,    10,    31,     8,    69,    70,
      12,    13,    14,    15,    34,   108,    74,    75,    76,    77,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    78,    79,    80,    81,    82,    83,    84,    85,
       3,     4,     5,     6,    60,    61,     7,     8,    11,     3,
       4,     5,     6,     8,    26,    33,    26,    34,    32,    32,
      36,    24,    25,    26,    27,    28,    29,    30,    32,    10,
      33,    32,    26,    27,    28,    29,    30,    11,    64,    33,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    16,    17,    18,    19,    20,    21,    22,    23,
      22,    32,    32,    35,    32,    32,    32,    63,    73,   154,
      72,    64,    64,    64,    64,    64,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    11,    24,    25,    26,    27,
      28,    29,    30,    33,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    54,    55,    56,    57,
      59,    60,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    45,    45,    74,    64,    76,
      57,     7,     8,    26,    30,    40,    42,    57,     0,    33,
       5,     6,    26,    49,    31,    51,    52,    37,    35,     5,
       6,    52,    10,     9,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    26,    30,
       8,    34,    34,    57,    61,    62,    46,    46,    51,    26,
      28,    48,    53,    58,    60,    66,    67,    69,    71,    73,
      75,    52,    64,    60,    45,    45,    68,    70,    72,    72,
      72,    72,    74,    74,    74,    74,    74,    74,    74,    74,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    26,    34,    36,    32,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    42,    43,    43,    44,
      44,    44,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    51,    52,    53,    53,    53,    53,    54,    55,    56,
      56,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     3,     1,     3,     2,     2,     1,     1,
       1,     2,     2,     2,     1,     1,     1,     3,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     4,     3,     3,     1,     1,     1,     3,     1,
       3,     3,     1,     1,     2,     1,     1,     3,     1,     1,
       3,     1,     1,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = XSLPATTERN_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == XSLPATTERN_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (p, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use XSLPATTERN_error or XSLPATTERN_UNDEF. */
#define YYERRCODE XSLPATTERN_UNDEF


/* Enable debugging if requested.  */
#if XSLPATTERN_DEBUG

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
                  Kind, Value, p, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, parser_param* p, void* scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (p);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, parser_param* p, void* scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, p, scanner);
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
                 int yyrule, parser_param* p, void* scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], p, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, p, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !XSLPATTERN_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !XSLPATTERN_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, parser_param* p, void* scanner)
{
  YY_USE (yyvaluep);
  YY_USE (p);
  YY_USE (scanner);
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
yyparse (parser_param* p, void* scanner)
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

  yychar = XSLPATTERN_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == XSLPATTERN_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= XSLPATTERN_EOF)
    {
      yychar = XSLPATTERN_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == XSLPATTERN_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = XSLPATTERN_UNDEF;
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
  yychar = XSLPATTERN_EMPTY;
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
  case 2: /* XSLPattern: Expr  */
#line 85 "dlls/msxml3/xslpattern.y"
                            {
                                p->out = yyvsp[0];
                            }
#line 1379 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 5: /* PrefixedName: TOK_NCName TOK_Colon TOK_NCName  */
#line 98 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got PrefixedName: \"%s:%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(":"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1391 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 6: /* UnprefixedName: TOK_NCName  */
#line 107 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got UnprefixedName: \"%s\"\n", yyvsp[0]);
                                yyval=yyvsp[0];
                            }
#line 1400 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 9: /* AbsoluteLocationPath: TOK_FSlash RelativeLocationPath  */
#line 121 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbsoluteLocationPath: \"/%s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U("/"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1411 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 10: /* AbsoluteLocationPath: TOK_FSlash  */
#line 128 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbsoluteLocationPath: \"/\"\n");
                                yyval=xmlStrdup(U("/"));
                            }
#line 1420 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 13: /* RelativeLocationPath: RelativeLocationPath TOK_FSlash Step  */
#line 136 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelativeLocationPath: \"%s/%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("/"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1432 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 15: /* Step: AxisSpecifier NodeTest Predicates  */
#line 147 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got Step: \"%s%s%s\"\n", yyvsp[-2], yyvsp[-1], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,yyvsp[-1]);
                                xmlFree(yyvsp[-1]);
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1445 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 16: /* Step: NodeTest Predicates  */
#line 156 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got Step: \"%s%s\"\n", yyvsp[-1], yyvsp[0]);
                                yyval=yyvsp[-1];
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1456 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 17: /* Step: AxisSpecifier NodeTest  */
#line 163 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got Step: \"%s%s\"\n", yyvsp[-1], yyvsp[0]);
                                yyval=yyvsp[-1];
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1467 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 21: /* AxisSpecifier: TOK_NCName TOK_Axis  */
#line 174 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AxisSpecifier: \"%s::\"\n", yyvsp[-1]);
                                yyval=yyvsp[-1];
                                yyval=xmlStrcat(yyval,U("::"));
                            }
#line 1477 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 22: /* Attribute: '@' QName  */
#line 181 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got Attribute: \"@%s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U("@"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1488 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 23: /* Attribute: '@' '*'  */
#line 188 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got All attributes pattern: \"@*\"\n");
                                yyval=xmlStrdup(U("@*"));
                            }
#line 1497 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 26: /* NameTest: '*'  */
#line 199 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got NameTest: \"*\"\n");
                                yyval=xmlStrdup(U("*"));
                            }
#line 1506 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 27: /* NameTest: TOK_NCName TOK_Colon '*'  */
#line 204 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got NameTest: \"%s:*\"\n", yyvsp[-2]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(":*"));
                            }
#line 1516 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 28: /* NameTest: TOK_NCName TOK_Colon TOK_NCName  */
#line 210 "dlls/msxml3/xslpattern.y"
                            { /* PrefixedName */
                                xmlChar const* registeredNsURI = xmlXPathNsLookup(p->ctx, yyvsp[-2]);
                                TRACE("Got PrefixedName: \"%s:%s\"\n", yyvsp[-2], yyvsp[0]);

                                if (registeredNsURI)
                                    yyval=xmlStrdup(U(""));
                                else
                                    yyval=xmlStrdup(NameTest_mod_pre);

                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(":"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);

                                if (!registeredNsURI)
                                    yyval=xmlStrcat(yyval,NameTest_mod_post);
                            }
#line 1539 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 29: /* NameTest: UnprefixedName  */
#line 229 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(NameTest_mod_pre);
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,NameTest_mod_post);
                            }
#line 1550 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 30: /* Predicates: Predicates Predicate  */
#line 237 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-1];
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1560 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 32: /* Predicate: '[' PredicateExpr ']'  */
#line 245 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got Predicate: \"[%s]\"\n", yyvsp[-1]);
                                yyval=xmlStrdup(U("["));
                                yyval=xmlStrcat(yyval,yyvsp[-1]);
                                xmlFree(yyvsp[-1]);
                                yyval=xmlStrcat(yyval,U("]"));
                            }
#line 1572 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 33: /* PredicateExpr: TOK_Number  */
#line 254 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("index()="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1582 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 37: /* AbbreviatedAbsoluteLocationPath: TOK_DblFSlash RelativeLocationPath  */
#line 265 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbbreviatedAbsoluteLocationPath: \"//%s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U("//"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1593 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 38: /* AbbreviatedRelativeLocationPath: RelativeLocationPath TOK_DblFSlash Step  */
#line 273 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbbreviatedRelativeLocationPath: \"%s//%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("//"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1605 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 39: /* AbbreviatedStep: TOK_Parent  */
#line 282 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbbreviatedStep: \"..\"\n");
                                yyval=xmlStrdup(U(".."));
                            }
#line 1614 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 40: /* AbbreviatedStep: TOK_Self  */
#line 287 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AbbreviatedStep: \".\"\n");
                                yyval=xmlStrdup(U("."));
                            }
#line 1623 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 48: /* PrimaryExpr: '(' Expr ')'  */
#line 305 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got PrimaryExpr: \"(%s)\"\n", yyvsp[-2]);
                                yyval=xmlStrdup(U("("));
                                yyval=xmlStrcat(yyval,yyvsp[-1]);
                                xmlFree(yyvsp[-1]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1635 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 49: /* PrimaryExpr: PathExpr '!' FunctionCall  */
#line 313 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got PrimaryExpr: \"%s!%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("/"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1647 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 52: /* FunctionCall: QName '(' Arguments ')'  */
#line 325 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got FunctionCall: \"%s(%s)\"\n", yyvsp[-3], yyvsp[-1]);
                                if (xmlStrEqual(yyvsp[-3],U("ancestor")))
                                {
                                    yyval=yyvsp[-3];
                                    yyval=xmlStrcat(yyval,U("::"));
                                    yyval=xmlStrcat(yyval,yyvsp[-1]);
                                    xmlFree(yyvsp[-1]);
                                }
                                else if (xmlStrEqual(yyvsp[-3],U("attribute")))
                                {
                                    if (is_literal(yyvsp[-1]))
                                    {
                                        yyval=xmlStrdup(U("@*[name()="));
                                        xmlFree(yyvsp[-3]);
                                        yyval=xmlStrcat(yyval,yyvsp[-1]);
                                        xmlFree(yyvsp[-1]);
                                        yyval=xmlStrcat(yyval,U("]"));
                                    }
                                    else
                                    {
                                        /* XML_XPATH_INVALID_TYPE */
                                        yyval=xmlStrdup(U("error(1211, 'Error: attribute("));
                                        xmlFree(yyvsp[-3]);
                                        yyval=xmlStrcat(yyval,yyvsp[-1]);
                                        xmlFree(yyvsp[-1]);
                                        yyval=xmlStrcat(yyval,U("): invalid argument')"));
                                    }
                                }
                                else if (xmlStrEqual(yyvsp[-3],U("element")))
                                {
                                    if (is_literal(yyvsp[-1]))
                                    {
                                        yyval=xmlStrdup(U("node()[nodeType()=1][name()="));
                                        xmlFree(yyvsp[-3]);
                                        yyval=xmlStrcat(yyval,yyvsp[-1]);
                                        xmlFree(yyvsp[-1]);
                                        yyval=xmlStrcat(yyval,U("]"));
                                    }
                                    else
                                    {
                                        /* XML_XPATH_INVALID_TYPE */
                                        yyval=xmlStrdup(U("error(1211, 'Error: element("));
                                        xmlFree(yyvsp[-3]);
                                        yyval=xmlStrcat(yyval,yyvsp[-1]);
                                        xmlFree(yyvsp[-1]);
                                        yyval=xmlStrcat(yyval,U("): invalid argument')"));
                                    }
                                }
                                else
                                {
                                    yyval=yyvsp[-3];
                                    yyval=xmlStrcat(yyval,U("("));
                                    yyval=xmlStrcat(yyval,yyvsp[-1]);
                                    xmlFree(yyvsp[-1]);
                                    yyval=xmlStrcat(yyval,U(")"));
                                }
                            }
#line 1710 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 53: /* FunctionCall: QName '(' ')'  */
#line 384 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got FunctionCall: \"%s()\"\n", yyvsp[-2]);
                                /* comment() & node() work the same in XPath */
                                if (xmlStrEqual(yyvsp[-2],U("attribute")))
                                {
                                    yyval=xmlStrdup(U("@*"));
                                    xmlFree(yyvsp[-2]);
                                }
                                else if (xmlStrEqual(yyvsp[-2],U("element")))
                                {
                                    yyval=xmlStrdup(U("node()[nodeType()=1]"));
                                    xmlFree(yyvsp[-2]);
                                }
                                else if (xmlStrEqual(yyvsp[-2],U("pi")))
                                {
                                    yyval=xmlStrdup(U("processing-instruction()"));
                                    xmlFree(yyvsp[-2]);
                                }
                                else if (xmlStrEqual(yyvsp[-2],U("textnode")))
                                {
                                    yyval=xmlStrdup(U("text()"));
                                    xmlFree(yyvsp[-2]);
                                }
                                else
                                {
                                    yyval=yyvsp[-2];
                                    yyval=xmlStrcat(yyval,U("()"));
                                }
                            }
#line 1744 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 54: /* Arguments: Argument ',' Arguments  */
#line 415 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1755 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 58: /* UnionExpr: UnionExpr '|' PathExpr  */
#line 428 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got UnionExpr: \"%s|%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("|"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1767 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 60: /* PathExpr: FilterExpr TOK_FSlash RelativeLocationPath  */
#line 438 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got PathExpr: \"%s/%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("/"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1779 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 61: /* PathExpr: FilterExpr TOK_DblFSlash RelativeLocationPath  */
#line 446 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got PathExpr: \"%s//%s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("//"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1791 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 64: /* FilterExpr: FilterExpr Predicate  */
#line 457 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got FilterExpr: \"%s%s\"\n", yyvsp[-1], yyvsp[0]);
                                yyval=yyvsp[-1];
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1802 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 67: /* BoolOrExpr: OrExpr TOK_OpOr AndExpr  */
#line 469 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got OrExpr: \"%s $or$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(" or "));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1814 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 70: /* BoolAndExpr: AndExpr TOK_OpAnd EqualityExpr  */
#line 481 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got AndExpr: \"%s $and$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(" and "));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1826 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 73: /* BoolEqualityExpr: EqualityExpr TOK_OpEq RelationalExpr  */
#line 493 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got EqualityExpr: \"%s $eq$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1838 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 74: /* BoolEqualityExpr: EqualityExpr TOK_OpIEq RelationalExpr  */
#line 501 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got EqualityExpr: \"%s $ieq$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_IEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1853 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 75: /* BoolEqualityExpr: EqualityExpr TOK_OpNEq RelationalExpr  */
#line 512 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got EqualityExpr: \"%s $ne$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("!="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1865 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 76: /* BoolEqualityExpr: EqualityExpr TOK_OpINEq RelationalExpr  */
#line 520 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got EqualityExpr: \"%s $ine$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_INEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1880 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 79: /* BoolRelationalExpr: RelationalExpr TOK_OpLt UnaryExpr  */
#line 535 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $lt$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("<"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1892 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 80: /* BoolRelationalExpr: RelationalExpr TOK_OpILt UnaryExpr  */
#line 543 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $ilt$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_ILt("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1907 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 81: /* BoolRelationalExpr: RelationalExpr TOK_OpGt UnaryExpr  */
#line 554 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $gt$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(">"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1919 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 82: /* BoolRelationalExpr: RelationalExpr TOK_OpIGt UnaryExpr  */
#line 562 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $igt$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_IGt("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1934 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 83: /* BoolRelationalExpr: RelationalExpr TOK_OpLEq UnaryExpr  */
#line 573 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $le$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("<="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1946 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 84: /* BoolRelationalExpr: RelationalExpr TOK_OpILEq UnaryExpr  */
#line 581 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $ile$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_ILEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1961 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 85: /* BoolRelationalExpr: RelationalExpr TOK_OpGEq UnaryExpr  */
#line 592 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $ge$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(">="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 1973 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 86: /* BoolRelationalExpr: RelationalExpr TOK_OpIGEq UnaryExpr  */
#line 600 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got RelationalExpr: \"%s $ige$ %s\"\n", yyvsp[-2], yyvsp[0]);
                                yyval=xmlStrdup(U("OP_IGEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 1988 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 89: /* BoolUnaryExpr: TOK_OpNot UnaryExpr  */
#line 617 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got UnaryExpr: \"$not$ %s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U(" not("));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2000 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 90: /* BoolUnaryExpr: TOK_OpAny Expr  */
#line 625 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got UnaryExpr: \"$any$ %s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U("boolean("));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2012 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 91: /* BoolUnaryExpr: TOK_OpAll AllExpr  */
#line 633 "dlls/msxml3/xslpattern.y"
                            {
                                TRACE("Got UnaryExpr: \"$all$ %s\"\n", yyvsp[0]);
                                yyval=xmlStrdup(U("not("));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2024 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 92: /* BoolUnaryExpr: TOK_OpAll  */
#line 641 "dlls/msxml3/xslpattern.y"
                            {
                                FIXME("Unrecognized $all$ expression - ignoring\n");
                                yyval=xmlStrdup(U(""));
                            }
#line 2033 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 93: /* AllExpr: PathExpr TOK_OpEq PathExpr  */
#line 647 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("!="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2044 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 94: /* AllExpr: PathExpr TOK_OpNEq PathExpr  */
#line 654 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2055 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 95: /* AllExpr: PathExpr TOK_OpLt PathExpr  */
#line 661 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(">="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2066 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 96: /* AllExpr: PathExpr TOK_OpLEq PathExpr  */
#line 668 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U(">"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2077 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 97: /* AllExpr: PathExpr TOK_OpGt PathExpr  */
#line 675 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("<="));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2088 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 98: /* AllExpr: PathExpr TOK_OpGEq PathExpr  */
#line 682 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=yyvsp[-2];
                                yyval=xmlStrcat(yyval,U("<"));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                            }
#line 2099 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 99: /* AllExpr: PathExpr TOK_OpIEq PathExpr  */
#line 689 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_INEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2113 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 100: /* AllExpr: PathExpr TOK_OpINEq PathExpr  */
#line 699 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_IEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2127 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 101: /* AllExpr: PathExpr TOK_OpILt PathExpr  */
#line 709 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_IGEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2141 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 102: /* AllExpr: PathExpr TOK_OpILEq PathExpr  */
#line 719 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_IGt("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2155 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 103: /* AllExpr: PathExpr TOK_OpIGt PathExpr  */
#line 729 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_ILEq("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2169 "dlls/msxml3/xslpattern.tab.c"
    break;

  case 104: /* AllExpr: PathExpr TOK_OpIGEq PathExpr  */
#line 739 "dlls/msxml3/xslpattern.y"
                            {
                                yyval=xmlStrdup(U("OP_ILt("));
                                yyval=xmlStrcat(yyval,yyvsp[-2]);
                                xmlFree(yyvsp[-2]);
                                yyval=xmlStrcat(yyval,U(","));
                                yyval=xmlStrcat(yyval,yyvsp[0]);
                                xmlFree(yyvsp[0]);
                                yyval=xmlStrcat(yyval,U(")"));
                            }
#line 2183 "dlls/msxml3/xslpattern.tab.c"
    break;


#line 2187 "dlls/msxml3/xslpattern.tab.c"

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
  yytoken = yychar == XSLPATTERN_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (p, scanner, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= XSLPATTERN_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == XSLPATTERN_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, p, scanner);
          yychar = XSLPATTERN_EMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, p, scanner);
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
  yyerror (p, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != XSLPATTERN_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, p, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, p, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 750 "dlls/msxml3/xslpattern.y"

