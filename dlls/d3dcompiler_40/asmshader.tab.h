/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_ASMSHADER_DLLS_D3DCOMPILER_40_ASMSHADER_TAB_H_INCLUDED
# define YY_ASMSHADER_DLLS_D3DCOMPILER_40_ASMSHADER_TAB_H_INCLUDED
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

#line 269 "dlls/d3dcompiler_40/asmshader.tab.h"

};
typedef union ASMSHADER_STYPE ASMSHADER_STYPE;
# define ASMSHADER_STYPE_IS_TRIVIAL 1
# define ASMSHADER_STYPE_IS_DECLARED 1
#endif


extern ASMSHADER_STYPE asmshader_lval;


int asmshader_parse (void);


#endif /* !YY_ASMSHADER_DLLS_D3DCOMPILER_40_ASMSHADER_TAB_H_INCLUDED  */
