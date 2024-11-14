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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         ASMSHADER_STYPE
/* Substitute the variable and function names.  */
#define yyparse         asmshader_parse
#define yylex           asmshader_lex
#define yyerror         asmshader_error
#define yydebug         asmshader_debug
#define yynerrs         asmshader_nerrs
#define yylval          asmshader_lval
#define yychar          asmshader_char

/* First part of user prologue.  */
#line 22 "dlls/d3dcompiler_43/asmshader.y"

#include "wine/debug.h"

#include "d3dcompiler_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(asmshader);

struct asm_parser asm_ctx;

void WINAPIV asmparser_message(struct asm_parser *ctx, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    compilation_message(&ctx->messages, fmt, args);
    va_end(args);
}

static void asmshader_error(char const *s) {
    asmparser_message(&asm_ctx, "Line %u: Error \"%s\" from bison\n", asm_ctx.line_no, s);
    set_parse_status(&asm_ctx.status, PARSE_ERR);
}

static void set_rel_reg(struct shader_reg *reg, struct rel_reg *rel) {
    /* We can have an additional offset without true relative addressing
     * ex. c2[ 4 ] */
    reg->regnum += rel->additional_offset;
    if(!rel->has_rel_reg) {
        reg->rel_reg = NULL;
    } else {
        reg->rel_reg = calloc(1, sizeof(*reg->rel_reg));
        if(!reg->rel_reg) {
            return;
        }
        reg->rel_reg->type = rel->type;
        reg->rel_reg->swizzle = rel->swizzle;
        reg->rel_reg->regnum = rel->rel_regnum;
    }
}

/* Needed lexer functions declarations */
int asmshader_lex(void);



#line 125 "dlls/d3dcompiler_33/asmshader.tab.c"

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
#ifndef ASMSHADER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ASMSHADER_DEBUG 1
#  else
#   define ASMSHADER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ASMSHADER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ASMSHADER_DEBUG */
#if ASMSHADER_DEBUG
extern int asmshader_debug;
#endif

/* Token kinds.  */
#ifndef ASMSHADER_TOKENTYPE
# define ASMSHADER_TOKENTYPE
  enum asmshader_tokentype
  {
    ASMSHADER_EMPTY = -2,
    ASMSHADER_EOF = 0,             /* "end of file"  */
    ASMSHADER_error = 256,         /* error  */
    ASMSHADER_UNDEF = 257,         /* "invalid token"  */
    INSTR_ADD = 258,               /* INSTR_ADD  */
    INSTR_NOP = 259,               /* INSTR_NOP  */
    INSTR_MOV = 260,               /* INSTR_MOV  */
    INSTR_SUB = 261,               /* INSTR_SUB  */
    INSTR_MAD = 262,               /* INSTR_MAD  */
    INSTR_MUL = 263,               /* INSTR_MUL  */
    INSTR_RCP = 264,               /* INSTR_RCP  */
    INSTR_RSQ = 265,               /* INSTR_RSQ  */
    INSTR_DP3 = 266,               /* INSTR_DP3  */
    INSTR_DP4 = 267,               /* INSTR_DP4  */
    INSTR_MIN = 268,               /* INSTR_MIN  */
    INSTR_MAX = 269,               /* INSTR_MAX  */
    INSTR_SLT = 270,               /* INSTR_SLT  */
    INSTR_SGE = 271,               /* INSTR_SGE  */
    INSTR_ABS = 272,               /* INSTR_ABS  */
    INSTR_EXP = 273,               /* INSTR_EXP  */
    INSTR_LOG = 274,               /* INSTR_LOG  */
    INSTR_EXPP = 275,              /* INSTR_EXPP  */
    INSTR_LOGP = 276,              /* INSTR_LOGP  */
    INSTR_DST = 277,               /* INSTR_DST  */
    INSTR_LRP = 278,               /* INSTR_LRP  */
    INSTR_FRC = 279,               /* INSTR_FRC  */
    INSTR_POW = 280,               /* INSTR_POW  */
    INSTR_CRS = 281,               /* INSTR_CRS  */
    INSTR_SGN = 282,               /* INSTR_SGN  */
    INSTR_NRM = 283,               /* INSTR_NRM  */
    INSTR_SINCOS = 284,            /* INSTR_SINCOS  */
    INSTR_M4x4 = 285,              /* INSTR_M4x4  */
    INSTR_M4x3 = 286,              /* INSTR_M4x3  */
    INSTR_M3x4 = 287,              /* INSTR_M3x4  */
    INSTR_M3x3 = 288,              /* INSTR_M3x3  */
    INSTR_M3x2 = 289,              /* INSTR_M3x2  */
    INSTR_DCL = 290,               /* INSTR_DCL  */
    INSTR_DEF = 291,               /* INSTR_DEF  */
    INSTR_DEFB = 292,              /* INSTR_DEFB  */
    INSTR_DEFI = 293,              /* INSTR_DEFI  */
    INSTR_REP = 294,               /* INSTR_REP  */
    INSTR_ENDREP = 295,            /* INSTR_ENDREP  */
    INSTR_IF = 296,                /* INSTR_IF  */
    INSTR_ELSE = 297,              /* INSTR_ELSE  */
    INSTR_ENDIF = 298,             /* INSTR_ENDIF  */
    INSTR_BREAK = 299,             /* INSTR_BREAK  */
    INSTR_BREAKP = 300,            /* INSTR_BREAKP  */
    INSTR_CALL = 301,              /* INSTR_CALL  */
    INSTR_CALLNZ = 302,            /* INSTR_CALLNZ  */
    INSTR_LOOP = 303,              /* INSTR_LOOP  */
    INSTR_RET = 304,               /* INSTR_RET  */
    INSTR_ENDLOOP = 305,           /* INSTR_ENDLOOP  */
    INSTR_LABEL = 306,             /* INSTR_LABEL  */
    INSTR_SETP = 307,              /* INSTR_SETP  */
    INSTR_TEXLDL = 308,            /* INSTR_TEXLDL  */
    INSTR_LIT = 309,               /* INSTR_LIT  */
    INSTR_MOVA = 310,              /* INSTR_MOVA  */
    INSTR_CND = 311,               /* INSTR_CND  */
    INSTR_CMP = 312,               /* INSTR_CMP  */
    INSTR_DP2ADD = 313,            /* INSTR_DP2ADD  */
    INSTR_TEXCOORD = 314,          /* INSTR_TEXCOORD  */
    INSTR_TEXCRD = 315,            /* INSTR_TEXCRD  */
    INSTR_TEXKILL = 316,           /* INSTR_TEXKILL  */
    INSTR_TEX = 317,               /* INSTR_TEX  */
    INSTR_TEXLD = 318,             /* INSTR_TEXLD  */
    INSTR_TEXBEM = 319,            /* INSTR_TEXBEM  */
    INSTR_TEXBEML = 320,           /* INSTR_TEXBEML  */
    INSTR_TEXREG2AR = 321,         /* INSTR_TEXREG2AR  */
    INSTR_TEXREG2GB = 322,         /* INSTR_TEXREG2GB  */
    INSTR_TEXREG2RGB = 323,        /* INSTR_TEXREG2RGB  */
    INSTR_TEXM3x2PAD = 324,        /* INSTR_TEXM3x2PAD  */
    INSTR_TEXM3x2TEX = 325,        /* INSTR_TEXM3x2TEX  */
    INSTR_TEXM3x3PAD = 326,        /* INSTR_TEXM3x3PAD  */
    INSTR_TEXM3x3SPEC = 327,       /* INSTR_TEXM3x3SPEC  */
    INSTR_TEXM3x3VSPEC = 328,      /* INSTR_TEXM3x3VSPEC  */
    INSTR_TEXM3x3TEX = 329,        /* INSTR_TEXM3x3TEX  */
    INSTR_TEXDP3TEX = 330,         /* INSTR_TEXDP3TEX  */
    INSTR_TEXM3x2DEPTH = 331,      /* INSTR_TEXM3x2DEPTH  */
    INSTR_TEXDP3 = 332,            /* INSTR_TEXDP3  */
    INSTR_TEXM3x3 = 333,           /* INSTR_TEXM3x3  */
    INSTR_TEXDEPTH = 334,          /* INSTR_TEXDEPTH  */
    INSTR_BEM = 335,               /* INSTR_BEM  */
    INSTR_DSX = 336,               /* INSTR_DSX  */
    INSTR_DSY = 337,               /* INSTR_DSY  */
    INSTR_TEXLDP = 338,            /* INSTR_TEXLDP  */
    INSTR_TEXLDB = 339,            /* INSTR_TEXLDB  */
    INSTR_TEXLDD = 340,            /* INSTR_TEXLDD  */
    INSTR_PHASE = 341,             /* INSTR_PHASE  */
    REG_TEMP = 342,                /* REG_TEMP  */
    REG_OUTPUT = 343,              /* REG_OUTPUT  */
    REG_INPUT = 344,               /* REG_INPUT  */
    REG_CONSTFLOAT = 345,          /* REG_CONSTFLOAT  */
    REG_CONSTINT = 346,            /* REG_CONSTINT  */
    REG_CONSTBOOL = 347,           /* REG_CONSTBOOL  */
    REG_TEXTURE = 348,             /* REG_TEXTURE  */
    REG_SAMPLER = 349,             /* REG_SAMPLER  */
    REG_TEXCRDOUT = 350,           /* REG_TEXCRDOUT  */
    REG_OPOS = 351,                /* REG_OPOS  */
    REG_OFOG = 352,                /* REG_OFOG  */
    REG_OPTS = 353,                /* REG_OPTS  */
    REG_VERTEXCOLOR = 354,         /* REG_VERTEXCOLOR  */
    REG_FRAGCOLOR = 355,           /* REG_FRAGCOLOR  */
    REG_FRAGDEPTH = 356,           /* REG_FRAGDEPTH  */
    REG_VPOS = 357,                /* REG_VPOS  */
    REG_VFACE = 358,               /* REG_VFACE  */
    REG_ADDRESS = 359,             /* REG_ADDRESS  */
    REG_LOOP = 360,                /* REG_LOOP  */
    REG_PREDICATE = 361,           /* REG_PREDICATE  */
    REG_LABEL = 362,               /* REG_LABEL  */
    VER_VS10 = 363,                /* VER_VS10  */
    VER_VS11 = 364,                /* VER_VS11  */
    VER_VS20 = 365,                /* VER_VS20  */
    VER_VS2X = 366,                /* VER_VS2X  */
    VER_VS30 = 367,                /* VER_VS30  */
    VER_PS10 = 368,                /* VER_PS10  */
    VER_PS11 = 369,                /* VER_PS11  */
    VER_PS12 = 370,                /* VER_PS12  */
    VER_PS13 = 371,                /* VER_PS13  */
    VER_PS14 = 372,                /* VER_PS14  */
    VER_PS20 = 373,                /* VER_PS20  */
    VER_PS2X = 374,                /* VER_PS2X  */
    VER_PS30 = 375,                /* VER_PS30  */
    SHIFT_X2 = 376,                /* SHIFT_X2  */
    SHIFT_X4 = 377,                /* SHIFT_X4  */
    SHIFT_X8 = 378,                /* SHIFT_X8  */
    SHIFT_D2 = 379,                /* SHIFT_D2  */
    SHIFT_D4 = 380,                /* SHIFT_D4  */
    SHIFT_D8 = 381,                /* SHIFT_D8  */
    MOD_SAT = 382,                 /* MOD_SAT  */
    MOD_PP = 383,                  /* MOD_PP  */
    MOD_CENTROID = 384,            /* MOD_CENTROID  */
    COMP_GT = 385,                 /* COMP_GT  */
    COMP_LT = 386,                 /* COMP_LT  */
    COMP_GE = 387,                 /* COMP_GE  */
    COMP_LE = 388,                 /* COMP_LE  */
    COMP_EQ = 389,                 /* COMP_EQ  */
    COMP_NE = 390,                 /* COMP_NE  */
    SMOD_BIAS = 391,               /* SMOD_BIAS  */
    SMOD_SCALEBIAS = 392,          /* SMOD_SCALEBIAS  */
    SMOD_DZ = 393,                 /* SMOD_DZ  */
    SMOD_DW = 394,                 /* SMOD_DW  */
    SMOD_ABS = 395,                /* SMOD_ABS  */
    SMOD_NOT = 396,                /* SMOD_NOT  */
    SAMPTYPE_1D = 397,             /* SAMPTYPE_1D  */
    SAMPTYPE_2D = 398,             /* SAMPTYPE_2D  */
    SAMPTYPE_CUBE = 399,           /* SAMPTYPE_CUBE  */
    SAMPTYPE_VOLUME = 400,         /* SAMPTYPE_VOLUME  */
    USAGE_POSITION = 401,          /* USAGE_POSITION  */
    USAGE_BLENDWEIGHT = 402,       /* USAGE_BLENDWEIGHT  */
    USAGE_BLENDINDICES = 403,      /* USAGE_BLENDINDICES  */
    USAGE_NORMAL = 404,            /* USAGE_NORMAL  */
    USAGE_PSIZE = 405,             /* USAGE_PSIZE  */
    USAGE_TEXCOORD = 406,          /* USAGE_TEXCOORD  */
    USAGE_TANGENT = 407,           /* USAGE_TANGENT  */
    USAGE_BINORMAL = 408,          /* USAGE_BINORMAL  */
    USAGE_TESSFACTOR = 409,        /* USAGE_TESSFACTOR  */
    USAGE_POSITIONT = 410,         /* USAGE_POSITIONT  */
    USAGE_COLOR = 411,             /* USAGE_COLOR  */
    USAGE_FOG = 412,               /* USAGE_FOG  */
    USAGE_DEPTH = 413,             /* USAGE_DEPTH  */
    USAGE_SAMPLE = 414,            /* USAGE_SAMPLE  */
    COMPONENT = 415,               /* COMPONENT  */
    IMMVAL = 416,                  /* IMMVAL  */
    IMMBOOL = 417                  /* IMMBOOL  */
  };
  typedef enum asmshader_tokentype asmshader_token_kind_t;
#endif

/* Value type.  */
#if ! defined ASMSHADER_STYPE && ! defined ASMSHADER_STYPE_IS_DECLARED
union ASMSHADER_STYPE
{
#line 70 "dlls/d3dcompiler_43/asmshader.y"

    struct {
        float           val;
        BOOL            integer;
    } immval;
    BOOL                immbool;
    unsigned int        regnum;
    struct shader_reg   reg;
    uint32_t            srcmod;
    uint32_t            writemask;
    struct {
        uint32_t        writemask;
        uint32_t        idx;
        uint32_t        last;
    } wm_components;
    uint32_t            swizzle;
    struct {
        uint32_t        swizzle;
        uint32_t        idx;
    } sw_components;
    uint32_t            component;
    struct {
        uint32_t        mod;
        uint32_t        shift;
    } modshift;
    enum bwriter_comparison_type comptype;
    struct {
        uint32_t        dclusage;
        unsigned int    regnum;
    } declaration;
    enum bwritersampler_texture_type samplertype;
    struct rel_reg      rel_reg;
    struct src_regs     sregs;

#line 377 "dlls/d3dcompiler_33/asmshader.tab.c"

};
typedef union ASMSHADER_STYPE ASMSHADER_STYPE;
# define ASMSHADER_STYPE_IS_TRIVIAL 1
# define ASMSHADER_STYPE_IS_DECLARED 1
#endif


extern ASMSHADER_STYPE asmshader_lval;


int asmshader_parse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INSTR_ADD = 3,                  /* INSTR_ADD  */
  YYSYMBOL_INSTR_NOP = 4,                  /* INSTR_NOP  */
  YYSYMBOL_INSTR_MOV = 5,                  /* INSTR_MOV  */
  YYSYMBOL_INSTR_SUB = 6,                  /* INSTR_SUB  */
  YYSYMBOL_INSTR_MAD = 7,                  /* INSTR_MAD  */
  YYSYMBOL_INSTR_MUL = 8,                  /* INSTR_MUL  */
  YYSYMBOL_INSTR_RCP = 9,                  /* INSTR_RCP  */
  YYSYMBOL_INSTR_RSQ = 10,                 /* INSTR_RSQ  */
  YYSYMBOL_INSTR_DP3 = 11,                 /* INSTR_DP3  */
  YYSYMBOL_INSTR_DP4 = 12,                 /* INSTR_DP4  */
  YYSYMBOL_INSTR_MIN = 13,                 /* INSTR_MIN  */
  YYSYMBOL_INSTR_MAX = 14,                 /* INSTR_MAX  */
  YYSYMBOL_INSTR_SLT = 15,                 /* INSTR_SLT  */
  YYSYMBOL_INSTR_SGE = 16,                 /* INSTR_SGE  */
  YYSYMBOL_INSTR_ABS = 17,                 /* INSTR_ABS  */
  YYSYMBOL_INSTR_EXP = 18,                 /* INSTR_EXP  */
  YYSYMBOL_INSTR_LOG = 19,                 /* INSTR_LOG  */
  YYSYMBOL_INSTR_EXPP = 20,                /* INSTR_EXPP  */
  YYSYMBOL_INSTR_LOGP = 21,                /* INSTR_LOGP  */
  YYSYMBOL_INSTR_DST = 22,                 /* INSTR_DST  */
  YYSYMBOL_INSTR_LRP = 23,                 /* INSTR_LRP  */
  YYSYMBOL_INSTR_FRC = 24,                 /* INSTR_FRC  */
  YYSYMBOL_INSTR_POW = 25,                 /* INSTR_POW  */
  YYSYMBOL_INSTR_CRS = 26,                 /* INSTR_CRS  */
  YYSYMBOL_INSTR_SGN = 27,                 /* INSTR_SGN  */
  YYSYMBOL_INSTR_NRM = 28,                 /* INSTR_NRM  */
  YYSYMBOL_INSTR_SINCOS = 29,              /* INSTR_SINCOS  */
  YYSYMBOL_INSTR_M4x4 = 30,                /* INSTR_M4x4  */
  YYSYMBOL_INSTR_M4x3 = 31,                /* INSTR_M4x3  */
  YYSYMBOL_INSTR_M3x4 = 32,                /* INSTR_M3x4  */
  YYSYMBOL_INSTR_M3x3 = 33,                /* INSTR_M3x3  */
  YYSYMBOL_INSTR_M3x2 = 34,                /* INSTR_M3x2  */
  YYSYMBOL_INSTR_DCL = 35,                 /* INSTR_DCL  */
  YYSYMBOL_INSTR_DEF = 36,                 /* INSTR_DEF  */
  YYSYMBOL_INSTR_DEFB = 37,                /* INSTR_DEFB  */
  YYSYMBOL_INSTR_DEFI = 38,                /* INSTR_DEFI  */
  YYSYMBOL_INSTR_REP = 39,                 /* INSTR_REP  */
  YYSYMBOL_INSTR_ENDREP = 40,              /* INSTR_ENDREP  */
  YYSYMBOL_INSTR_IF = 41,                  /* INSTR_IF  */
  YYSYMBOL_INSTR_ELSE = 42,                /* INSTR_ELSE  */
  YYSYMBOL_INSTR_ENDIF = 43,               /* INSTR_ENDIF  */
  YYSYMBOL_INSTR_BREAK = 44,               /* INSTR_BREAK  */
  YYSYMBOL_INSTR_BREAKP = 45,              /* INSTR_BREAKP  */
  YYSYMBOL_INSTR_CALL = 46,                /* INSTR_CALL  */
  YYSYMBOL_INSTR_CALLNZ = 47,              /* INSTR_CALLNZ  */
  YYSYMBOL_INSTR_LOOP = 48,                /* INSTR_LOOP  */
  YYSYMBOL_INSTR_RET = 49,                 /* INSTR_RET  */
  YYSYMBOL_INSTR_ENDLOOP = 50,             /* INSTR_ENDLOOP  */
  YYSYMBOL_INSTR_LABEL = 51,               /* INSTR_LABEL  */
  YYSYMBOL_INSTR_SETP = 52,                /* INSTR_SETP  */
  YYSYMBOL_INSTR_TEXLDL = 53,              /* INSTR_TEXLDL  */
  YYSYMBOL_INSTR_LIT = 54,                 /* INSTR_LIT  */
  YYSYMBOL_INSTR_MOVA = 55,                /* INSTR_MOVA  */
  YYSYMBOL_INSTR_CND = 56,                 /* INSTR_CND  */
  YYSYMBOL_INSTR_CMP = 57,                 /* INSTR_CMP  */
  YYSYMBOL_INSTR_DP2ADD = 58,              /* INSTR_DP2ADD  */
  YYSYMBOL_INSTR_TEXCOORD = 59,            /* INSTR_TEXCOORD  */
  YYSYMBOL_INSTR_TEXCRD = 60,              /* INSTR_TEXCRD  */
  YYSYMBOL_INSTR_TEXKILL = 61,             /* INSTR_TEXKILL  */
  YYSYMBOL_INSTR_TEX = 62,                 /* INSTR_TEX  */
  YYSYMBOL_INSTR_TEXLD = 63,               /* INSTR_TEXLD  */
  YYSYMBOL_INSTR_TEXBEM = 64,              /* INSTR_TEXBEM  */
  YYSYMBOL_INSTR_TEXBEML = 65,             /* INSTR_TEXBEML  */
  YYSYMBOL_INSTR_TEXREG2AR = 66,           /* INSTR_TEXREG2AR  */
  YYSYMBOL_INSTR_TEXREG2GB = 67,           /* INSTR_TEXREG2GB  */
  YYSYMBOL_INSTR_TEXREG2RGB = 68,          /* INSTR_TEXREG2RGB  */
  YYSYMBOL_INSTR_TEXM3x2PAD = 69,          /* INSTR_TEXM3x2PAD  */
  YYSYMBOL_INSTR_TEXM3x2TEX = 70,          /* INSTR_TEXM3x2TEX  */
  YYSYMBOL_INSTR_TEXM3x3PAD = 71,          /* INSTR_TEXM3x3PAD  */
  YYSYMBOL_INSTR_TEXM3x3SPEC = 72,         /* INSTR_TEXM3x3SPEC  */
  YYSYMBOL_INSTR_TEXM3x3VSPEC = 73,        /* INSTR_TEXM3x3VSPEC  */
  YYSYMBOL_INSTR_TEXM3x3TEX = 74,          /* INSTR_TEXM3x3TEX  */
  YYSYMBOL_INSTR_TEXDP3TEX = 75,           /* INSTR_TEXDP3TEX  */
  YYSYMBOL_INSTR_TEXM3x2DEPTH = 76,        /* INSTR_TEXM3x2DEPTH  */
  YYSYMBOL_INSTR_TEXDP3 = 77,              /* INSTR_TEXDP3  */
  YYSYMBOL_INSTR_TEXM3x3 = 78,             /* INSTR_TEXM3x3  */
  YYSYMBOL_INSTR_TEXDEPTH = 79,            /* INSTR_TEXDEPTH  */
  YYSYMBOL_INSTR_BEM = 80,                 /* INSTR_BEM  */
  YYSYMBOL_INSTR_DSX = 81,                 /* INSTR_DSX  */
  YYSYMBOL_INSTR_DSY = 82,                 /* INSTR_DSY  */
  YYSYMBOL_INSTR_TEXLDP = 83,              /* INSTR_TEXLDP  */
  YYSYMBOL_INSTR_TEXLDB = 84,              /* INSTR_TEXLDB  */
  YYSYMBOL_INSTR_TEXLDD = 85,              /* INSTR_TEXLDD  */
  YYSYMBOL_INSTR_PHASE = 86,               /* INSTR_PHASE  */
  YYSYMBOL_REG_TEMP = 87,                  /* REG_TEMP  */
  YYSYMBOL_REG_OUTPUT = 88,                /* REG_OUTPUT  */
  YYSYMBOL_REG_INPUT = 89,                 /* REG_INPUT  */
  YYSYMBOL_REG_CONSTFLOAT = 90,            /* REG_CONSTFLOAT  */
  YYSYMBOL_REG_CONSTINT = 91,              /* REG_CONSTINT  */
  YYSYMBOL_REG_CONSTBOOL = 92,             /* REG_CONSTBOOL  */
  YYSYMBOL_REG_TEXTURE = 93,               /* REG_TEXTURE  */
  YYSYMBOL_REG_SAMPLER = 94,               /* REG_SAMPLER  */
  YYSYMBOL_REG_TEXCRDOUT = 95,             /* REG_TEXCRDOUT  */
  YYSYMBOL_REG_OPOS = 96,                  /* REG_OPOS  */
  YYSYMBOL_REG_OFOG = 97,                  /* REG_OFOG  */
  YYSYMBOL_REG_OPTS = 98,                  /* REG_OPTS  */
  YYSYMBOL_REG_VERTEXCOLOR = 99,           /* REG_VERTEXCOLOR  */
  YYSYMBOL_REG_FRAGCOLOR = 100,            /* REG_FRAGCOLOR  */
  YYSYMBOL_REG_FRAGDEPTH = 101,            /* REG_FRAGDEPTH  */
  YYSYMBOL_REG_VPOS = 102,                 /* REG_VPOS  */
  YYSYMBOL_REG_VFACE = 103,                /* REG_VFACE  */
  YYSYMBOL_REG_ADDRESS = 104,              /* REG_ADDRESS  */
  YYSYMBOL_REG_LOOP = 105,                 /* REG_LOOP  */
  YYSYMBOL_REG_PREDICATE = 106,            /* REG_PREDICATE  */
  YYSYMBOL_REG_LABEL = 107,                /* REG_LABEL  */
  YYSYMBOL_VER_VS10 = 108,                 /* VER_VS10  */
  YYSYMBOL_VER_VS11 = 109,                 /* VER_VS11  */
  YYSYMBOL_VER_VS20 = 110,                 /* VER_VS20  */
  YYSYMBOL_VER_VS2X = 111,                 /* VER_VS2X  */
  YYSYMBOL_VER_VS30 = 112,                 /* VER_VS30  */
  YYSYMBOL_VER_PS10 = 113,                 /* VER_PS10  */
  YYSYMBOL_VER_PS11 = 114,                 /* VER_PS11  */
  YYSYMBOL_VER_PS12 = 115,                 /* VER_PS12  */
  YYSYMBOL_VER_PS13 = 116,                 /* VER_PS13  */
  YYSYMBOL_VER_PS14 = 117,                 /* VER_PS14  */
  YYSYMBOL_VER_PS20 = 118,                 /* VER_PS20  */
  YYSYMBOL_VER_PS2X = 119,                 /* VER_PS2X  */
  YYSYMBOL_VER_PS30 = 120,                 /* VER_PS30  */
  YYSYMBOL_SHIFT_X2 = 121,                 /* SHIFT_X2  */
  YYSYMBOL_SHIFT_X4 = 122,                 /* SHIFT_X4  */
  YYSYMBOL_SHIFT_X8 = 123,                 /* SHIFT_X8  */
  YYSYMBOL_SHIFT_D2 = 124,                 /* SHIFT_D2  */
  YYSYMBOL_SHIFT_D4 = 125,                 /* SHIFT_D4  */
  YYSYMBOL_SHIFT_D8 = 126,                 /* SHIFT_D8  */
  YYSYMBOL_MOD_SAT = 127,                  /* MOD_SAT  */
  YYSYMBOL_MOD_PP = 128,                   /* MOD_PP  */
  YYSYMBOL_MOD_CENTROID = 129,             /* MOD_CENTROID  */
  YYSYMBOL_COMP_GT = 130,                  /* COMP_GT  */
  YYSYMBOL_COMP_LT = 131,                  /* COMP_LT  */
  YYSYMBOL_COMP_GE = 132,                  /* COMP_GE  */
  YYSYMBOL_COMP_LE = 133,                  /* COMP_LE  */
  YYSYMBOL_COMP_EQ = 134,                  /* COMP_EQ  */
  YYSYMBOL_COMP_NE = 135,                  /* COMP_NE  */
  YYSYMBOL_SMOD_BIAS = 136,                /* SMOD_BIAS  */
  YYSYMBOL_SMOD_SCALEBIAS = 137,           /* SMOD_SCALEBIAS  */
  YYSYMBOL_SMOD_DZ = 138,                  /* SMOD_DZ  */
  YYSYMBOL_SMOD_DW = 139,                  /* SMOD_DW  */
  YYSYMBOL_SMOD_ABS = 140,                 /* SMOD_ABS  */
  YYSYMBOL_SMOD_NOT = 141,                 /* SMOD_NOT  */
  YYSYMBOL_SAMPTYPE_1D = 142,              /* SAMPTYPE_1D  */
  YYSYMBOL_SAMPTYPE_2D = 143,              /* SAMPTYPE_2D  */
  YYSYMBOL_SAMPTYPE_CUBE = 144,            /* SAMPTYPE_CUBE  */
  YYSYMBOL_SAMPTYPE_VOLUME = 145,          /* SAMPTYPE_VOLUME  */
  YYSYMBOL_USAGE_POSITION = 146,           /* USAGE_POSITION  */
  YYSYMBOL_USAGE_BLENDWEIGHT = 147,        /* USAGE_BLENDWEIGHT  */
  YYSYMBOL_USAGE_BLENDINDICES = 148,       /* USAGE_BLENDINDICES  */
  YYSYMBOL_USAGE_NORMAL = 149,             /* USAGE_NORMAL  */
  YYSYMBOL_USAGE_PSIZE = 150,              /* USAGE_PSIZE  */
  YYSYMBOL_USAGE_TEXCOORD = 151,           /* USAGE_TEXCOORD  */
  YYSYMBOL_USAGE_TANGENT = 152,            /* USAGE_TANGENT  */
  YYSYMBOL_USAGE_BINORMAL = 153,           /* USAGE_BINORMAL  */
  YYSYMBOL_USAGE_TESSFACTOR = 154,         /* USAGE_TESSFACTOR  */
  YYSYMBOL_USAGE_POSITIONT = 155,          /* USAGE_POSITIONT  */
  YYSYMBOL_USAGE_COLOR = 156,              /* USAGE_COLOR  */
  YYSYMBOL_USAGE_FOG = 157,                /* USAGE_FOG  */
  YYSYMBOL_USAGE_DEPTH = 158,              /* USAGE_DEPTH  */
  YYSYMBOL_USAGE_SAMPLE = 159,             /* USAGE_SAMPLE  */
  YYSYMBOL_COMPONENT = 160,                /* COMPONENT  */
  YYSYMBOL_IMMVAL = 161,                   /* IMMVAL  */
  YYSYMBOL_IMMBOOL = 162,                  /* IMMBOOL  */
  YYSYMBOL_163_ = 163,                     /* '+'  */
  YYSYMBOL_164_ = 164,                     /* ','  */
  YYSYMBOL_165_ = 165,                     /* '.'  */
  YYSYMBOL_166_ = 166,                     /* '-'  */
  YYSYMBOL_167_ = 167,                     /* '['  */
  YYSYMBOL_168_ = 168,                     /* ']'  */
  YYSYMBOL_169_ = 169,                     /* '('  */
  YYSYMBOL_170_ = 170,                     /* ')'  */
  YYSYMBOL_YYACCEPT = 171,                 /* $accept  */
  YYSYMBOL_shader = 172,                   /* shader  */
  YYSYMBOL_version_marker = 173,           /* version_marker  */
  YYSYMBOL_instructions = 174,             /* instructions  */
  YYSYMBOL_complexinstr = 175,             /* complexinstr  */
  YYSYMBOL_instruction = 176,              /* instruction  */
  YYSYMBOL_dreg = 177,                     /* dreg  */
  YYSYMBOL_dreg_name = 178,                /* dreg_name  */
  YYSYMBOL_writemask = 179,                /* writemask  */
  YYSYMBOL_wm_components = 180,            /* wm_components  */
  YYSYMBOL_swizzle = 181,                  /* swizzle  */
  YYSYMBOL_sw_components = 182,            /* sw_components  */
  YYSYMBOL_omods = 183,                    /* omods  */
  YYSYMBOL_omodifier = 184,                /* omodifier  */
  YYSYMBOL_sregs = 185,                    /* sregs  */
  YYSYMBOL_sreg = 186,                     /* sreg  */
  YYSYMBOL_rel_reg = 187,                  /* rel_reg  */
  YYSYMBOL_immsum = 188,                   /* immsum  */
  YYSYMBOL_signed_integer = 189,           /* signed_integer  */
  YYSYMBOL_signed_float = 190,             /* signed_float  */
  YYSYMBOL_smod = 191,                     /* smod  */
  YYSYMBOL_relreg_name = 192,              /* relreg_name  */
  YYSYMBOL_sreg_name = 193,                /* sreg_name  */
  YYSYMBOL_comp = 194,                     /* comp  */
  YYSYMBOL_dclusage = 195,                 /* dclusage  */
  YYSYMBOL_dcl_inputreg = 196,             /* dcl_inputreg  */
  YYSYMBOL_sampdcl = 197,                  /* sampdcl  */
  YYSYMBOL_predicate = 198                 /* predicate  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined ASMSHADER_STYPE_IS_TRIVIAL && ASMSHADER_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  171
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  560

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   417


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     169,   170,     2,   163,   164,   166,   165,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   167,     2,   168,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162
};

#if ASMSHADER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   313,   313,   318,   323,   328,   333,   338,   343,   348,
     353,   358,   363,   368,   373,   378,   384,   385,   390,   394,
     399,   405,   410,   415,   420,   425,   430,   435,   440,   445,
     450,   455,   460,   465,   470,   475,   480,   485,   490,   495,
     500,   505,   510,   515,   520,   525,   530,   535,   540,   545,
     550,   555,   560,   565,   577,   589,   612,   635,   657,   679,
     689,   704,   711,   718,   722,   726,   730,   735,   740,   745,
     750,   755,   760,   765,   770,   775,   780,   785,   790,   795,
     800,   805,   810,   815,   820,   825,   830,   835,   840,   845,
     851,   856,   861,   866,   877,   882,   887,   892,   897,   902,
     907,   912,   917,   922,   927,   932,   937,   942,   947,   952,
     957,   962,   967,   972,   977,   982,   989,   997,  1006,  1010,
    1014,  1018,  1024,  1030,  1036,  1040,  1044,  1050,  1054,  1058,
    1062,  1066,  1070,  1074,  1078,  1084,  1090,  1095,  1102,  1117,
    1123,  1139,  1143,  1165,  1170,  1184,  1188,  1201,  1206,  1211,
    1216,  1221,  1226,  1231,  1236,  1241,  1247,  1252,  1263,  1271,
    1279,  1287,  1312,  1326,  1340,  1350,  1354,  1359,  1367,  1375,
    1383,  1392,  1393,  1397,  1403,  1413,  1425,  1429,  1434,  1438,
    1442,  1446,  1450,  1454,  1459,  1463,  1468,  1472,  1478,  1482,
    1486,  1490,  1494,  1498,  1504,  1508,  1514,  1520,  1526,  1532,
    1538,  1542,  1546,  1550,  1554,  1558,  1563,  1564,  1565,  1566,
    1567,  1568,  1570,  1576,  1582,  1588,  1594,  1600,  1606,  1612,
    1618,  1624,  1630,  1636,  1642,  1648,  1655,  1659,  1664,  1668,
    1672,  1676,  1681,  1689
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if ASMSHADER_DEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INSTR_ADD",
  "INSTR_NOP", "INSTR_MOV", "INSTR_SUB", "INSTR_MAD", "INSTR_MUL",
  "INSTR_RCP", "INSTR_RSQ", "INSTR_DP3", "INSTR_DP4", "INSTR_MIN",
  "INSTR_MAX", "INSTR_SLT", "INSTR_SGE", "INSTR_ABS", "INSTR_EXP",
  "INSTR_LOG", "INSTR_EXPP", "INSTR_LOGP", "INSTR_DST", "INSTR_LRP",
  "INSTR_FRC", "INSTR_POW", "INSTR_CRS", "INSTR_SGN", "INSTR_NRM",
  "INSTR_SINCOS", "INSTR_M4x4", "INSTR_M4x3", "INSTR_M3x4", "INSTR_M3x3",
  "INSTR_M3x2", "INSTR_DCL", "INSTR_DEF", "INSTR_DEFB", "INSTR_DEFI",
  "INSTR_REP", "INSTR_ENDREP", "INSTR_IF", "INSTR_ELSE", "INSTR_ENDIF",
  "INSTR_BREAK", "INSTR_BREAKP", "INSTR_CALL", "INSTR_CALLNZ",
  "INSTR_LOOP", "INSTR_RET", "INSTR_ENDLOOP", "INSTR_LABEL", "INSTR_SETP",
  "INSTR_TEXLDL", "INSTR_LIT", "INSTR_MOVA", "INSTR_CND", "INSTR_CMP",
  "INSTR_DP2ADD", "INSTR_TEXCOORD", "INSTR_TEXCRD", "INSTR_TEXKILL",
  "INSTR_TEX", "INSTR_TEXLD", "INSTR_TEXBEM", "INSTR_TEXBEML",
  "INSTR_TEXREG2AR", "INSTR_TEXREG2GB", "INSTR_TEXREG2RGB",
  "INSTR_TEXM3x2PAD", "INSTR_TEXM3x2TEX", "INSTR_TEXM3x3PAD",
  "INSTR_TEXM3x3SPEC", "INSTR_TEXM3x3VSPEC", "INSTR_TEXM3x3TEX",
  "INSTR_TEXDP3TEX", "INSTR_TEXM3x2DEPTH", "INSTR_TEXDP3", "INSTR_TEXM3x3",
  "INSTR_TEXDEPTH", "INSTR_BEM", "INSTR_DSX", "INSTR_DSY", "INSTR_TEXLDP",
  "INSTR_TEXLDB", "INSTR_TEXLDD", "INSTR_PHASE", "REG_TEMP", "REG_OUTPUT",
  "REG_INPUT", "REG_CONSTFLOAT", "REG_CONSTINT", "REG_CONSTBOOL",
  "REG_TEXTURE", "REG_SAMPLER", "REG_TEXCRDOUT", "REG_OPOS", "REG_OFOG",
  "REG_OPTS", "REG_VERTEXCOLOR", "REG_FRAGCOLOR", "REG_FRAGDEPTH",
  "REG_VPOS", "REG_VFACE", "REG_ADDRESS", "REG_LOOP", "REG_PREDICATE",
  "REG_LABEL", "VER_VS10", "VER_VS11", "VER_VS20", "VER_VS2X", "VER_VS30",
  "VER_PS10", "VER_PS11", "VER_PS12", "VER_PS13", "VER_PS14", "VER_PS20",
  "VER_PS2X", "VER_PS30", "SHIFT_X2", "SHIFT_X4", "SHIFT_X8", "SHIFT_D2",
  "SHIFT_D4", "SHIFT_D8", "MOD_SAT", "MOD_PP", "MOD_CENTROID", "COMP_GT",
  "COMP_LT", "COMP_GE", "COMP_LE", "COMP_EQ", "COMP_NE", "SMOD_BIAS",
  "SMOD_SCALEBIAS", "SMOD_DZ", "SMOD_DW", "SMOD_ABS", "SMOD_NOT",
  "SAMPTYPE_1D", "SAMPTYPE_2D", "SAMPTYPE_CUBE", "SAMPTYPE_VOLUME",
  "USAGE_POSITION", "USAGE_BLENDWEIGHT", "USAGE_BLENDINDICES",
  "USAGE_NORMAL", "USAGE_PSIZE", "USAGE_TEXCOORD", "USAGE_TANGENT",
  "USAGE_BINORMAL", "USAGE_TESSFACTOR", "USAGE_POSITIONT", "USAGE_COLOR",
  "USAGE_FOG", "USAGE_DEPTH", "USAGE_SAMPLE", "COMPONENT", "IMMVAL",
  "IMMBOOL", "'+'", "','", "'.'", "'-'", "'['", "']'", "'('", "')'",
  "$accept", "shader", "version_marker", "instructions", "complexinstr",
  "instruction", "dreg", "dreg_name", "writemask", "wm_components",
  "swizzle", "sw_components", "omods", "omodifier", "sregs", "sreg",
  "rel_reg", "immsum", "signed_integer", "signed_float", "smod",
  "relreg_name", "sreg_name", "comp", "dclusage", "dcl_inputreg",
  "sampdcl", "predicate", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-533)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     628,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,    20,  -533,  -533,   393,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
     576,   -12,   -26,   -38,   -32,  -533,   394,  -533,  -533,   -39,
     -32,   -32,   -32,   -32,  -533,  -533,   -32,   -39,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,   250,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,   560,   -89,  -533,  -533,   560,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,   579,     1,  -533,   -54,
     -51,   -50,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,   192,   -41,   192,   -31,  -533,   -29,  -533,  -533,
    -533,  -533,  -533,  -533,   -31,   -32,   -32,   -31,   -31,   -31,
     -31,   -31,   250,   561,   561,   561,   561,   561,   561,   561,
     561,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
    -533,  -533,   -88,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,  -533,   -30,    22,
    -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,  -533,
     -28,  -533,   -20,   -19,   -18,     7,     8,     9,    11,    12,
      13,    14,    15,    16,    18,    19,    23,    25,    27,    28,
      29,    30,    31,    32,    33,    65,    66,    67,    69,    72,
      73,    74,  -533,  -533,  -533,    75,    75,   588,   424,   -62,
      77,   -55,   -30,   192,   -29,   -32,   -24,   371,   -31,   -31,
      79,    80,    90,   126,   136,   137,   138,  -533,   170,    24,
    -533,  -533,  -533,   193,   194,   195,   196,   197,   198,   199,
     208,   209,   316,   338,   339,   340,   341,   342,   350,  -533,
     351,   352,   355,   356,   357,   358,    81,   353,   -30,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
    -533,  -533,    75,  -533,  -533,  -533,  -533,   369,   367,  -533,
    -533,   372,   368,  -533,   -29,   371,  -533,  -533,  -533,   -81,
    -533,   -30,  -533,  -533,  -533,  -533,  -533,  -533,  -533,   -30,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,  -533,   374,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,  -533,   377,  -533,   370,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,  -533,  -533,   -62,
    -533,   -55,   371,  -533,   -30,   -24,   -55,  -533,   -37,  -533,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,  -533,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,  -533,  -533,   375,   378,  -533,   -30,  -533,  -533,   -30,
    -533,   -55,  -533,   -62,   -55,  -533,   -36,   -80,   379,   380,
     -55,  -533,   -55,  -533,   -62,   -55,   -63,  -533,  -533,  -533
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,    16,     1,     2,   145,    22,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,     0,     0,     0,     0,    67,     0,    70,    71,    72,
       0,     0,     0,     0,    78,    79,     0,     0,   145,   145,
     145,   145,   145,   145,   145,   145,     0,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   115,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   228,   229,
     230,   231,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,     0,   145,   145,     0,
       0,     0,   186,   187,   188,   189,   190,   191,   192,   194,
     193,   195,   196,   197,   198,   199,   201,   202,   203,   204,
     200,   205,     0,     0,     0,    66,   156,   165,   206,   207,
     208,   209,   210,   211,    68,     0,     0,    74,    75,    76,
      77,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   126,   125,
     127,   129,   128,   130,   131,   132,   134,   135,   136,   137,
     133,    90,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,   141,     0,
      19,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   227,    60,    57,    53,     0,     0,     0,
       0,     0,   141,     0,   165,     0,     0,   141,    69,    73,
       0,     0,     0,     0,     0,     0,     0,    88,     0,     0,
     117,   116,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    54,    55,    62,    59,    61,   176,     0,     0,    65,
     174,     0,     0,   164,   165,   141,   157,   184,   185,     0,
     171,   141,   179,   178,   180,   181,   182,   183,   158,   141,
       0,     0,     0,     0,     0,     0,     0,     0,   139,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   142,   232,     0,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    39,    38,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    56,   177,     0,
     175,     0,   141,   160,   141,     0,     0,   166,     0,   159,
      81,    82,    83,    84,    85,    86,    87,    89,   140,    93,
      96,    97,    98,    99,   100,   101,   108,   102,   103,   104,
     105,   106,   107,   109,   110,   111,   112,   113,    94,    95,
     114,   144,   233,     0,     0,   162,   141,   161,   172,   141,
     173,     0,   167,     0,     0,   163,     0,     0,     0,     0,
       0,   168,     0,   169,     0,     0,     0,    63,    64,   170
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -533,  -533,  -533,  -533,  -533,     6,   -86,  -533,  -290,  -533,
    -304,  -533,   178,  -533,   -56,   223,  -230,  -532,  -310,  -413,
    -402,    46,  -170,   -48,  -533,  -210,  -533,  -533
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    14,    15,    17,   104,   105,   231,   232,   330,   429,
     357,   453,   107,   271,   185,   186,   317,   409,   410,   398,
     419,   411,   187,   195,   157,   305,   158,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     194,   402,   331,   494,   197,   198,   199,   200,   403,   547,
     201,   196,   312,   418,   314,   390,   391,   258,   556,   202,
      16,   270,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   259,   161,   455,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   160,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   533,   329,   159,   316,
     407,   408,   495,   552,   405,   496,   496,   497,   553,   306,
     536,   188,   189,   190,   191,   192,   193,   392,   395,   396,
     552,   493,   487,   496,   397,   559,   400,   498,   257,   182,
     309,   401,   260,   310,   311,   499,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   313,   541,   550,   358,   183,
     548,   542,   551,   315,   184,   356,   359,   400,   316,   318,
     319,   557,   401,   404,   360,   361,   362,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   363,   364,   365,   492,   366,   367,   368,   369,   370,
     371,   534,   372,   373,   428,   538,   540,   374,   535,   375,
     537,   376,   377,   378,   379,   380,   381,   382,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   156,   383,
     384,   385,   545,   386,   549,   546,   387,   388,   389,   399,
     329,   452,   538,   420,   421,   558,   203,   204,   205,   206,
     207,   208,   209,   210,   422,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     423,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     424,   425,   426,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   427,   307,   308,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   430,   431,   432,
     433,   434,   435,   436,   500,   501,   502,   503,   504,   505,
     506,   507,   437,   438,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     439,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   412,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   440,   441,   442,   443,   444,   413,   414,   415,
     416,   417,   393,   302,   445,   446,   447,   303,   394,   448,
     449,   450,   451,   454,   188,   189,   190,   191,   192,   193,
     488,   489,   491,   490,   508,   182,   356,   531,   406,   543,
     532,   539,   544,   554,   555,   261,   262,   263,   264,   265,
     266,   267,   268,   269,     0,   183,   102,     0,     0,     0,
     184,     0,   103,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   302,     0,
       0,     0,   303,   304,     0,     0,     0,   302,     0,     0,
       0,   303,   261,   262,   263,   264,   265,   266,   267,   268,
     269,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

static const yytype_int16 yycheck[] =
{
      56,   311,   232,   405,    60,    61,    62,    63,   312,   541,
      66,    59,   182,   317,   184,   305,   306,   106,   550,    67,
       0,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   141,    91,   358,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    92,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   489,   165,    90,   167,
     104,   105,   163,   163,   314,   166,   166,   168,   168,    88,
     492,   130,   131,   132,   133,   134,   135,   307,   308,   161,
     163,   405,   392,   166,   166,   168,   161,   411,   102,   141,
     164,   166,   106,   164,   164,   419,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   166,   163,   163,   106,   161,
     543,   168,   168,   164,   166,   165,   164,   161,   167,   195,
     196,   554,   166,   313,   164,   164,   164,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   164,   164,   164,   404,   164,   164,   164,   164,   164,
     164,   491,   164,   164,   160,   495,   496,   164,   492,   164,
     494,   164,   164,   164,   164,   164,   164,   164,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,   164,
     164,   164,   536,   164,   544,   539,   164,   164,   164,   162,
     165,   160,   552,   164,   164,   555,    68,    69,    70,    71,
      72,    73,    74,    75,   164,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     164,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     164,   164,   164,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   164,   157,   158,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   164,   164,   164,
     164,   164,   164,   164,   420,   421,   422,   423,   424,   425,
     426,   427,   164,   164,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
     164,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   121,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   164,   164,   164,   164,   164,   136,   137,   138,
     139,   140,    88,    89,   164,   164,   164,    93,    94,   164,
     164,   164,   164,   170,   130,   131,   132,   133,   134,   135,
     161,   164,   164,   161,   160,   141,   165,   160,   315,   164,
     170,   495,   164,   164,   164,   121,   122,   123,   124,   125,
     126,   127,   128,   129,    -1,   161,   163,    -1,    -1,    -1,
     166,    -1,   169,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    -1,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    89,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   172,   173,     0,   174,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,   163,   169,   175,   176,   198,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   183,   195,   197,    90,
      92,    91,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   141,   161,   166,   185,   186,   193,   130,   131,
     132,   133,   134,   135,   185,   194,   194,   185,   185,   185,
     185,   185,   194,   183,   183,   183,   183,   183,   183,   183,
     183,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   177,   178,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   176,   106,   141,
     176,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     177,   184,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,    89,    93,    94,   196,    88,   183,   183,   164,
     164,   164,   193,   166,   193,   164,   167,   187,   185,   185,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   165,
     179,   187,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   165,   181,   106,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     179,   179,   196,    88,    94,   196,   161,   166,   190,   162,
     161,   166,   189,   181,   193,   187,   186,   104,   105,   188,
     189,   192,   121,   136,   137,   138,   139,   140,   181,   191,
     164,   164,   164,   164,   164,   164,   164,   164,   160,   180,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   160,   182,   170,   181,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   179,   161,   164,
     161,   164,   187,   181,   191,   163,   166,   168,   181,   181,
     185,   185,   185,   185,   185,   185,   185,   185,   160,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   160,   170,   190,   189,   181,   191,   181,   189,   192,
     189,   163,   168,   164,   164,   181,   181,   188,   190,   189,
     163,   168,   163,   168,   164,   164,   188,   190,   189,   168
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   171,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175,   175,
     175,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   177,   177,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   186,   186,
     186,   186,   186,   186,   186,   187,   187,   187,   187,   187,
     187,   188,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   191,   191,   191,   192,   192,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   194,   194,   194,   194,
     194,   194,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   196,   196,   197,   197,
     197,   197,   198,   198
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     2,
       2,     5,     1,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     3,     4,     4,     5,     3,     4,     4,
       3,     4,     4,    10,    10,     4,     2,     1,     2,     3,
       1,     1,     1,     3,     2,     2,     2,     2,     1,     1,
       2,     5,     5,     5,     5,     5,     5,     5,     3,     5,
       2,     3,     3,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     0,     2,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     5,     5,     6,     3,     0,     3,     4,     6,     6,
       8,     1,     3,     3,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = ASMSHADER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == ASMSHADER_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use ASMSHADER_error or ASMSHADER_UNDEF. */
#define YYERRCODE ASMSHADER_UNDEF


/* Enable debugging if requested.  */
#if ASMSHADER_DEBUG

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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !ASMSHADER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !ASMSHADER_DEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  yychar = ASMSHADER_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == ASMSHADER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= ASMSHADER_EOF)
    {
      yychar = ASMSHADER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == ASMSHADER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = ASMSHADER_UNDEF;
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
  yychar = ASMSHADER_EMPTY;
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
  case 2: /* shader: version_marker instructions  */
#line 314 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asm_ctx.funcs->end(&asm_ctx);
                        }
#line 1984 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 3: /* version_marker: VER_VS10  */
#line 319 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Vertex shader 1.0\n");
                            create_vs10_parser(&asm_ctx);
                        }
#line 1993 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 4: /* version_marker: VER_VS11  */
#line 324 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Vertex shader 1.1\n");
                            create_vs11_parser(&asm_ctx);
                        }
#line 2002 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 5: /* version_marker: VER_VS20  */
#line 329 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Vertex shader 2.0\n");
                            create_vs20_parser(&asm_ctx);
                        }
#line 2011 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 6: /* version_marker: VER_VS2X  */
#line 334 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Vertex shader 2.x\n");
                            create_vs2x_parser(&asm_ctx);
                        }
#line 2020 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 7: /* version_marker: VER_VS30  */
#line 339 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Vertex shader 3.0\n");
                            create_vs30_parser(&asm_ctx);
                        }
#line 2029 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 8: /* version_marker: VER_PS10  */
#line 344 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 1.0\n");
                            create_ps10_parser(&asm_ctx);
                        }
#line 2038 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 9: /* version_marker: VER_PS11  */
#line 349 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 1.1\n");
                            create_ps11_parser(&asm_ctx);
                        }
#line 2047 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 10: /* version_marker: VER_PS12  */
#line 354 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 1.2\n");
                            create_ps12_parser(&asm_ctx);
                        }
#line 2056 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 11: /* version_marker: VER_PS13  */
#line 359 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 1.3\n");
                            create_ps13_parser(&asm_ctx);
                        }
#line 2065 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 12: /* version_marker: VER_PS14  */
#line 364 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 1.4\n");
                            create_ps14_parser(&asm_ctx);
                        }
#line 2074 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 13: /* version_marker: VER_PS20  */
#line 369 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 2.0\n");
                            create_ps20_parser(&asm_ctx);
                        }
#line 2083 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 14: /* version_marker: VER_PS2X  */
#line 374 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 2.x\n");
                            create_ps2x_parser(&asm_ctx);
                        }
#line 2092 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 15: /* version_marker: VER_PS30  */
#line 379 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("Pixel  shader 3.0\n");
                            create_ps30_parser(&asm_ctx);
                        }
#line 2101 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 17: /* instructions: instructions complexinstr  */
#line 386 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                /* Nothing to do */
                            }
#line 2109 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 18: /* complexinstr: instruction  */
#line 391 "dlls/d3dcompiler_43/asmshader.y"
                            {

                            }
#line 2117 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 19: /* complexinstr: predicate instruction  */
#line 395 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("predicate\n");
                                asm_ctx.funcs->predicate(&asm_ctx, &(yyvsp[-1].reg));
                            }
#line 2126 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 20: /* complexinstr: '+' instruction  */
#line 400 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("coissue\n");
                                asm_ctx.funcs->coissue(&asm_ctx);
                            }
#line 2135 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 21: /* instruction: INSTR_ADD omods dreg ',' sregs  */
#line 406 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ADD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ADD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2144 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 22: /* instruction: INSTR_NOP  */
#line 411 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("NOP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_NOP, 0, 0, 0, 0, 0, 0);
                            }
#line 2153 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 23: /* instruction: INSTR_MOV omods dreg ',' sregs  */
#line 416 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MOV\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MOV, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2162 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 24: /* instruction: INSTR_SUB omods dreg ',' sregs  */
#line 421 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SUB\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SUB, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2171 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 25: /* instruction: INSTR_MAD omods dreg ',' sregs  */
#line 426 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MAD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MAD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2180 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 26: /* instruction: INSTR_MUL omods dreg ',' sregs  */
#line 431 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MUL\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MUL, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2189 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 27: /* instruction: INSTR_RCP omods dreg ',' sregs  */
#line 436 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("RCP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_RCP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2198 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 28: /* instruction: INSTR_RSQ omods dreg ',' sregs  */
#line 441 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("RSQ\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_RSQ, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2207 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 29: /* instruction: INSTR_DP3 omods dreg ',' sregs  */
#line 446 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DP3\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DP3, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2216 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 30: /* instruction: INSTR_DP4 omods dreg ',' sregs  */
#line 451 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DP4\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DP4, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2225 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 31: /* instruction: INSTR_MIN omods dreg ',' sregs  */
#line 456 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MIN\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MIN, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2234 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 32: /* instruction: INSTR_MAX omods dreg ',' sregs  */
#line 461 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MAX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MAX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2243 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 33: /* instruction: INSTR_SLT omods dreg ',' sregs  */
#line 466 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SLT\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SLT, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2252 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 34: /* instruction: INSTR_SGE omods dreg ',' sregs  */
#line 471 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SGE\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SGE, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2261 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 35: /* instruction: INSTR_ABS omods dreg ',' sregs  */
#line 476 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ABS\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ABS, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2270 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 36: /* instruction: INSTR_EXP omods dreg ',' sregs  */
#line 481 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("EXP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_EXP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2279 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 37: /* instruction: INSTR_LOG omods dreg ',' sregs  */
#line 486 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LOG\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LOG, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2288 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 38: /* instruction: INSTR_LOGP omods dreg ',' sregs  */
#line 491 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LOGP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LOGP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2297 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 39: /* instruction: INSTR_EXPP omods dreg ',' sregs  */
#line 496 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("EXPP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_EXPP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2306 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 40: /* instruction: INSTR_DST omods dreg ',' sregs  */
#line 501 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DST\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DST, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2315 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 41: /* instruction: INSTR_LRP omods dreg ',' sregs  */
#line 506 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LRP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LRP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2324 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 42: /* instruction: INSTR_FRC omods dreg ',' sregs  */
#line 511 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("FRC\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_FRC, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2333 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 43: /* instruction: INSTR_POW omods dreg ',' sregs  */
#line 516 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("POW\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_POW, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2342 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 44: /* instruction: INSTR_CRS omods dreg ',' sregs  */
#line 521 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("CRS\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_CRS, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2351 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 45: /* instruction: INSTR_SGN omods dreg ',' sregs  */
#line 526 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SGN\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SGN, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2360 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 46: /* instruction: INSTR_NRM omods dreg ',' sregs  */
#line 531 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("NRM\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_NRM, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2369 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 47: /* instruction: INSTR_SINCOS omods dreg ',' sregs  */
#line 536 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SINCOS\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SINCOS, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2378 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 48: /* instruction: INSTR_M4x4 omods dreg ',' sregs  */
#line 541 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("M4x4\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_M4x4, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2387 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 49: /* instruction: INSTR_M4x3 omods dreg ',' sregs  */
#line 546 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("M4x3\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_M4x3, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2396 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 50: /* instruction: INSTR_M3x4 omods dreg ',' sregs  */
#line 551 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("M3x4\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_M3x4, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2405 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 51: /* instruction: INSTR_M3x3 omods dreg ',' sregs  */
#line 556 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("M3x3\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_M3x3, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2414 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 52: /* instruction: INSTR_M3x2 omods dreg ',' sregs  */
#line 561 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("M3x2\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_M3x2, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2423 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 53: /* instruction: INSTR_DCL dclusage REG_OUTPUT  */
#line 566 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Output reg declaration\n");
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = BWRITERSPR_OUTPUT;
                                reg.regnum = (yyvsp[0].regnum);
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = BWRITERSP_WRITEMASK_ALL;
                                asm_ctx.funcs->dcl_output(&asm_ctx, (yyvsp[-1].declaration).dclusage, (yyvsp[-1].declaration).regnum, &reg);
                            }
#line 2439 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 54: /* instruction: INSTR_DCL dclusage REG_OUTPUT writemask  */
#line 578 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Output reg declaration\n");
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = BWRITERSPR_OUTPUT;
                                reg.regnum = (yyvsp[-1].regnum);
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = (yyvsp[0].writemask);
                                asm_ctx.funcs->dcl_output(&asm_ctx, (yyvsp[-2].declaration).dclusage, (yyvsp[-2].declaration).regnum, &reg);
                            }
#line 2455 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 55: /* instruction: INSTR_DCL dclusage omods dcl_inputreg  */
#line 590 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Input reg declaration\n");
                                if((yyvsp[-1].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                if (asm_ctx.shader->type == ST_PIXEL && asm_ctx.shader->major_version == 2)
                                {
                                    asmparser_message(&asm_ctx, "Line %u: Declaration not supported in PS 2\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = (yyvsp[0].reg).type;
                                reg.regnum = (yyvsp[0].reg).regnum;
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = BWRITERSP_WRITEMASK_ALL;
                                asm_ctx.funcs->dcl_input(&asm_ctx, (yyvsp[-2].declaration).dclusage, (yyvsp[-2].declaration).regnum, (yyvsp[-1].modshift).mod, &reg);
                            }
#line 2482 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 56: /* instruction: INSTR_DCL dclusage omods dcl_inputreg writemask  */
#line 613 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Input reg declaration\n");
                                if((yyvsp[-2].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                if (asm_ctx.shader->type == ST_PIXEL && asm_ctx.shader->major_version == 2)
                                {
                                    asmparser_message(&asm_ctx, "Line %u: Declaration not supported in PS 2\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = (yyvsp[-1].reg).type;
                                reg.regnum = (yyvsp[-1].reg).regnum;
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = (yyvsp[0].writemask);
                                asm_ctx.funcs->dcl_input(&asm_ctx, (yyvsp[-3].declaration).dclusage, (yyvsp[-3].declaration).regnum, (yyvsp[-2].modshift).mod, &reg);
                            }
#line 2509 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 57: /* instruction: INSTR_DCL omods dcl_inputreg  */
#line 636 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Input reg declaration\n");
                                if((yyvsp[-1].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                if(asm_ctx.shader->type != ST_PIXEL) {
                                    asmparser_message(&asm_ctx, "Line %u: Declaration needs a semantic\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = (yyvsp[0].reg).type;
                                reg.regnum = (yyvsp[0].reg).regnum;
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = BWRITERSP_WRITEMASK_ALL;
                                asm_ctx.funcs->dcl_input(&asm_ctx, 0, 0, (yyvsp[-1].modshift).mod, &reg);
                            }
#line 2535 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 58: /* instruction: INSTR_DCL omods dcl_inputreg writemask  */
#line 658 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                struct shader_reg reg;
                                TRACE("Input reg declaration\n");
                                if((yyvsp[-2].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                if(asm_ctx.shader->type != ST_PIXEL) {
                                    asmparser_message(&asm_ctx, "Line %u: Declaration needs a semantic\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                ZeroMemory(&reg, sizeof(reg));
                                reg.type = (yyvsp[-1].reg).type;
                                reg.regnum = (yyvsp[-1].reg).regnum;
                                reg.rel_reg = NULL;
                                reg.srcmod = 0;
                                reg.writemask = (yyvsp[0].writemask);
                                asm_ctx.funcs->dcl_input(&asm_ctx, 0, 0, (yyvsp[-2].modshift).mod, &reg);
                            }
#line 2561 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 59: /* instruction: INSTR_DCL sampdcl omods REG_SAMPLER  */
#line 680 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("Sampler declared\n");
                                if((yyvsp[-1].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                asm_ctx.funcs->dcl_sampler(&asm_ctx, (yyvsp[-2].samplertype), (yyvsp[-1].modshift).mod, (yyvsp[0].regnum), asm_ctx.line_no);
                            }
#line 2575 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 60: /* instruction: INSTR_DCL omods REG_SAMPLER  */
#line 690 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("Sampler declared\n");
                                if((yyvsp[-1].modshift).shift != 0) {
                                    asmparser_message(&asm_ctx, "Line %u: Shift modifier not allowed here\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                if(asm_ctx.shader->type != ST_PIXEL) {
                                    asmparser_message(&asm_ctx, "Line %u: Declaration needs a sampler type\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                }
                                asm_ctx.funcs->dcl_sampler(&asm_ctx, BWRITERSTT_UNKNOWN, (yyvsp[-1].modshift).mod, (yyvsp[0].regnum), asm_ctx.line_no);
                            }
#line 2594 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 61: /* instruction: INSTR_DCL sampdcl omods dcl_inputreg  */
#line 705 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("Error rule: sampler decl of input reg\n");
                                asmparser_message(&asm_ctx, "Line %u: Sampler declarations of input regs is not valid\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_WARN);
                            }
#line 2605 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 62: /* instruction: INSTR_DCL sampdcl omods REG_OUTPUT  */
#line 712 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("Error rule: sampler decl of output reg\n");
                                asmparser_message(&asm_ctx, "Line %u: Sampler declarations of output regs is not valid\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_WARN);
                            }
#line 2616 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 63: /* instruction: INSTR_DEF REG_CONSTFLOAT ',' signed_float ',' signed_float ',' signed_float ',' signed_float  */
#line 719 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                asm_ctx.funcs->constF(&asm_ctx, (yyvsp[-8].regnum), (yyvsp[-6].immval).val, (yyvsp[-4].immval).val, (yyvsp[-2].immval).val, (yyvsp[0].immval).val);
                            }
#line 2624 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 64: /* instruction: INSTR_DEFI REG_CONSTINT ',' signed_integer ',' signed_integer ',' signed_integer ',' signed_integer  */
#line 723 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                asm_ctx.funcs->constI(&asm_ctx, (yyvsp[-8].regnum), (yyvsp[-6].immval).val, (yyvsp[-4].immval).val, (yyvsp[-2].immval).val, (yyvsp[0].immval).val);
                            }
#line 2632 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 65: /* instruction: INSTR_DEFB REG_CONSTBOOL ',' IMMBOOL  */
#line 727 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                asm_ctx.funcs->constB(&asm_ctx, (yyvsp[-2].regnum), (yyvsp[0].immbool));
                            }
#line 2640 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 66: /* instruction: INSTR_REP sregs  */
#line 731 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("REP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_REP, 0, 0, 0, 0, &(yyvsp[0].sregs), 1);
                            }
#line 2649 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 67: /* instruction: INSTR_ENDREP  */
#line 736 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ENDREP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ENDREP, 0, 0, 0, 0, 0, 0);
                            }
#line 2658 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 68: /* instruction: INSTR_IF sregs  */
#line 741 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("IF\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_IF, 0, 0, 0, 0, &(yyvsp[0].sregs), 1);
                            }
#line 2667 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 69: /* instruction: INSTR_IF comp sregs  */
#line 746 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("IFC\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_IFC, 0, 0, (yyvsp[-1].comptype), 0, &(yyvsp[0].sregs), 2);
                            }
#line 2676 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 70: /* instruction: INSTR_ELSE  */
#line 751 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ELSE\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ELSE, 0, 0, 0, 0, 0, 0);
                            }
#line 2685 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 71: /* instruction: INSTR_ENDIF  */
#line 756 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ENDIF\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ENDIF, 0, 0, 0, 0, 0, 0);
                            }
#line 2694 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 72: /* instruction: INSTR_BREAK  */
#line 761 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("BREAK\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_BREAK, 0, 0, 0, 0, 0, 0);
                            }
#line 2703 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 73: /* instruction: INSTR_BREAK comp sregs  */
#line 766 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("BREAKC\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_BREAKC, 0, 0, (yyvsp[-1].comptype), 0, &(yyvsp[0].sregs), 2);
                            }
#line 2712 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 74: /* instruction: INSTR_BREAKP sregs  */
#line 771 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("BREAKP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_BREAKP, 0, 0, 0, 0, &(yyvsp[0].sregs), 1);
                            }
#line 2721 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 75: /* instruction: INSTR_CALL sregs  */
#line 776 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("CALL\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_CALL, 0, 0, 0, 0, &(yyvsp[0].sregs), 1);
                            }
#line 2730 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 76: /* instruction: INSTR_CALLNZ sregs  */
#line 781 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("CALLNZ\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_CALLNZ, 0, 0, 0, 0, &(yyvsp[0].sregs), 2);
                            }
#line 2739 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 77: /* instruction: INSTR_LOOP sregs  */
#line 786 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LOOP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LOOP, 0, 0, 0, 0, &(yyvsp[0].sregs), 2);
                            }
#line 2748 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 78: /* instruction: INSTR_RET  */
#line 791 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("RET\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_RET, 0, 0, 0, 0, 0, 0);
                            }
#line 2757 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 79: /* instruction: INSTR_ENDLOOP  */
#line 796 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("ENDLOOP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_ENDLOOP, 0, 0, 0, 0, 0, 0);
                            }
#line 2766 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 80: /* instruction: INSTR_LABEL sregs  */
#line 801 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LABEL\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LABEL, 0, 0, 0, 0, &(yyvsp[0].sregs), 1);
                            }
#line 2775 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 81: /* instruction: INSTR_SETP comp dreg ',' sregs  */
#line 806 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("SETP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_SETP, 0, 0, (yyvsp[-3].comptype), &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2784 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 82: /* instruction: INSTR_TEXLDL omods dreg ',' sregs  */
#line 811 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXLDL\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXLDL, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2793 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 83: /* instruction: INSTR_LIT omods dreg ',' sregs  */
#line 816 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("LIT\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_LIT, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2802 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 84: /* instruction: INSTR_MOVA omods dreg ',' sregs  */
#line 821 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("MOVA\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_MOVA, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2811 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 85: /* instruction: INSTR_CND omods dreg ',' sregs  */
#line 826 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("CND\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_CND, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2820 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 86: /* instruction: INSTR_CMP omods dreg ',' sregs  */
#line 831 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("CMP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_CMP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2829 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 87: /* instruction: INSTR_DP2ADD omods dreg ',' sregs  */
#line 836 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DP2ADD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DP2ADD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 3);
                            }
#line 2838 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 88: /* instruction: INSTR_TEXCOORD omods dreg  */
#line 841 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXCOORD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXCOORD, (yyvsp[-1].modshift).mod, (yyvsp[-1].modshift).shift, 0, &(yyvsp[0].reg), 0, 0);
                            }
#line 2847 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 89: /* instruction: INSTR_TEXCRD omods dreg ',' sregs  */
#line 846 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXCRD\n");
                                /* texcoord and texcrd share the same opcode */
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXCOORD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2857 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 90: /* instruction: INSTR_TEXKILL dreg  */
#line 852 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXKILL\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXKILL, 0, 0, 0, &(yyvsp[0].reg), 0, 0);
                            }
#line 2866 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 91: /* instruction: INSTR_TEX omods dreg  */
#line 857 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEX, (yyvsp[-1].modshift).mod, (yyvsp[-1].modshift).shift, 0, &(yyvsp[0].reg), 0, 0);
                            }
#line 2875 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 92: /* instruction: INSTR_TEXDEPTH omods dreg  */
#line 862 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXDEPTH\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXDEPTH, (yyvsp[-1].modshift).mod, (yyvsp[-1].modshift).shift, 0, &(yyvsp[0].reg), 0, 0);
                            }
#line 2884 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 93: /* instruction: INSTR_TEXLD omods dreg ',' sregs  */
#line 867 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXLD\n");
                                /* There is more than one acceptable syntax for texld:
                                   with 1 sreg (PS 1.4) or
                                   with 2 sregs (PS 2.0+)
                                   Moreover, texld shares the same opcode as the tex instruction,
                                   so there are a total of 3 valid syntaxes
                                   These variations are handled in asmparser.c */
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2899 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 94: /* instruction: INSTR_TEXLDP omods dreg ',' sregs  */
#line 878 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXLDP\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXLDP, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2908 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 95: /* instruction: INSTR_TEXLDB omods dreg ',' sregs  */
#line 883 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXLDB\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXLDB, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2917 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 96: /* instruction: INSTR_TEXBEM omods dreg ',' sregs  */
#line 888 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXBEM\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXBEM, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2926 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 97: /* instruction: INSTR_TEXBEML omods dreg ',' sregs  */
#line 893 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXBEML\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXBEML, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2935 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 98: /* instruction: INSTR_TEXREG2AR omods dreg ',' sregs  */
#line 898 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXREG2AR\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXREG2AR, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2944 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 99: /* instruction: INSTR_TEXREG2GB omods dreg ',' sregs  */
#line 903 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXREG2GB\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXREG2GB, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2953 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 100: /* instruction: INSTR_TEXREG2RGB omods dreg ',' sregs  */
#line 908 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXREG2RGB\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXREG2RGB, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2962 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 101: /* instruction: INSTR_TEXM3x2PAD omods dreg ',' sregs  */
#line 913 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x2PAD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x2PAD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2971 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 102: /* instruction: INSTR_TEXM3x3PAD omods dreg ',' sregs  */
#line 918 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("INSTR_TEXM3x3PAD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x3PAD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2980 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 103: /* instruction: INSTR_TEXM3x3SPEC omods dreg ',' sregs  */
#line 923 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x3SPEC\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x3SPEC, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 2989 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 104: /* instruction: INSTR_TEXM3x3VSPEC omods dreg ',' sregs  */
#line 928 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x3VSPEC\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x3VSPEC, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 2998 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 105: /* instruction: INSTR_TEXM3x3TEX omods dreg ',' sregs  */
#line 933 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x3TEX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x3TEX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3007 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 106: /* instruction: INSTR_TEXDP3TEX omods dreg ',' sregs  */
#line 938 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXDP3TEX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXDP3TEX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3016 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 107: /* instruction: INSTR_TEXM3x2DEPTH omods dreg ',' sregs  */
#line 943 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x2DEPTH\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x2DEPTH, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3025 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 108: /* instruction: INSTR_TEXM3x2TEX omods dreg ',' sregs  */
#line 948 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x2TEX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x2TEX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3034 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 109: /* instruction: INSTR_TEXDP3 omods dreg ',' sregs  */
#line 953 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXDP3\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXDP3, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3043 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 110: /* instruction: INSTR_TEXM3x3 omods dreg ',' sregs  */
#line 958 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXM3x3\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXM3x3, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3052 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 111: /* instruction: INSTR_BEM omods dreg ',' sregs  */
#line 963 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("BEM\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_BEM, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 2);
                            }
#line 3061 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 112: /* instruction: INSTR_DSX omods dreg ',' sregs  */
#line 968 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DSX\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DSX, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3070 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 113: /* instruction: INSTR_DSY omods dreg ',' sregs  */
#line 973 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("DSY\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_DSY, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 1);
                            }
#line 3079 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 114: /* instruction: INSTR_TEXLDD omods dreg ',' sregs  */
#line 978 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("TEXLDD\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_TEXLDD, (yyvsp[-3].modshift).mod, (yyvsp[-3].modshift).shift, 0, &(yyvsp[-2].reg), &(yyvsp[0].sregs), 4);
                            }
#line 3088 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 115: /* instruction: INSTR_PHASE  */
#line 983 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                TRACE("PHASE\n");
                                asm_ctx.funcs->instr(&asm_ctx, BWRITERSIO_PHASE, 0, 0, 0, 0, 0, 0);
                            }
#line 3097 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 116: /* dreg: dreg_name rel_reg  */
#line 990 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                (yyval.reg).regnum = (yyvsp[-1].reg).regnum;
                                (yyval.reg).type = (yyvsp[-1].reg).type;
                                (yyval.reg).writemask = BWRITERSP_WRITEMASK_ALL;
                                (yyval.reg).srcmod = BWRITERSPSM_NONE;
                                set_rel_reg(&(yyval.reg), &(yyvsp[0].rel_reg));
                            }
#line 3109 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 117: /* dreg: dreg_name writemask  */
#line 998 "dlls/d3dcompiler_43/asmshader.y"
                            {
                                (yyval.reg).regnum = (yyvsp[-1].reg).regnum;
                                (yyval.reg).type = (yyvsp[-1].reg).type;
                                (yyval.reg).writemask = (yyvsp[0].writemask);
                                (yyval.reg).srcmod = BWRITERSPSM_NONE;
                                (yyval.reg).rel_reg = NULL;
                            }
#line 3121 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 118: /* dreg_name: REG_TEMP  */
#line 1007 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEMP;
                        }
#line 3129 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 119: /* dreg_name: REG_OUTPUT  */
#line 1011 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_OUTPUT;
                        }
#line 3137 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 120: /* dreg_name: REG_INPUT  */
#line 1015 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_INPUT;
                        }
#line 3145 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 121: /* dreg_name: REG_CONSTFLOAT  */
#line 1019 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register c%u is not a valid destination register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3155 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 122: /* dreg_name: REG_CONSTINT  */
#line 1025 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register i%u is not a valid destination register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3165 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 123: /* dreg_name: REG_CONSTBOOL  */
#line 1031 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register b%u is not a valid destination register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3175 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 124: /* dreg_name: REG_TEXTURE  */
#line 1037 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEXTURE;
                        }
#line 3183 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 125: /* dreg_name: REG_TEXCRDOUT  */
#line 1041 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEXCRDOUT;
                        }
#line 3191 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 126: /* dreg_name: REG_SAMPLER  */
#line 1045 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register s%u is not a valid destination register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3201 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 127: /* dreg_name: REG_OPOS  */
#line 1051 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = BWRITERSRO_POSITION; (yyval.reg).type = BWRITERSPR_RASTOUT;
                        }
#line 3209 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 128: /* dreg_name: REG_OPTS  */
#line 1055 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = BWRITERSRO_POINT_SIZE; (yyval.reg).type = BWRITERSPR_RASTOUT;
                        }
#line 3217 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 129: /* dreg_name: REG_OFOG  */
#line 1059 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = BWRITERSRO_FOG; (yyval.reg).type = BWRITERSPR_RASTOUT;
                        }
#line 3225 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 130: /* dreg_name: REG_VERTEXCOLOR  */
#line 1063 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_ATTROUT;
                        }
#line 3233 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 131: /* dreg_name: REG_FRAGCOLOR  */
#line 1067 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_COLOROUT;
                        }
#line 3241 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 132: /* dreg_name: REG_FRAGDEPTH  */
#line 1071 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_DEPTHOUT;
                        }
#line 3249 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 133: /* dreg_name: REG_PREDICATE  */
#line 1075 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_PREDICATE;
                        }
#line 3257 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 134: /* dreg_name: REG_VPOS  */
#line 1079 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register vPos is not a valid destination register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3267 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 135: /* dreg_name: REG_VFACE  */
#line 1085 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register vFace is not a valid destination register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3277 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 136: /* dreg_name: REG_ADDRESS  */
#line 1091 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            /* index 0 is hardcoded for the addr register */
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_ADDR;
                        }
#line 3286 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 137: /* dreg_name: REG_LOOP  */
#line 1096 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register aL is not a valid destination register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3296 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 138: /* writemask: '.' wm_components  */
#line 1103 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyvsp[0].wm_components).writemask == SWIZZLE_ERR) {
                                asmparser_message(&asm_ctx, "Line %u: Invalid writemask specified\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                /* Provide a correct writemask to prevent following complaints */
                                (yyval.writemask) = BWRITERSP_WRITEMASK_ALL;
                            }
                            else {
                                (yyval.writemask) = (yyvsp[0].wm_components).writemask;
                                TRACE("Writemask: %x\n", (yyval.writemask));
                            }
                        }
#line 3314 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 139: /* wm_components: COMPONENT  */
#line 1118 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.wm_components).writemask = 1 << (yyvsp[0].component);
                            (yyval.wm_components).last = (yyvsp[0].component);
                            (yyval.wm_components).idx = 1;
                        }
#line 3324 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 140: /* wm_components: wm_components COMPONENT  */
#line 1124 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyvsp[-1].wm_components).writemask == SWIZZLE_ERR || (yyvsp[-1].wm_components).idx == 4)
                                /* Wrong writemask */
                                (yyval.wm_components).writemask = SWIZZLE_ERR;
                            else {
                                if((yyvsp[0].component) <= (yyvsp[-1].wm_components).last)
                                    (yyval.wm_components).writemask = SWIZZLE_ERR;
                                else {
                                    (yyval.wm_components).writemask = (yyvsp[-1].wm_components).writemask | (1 << (yyvsp[0].component));
                                    (yyval.wm_components).idx = (yyvsp[-1].wm_components).idx + 1;
                                }
                            }
                        }
#line 3342 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 141: /* swizzle: %empty  */
#line 1139 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.swizzle) = BWRITERVS_NOSWIZZLE;
                            TRACE("Default swizzle: %08x\n", (yyval.swizzle));
                        }
#line 3351 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 142: /* swizzle: '.' sw_components  */
#line 1144 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyvsp[0].sw_components).swizzle == SWIZZLE_ERR) {
                                asmparser_message(&asm_ctx, "Line %u: Invalid swizzle\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                /* Provide a correct swizzle to prevent following complaints */
                                (yyval.swizzle) = BWRITERVS_NOSWIZZLE;
                            }
                            else {
                                uint32_t last, i;

                                (yyval.swizzle) = (yyvsp[0].sw_components).swizzle;
                                /* Fill the swizzle by extending the last component */
                                last = ((yyvsp[0].sw_components).swizzle >> 2 * ((yyvsp[0].sw_components).idx - 1)) & 0x03;
                                for(i = (yyvsp[0].sw_components).idx; i < 4; i++){
                                    (yyval.swizzle) |= last << (2 * i);
                                }
                                TRACE("Got a swizzle: %08x\n", (yyval.swizzle));
                            }
                        }
#line 3376 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 143: /* sw_components: COMPONENT  */
#line 1166 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.sw_components).swizzle = (yyvsp[0].component);
                            (yyval.sw_components).idx = 1;
                        }
#line 3385 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 144: /* sw_components: sw_components COMPONENT  */
#line 1171 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyvsp[-1].sw_components).idx == 4) {
                                /* Too many sw_components */
                                (yyval.sw_components).swizzle = SWIZZLE_ERR;
                                (yyval.sw_components).idx = 4;
                            }
                            else {
                                (yyval.sw_components).swizzle = (yyvsp[-1].sw_components).swizzle | ((yyvsp[0].component) << 2 * (yyvsp[-1].sw_components).idx);
                                (yyval.sw_components).idx = (yyvsp[-1].sw_components).idx + 1;
                            }
                        }
#line 3401 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 145: /* omods: %empty  */
#line 1184 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 0;
                        }
#line 3410 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 146: /* omods: omods omodifier  */
#line 1189 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = (yyvsp[-1].modshift).mod | (yyvsp[0].modshift).mod;
                            if((yyvsp[-1].modshift).shift && (yyvsp[0].modshift).shift) {
                                asmparser_message(&asm_ctx, "Line %u: More than one shift flag\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                (yyval.modshift).shift = (yyvsp[-1].modshift).shift;
                            } else {
                                (yyval.modshift).shift = (yyvsp[-1].modshift).shift | (yyvsp[0].modshift).shift;
                            }
                        }
#line 3426 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 147: /* omodifier: SHIFT_X2  */
#line 1202 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 1;
                        }
#line 3435 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 148: /* omodifier: SHIFT_X4  */
#line 1207 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 2;
                        }
#line 3444 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 149: /* omodifier: SHIFT_X8  */
#line 1212 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 3;
                        }
#line 3453 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 150: /* omodifier: SHIFT_D2  */
#line 1217 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 15;
                        }
#line 3462 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 151: /* omodifier: SHIFT_D4  */
#line 1222 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 14;
                        }
#line 3471 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 152: /* omodifier: SHIFT_D8  */
#line 1227 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = 0;
                            (yyval.modshift).shift = 13;
                        }
#line 3480 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 153: /* omodifier: MOD_SAT  */
#line 1232 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = BWRITERSPDM_SATURATE;
                            (yyval.modshift).shift = 0;
                        }
#line 3489 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 154: /* omodifier: MOD_PP  */
#line 1237 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = BWRITERSPDM_PARTIALPRECISION;
                            (yyval.modshift).shift = 0;
                        }
#line 3498 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 155: /* omodifier: MOD_CENTROID  */
#line 1242 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.modshift).mod = BWRITERSPDM_MSAMPCENTROID;
                            (yyval.modshift).shift = 0;
                        }
#line 3507 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 156: /* sregs: sreg  */
#line 1248 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.sregs).reg[0] = (yyvsp[0].reg);
                            (yyval.sregs).count = 1;
                        }
#line 3516 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 157: /* sregs: sregs ',' sreg  */
#line 1253 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyval.sregs).count == MAX_SRC_REGS){
                                asmparser_message(&asm_ctx, "Line %u: Too many source registers in this instruction\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            }
                            else
                                (yyval.sregs).reg[(yyval.sregs).count++] = (yyvsp[0].reg);
                        }
#line 3530 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 158: /* sreg: sreg_name rel_reg swizzle  */
#line 1264 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = (yyvsp[-2].reg).type;
                            (yyval.reg).regnum = (yyvsp[-2].reg).regnum;
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                            (yyval.reg).srcmod = BWRITERSPSM_NONE;
                            set_rel_reg(&(yyval.reg), &(yyvsp[-1].rel_reg));
                        }
#line 3542 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 159: /* sreg: sreg_name rel_reg smod swizzle  */
#line 1272 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = (yyvsp[-3].reg).type;
                            (yyval.reg).regnum = (yyvsp[-3].reg).regnum;
                            set_rel_reg(&(yyval.reg), &(yyvsp[-2].rel_reg));
                            (yyval.reg).srcmod = (yyvsp[-1].srcmod);
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                        }
#line 3554 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 160: /* sreg: '-' sreg_name rel_reg swizzle  */
#line 1280 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = (yyvsp[-2].reg).type;
                            (yyval.reg).regnum = (yyvsp[-2].reg).regnum;
                            (yyval.reg).srcmod = BWRITERSPSM_NEG;
                            set_rel_reg(&(yyval.reg), &(yyvsp[-1].rel_reg));
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                        }
#line 3566 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 161: /* sreg: '-' sreg_name rel_reg smod swizzle  */
#line 1288 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = (yyvsp[-3].reg).type;
                            (yyval.reg).regnum = (yyvsp[-3].reg).regnum;
                            set_rel_reg(&(yyval.reg), &(yyvsp[-2].rel_reg));
                            switch((yyvsp[-1].srcmod)) {
                                case BWRITERSPSM_BIAS: (yyval.reg).srcmod = BWRITERSPSM_BIASNEG; break;
                                case BWRITERSPSM_X2:   (yyval.reg).srcmod = BWRITERSPSM_X2NEG;   break;
                                case BWRITERSPSM_SIGN: (yyval.reg).srcmod = BWRITERSPSM_SIGNNEG; break;
                                case BWRITERSPSM_ABS:  (yyval.reg).srcmod = BWRITERSPSM_ABSNEG;  break;
                                case BWRITERSPSM_DZ:
                                    asmparser_message(&asm_ctx, "Line %u: Incompatible source modifiers: NEG and DZ\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                    break;
                                case BWRITERSPSM_DW:
                                    asmparser_message(&asm_ctx, "Line %u: Incompatible source modifiers: NEG and DW\n",
                                                      asm_ctx.line_no);
                                    set_parse_status(&asm_ctx.status,  PARSE_ERR);
                                    break;
                                default:
                                    FIXME("Unhandled combination of NEGATE and %u\n", (yyvsp[-1].srcmod));
                            }
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                        }
#line 3595 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 162: /* sreg: IMMVAL '-' sreg_name rel_reg swizzle  */
#line 1313 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if((yyvsp[-4].immval).val != 1.0 || (!(yyvsp[-4].immval).integer)) {
                                asmparser_message(&asm_ctx, "Line %u: Only \"1 - reg\" is valid for D3DSPSM_COMP, "
                                                  "%g - reg found\n", asm_ctx.line_no, (yyvsp[-4].immval).val);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            }
                            /* Complement - not compatible with other source modifiers */
                            (yyval.reg).type = (yyvsp[-2].reg).type;
                            (yyval.reg).regnum = (yyvsp[-2].reg).regnum;
                            (yyval.reg).srcmod = BWRITERSPSM_COMP;
                            set_rel_reg(&(yyval.reg), &(yyvsp[-1].rel_reg));
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                        }
#line 3613 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 163: /* sreg: IMMVAL '-' sreg_name rel_reg smod swizzle  */
#line 1327 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            /* For nicer error reporting */
                            if((yyvsp[-5].immval).val != 1.0 || (!(yyvsp[-5].immval).integer)) {
                                asmparser_message(&asm_ctx, "Line %u: Only \"1 - reg\" is valid for D3DSPSM_COMP\n",
                                                  asm_ctx.line_no);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            } else {
                                asmparser_message(&asm_ctx, "Line %u: Incompatible source modifiers: D3DSPSM_COMP and %s\n",
                                                  asm_ctx.line_no,
                                                  debug_print_srcmod((yyvsp[-1].srcmod)));
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            }
                        }
#line 3631 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 164: /* sreg: SMOD_NOT sreg_name swizzle  */
#line 1341 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = (yyvsp[-1].reg).type;
                            (yyval.reg).regnum = (yyvsp[-1].reg).regnum;
                            (yyval.reg).rel_reg = NULL;
                            (yyval.reg).srcmod = BWRITERSPSM_NOT;
                            (yyval.reg).swizzle = (yyvsp[0].swizzle);
                        }
#line 3643 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 165: /* rel_reg: %empty  */
#line 1350 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = FALSE;
                            (yyval.rel_reg).additional_offset = 0;
                        }
#line 3652 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 166: /* rel_reg: '[' immsum ']'  */
#line 1355 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = FALSE;
                            (yyval.rel_reg).additional_offset = (yyvsp[-1].immval).val;
                        }
#line 3661 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 167: /* rel_reg: '[' relreg_name swizzle ']'  */
#line 1360 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = TRUE;
                            (yyval.rel_reg).type = (yyvsp[-2].reg).type;
                            (yyval.rel_reg).additional_offset = 0;
                            (yyval.rel_reg).rel_regnum = (yyvsp[-2].reg).regnum;
                            (yyval.rel_reg).swizzle = (yyvsp[-1].swizzle);
                        }
#line 3673 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 168: /* rel_reg: '[' immsum '+' relreg_name swizzle ']'  */
#line 1368 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = TRUE;
                            (yyval.rel_reg).type = (yyvsp[-2].reg).type;
                            (yyval.rel_reg).additional_offset = (yyvsp[-4].immval).val;
                            (yyval.rel_reg).rel_regnum = (yyvsp[-2].reg).regnum;
                            (yyval.rel_reg).swizzle = (yyvsp[-1].swizzle);
                        }
#line 3685 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 169: /* rel_reg: '[' relreg_name swizzle '+' immsum ']'  */
#line 1376 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = TRUE;
                            (yyval.rel_reg).type = (yyvsp[-4].reg).type;
                            (yyval.rel_reg).additional_offset = (yyvsp[-1].immval).val;
                            (yyval.rel_reg).rel_regnum = (yyvsp[-4].reg).regnum;
                            (yyval.rel_reg).swizzle = (yyvsp[-3].swizzle);
                        }
#line 3697 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 170: /* rel_reg: '[' immsum '+' relreg_name swizzle '+' immsum ']'  */
#line 1384 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.rel_reg).has_rel_reg = TRUE;
                            (yyval.rel_reg).type = (yyvsp[-4].reg).type;
                            (yyval.rel_reg).additional_offset = (yyvsp[-6].immval).val + (yyvsp[-1].immval).val;
                            (yyval.rel_reg).rel_regnum = (yyvsp[-4].reg).regnum;
                            (yyval.rel_reg).swizzle = (yyvsp[-3].swizzle);
                        }
#line 3709 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 172: /* immsum: immsum '+' signed_integer  */
#line 1394 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.immval).val = (yyvsp[-2].immval).val + (yyvsp[0].immval).val;
                        }
#line 3717 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 173: /* immsum: immsum '-' signed_integer  */
#line 1398 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.immval).val = (yyvsp[-2].immval).val - (yyvsp[0].immval).val;
                        }
#line 3725 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 174: /* signed_integer: IMMVAL  */
#line 1404 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if (!(yyvsp[0].immval).integer)
                            {
                                asmparser_message(&asm_ctx, "Line %u: Unexpected float %f\n",
                                        asm_ctx.line_no, (yyvsp[0].immval).val);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            }
                            (yyval.immval).val = (yyvsp[0].immval).val;
                        }
#line 3739 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 175: /* signed_integer: '-' IMMVAL  */
#line 1414 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            if (!(yyvsp[0].immval).integer)
                            {
                                asmparser_message(&asm_ctx, "Line %u: Unexpected float %f\n",
                                        asm_ctx.line_no, (yyvsp[0].immval).val);
                                set_parse_status(&asm_ctx.status,  PARSE_ERR);
                            }
                            (yyval.immval).val = -(yyvsp[0].immval).val;
                        }
#line 3753 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 176: /* signed_float: IMMVAL  */
#line 1426 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.immval).val = (yyvsp[0].immval).val;
                        }
#line 3761 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 177: /* signed_float: '-' IMMVAL  */
#line 1430 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.immval).val = -(yyvsp[0].immval).val;
                        }
#line 3769 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 178: /* smod: SMOD_BIAS  */
#line 1435 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_BIAS;
                        }
#line 3777 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 179: /* smod: SHIFT_X2  */
#line 1439 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_X2;
                        }
#line 3785 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 180: /* smod: SMOD_SCALEBIAS  */
#line 1443 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_SIGN;
                        }
#line 3793 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 181: /* smod: SMOD_DZ  */
#line 1447 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_DZ;
                        }
#line 3801 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 182: /* smod: SMOD_DW  */
#line 1451 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_DW;
                        }
#line 3809 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 183: /* smod: SMOD_ABS  */
#line 1455 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.srcmod) = BWRITERSPSM_ABS;
                        }
#line 3817 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 184: /* relreg_name: REG_ADDRESS  */
#line 1460 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_ADDR;
                        }
#line 3825 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 185: /* relreg_name: REG_LOOP  */
#line 1464 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_LOOP;
                        }
#line 3833 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 186: /* sreg_name: REG_TEMP  */
#line 1469 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEMP;
                        }
#line 3841 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 187: /* sreg_name: REG_OUTPUT  */
#line 1473 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register o%u is not a valid source register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3851 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 188: /* sreg_name: REG_INPUT  */
#line 1479 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_INPUT;
                        }
#line 3859 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 189: /* sreg_name: REG_CONSTFLOAT  */
#line 1483 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_CONST;
                        }
#line 3867 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 190: /* sreg_name: REG_CONSTINT  */
#line 1487 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_CONSTINT;
                        }
#line 3875 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 191: /* sreg_name: REG_CONSTBOOL  */
#line 1491 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_CONSTBOOL;
                        }
#line 3883 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 192: /* sreg_name: REG_TEXTURE  */
#line 1495 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEXTURE;
                        }
#line 3891 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 193: /* sreg_name: REG_TEXCRDOUT  */
#line 1499 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oT%u is not a valid source register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3901 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 194: /* sreg_name: REG_SAMPLER  */
#line 1505 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_SAMPLER;
                        }
#line 3909 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 195: /* sreg_name: REG_OPOS  */
#line 1509 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oPos is not a valid source register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3919 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 196: /* sreg_name: REG_OFOG  */
#line 1515 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oFog is not a valid source register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3929 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 197: /* sreg_name: REG_VERTEXCOLOR  */
#line 1521 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oD%u is not a valid source register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3939 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 198: /* sreg_name: REG_FRAGCOLOR  */
#line 1527 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oC%u is not a valid source register\n",
                                              asm_ctx.line_no, (yyvsp[0].regnum));
                            set_parse_status(&asm_ctx.status,  PARSE_WARN);
                        }
#line 3949 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 199: /* sreg_name: REG_FRAGDEPTH  */
#line 1533 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            asmparser_message(&asm_ctx, "Line %u: Register oDepth is not a valid source register\n",
                                              asm_ctx.line_no);
                            set_parse_status(&asm_ctx.status, PARSE_WARN);
                        }
#line 3959 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 200: /* sreg_name: REG_PREDICATE  */
#line 1539 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_PREDICATE;
                        }
#line 3967 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 201: /* sreg_name: REG_VPOS  */
#line 1543 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_MISCTYPE;
                        }
#line 3975 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 202: /* sreg_name: REG_VFACE  */
#line 1547 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 1; (yyval.reg).type = BWRITERSPR_MISCTYPE;
                        }
#line 3983 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 203: /* sreg_name: REG_ADDRESS  */
#line 1551 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_ADDR;
                        }
#line 3991 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 204: /* sreg_name: REG_LOOP  */
#line 1555 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = 0; (yyval.reg).type = BWRITERSPR_LOOP;
                        }
#line 3999 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 205: /* sreg_name: REG_LABEL  */
#line 1559 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_LABEL;
                        }
#line 4007 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 206: /* comp: COMP_GT  */
#line 1563 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_GT;       }
#line 4013 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 207: /* comp: COMP_LT  */
#line 1564 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_LT;       }
#line 4019 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 208: /* comp: COMP_GE  */
#line 1565 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_GE;       }
#line 4025 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 209: /* comp: COMP_LE  */
#line 1566 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_LE;       }
#line 4031 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 210: /* comp: COMP_EQ  */
#line 1567 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_EQ;       }
#line 4037 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 211: /* comp: COMP_NE  */
#line 1568 "dlls/d3dcompiler_43/asmshader.y"
                                        { (yyval.comptype) = BWRITER_COMPARISON_NE;       }
#line 4043 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 212: /* dclusage: USAGE_POSITION  */
#line 1571 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_position%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_POSITION;
                        }
#line 4053 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 213: /* dclusage: USAGE_BLENDWEIGHT  */
#line 1577 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_blendweight%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_BLENDWEIGHT;
                        }
#line 4063 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 214: /* dclusage: USAGE_BLENDINDICES  */
#line 1583 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_blendindices%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_BLENDINDICES;
                        }
#line 4073 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 215: /* dclusage: USAGE_NORMAL  */
#line 1589 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_normal%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_NORMAL;
                        }
#line 4083 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 216: /* dclusage: USAGE_PSIZE  */
#line 1595 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_psize%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_PSIZE;
                        }
#line 4093 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 217: /* dclusage: USAGE_TEXCOORD  */
#line 1601 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_texcoord%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_TEXCOORD;
                        }
#line 4103 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 218: /* dclusage: USAGE_TANGENT  */
#line 1607 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_tangent%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_TANGENT;
                        }
#line 4113 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 219: /* dclusage: USAGE_BINORMAL  */
#line 1613 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_binormal%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_BINORMAL;
                        }
#line 4123 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 220: /* dclusage: USAGE_TESSFACTOR  */
#line 1619 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_tessfactor%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_TESSFACTOR;
                        }
#line 4133 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 221: /* dclusage: USAGE_POSITIONT  */
#line 1625 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_positiont%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_POSITIONT;
                        }
#line 4143 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 222: /* dclusage: USAGE_COLOR  */
#line 1631 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_color%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_COLOR;
                        }
#line 4153 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 223: /* dclusage: USAGE_FOG  */
#line 1637 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_fog%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_FOG;
                        }
#line 4163 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 224: /* dclusage: USAGE_DEPTH  */
#line 1643 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_depth%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_DEPTH;
                        }
#line 4173 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 225: /* dclusage: USAGE_SAMPLE  */
#line 1649 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            TRACE("dcl_sample%u\n", (yyvsp[0].regnum));
                            (yyval.declaration).regnum = (yyvsp[0].regnum);
                            (yyval.declaration).dclusage = BWRITERDECLUSAGE_SAMPLE;
                        }
#line 4183 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 226: /* dcl_inputreg: REG_INPUT  */
#line 1656 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_INPUT;
                        }
#line 4191 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 227: /* dcl_inputreg: REG_TEXTURE  */
#line 1660 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).regnum = (yyvsp[0].regnum); (yyval.reg).type = BWRITERSPR_TEXTURE;
                        }
#line 4199 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 228: /* sampdcl: SAMPTYPE_1D  */
#line 1665 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.samplertype) = BWRITERSTT_1D;
                        }
#line 4207 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 229: /* sampdcl: SAMPTYPE_2D  */
#line 1669 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.samplertype) = BWRITERSTT_2D;
                        }
#line 4215 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 230: /* sampdcl: SAMPTYPE_CUBE  */
#line 1673 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.samplertype) = BWRITERSTT_CUBE;
                        }
#line 4223 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 231: /* sampdcl: SAMPTYPE_VOLUME  */
#line 1677 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.samplertype) = BWRITERSTT_VOLUME;
                        }
#line 4231 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 232: /* predicate: '(' REG_PREDICATE swizzle ')'  */
#line 1682 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = BWRITERSPR_PREDICATE;
                            (yyval.reg).regnum = 0;
                            (yyval.reg).rel_reg = NULL;
                            (yyval.reg).srcmod = BWRITERSPSM_NONE;
                            (yyval.reg).swizzle = (yyvsp[-1].swizzle);
                        }
#line 4243 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;

  case 233: /* predicate: '(' SMOD_NOT REG_PREDICATE swizzle ')'  */
#line 1690 "dlls/d3dcompiler_43/asmshader.y"
                        {
                            (yyval.reg).type = BWRITERSPR_PREDICATE;
                            (yyval.reg).regnum = 0;
                            (yyval.reg).rel_reg = NULL;
                            (yyval.reg).srcmod = BWRITERSPSM_NOT;
                            (yyval.reg).swizzle = (yyvsp[-1].swizzle);
                        }
#line 4255 "dlls/d3dcompiler_33/asmshader.tab.c"
    break;


#line 4259 "dlls/d3dcompiler_33/asmshader.tab.c"

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
  yytoken = yychar == ASMSHADER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= ASMSHADER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == ASMSHADER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = ASMSHADER_EMPTY;
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != ASMSHADER_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1698 "dlls/d3dcompiler_43/asmshader.y"


struct bwriter_shader *parse_asm_shader(char **messages)
{
    struct bwriter_shader *ret = NULL;

    asm_ctx.shader = NULL;
    asm_ctx.status = PARSE_SUCCESS;
    asm_ctx.messages.size = asm_ctx.messages.capacity = 0;
    asm_ctx.line_no = 1;

    asmshader_parse();

    if (asm_ctx.status != PARSE_ERR)
        ret = asm_ctx.shader;
    else if (asm_ctx.shader)
        SlDeleteShader(asm_ctx.shader);

    if (messages)
    {
        if (asm_ctx.messages.size)
        {
            /* Shrink the buffer to the used size */
            *messages = realloc(asm_ctx.messages.string, asm_ctx.messages.size + 1);
            if (!*messages)
            {
                ERR("Out of memory, no messages reported\n");
                free(asm_ctx.messages.string);
            }
        }
        else
        {
            *messages = NULL;
        }
    }
    else
    {
        if (asm_ctx.messages.capacity)
            free(asm_ctx.messages.string);
    }

    return ret;
}
