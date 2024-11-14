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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HLSL_YYSTYPE
#define YYLTYPE         HLSL_YYLTYPE
/* Substitute the variable and function names.  */
#define yyparse         hlsl_yyparse
#define yylex           hlsl_yylex
#define yyerror         hlsl_yyerror
#define yydebug         hlsl_yydebug
#define yynerrs         hlsl_yynerrs


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
#ifndef HLSL_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HLSL_YYDEBUG 1
#  else
#   define HLSL_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HLSL_YYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HLSL_YYDEBUG */
#if HLSL_YYDEBUG
extern int hlsl_yydebug;
#endif
/* "%code requires" blocks.  */
#line 24 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"


#include "hlsl.h"
#include <stdio.h>

#define HLSL_YYLTYPE struct vkd3d_shader_location

struct parse_fields
{
    struct hlsl_struct_field *fields;
    size_t count, capacity;
};

struct parse_initializer
{
    struct hlsl_ir_node **args;
    unsigned int args_count;
    struct hlsl_block *instrs;
    bool braces;
};

struct parse_parameter
{
    struct hlsl_type *type;
    const char *name;
    struct hlsl_semantic semantic;
    struct hlsl_reg_reservation reg_reservation;
    uint32_t modifiers;
    struct parse_initializer initializer;
};

struct parse_colon_attribute
{
    struct hlsl_semantic semantic;
    struct hlsl_reg_reservation reg_reservation;
};

struct parse_array_sizes
{
    uint32_t *sizes; /* innermost first */
    unsigned int count;
};

struct parse_variable_def
{
    struct list entry;
    struct vkd3d_shader_location loc;

    char *name;
    struct parse_array_sizes arrays;
    struct hlsl_semantic semantic;
    struct hlsl_reg_reservation reg_reservation;
    struct parse_initializer initializer;
    struct hlsl_scope *annotations;

    struct hlsl_type *basic_type;
    uint32_t modifiers;
    struct vkd3d_shader_location modifiers_loc;

    struct hlsl_state_block **state_blocks;
    unsigned int state_block_count;
    size_t state_block_capacity;
};

struct parse_function
{
    struct hlsl_ir_function_decl *decl;
    struct hlsl_func_parameters parameters;
    struct hlsl_semantic return_semantic;
    bool first;
};

struct parse_if_body
{
    struct hlsl_block *then_block;
    struct hlsl_block *else_block;
};

enum parse_assign_op
{
    ASSIGN_OP_ASSIGN,
    ASSIGN_OP_ADD,
    ASSIGN_OP_SUB,
    ASSIGN_OP_MUL,
    ASSIGN_OP_DIV,
    ASSIGN_OP_MOD,
    ASSIGN_OP_LSHIFT,
    ASSIGN_OP_RSHIFT,
    ASSIGN_OP_AND,
    ASSIGN_OP_OR,
    ASSIGN_OP_XOR,
};

struct parse_attribute_list
{
    unsigned int count;
    const struct hlsl_attribute **attrs;
};

struct state_block_index
{
    bool has_index;
    unsigned int index;
};


#line 223 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"

/* Token kinds.  */
#ifndef HLSL_YYTOKENTYPE
# define HLSL_YYTOKENTYPE
  enum hlsl_yytokentype
  {
    HLSL_YYEMPTY = -2,
    HLSL_YYEOF = 0,                /* "end of file"  */
    HLSL_YYerror = 256,            /* error  */
    HLSL_YYUNDEF = 257,            /* "invalid token"  */
    KW_BLENDSTATE = 258,           /* KW_BLENDSTATE  */
    KW_BREAK = 259,                /* KW_BREAK  */
    KW_BUFFER = 260,               /* KW_BUFFER  */
    KW_CASE = 261,                 /* KW_CASE  */
    KW_CONSTANTBUFFER = 262,       /* KW_CONSTANTBUFFER  */
    KW_CBUFFER = 263,              /* KW_CBUFFER  */
    KW_CENTROID = 264,             /* KW_CENTROID  */
    KW_COLUMN_MAJOR = 265,         /* KW_COLUMN_MAJOR  */
    KW_COMPILE = 266,              /* KW_COMPILE  */
    KW_COMPUTESHADER = 267,        /* KW_COMPUTESHADER  */
    KW_CONST = 268,                /* KW_CONST  */
    KW_CONTINUE = 269,             /* KW_CONTINUE  */
    KW_DEFAULT = 270,              /* KW_DEFAULT  */
    KW_DEPTHSTENCILSTATE = 271,    /* KW_DEPTHSTENCILSTATE  */
    KW_DEPTHSTENCILVIEW = 272,     /* KW_DEPTHSTENCILVIEW  */
    KW_DISCARD = 273,              /* KW_DISCARD  */
    KW_DO = 274,                   /* KW_DO  */
    KW_DOMAINSHADER = 275,         /* KW_DOMAINSHADER  */
    KW_DOUBLE = 276,               /* KW_DOUBLE  */
    KW_ELSE = 277,                 /* KW_ELSE  */
    KW_EXPORT = 278,               /* KW_EXPORT  */
    KW_EXTERN = 279,               /* KW_EXTERN  */
    KW_FALSE = 280,                /* KW_FALSE  */
    KW_FOR = 281,                  /* KW_FOR  */
    KW_FXGROUP = 282,              /* KW_FXGROUP  */
    KW_GEOMETRYSHADER = 283,       /* KW_GEOMETRYSHADER  */
    KW_GROUPSHARED = 284,          /* KW_GROUPSHARED  */
    KW_HULLSHADER = 285,           /* KW_HULLSHADER  */
    KW_IF = 286,                   /* KW_IF  */
    KW_IN = 287,                   /* KW_IN  */
    KW_INLINE = 288,               /* KW_INLINE  */
    KW_INOUT = 289,                /* KW_INOUT  */
    KW_LINEAR = 290,               /* KW_LINEAR  */
    KW_MATRIX = 291,               /* KW_MATRIX  */
    KW_NAMESPACE = 292,            /* KW_NAMESPACE  */
    KW_NOINTERPOLATION = 293,      /* KW_NOINTERPOLATION  */
    KW_NOPERSPECTIVE = 294,        /* KW_NOPERSPECTIVE  */
    KW_NULL = 295,                 /* KW_NULL  */
    KW_OUT = 296,                  /* KW_OUT  */
    KW_PACKOFFSET = 297,           /* KW_PACKOFFSET  */
    KW_PASS = 298,                 /* KW_PASS  */
    KW_PIXELSHADER = 299,          /* KW_PIXELSHADER  */
    KW_RASTERIZERORDEREDBUFFER = 300, /* KW_RASTERIZERORDEREDBUFFER  */
    KW_RASTERIZERORDEREDSTRUCTUREDBUFFER = 301, /* KW_RASTERIZERORDEREDSTRUCTUREDBUFFER  */
    KW_RASTERIZERORDEREDTEXTURE1D = 302, /* KW_RASTERIZERORDEREDTEXTURE1D  */
    KW_RASTERIZERORDEREDTEXTURE1DARRAY = 303, /* KW_RASTERIZERORDEREDTEXTURE1DARRAY  */
    KW_RASTERIZERORDEREDTEXTURE2D = 304, /* KW_RASTERIZERORDEREDTEXTURE2D  */
    KW_RASTERIZERORDEREDTEXTURE2DARRAY = 305, /* KW_RASTERIZERORDEREDTEXTURE2DARRAY  */
    KW_RASTERIZERORDEREDTEXTURE3D = 306, /* KW_RASTERIZERORDEREDTEXTURE3D  */
    KW_RASTERIZERSTATE = 307,      /* KW_RASTERIZERSTATE  */
    KW_RENDERTARGETVIEW = 308,     /* KW_RENDERTARGETVIEW  */
    KW_RETURN = 309,               /* KW_RETURN  */
    KW_REGISTER = 310,             /* KW_REGISTER  */
    KW_ROW_MAJOR = 311,            /* KW_ROW_MAJOR  */
    KW_RWBUFFER = 312,             /* KW_RWBUFFER  */
    KW_RWSTRUCTUREDBUFFER = 313,   /* KW_RWSTRUCTUREDBUFFER  */
    KW_RWTEXTURE1D = 314,          /* KW_RWTEXTURE1D  */
    KW_RWTEXTURE1DARRAY = 315,     /* KW_RWTEXTURE1DARRAY  */
    KW_RWTEXTURE2D = 316,          /* KW_RWTEXTURE2D  */
    KW_RWTEXTURE2DARRAY = 317,     /* KW_RWTEXTURE2DARRAY  */
    KW_RWTEXTURE3D = 318,          /* KW_RWTEXTURE3D  */
    KW_SAMPLER = 319,              /* KW_SAMPLER  */
    KW_SAMPLER1D = 320,            /* KW_SAMPLER1D  */
    KW_SAMPLER2D = 321,            /* KW_SAMPLER2D  */
    KW_SAMPLER3D = 322,            /* KW_SAMPLER3D  */
    KW_SAMPLERCUBE = 323,          /* KW_SAMPLERCUBE  */
    KW_SAMPLER_STATE = 324,        /* KW_SAMPLER_STATE  */
    KW_SAMPLERCOMPARISONSTATE = 325, /* KW_SAMPLERCOMPARISONSTATE  */
    KW_SHARED = 326,               /* KW_SHARED  */
    KW_STATEBLOCK = 327,           /* KW_STATEBLOCK  */
    KW_STATEBLOCK_STATE = 328,     /* KW_STATEBLOCK_STATE  */
    KW_STATIC = 329,               /* KW_STATIC  */
    KW_STRING = 330,               /* KW_STRING  */
    KW_STRUCT = 331,               /* KW_STRUCT  */
    KW_SWITCH = 332,               /* KW_SWITCH  */
    KW_TBUFFER = 333,              /* KW_TBUFFER  */
    KW_TECHNIQUE = 334,            /* KW_TECHNIQUE  */
    KW_TECHNIQUE10 = 335,          /* KW_TECHNIQUE10  */
    KW_TECHNIQUE11 = 336,          /* KW_TECHNIQUE11  */
    KW_TEXTURE = 337,              /* KW_TEXTURE  */
    KW_TEXTURE1D = 338,            /* KW_TEXTURE1D  */
    KW_TEXTURE1DARRAY = 339,       /* KW_TEXTURE1DARRAY  */
    KW_TEXTURE2D = 340,            /* KW_TEXTURE2D  */
    KW_TEXTURE2DARRAY = 341,       /* KW_TEXTURE2DARRAY  */
    KW_TEXTURE2DMS = 342,          /* KW_TEXTURE2DMS  */
    KW_TEXTURE2DMSARRAY = 343,     /* KW_TEXTURE2DMSARRAY  */
    KW_TEXTURE3D = 344,            /* KW_TEXTURE3D  */
    KW_TEXTURECUBE = 345,          /* KW_TEXTURECUBE  */
    KW_TEXTURECUBEARRAY = 346,     /* KW_TEXTURECUBEARRAY  */
    KW_TRUE = 347,                 /* KW_TRUE  */
    KW_TYPEDEF = 348,              /* KW_TYPEDEF  */
    KW_UNSIGNED = 349,             /* KW_UNSIGNED  */
    KW_UNIFORM = 350,              /* KW_UNIFORM  */
    KW_VECTOR = 351,               /* KW_VECTOR  */
    KW_VERTEXSHADER = 352,         /* KW_VERTEXSHADER  */
    KW_VOID = 353,                 /* KW_VOID  */
    KW_VOLATILE = 354,             /* KW_VOLATILE  */
    KW_WHILE = 355,                /* KW_WHILE  */
    OP_INC = 356,                  /* OP_INC  */
    OP_DEC = 357,                  /* OP_DEC  */
    OP_AND = 358,                  /* OP_AND  */
    OP_OR = 359,                   /* OP_OR  */
    OP_EQ = 360,                   /* OP_EQ  */
    OP_LEFTSHIFT = 361,            /* OP_LEFTSHIFT  */
    OP_LEFTSHIFTASSIGN = 362,      /* OP_LEFTSHIFTASSIGN  */
    OP_RIGHTSHIFT = 363,           /* OP_RIGHTSHIFT  */
    OP_RIGHTSHIFTASSIGN = 364,     /* OP_RIGHTSHIFTASSIGN  */
    OP_LE = 365,                   /* OP_LE  */
    OP_GE = 366,                   /* OP_GE  */
    OP_NE = 367,                   /* OP_NE  */
    OP_ADDASSIGN = 368,            /* OP_ADDASSIGN  */
    OP_SUBASSIGN = 369,            /* OP_SUBASSIGN  */
    OP_MULASSIGN = 370,            /* OP_MULASSIGN  */
    OP_DIVASSIGN = 371,            /* OP_DIVASSIGN  */
    OP_MODASSIGN = 372,            /* OP_MODASSIGN  */
    OP_ANDASSIGN = 373,            /* OP_ANDASSIGN  */
    OP_ORASSIGN = 374,             /* OP_ORASSIGN  */
    OP_XORASSIGN = 375,            /* OP_XORASSIGN  */
    C_FLOAT = 376,                 /* C_FLOAT  */
    C_INTEGER = 377,               /* C_INTEGER  */
    C_UNSIGNED = 378,              /* C_UNSIGNED  */
    PRE_LINE = 379,                /* PRE_LINE  */
    VAR_IDENTIFIER = 380,          /* VAR_IDENTIFIER  */
    NEW_IDENTIFIER = 381,          /* NEW_IDENTIFIER  */
    STRING = 382,                  /* STRING  */
    TYPE_IDENTIFIER = 383          /* TYPE_IDENTIFIER  */
  };
  typedef enum hlsl_yytokentype hlsl_yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined HLSL_YYSTYPE && ! defined HLSL_YYSTYPE_IS_DECLARED
union HLSL_YYSTYPE
{
#line 6020 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"

    struct hlsl_type *type;
    INT intval;
    FLOAT floatval;
    bool boolval;
    char *name;
    uint32_t modifiers;
    struct hlsl_ir_node *instr;
    struct hlsl_block *block;
    struct list *list;
    struct parse_fields fields;
    struct parse_function function;
    struct parse_parameter parameter;
    struct hlsl_func_parameters parameters;
    struct parse_initializer initializer;
    struct parse_array_sizes arrays;
    struct parse_variable_def *variable_def;
    struct parse_if_body if_body;
    enum parse_assign_op assign_op;
    struct hlsl_reg_reservation reg_reservation;
    struct parse_colon_attribute colon_attribute;
    struct hlsl_semantic semantic;
    enum hlsl_buffer_type buffer_type;
    enum hlsl_sampler_dim sampler_dim;
    struct hlsl_attribute *attr;
    struct parse_attribute_list attr_list;
    struct hlsl_ir_switch_case *switch_case;
    struct hlsl_scope *scope;
    struct hlsl_state_block *state_block;
    struct state_block_index state_block_index;

#line 400 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"

};
typedef union HLSL_YYSTYPE HLSL_YYSTYPE;
# define HLSL_YYSTYPE_IS_TRIVIAL 1
# define HLSL_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HLSL_YYLTYPE && ! defined HLSL_YYLTYPE_IS_DECLARED
typedef struct HLSL_YYLTYPE HLSL_YYLTYPE;
struct HLSL_YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HLSL_YYLTYPE_IS_DECLARED 1
# define HLSL_YYLTYPE_IS_TRIVIAL 1
#endif




int hlsl_yyparse (void *scanner, struct hlsl_ctx *ctx);

/* "%code provides" blocks.  */
#line 132 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"


int yylex(HLSL_YYSTYPE *yylval_param, HLSL_YYLTYPE *yylloc_param, void *yyscanner);


#line 434 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_BLENDSTATE = 3,              /* KW_BLENDSTATE  */
  YYSYMBOL_KW_BREAK = 4,                   /* KW_BREAK  */
  YYSYMBOL_KW_BUFFER = 5,                  /* KW_BUFFER  */
  YYSYMBOL_KW_CASE = 6,                    /* KW_CASE  */
  YYSYMBOL_KW_CONSTANTBUFFER = 7,          /* KW_CONSTANTBUFFER  */
  YYSYMBOL_KW_CBUFFER = 8,                 /* KW_CBUFFER  */
  YYSYMBOL_KW_CENTROID = 9,                /* KW_CENTROID  */
  YYSYMBOL_KW_COLUMN_MAJOR = 10,           /* KW_COLUMN_MAJOR  */
  YYSYMBOL_KW_COMPILE = 11,                /* KW_COMPILE  */
  YYSYMBOL_KW_COMPUTESHADER = 12,          /* KW_COMPUTESHADER  */
  YYSYMBOL_KW_CONST = 13,                  /* KW_CONST  */
  YYSYMBOL_KW_CONTINUE = 14,               /* KW_CONTINUE  */
  YYSYMBOL_KW_DEFAULT = 15,                /* KW_DEFAULT  */
  YYSYMBOL_KW_DEPTHSTENCILSTATE = 16,      /* KW_DEPTHSTENCILSTATE  */
  YYSYMBOL_KW_DEPTHSTENCILVIEW = 17,       /* KW_DEPTHSTENCILVIEW  */
  YYSYMBOL_KW_DISCARD = 18,                /* KW_DISCARD  */
  YYSYMBOL_KW_DO = 19,                     /* KW_DO  */
  YYSYMBOL_KW_DOMAINSHADER = 20,           /* KW_DOMAINSHADER  */
  YYSYMBOL_KW_DOUBLE = 21,                 /* KW_DOUBLE  */
  YYSYMBOL_KW_ELSE = 22,                   /* KW_ELSE  */
  YYSYMBOL_KW_EXPORT = 23,                 /* KW_EXPORT  */
  YYSYMBOL_KW_EXTERN = 24,                 /* KW_EXTERN  */
  YYSYMBOL_KW_FALSE = 25,                  /* KW_FALSE  */
  YYSYMBOL_KW_FOR = 26,                    /* KW_FOR  */
  YYSYMBOL_KW_FXGROUP = 27,                /* KW_FXGROUP  */
  YYSYMBOL_KW_GEOMETRYSHADER = 28,         /* KW_GEOMETRYSHADER  */
  YYSYMBOL_KW_GROUPSHARED = 29,            /* KW_GROUPSHARED  */
  YYSYMBOL_KW_HULLSHADER = 30,             /* KW_HULLSHADER  */
  YYSYMBOL_KW_IF = 31,                     /* KW_IF  */
  YYSYMBOL_KW_IN = 32,                     /* KW_IN  */
  YYSYMBOL_KW_INLINE = 33,                 /* KW_INLINE  */
  YYSYMBOL_KW_INOUT = 34,                  /* KW_INOUT  */
  YYSYMBOL_KW_LINEAR = 35,                 /* KW_LINEAR  */
  YYSYMBOL_KW_MATRIX = 36,                 /* KW_MATRIX  */
  YYSYMBOL_KW_NAMESPACE = 37,              /* KW_NAMESPACE  */
  YYSYMBOL_KW_NOINTERPOLATION = 38,        /* KW_NOINTERPOLATION  */
  YYSYMBOL_KW_NOPERSPECTIVE = 39,          /* KW_NOPERSPECTIVE  */
  YYSYMBOL_KW_NULL = 40,                   /* KW_NULL  */
  YYSYMBOL_KW_OUT = 41,                    /* KW_OUT  */
  YYSYMBOL_KW_PACKOFFSET = 42,             /* KW_PACKOFFSET  */
  YYSYMBOL_KW_PASS = 43,                   /* KW_PASS  */
  YYSYMBOL_KW_PIXELSHADER = 44,            /* KW_PIXELSHADER  */
  YYSYMBOL_KW_RASTERIZERORDEREDBUFFER = 45, /* KW_RASTERIZERORDEREDBUFFER  */
  YYSYMBOL_KW_RASTERIZERORDEREDSTRUCTUREDBUFFER = 46, /* KW_RASTERIZERORDEREDSTRUCTUREDBUFFER  */
  YYSYMBOL_KW_RASTERIZERORDEREDTEXTURE1D = 47, /* KW_RASTERIZERORDEREDTEXTURE1D  */
  YYSYMBOL_KW_RASTERIZERORDEREDTEXTURE1DARRAY = 48, /* KW_RASTERIZERORDEREDTEXTURE1DARRAY  */
  YYSYMBOL_KW_RASTERIZERORDEREDTEXTURE2D = 49, /* KW_RASTERIZERORDEREDTEXTURE2D  */
  YYSYMBOL_KW_RASTERIZERORDEREDTEXTURE2DARRAY = 50, /* KW_RASTERIZERORDEREDTEXTURE2DARRAY  */
  YYSYMBOL_KW_RASTERIZERORDEREDTEXTURE3D = 51, /* KW_RASTERIZERORDEREDTEXTURE3D  */
  YYSYMBOL_KW_RASTERIZERSTATE = 52,        /* KW_RASTERIZERSTATE  */
  YYSYMBOL_KW_RENDERTARGETVIEW = 53,       /* KW_RENDERTARGETVIEW  */
  YYSYMBOL_KW_RETURN = 54,                 /* KW_RETURN  */
  YYSYMBOL_KW_REGISTER = 55,               /* KW_REGISTER  */
  YYSYMBOL_KW_ROW_MAJOR = 56,              /* KW_ROW_MAJOR  */
  YYSYMBOL_KW_RWBUFFER = 57,               /* KW_RWBUFFER  */
  YYSYMBOL_KW_RWSTRUCTUREDBUFFER = 58,     /* KW_RWSTRUCTUREDBUFFER  */
  YYSYMBOL_KW_RWTEXTURE1D = 59,            /* KW_RWTEXTURE1D  */
  YYSYMBOL_KW_RWTEXTURE1DARRAY = 60,       /* KW_RWTEXTURE1DARRAY  */
  YYSYMBOL_KW_RWTEXTURE2D = 61,            /* KW_RWTEXTURE2D  */
  YYSYMBOL_KW_RWTEXTURE2DARRAY = 62,       /* KW_RWTEXTURE2DARRAY  */
  YYSYMBOL_KW_RWTEXTURE3D = 63,            /* KW_RWTEXTURE3D  */
  YYSYMBOL_KW_SAMPLER = 64,                /* KW_SAMPLER  */
  YYSYMBOL_KW_SAMPLER1D = 65,              /* KW_SAMPLER1D  */
  YYSYMBOL_KW_SAMPLER2D = 66,              /* KW_SAMPLER2D  */
  YYSYMBOL_KW_SAMPLER3D = 67,              /* KW_SAMPLER3D  */
  YYSYMBOL_KW_SAMPLERCUBE = 68,            /* KW_SAMPLERCUBE  */
  YYSYMBOL_KW_SAMPLER_STATE = 69,          /* KW_SAMPLER_STATE  */
  YYSYMBOL_KW_SAMPLERCOMPARISONSTATE = 70, /* KW_SAMPLERCOMPARISONSTATE  */
  YYSYMBOL_KW_SHARED = 71,                 /* KW_SHARED  */
  YYSYMBOL_KW_STATEBLOCK = 72,             /* KW_STATEBLOCK  */
  YYSYMBOL_KW_STATEBLOCK_STATE = 73,       /* KW_STATEBLOCK_STATE  */
  YYSYMBOL_KW_STATIC = 74,                 /* KW_STATIC  */
  YYSYMBOL_KW_STRING = 75,                 /* KW_STRING  */
  YYSYMBOL_KW_STRUCT = 76,                 /* KW_STRUCT  */
  YYSYMBOL_KW_SWITCH = 77,                 /* KW_SWITCH  */
  YYSYMBOL_KW_TBUFFER = 78,                /* KW_TBUFFER  */
  YYSYMBOL_KW_TECHNIQUE = 79,              /* KW_TECHNIQUE  */
  YYSYMBOL_KW_TECHNIQUE10 = 80,            /* KW_TECHNIQUE10  */
  YYSYMBOL_KW_TECHNIQUE11 = 81,            /* KW_TECHNIQUE11  */
  YYSYMBOL_KW_TEXTURE = 82,                /* KW_TEXTURE  */
  YYSYMBOL_KW_TEXTURE1D = 83,              /* KW_TEXTURE1D  */
  YYSYMBOL_KW_TEXTURE1DARRAY = 84,         /* KW_TEXTURE1DARRAY  */
  YYSYMBOL_KW_TEXTURE2D = 85,              /* KW_TEXTURE2D  */
  YYSYMBOL_KW_TEXTURE2DARRAY = 86,         /* KW_TEXTURE2DARRAY  */
  YYSYMBOL_KW_TEXTURE2DMS = 87,            /* KW_TEXTURE2DMS  */
  YYSYMBOL_KW_TEXTURE2DMSARRAY = 88,       /* KW_TEXTURE2DMSARRAY  */
  YYSYMBOL_KW_TEXTURE3D = 89,              /* KW_TEXTURE3D  */
  YYSYMBOL_KW_TEXTURECUBE = 90,            /* KW_TEXTURECUBE  */
  YYSYMBOL_KW_TEXTURECUBEARRAY = 91,       /* KW_TEXTURECUBEARRAY  */
  YYSYMBOL_KW_TRUE = 92,                   /* KW_TRUE  */
  YYSYMBOL_KW_TYPEDEF = 93,                /* KW_TYPEDEF  */
  YYSYMBOL_KW_UNSIGNED = 94,               /* KW_UNSIGNED  */
  YYSYMBOL_KW_UNIFORM = 95,                /* KW_UNIFORM  */
  YYSYMBOL_KW_VECTOR = 96,                 /* KW_VECTOR  */
  YYSYMBOL_KW_VERTEXSHADER = 97,           /* KW_VERTEXSHADER  */
  YYSYMBOL_KW_VOID = 98,                   /* KW_VOID  */
  YYSYMBOL_KW_VOLATILE = 99,               /* KW_VOLATILE  */
  YYSYMBOL_KW_WHILE = 100,                 /* KW_WHILE  */
  YYSYMBOL_OP_INC = 101,                   /* OP_INC  */
  YYSYMBOL_OP_DEC = 102,                   /* OP_DEC  */
  YYSYMBOL_OP_AND = 103,                   /* OP_AND  */
  YYSYMBOL_OP_OR = 104,                    /* OP_OR  */
  YYSYMBOL_OP_EQ = 105,                    /* OP_EQ  */
  YYSYMBOL_OP_LEFTSHIFT = 106,             /* OP_LEFTSHIFT  */
  YYSYMBOL_OP_LEFTSHIFTASSIGN = 107,       /* OP_LEFTSHIFTASSIGN  */
  YYSYMBOL_OP_RIGHTSHIFT = 108,            /* OP_RIGHTSHIFT  */
  YYSYMBOL_OP_RIGHTSHIFTASSIGN = 109,      /* OP_RIGHTSHIFTASSIGN  */
  YYSYMBOL_OP_LE = 110,                    /* OP_LE  */
  YYSYMBOL_OP_GE = 111,                    /* OP_GE  */
  YYSYMBOL_OP_NE = 112,                    /* OP_NE  */
  YYSYMBOL_OP_ADDASSIGN = 113,             /* OP_ADDASSIGN  */
  YYSYMBOL_OP_SUBASSIGN = 114,             /* OP_SUBASSIGN  */
  YYSYMBOL_OP_MULASSIGN = 115,             /* OP_MULASSIGN  */
  YYSYMBOL_OP_DIVASSIGN = 116,             /* OP_DIVASSIGN  */
  YYSYMBOL_OP_MODASSIGN = 117,             /* OP_MODASSIGN  */
  YYSYMBOL_OP_ANDASSIGN = 118,             /* OP_ANDASSIGN  */
  YYSYMBOL_OP_ORASSIGN = 119,              /* OP_ORASSIGN  */
  YYSYMBOL_OP_XORASSIGN = 120,             /* OP_XORASSIGN  */
  YYSYMBOL_C_FLOAT = 121,                  /* C_FLOAT  */
  YYSYMBOL_C_INTEGER = 122,                /* C_INTEGER  */
  YYSYMBOL_C_UNSIGNED = 123,               /* C_UNSIGNED  */
  YYSYMBOL_PRE_LINE = 124,                 /* PRE_LINE  */
  YYSYMBOL_VAR_IDENTIFIER = 125,           /* VAR_IDENTIFIER  */
  YYSYMBOL_NEW_IDENTIFIER = 126,           /* NEW_IDENTIFIER  */
  YYSYMBOL_STRING = 127,                   /* STRING  */
  YYSYMBOL_TYPE_IDENTIFIER = 128,          /* TYPE_IDENTIFIER  */
  YYSYMBOL_129_ = 129,                     /* ';'  */
  YYSYMBOL_130_ = 130,                     /* '{'  */
  YYSYMBOL_131_ = 131,                     /* '}'  */
  YYSYMBOL_132_ = 132,                     /* '<'  */
  YYSYMBOL_133_ = 133,                     /* '>'  */
  YYSYMBOL_134_ = 134,                     /* '['  */
  YYSYMBOL_135_ = 135,                     /* ']'  */
  YYSYMBOL_136_ = 136,                     /* '('  */
  YYSYMBOL_137_ = 137,                     /* ')'  */
  YYSYMBOL_138_ = 138,                     /* ':'  */
  YYSYMBOL_139_ = 139,                     /* ','  */
  YYSYMBOL_140_ = 140,                     /* '.'  */
  YYSYMBOL_141_ = 141,                     /* '='  */
  YYSYMBOL_142_ = 142,                     /* '+'  */
  YYSYMBOL_143_ = 143,                     /* '-'  */
  YYSYMBOL_144_ = 144,                     /* '~'  */
  YYSYMBOL_145_ = 145,                     /* '!'  */
  YYSYMBOL_146_ = 146,                     /* '*'  */
  YYSYMBOL_147_ = 147,                     /* '/'  */
  YYSYMBOL_148_ = 148,                     /* '%'  */
  YYSYMBOL_149_ = 149,                     /* '&'  */
  YYSYMBOL_150_ = 150,                     /* '^'  */
  YYSYMBOL_151_ = 151,                     /* '|'  */
  YYSYMBOL_152_ = 152,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 153,                 /* $accept  */
  YYSYMBOL_hlsl_prog = 154,                /* hlsl_prog  */
  YYSYMBOL_name_opt = 155,                 /* name_opt  */
  YYSYMBOL_pass = 156,                     /* pass  */
  YYSYMBOL_annotations_list = 157,         /* annotations_list  */
  YYSYMBOL_annotations_opt = 158,          /* annotations_opt  */
  YYSYMBOL_pass_list = 159,                /* pass_list  */
  YYSYMBOL_passes = 160,                   /* passes  */
  YYSYMBOL_technique9 = 161,               /* technique9  */
  YYSYMBOL_technique10 = 162,              /* technique10  */
  YYSYMBOL_technique11 = 163,              /* technique11  */
  YYSYMBOL_global_technique = 164,         /* global_technique  */
  YYSYMBOL_group_technique = 165,          /* group_technique  */
  YYSYMBOL_group_techniques = 166,         /* group_techniques  */
  YYSYMBOL_effect_group = 167,             /* effect_group  */
  YYSYMBOL_buffer_declaration = 168,       /* buffer_declaration  */
  YYSYMBOL_buffer_body = 169,              /* buffer_body  */
  YYSYMBOL_buffer_type = 170,              /* buffer_type  */
  YYSYMBOL_declaration_statement_list = 171, /* declaration_statement_list  */
  YYSYMBOL_preproc_directive = 172,        /* preproc_directive  */
  YYSYMBOL_struct_declaration_without_vars = 173, /* struct_declaration_without_vars  */
  YYSYMBOL_struct_spec = 174,              /* struct_spec  */
  YYSYMBOL_named_struct_spec = 175,        /* named_struct_spec  */
  YYSYMBOL_unnamed_struct_spec = 176,      /* unnamed_struct_spec  */
  YYSYMBOL_any_identifier = 177,           /* any_identifier  */
  YYSYMBOL_fields_list = 178,              /* fields_list  */
  YYSYMBOL_field_type = 179,               /* field_type  */
  YYSYMBOL_field = 180,                    /* field  */
  YYSYMBOL_attribute = 181,                /* attribute  */
  YYSYMBOL_attribute_list = 182,           /* attribute_list  */
  YYSYMBOL_attribute_list_optional = 183,  /* attribute_list_optional  */
  YYSYMBOL_func_declaration = 184,         /* func_declaration  */
  YYSYMBOL_func_prototype_no_attrs = 185,  /* func_prototype_no_attrs  */
  YYSYMBOL_func_prototype = 186,           /* func_prototype  */
  YYSYMBOL_compound_statement = 187,       /* compound_statement  */
  YYSYMBOL_scope_start = 188,              /* scope_start  */
  YYSYMBOL_loop_scope_start = 189,         /* loop_scope_start  */
  YYSYMBOL_switch_scope_start = 190,       /* switch_scope_start  */
  YYSYMBOL_annotations_scope_start = 191,  /* annotations_scope_start  */
  YYSYMBOL_var_identifier = 192,           /* var_identifier  */
  YYSYMBOL_colon_attribute = 193,          /* colon_attribute  */
  YYSYMBOL_semantic = 194,                 /* semantic  */
  YYSYMBOL_register_reservation = 195,     /* register_reservation  */
  YYSYMBOL_packoffset_reservation = 196,   /* packoffset_reservation  */
  YYSYMBOL_parameters = 197,               /* parameters  */
  YYSYMBOL_param_list = 198,               /* param_list  */
  YYSYMBOL_parameter = 199,                /* parameter  */
  YYSYMBOL_parameter_decl = 200,           /* parameter_decl  */
  YYSYMBOL_texture_type = 201,             /* texture_type  */
  YYSYMBOL_texture_ms_type = 202,          /* texture_ms_type  */
  YYSYMBOL_uav_type = 203,                 /* uav_type  */
  YYSYMBOL_rov_type = 204,                 /* rov_type  */
  YYSYMBOL_type_no_void = 205,             /* type_no_void  */
  YYSYMBOL_type = 206,                     /* type  */
  YYSYMBOL_declaration_statement = 207,    /* declaration_statement  */
  YYSYMBOL_typedef_type = 208,             /* typedef_type  */
  YYSYMBOL_typedef = 209,                  /* typedef  */
  YYSYMBOL_type_specs = 210,               /* type_specs  */
  YYSYMBOL_type_spec = 211,                /* type_spec  */
  YYSYMBOL_declaration = 212,              /* declaration  */
  YYSYMBOL_variables_def = 213,            /* variables_def  */
  YYSYMBOL_variables_def_typed = 214,      /* variables_def_typed  */
  YYSYMBOL_variable_decl = 215,            /* variable_decl  */
  YYSYMBOL_state_block_start = 216,        /* state_block_start  */
  YYSYMBOL_stateblock_lhs_identifier = 217, /* stateblock_lhs_identifier  */
  YYSYMBOL_state_block_index_opt = 218,    /* state_block_index_opt  */
  YYSYMBOL_state_block = 219,              /* state_block  */
  YYSYMBOL_state_block_list = 220,         /* state_block_list  */
  YYSYMBOL_variable_def = 221,             /* variable_def  */
  YYSYMBOL_variable_def_typed = 222,       /* variable_def_typed  */
  YYSYMBOL_array = 223,                    /* array  */
  YYSYMBOL_arrays = 224,                   /* arrays  */
  YYSYMBOL_var_modifiers = 225,            /* var_modifiers  */
  YYSYMBOL_complex_initializer = 226,      /* complex_initializer  */
  YYSYMBOL_complex_initializer_list = 227, /* complex_initializer_list  */
  YYSYMBOL_initializer_expr = 228,         /* initializer_expr  */
  YYSYMBOL_initializer_expr_list = 229,    /* initializer_expr_list  */
  YYSYMBOL_boolean = 230,                  /* boolean  */
  YYSYMBOL_statement_list = 231,           /* statement_list  */
  YYSYMBOL_statement = 232,                /* statement  */
  YYSYMBOL_jump_statement = 233,           /* jump_statement  */
  YYSYMBOL_selection_statement = 234,      /* selection_statement  */
  YYSYMBOL_if_body = 235,                  /* if_body  */
  YYSYMBOL_loop_statement = 236,           /* loop_statement  */
  YYSYMBOL_switch_statement = 237,         /* switch_statement  */
  YYSYMBOL_switch_case = 238,              /* switch_case  */
  YYSYMBOL_switch_cases = 239,             /* switch_cases  */
  YYSYMBOL_expr_optional = 240,            /* expr_optional  */
  YYSYMBOL_expr_statement = 241,           /* expr_statement  */
  YYSYMBOL_func_arguments = 242,           /* func_arguments  */
  YYSYMBOL_primary_expr = 243,             /* primary_expr  */
  YYSYMBOL_postfix_expr = 244,             /* postfix_expr  */
  YYSYMBOL_unary_expr = 245,               /* unary_expr  */
  YYSYMBOL_mul_expr = 246,                 /* mul_expr  */
  YYSYMBOL_add_expr = 247,                 /* add_expr  */
  YYSYMBOL_shift_expr = 248,               /* shift_expr  */
  YYSYMBOL_relational_expr = 249,          /* relational_expr  */
  YYSYMBOL_equality_expr = 250,            /* equality_expr  */
  YYSYMBOL_bitand_expr = 251,              /* bitand_expr  */
  YYSYMBOL_bitxor_expr = 252,              /* bitxor_expr  */
  YYSYMBOL_bitor_expr = 253,               /* bitor_expr  */
  YYSYMBOL_logicand_expr = 254,            /* logicand_expr  */
  YYSYMBOL_logicor_expr = 255,             /* logicor_expr  */
  YYSYMBOL_conditional_expr = 256,         /* conditional_expr  */
  YYSYMBOL_assignment_expr = 257,          /* assignment_expr  */
  YYSYMBOL_assign_op = 258,                /* assign_op  */
  YYSYMBOL_expr = 259                      /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 139 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"


#define YYLLOC_DEFAULT(cur, rhs, n) (cur) = YYRHSLOC(rhs, !!n)

static void yyerror(YYLTYPE *loc, void *scanner, struct hlsl_ctx *ctx, const char *s)
{
    hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "%s", s);
}

static struct hlsl_ir_node *node_from_block(struct hlsl_block *block)
{
    return LIST_ENTRY(list_tail(&block->instrs), struct hlsl_ir_node, entry);
}

static struct hlsl_block *make_empty_block(struct hlsl_ctx *ctx)
{
    struct hlsl_block *block;

    if ((block = hlsl_alloc(ctx, sizeof(*block))))
        hlsl_block_init(block);
    return block;
}

static struct list *make_empty_list(struct hlsl_ctx *ctx)
{
    struct list *list;

    if ((list = hlsl_alloc(ctx, sizeof(*list))))
        list_init(list);
    return list;
}

static void destroy_block(struct hlsl_block *block)
{
    if (!block)
        return;

    hlsl_block_cleanup(block);
    vkd3d_free(block);
}

static void destroy_switch_cases(struct list *cases)
{
    hlsl_cleanup_ir_switch_cases(cases);
    vkd3d_free(cases);
}

static bool hlsl_types_are_componentwise_compatible(struct hlsl_ctx *ctx, struct hlsl_type *src,
        struct hlsl_type *dst)
{
    unsigned int k, count = hlsl_type_component_count(dst);

    if (count > hlsl_type_component_count(src))
        return false;

    for (k = 0; k < count; ++k)
    {
        struct hlsl_type *src_comp_type, *dst_comp_type;

        src_comp_type = hlsl_type_get_component_type(ctx, src, k);
        dst_comp_type = hlsl_type_get_component_type(ctx, dst, k);

        if ((src_comp_type->class != HLSL_CLASS_SCALAR || dst_comp_type->class != HLSL_CLASS_SCALAR)
                && !hlsl_types_are_equal(src_comp_type, dst_comp_type))
            return false;
    }
    return true;
}

static bool hlsl_types_are_componentwise_equal(struct hlsl_ctx *ctx, struct hlsl_type *src,
        struct hlsl_type *dst)
{
    unsigned int k, count = hlsl_type_component_count(src);

    if (count != hlsl_type_component_count(dst))
        return false;

    for (k = 0; k < count; ++k)
    {
        struct hlsl_type *src_comp_type, *dst_comp_type;

        src_comp_type = hlsl_type_get_component_type(ctx, src, k);
        dst_comp_type = hlsl_type_get_component_type(ctx, dst, k);

        if (!hlsl_types_are_equal(src_comp_type, dst_comp_type))
            return false;
    }
    return true;
}

static bool type_contains_only_numerics(const struct hlsl_type *type)
{
    unsigned int i;

    if (type->class == HLSL_CLASS_ARRAY)
        return type_contains_only_numerics(type->e.array.type);
    if (type->class == HLSL_CLASS_STRUCT)
    {
        for (i = 0; i < type->e.record.field_count; ++i)
        {
            if (!type_contains_only_numerics(type->e.record.fields[i].type))
                return false;
        }
        return true;
    }
    return hlsl_is_numeric_type(type);
}

static bool explicit_compatible_data_types(struct hlsl_ctx *ctx, struct hlsl_type *src, struct hlsl_type *dst)
{
    if (hlsl_is_numeric_type(src) && src->dimx == 1 && src->dimy == 1 && type_contains_only_numerics(dst))
        return true;

    if (src->class == HLSL_CLASS_MATRIX && dst->class == HLSL_CLASS_MATRIX
            && src->dimx >= dst->dimx && src->dimy >= dst->dimy)
        return true;

    if ((src->class == HLSL_CLASS_MATRIX && src->dimx > 1 && src->dimy > 1)
            && hlsl_type_component_count(src) != hlsl_type_component_count(dst))
        return false;

    if ((dst->class == HLSL_CLASS_MATRIX && dst->dimy > 1)
            && hlsl_type_component_count(src) != hlsl_type_component_count(dst))
        return false;

    return hlsl_types_are_componentwise_compatible(ctx, src, dst);
}

static bool implicit_compatible_data_types(struct hlsl_ctx *ctx, struct hlsl_type *src, struct hlsl_type *dst)
{
    if (hlsl_is_numeric_type(src) != hlsl_is_numeric_type(dst))
        return false;

    if (hlsl_is_numeric_type(src))
    {
        /* Scalar vars can be converted to any other numeric data type */
        if (src->dimx == 1 && src->dimy == 1)
            return true;
        /* The other way around is true too */
        if (dst->dimx == 1 && dst->dimy == 1)
            return true;

        if (src->class == HLSL_CLASS_MATRIX || dst->class == HLSL_CLASS_MATRIX)
        {
            if (src->class == HLSL_CLASS_MATRIX && dst->class == HLSL_CLASS_MATRIX)
                return src->dimx >= dst->dimx && src->dimy >= dst->dimy;

            /* Matrix-vector conversion is apparently allowed if they have
            * the same components count, or if the matrix is 1xN or Nx1
            * and we are reducing the component count */
            if (src->class == HLSL_CLASS_VECTOR || dst->class == HLSL_CLASS_VECTOR)
            {
                if (hlsl_type_component_count(src) == hlsl_type_component_count(dst))
                    return true;

                if ((src->class == HLSL_CLASS_VECTOR || src->dimx == 1 || src->dimy == 1) &&
                        (dst->class == HLSL_CLASS_VECTOR || dst->dimx == 1 || dst->dimy == 1))
                    return hlsl_type_component_count(src) >= hlsl_type_component_count(dst);
            }

            return false;
        }
        else
        {
            return src->dimx >= dst->dimx;
        }
    }

    if (src->class == HLSL_CLASS_NULL)
    {
        switch (dst->class)
        {
            case HLSL_CLASS_DEPTH_STENCIL_STATE:
            case HLSL_CLASS_DEPTH_STENCIL_VIEW:
            case HLSL_CLASS_PIXEL_SHADER:
            case HLSL_CLASS_RASTERIZER_STATE:
            case HLSL_CLASS_RENDER_TARGET_VIEW:
            case HLSL_CLASS_SAMPLER:
            case HLSL_CLASS_STRING:
            case HLSL_CLASS_TEXTURE:
            case HLSL_CLASS_UAV:
            case HLSL_CLASS_VERTEX_SHADER:
                return true;
            default:
                break;
        }
    }

    return hlsl_types_are_componentwise_equal(ctx, src, dst);
}

static void check_condition_type(struct hlsl_ctx *ctx, const struct hlsl_ir_node *cond)
{
    const struct hlsl_type *type = cond->data_type;

    if (type->class > HLSL_CLASS_LAST_NUMERIC || type->dimx > 1 || type->dimy > 1)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, type)))
            hlsl_error(ctx, &cond->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Condition type '%s' is not a scalar numeric type.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
}

static struct hlsl_ir_node *add_cast(struct hlsl_ctx *ctx, struct hlsl_block *block,
        struct hlsl_ir_node *node, struct hlsl_type *dst_type, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *src_type = node->data_type;
    struct hlsl_ir_node *cast;

    if (hlsl_types_are_equal(src_type, dst_type))
        return node;

    if (src_type->class == HLSL_CLASS_NULL)
        return node;

    if (src_type->class > HLSL_CLASS_VECTOR || dst_type->class > HLSL_CLASS_VECTOR)
    {
        unsigned int src_comp_count = hlsl_type_component_count(src_type);
        unsigned int dst_comp_count = hlsl_type_component_count(dst_type);
        struct hlsl_deref var_deref;
        bool broadcast, matrix_cast;
        struct hlsl_ir_load *load;
        struct hlsl_ir_var *var;
        unsigned int dst_idx;

        broadcast = hlsl_is_numeric_type(src_type) && src_type->dimx == 1 && src_type->dimy == 1;
        matrix_cast = !broadcast && dst_comp_count != src_comp_count
                && src_type->class == HLSL_CLASS_MATRIX && dst_type->class == HLSL_CLASS_MATRIX;
        VKD3D_ASSERT(src_comp_count >= dst_comp_count || broadcast);
        if (matrix_cast)
        {
            VKD3D_ASSERT(dst_type->dimx <= src_type->dimx);
            VKD3D_ASSERT(dst_type->dimy <= src_type->dimy);
        }

        if (!(var = hlsl_new_synthetic_var(ctx, "cast", dst_type, loc)))
            return NULL;
        hlsl_init_simple_deref_from_var(&var_deref, var);

        for (dst_idx = 0; dst_idx < dst_comp_count; ++dst_idx)
        {
            struct hlsl_ir_node *component_load;
            struct hlsl_type *dst_comp_type;
            struct hlsl_block store_block;
            unsigned int src_idx;

            if (broadcast)
            {
                src_idx = 0;
            }
            else if (matrix_cast)
            {
                unsigned int x = dst_idx % dst_type->dimx, y = dst_idx / dst_type->dimx;

                src_idx = y * src_type->dimx + x;
            }
            else
            {
                src_idx = dst_idx;
            }

            dst_comp_type = hlsl_type_get_component_type(ctx, dst_type, dst_idx);

            if (!(component_load = hlsl_add_load_component(ctx, block, node, src_idx, loc)))
                return NULL;

            if (!(cast = hlsl_new_cast(ctx, component_load, dst_comp_type, loc)))
                return NULL;
            hlsl_block_add_instr(block, cast);

            if (!hlsl_new_store_component(ctx, &store_block, &var_deref, dst_idx, cast))
                return NULL;
            hlsl_block_add_block(block, &store_block);
        }

        if (!(load = hlsl_new_var_load(ctx, var, loc)))
            return NULL;
        hlsl_block_add_instr(block, &load->node);

        return &load->node;
    }
    else
    {
        if (!(cast = hlsl_new_cast(ctx, node, dst_type, loc)))
            return NULL;
        hlsl_block_add_instr(block, cast);
        return cast;
    }
}

static struct hlsl_ir_node *add_implicit_conversion(struct hlsl_ctx *ctx, struct hlsl_block *block,
        struct hlsl_ir_node *node, struct hlsl_type *dst_type, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *src_type = node->data_type;

    if (hlsl_types_are_equal(src_type, dst_type))
        return node;

    if (!implicit_compatible_data_types(ctx, src_type, dst_type))
    {
        struct vkd3d_string_buffer *src_string, *dst_string;

        src_string = hlsl_type_to_string(ctx, src_type);
        dst_string = hlsl_type_to_string(ctx, dst_type);
        if (src_string && dst_string)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Can't implicitly convert from %s to %s.", src_string->buffer, dst_string->buffer);
        hlsl_release_string_buffer(ctx, src_string);
        hlsl_release_string_buffer(ctx, dst_string);
        return NULL;
    }

    if (dst_type->dimx * dst_type->dimy < src_type->dimx * src_type->dimy && ctx->warn_implicit_truncation)
        hlsl_warning(ctx, loc, VKD3D_SHADER_WARNING_HLSL_IMPLICIT_TRUNCATION, "Implicit truncation of %s type.",
                src_type->class == HLSL_CLASS_VECTOR ? "vector" : "matrix");

    return add_cast(ctx, block, node, dst_type, loc);
}

static uint32_t add_modifiers(struct hlsl_ctx *ctx, uint32_t modifiers, uint32_t mod,
        const struct vkd3d_shader_location *loc)
{
    if (modifiers & mod)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_modifiers_to_string(ctx, mod)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                    "Modifier '%s' was already specified.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return modifiers;
    }
    return modifiers | mod;
}

static bool append_conditional_break(struct hlsl_ctx *ctx, struct hlsl_block *cond_block)
{
    struct hlsl_ir_node *condition, *cast, *not, *iff, *jump;
    struct hlsl_block then_block;
    struct hlsl_type *bool_type;

    /* E.g. "for (i = 0; ; ++i)". */
    if (list_empty(&cond_block->instrs))
        return true;

    condition = node_from_block(cond_block);

    check_condition_type(ctx, condition);

    bool_type = hlsl_get_scalar_type(ctx, HLSL_TYPE_BOOL);
    if (!(cast = hlsl_new_cast(ctx, condition, bool_type, &condition->loc)))
        return false;
    hlsl_block_add_instr(cond_block, cast);

    if (!(not = hlsl_new_unary_expr(ctx, HLSL_OP1_LOGIC_NOT, cast, &condition->loc)))
        return false;
    hlsl_block_add_instr(cond_block, not);

    hlsl_block_init(&then_block);

    if (!(jump = hlsl_new_jump(ctx, HLSL_IR_JUMP_BREAK, NULL, &condition->loc)))
        return false;
    hlsl_block_add_instr(&then_block, jump);

    if (!(iff = hlsl_new_if(ctx, not, &then_block, NULL, &condition->loc)))
        return false;
    hlsl_block_add_instr(cond_block, iff);
    return true;
}

enum loop_type
{
    LOOP_FOR,
    LOOP_WHILE,
    LOOP_DO_WHILE
};

static bool attribute_list_has_duplicates(const struct parse_attribute_list *attrs)
{
    unsigned int i, j;

    for (i = 0; i < attrs->count; ++i)
    {
        for (j = i + 1; j < attrs->count; ++j)
        {
            if (!strcmp(attrs->attrs[i]->name, attrs->attrs[j]->name))
                 return true;
        }
    }

    return false;
}

static void resolve_loop_continue(struct hlsl_ctx *ctx, struct hlsl_block *block, enum loop_type type,
        struct hlsl_block *cond, struct hlsl_block *iter)
{
    struct hlsl_ir_node *instr, *next;

    LIST_FOR_EACH_ENTRY_SAFE(instr, next, &block->instrs, struct hlsl_ir_node, entry)
    {
        if (instr->type == HLSL_IR_IF)
        {
            struct hlsl_ir_if *iff = hlsl_ir_if(instr);

            resolve_loop_continue(ctx, &iff->then_block, type, cond, iter);
            resolve_loop_continue(ctx, &iff->else_block, type, cond, iter);
        }
        else if (instr->type == HLSL_IR_JUMP)
        {
            struct hlsl_ir_jump *jump = hlsl_ir_jump(instr);
            struct hlsl_block cond_block;

            if (jump->type != HLSL_IR_JUMP_UNRESOLVED_CONTINUE)
                continue;

            if (type == LOOP_DO_WHILE)
            {
                if (!hlsl_clone_block(ctx, &cond_block, cond))
                    return;
                if (!append_conditional_break(ctx, &cond_block))
                {
                    hlsl_block_cleanup(&cond_block);
                    return;
                }
                list_move_before(&instr->entry, &cond_block.instrs);
            }
            else if (type == LOOP_FOR)
            {
                if (!hlsl_clone_block(ctx, &cond_block, iter))
                    return;
                list_move_before(&instr->entry, &cond_block.instrs);
            }
            jump->type = HLSL_IR_JUMP_CONTINUE;
        }
    }
}

static void check_loop_attributes(struct hlsl_ctx *ctx, const struct parse_attribute_list *attributes,
        const struct vkd3d_shader_location *loc)
{
    bool has_unroll = false, has_loop = false, has_fastopt = false;
    unsigned int i;

    for (i = 0; i < attributes->count; ++i)
    {
        const char *name = attributes->attrs[i]->name;

        has_loop |= !strcmp(name, "loop");
        has_unroll |= !strcmp(name, "unroll");
        has_fastopt |= !strcmp(name, "fastopt");
    }

    if (has_unroll && has_loop)
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Unroll attribute can't be used with 'loop' attribute.");

    if (has_unroll && has_fastopt)
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Unroll attribute can't be used with 'fastopt' attribute.");
}

static struct hlsl_default_value evaluate_static_expression(struct hlsl_ctx *ctx,
        struct hlsl_block *block, struct hlsl_type *dst_type, const struct vkd3d_shader_location *loc)
{
    struct hlsl_default_value ret = {0};
    struct hlsl_ir_node *node;
    struct hlsl_block expr;
    struct hlsl_src src;

    LIST_FOR_EACH_ENTRY(node, &block->instrs, struct hlsl_ir_node, entry)
    {
        switch (node->type)
        {
            case HLSL_IR_CONSTANT:
            case HLSL_IR_EXPR:
            case HLSL_IR_STRING_CONSTANT:
            case HLSL_IR_SWIZZLE:
            case HLSL_IR_LOAD:
            case HLSL_IR_INDEX:
                continue;
            case HLSL_IR_STORE:
                if (hlsl_ir_store(node)->lhs.var->is_synthetic)
                    break;
                /* fall-through */
            case HLSL_IR_CALL:
            case HLSL_IR_IF:
            case HLSL_IR_LOOP:
            case HLSL_IR_JUMP:
            case HLSL_IR_RESOURCE_LOAD:
            case HLSL_IR_RESOURCE_STORE:
            case HLSL_IR_SWITCH:
            case HLSL_IR_STATEBLOCK_CONSTANT:
                hlsl_error(ctx, &node->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                        "Expected literal expression.");
                break;
        }
    }

    if (!hlsl_clone_block(ctx, &expr, &ctx->static_initializers))
        return ret;
    hlsl_block_add_block(&expr, block);

    if (!add_implicit_conversion(ctx, &expr, node_from_block(&expr), dst_type, loc))
    {
        hlsl_block_cleanup(&expr);
        return ret;
    }

    /* Wrap the node into a src to allow the reference to survive the multiple const passes. */
    hlsl_src_from_node(&src, node_from_block(&expr));
    hlsl_run_const_passes(ctx, &expr);
    node = src.node;
    hlsl_src_remove(&src);

    if (node->type == HLSL_IR_CONSTANT)
    {
        struct hlsl_ir_constant *constant = hlsl_ir_constant(node);

        ret.number = constant->value.u[0];
    }
    else if (node->type == HLSL_IR_STRING_CONSTANT)
    {
        struct hlsl_ir_string_constant *string = hlsl_ir_string_constant(node);

        if (!(ret.string = vkd3d_strdup(string->string)))
            return ret;
    }
    else if (node->type == HLSL_IR_STRING_CONSTANT)
    {
        hlsl_fixme(ctx, &node->loc, "Evaluate string constants as static expressions.");
    }
    else
    {
        hlsl_error(ctx, &node->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                "Failed to evaluate constant expression.");
    }

    hlsl_block_cleanup(&expr);

    return ret;
}

static unsigned int evaluate_static_expression_as_uint(struct hlsl_ctx *ctx, struct hlsl_block *block,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_default_value res;

    res = evaluate_static_expression(ctx, block, hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT), loc);
    VKD3D_ASSERT(!res.string);
    return res.number.u;
}

static struct hlsl_block *create_loop(struct hlsl_ctx *ctx, enum loop_type type,
        const struct parse_attribute_list *attributes, struct hlsl_block *init, struct hlsl_block *cond,
        struct hlsl_block *iter, struct hlsl_block *body, const struct vkd3d_shader_location *loc)
{
    enum hlsl_ir_loop_unroll_type unroll_type = HLSL_IR_LOOP_UNROLL;
    unsigned int i, unroll_limit = 0;
    struct hlsl_ir_node *loop;

    if (attribute_list_has_duplicates(attributes))
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Found duplicate attribute.");

    check_loop_attributes(ctx, attributes, loc);

    /* Ignore unroll(0) attribute, and any invalid attribute. */
    for (i = 0; i < attributes->count; ++i)
    {
        const struct hlsl_attribute *attr = attributes->attrs[i];
        if (!strcmp(attr->name, "unroll"))
        {
            if (attr->args_count > 1)
            {
                hlsl_warning(ctx, &attr->loc, VKD3D_SHADER_WARNING_HLSL_IGNORED_ATTRIBUTE,
                        "Ignoring 'unroll' attribute with more than 1 argument.");
                continue;
            }

            if (attr->args_count == 1)
            {
                struct hlsl_block expr;
                hlsl_block_init(&expr);
                if (!hlsl_clone_block(ctx, &expr, &attr->instrs))
                    return NULL;

                unroll_limit = evaluate_static_expression_as_uint(ctx, &expr, loc);
                hlsl_block_cleanup(&expr);
            }

            unroll_type = HLSL_IR_LOOP_FORCE_UNROLL;
        }
        else if (!strcmp(attr->name, "loop"))
        {
            unroll_type = HLSL_IR_LOOP_FORCE_LOOP;
        }
        else if (!strcmp(attr->name, "fastopt")
                || !strcmp(attr->name, "allow_uav_condition"))
        {
            hlsl_fixme(ctx, loc, "Unhandled attribute '%s'.", attr->name);
        }
        else
        {
            hlsl_warning(ctx, loc, VKD3D_SHADER_WARNING_HLSL_UNKNOWN_ATTRIBUTE, "Unrecognized attribute '%s'.", attr->name);
        }
    }

    resolve_loop_continue(ctx, body, type, cond, iter);

    if (!init && !(init = make_empty_block(ctx)))
        goto oom;

    if (!append_conditional_break(ctx, cond))
        goto oom;

    if (iter)
        hlsl_block_add_block(body, iter);

    if (type == LOOP_DO_WHILE)
        list_move_tail(&body->instrs, &cond->instrs);
    else
        list_move_head(&body->instrs, &cond->instrs);

    if (!(loop = hlsl_new_loop(ctx, body, unroll_type, unroll_limit, loc)))
        goto oom;
    hlsl_block_add_instr(init, loop);

    destroy_block(cond);
    destroy_block(body);
    destroy_block(iter);
    return init;

oom:
    destroy_block(init);
    destroy_block(cond);
    destroy_block(iter);
    destroy_block(body);
    return NULL;
}

static unsigned int initializer_size(const struct parse_initializer *initializer)
{
    unsigned int count = 0, i;

    for (i = 0; i < initializer->args_count; ++i)
    {
        count += hlsl_type_component_count(initializer->args[i]->data_type);
    }
    return count;
}

static void cleanup_parse_attribute_list(struct parse_attribute_list *attr_list)
{
    unsigned int i = 0;

    VKD3D_ASSERT(attr_list);
    for (i = 0; i < attr_list->count; ++i)
        hlsl_free_attribute((struct hlsl_attribute *) attr_list->attrs[i]);
    vkd3d_free(attr_list->attrs);
}

static void free_parse_initializer(struct parse_initializer *initializer)
{
    destroy_block(initializer->instrs);
    vkd3d_free(initializer->args);
}

static struct hlsl_ir_node *get_swizzle(struct hlsl_ctx *ctx, struct hlsl_ir_node *value, const char *swizzle,
        struct vkd3d_shader_location *loc)
{
    unsigned int len = strlen(swizzle), component = 0;
    unsigned int i, set, swiz = 0;
    bool valid;

    if (value->data_type->class == HLSL_CLASS_MATRIX)
    {
        /* Matrix swizzle */
        bool m_swizzle;
        unsigned int inc, x, y;

        if (len < 3 || swizzle[0] != '_')
            return NULL;
        m_swizzle = swizzle[1] == 'm';
        inc = m_swizzle ? 4 : 3;

        if (len % inc || len > inc * 4)
            return NULL;

        for (i = 0; i < len; i += inc)
        {
            if (swizzle[i] != '_')
                return NULL;
            if (m_swizzle)
            {
                if (swizzle[i + 1] != 'm')
                    return NULL;
                y = swizzle[i + 2] - '0';
                x = swizzle[i + 3] - '0';
            }
            else
            {
                y = swizzle[i + 1] - '1';
                x = swizzle[i + 2] - '1';
            }

            if (x >= value->data_type->dimx || y >= value->data_type->dimy)
                return NULL;
            swiz |= (y << 4 | x) << component * 8;
            component++;
        }
        return hlsl_new_swizzle(ctx, swiz, component, value, loc);
    }

    /* Vector swizzle */
    if (len > 4)
        return NULL;

    for (set = 0; set < 2; ++set)
    {
        valid = true;
        component = 0;
        for (i = 0; i < len; ++i)
        {
            char c[2][4] = {{'x', 'y', 'z', 'w'}, {'r', 'g', 'b', 'a'}};
            unsigned int s = 0;

            for (s = 0; s < 4; ++s)
            {
                if (swizzle[i] == c[set][s])
                    break;
            }
            if (s == 4)
            {
                valid = false;
                break;
            }

            if (s >= value->data_type->dimx)
                return NULL;
            swiz |= s << component * 2;
            component++;
        }
        if (valid)
            return hlsl_new_swizzle(ctx, swiz, component, value, loc);
    }

    return NULL;
}

static bool add_return(struct hlsl_ctx *ctx, struct hlsl_block *block,
        struct hlsl_ir_node *return_value, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *return_type = ctx->cur_function->return_type;
    struct hlsl_ir_node *jump;

    if (ctx->cur_function->return_var)
    {
        if (return_value)
        {
            struct hlsl_ir_node *store;

            if (!(return_value = add_implicit_conversion(ctx, block, return_value, return_type, loc)))
                return false;

            if (!(store = hlsl_new_simple_store(ctx, ctx->cur_function->return_var, return_value)))
                return false;
            list_add_after(&return_value->entry, &store->entry);
        }
        else
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RETURN, "Non-void functions must return a value.");
            return false;
        }
    }
    else
    {
        if (return_value)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RETURN, "Void functions cannot return a value.");
    }

    if (!(jump = hlsl_new_jump(ctx, HLSL_IR_JUMP_RETURN, NULL, loc)))
        return false;
    hlsl_block_add_instr(block, jump);

    return true;
}

struct hlsl_ir_node *hlsl_add_load_component(struct hlsl_ctx *ctx, struct hlsl_block *block,
        struct hlsl_ir_node *var_instr, unsigned int comp, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *load, *store;
    struct hlsl_block load_block;
    struct hlsl_ir_var *var;
    struct hlsl_deref src;

    if (!(var = hlsl_new_synthetic_var(ctx, "deref", var_instr->data_type, &var_instr->loc)))
        return NULL;

    if (!(store = hlsl_new_simple_store(ctx, var, var_instr)))
        return NULL;
    hlsl_block_add_instr(block, store);

    hlsl_init_simple_deref_from_var(&src, var);
    if (!(load = hlsl_new_load_component(ctx, &load_block, &src, comp, loc)))
        return NULL;
    hlsl_block_add_block(block, &load_block);

    return load;
}

static bool add_record_access(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *record,
        unsigned int idx, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *index, *c;

    VKD3D_ASSERT(idx < record->data_type->e.record.field_count);

    if (!(c = hlsl_new_uint_constant(ctx, idx, loc)))
        return false;
    hlsl_block_add_instr(block, c);

    if (!(index = hlsl_new_index(ctx, record, c, loc)))
        return false;
    hlsl_block_add_instr(block, index);

    return true;
}

static struct hlsl_ir_node *add_binary_arithmetic_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc);

static bool add_array_access(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *array,
        struct hlsl_ir_node *index, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *expr_type = array->data_type, *index_type = index->data_type;
    struct hlsl_ir_node *return_index, *cast;

    if ((expr_type->class == HLSL_CLASS_TEXTURE || expr_type->class == HLSL_CLASS_UAV)
            && expr_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC)
    {
        unsigned int dim_count = hlsl_sampler_dim_count(expr_type->sampler_dim);

        if (index_type->class > HLSL_CLASS_VECTOR || index_type->dimx != dim_count)
        {
            struct vkd3d_string_buffer *string;

            if ((string = hlsl_type_to_string(ctx, expr_type)))
                hlsl_error(ctx, &index->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "Array index of type '%s' must be of type 'uint%u'.", string->buffer, dim_count);
            hlsl_release_string_buffer(ctx, string);
            return false;
        }

        if (!(index = add_implicit_conversion(ctx, block, index,
                hlsl_get_vector_type(ctx, HLSL_TYPE_UINT, dim_count), &index->loc)))
            return false;

        if (!(return_index = hlsl_new_index(ctx, array, index, loc)))
            return false;
        hlsl_block_add_instr(block, return_index);

        return true;
    }

    if (index_type->class != HLSL_CLASS_SCALAR)
    {
        hlsl_error(ctx, &index->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Array index is not scalar.");
        return false;
    }

    if (!(cast = hlsl_new_cast(ctx, index, hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT), &index->loc)))
        return false;
    hlsl_block_add_instr(block, cast);
    index = cast;

    if (expr_type->class != HLSL_CLASS_ARRAY && expr_type->class != HLSL_CLASS_VECTOR && expr_type->class != HLSL_CLASS_MATRIX)
    {
        if (expr_type->class == HLSL_CLASS_SCALAR)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_INDEX, "Scalar expressions cannot be array-indexed.");
        else
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_INDEX, "Expression cannot be array-indexed.");
        return false;
    }

    if (!(return_index = hlsl_new_index(ctx, array, index, loc)))
        return false;
    hlsl_block_add_instr(block, return_index);

    return true;
}

static const struct hlsl_struct_field *get_struct_field(const struct hlsl_struct_field *fields,
        size_t count, const char *name)
{
    size_t i;

    for (i = 0; i < count; ++i)
    {
        if (!strcmp(fields[i].name, name))
            return &fields[i];
    }
    return NULL;
}

static struct hlsl_type *apply_type_modifiers(struct hlsl_ctx *ctx, struct hlsl_type *type,
        uint32_t *modifiers, bool force_majority, const struct vkd3d_shader_location *loc)
{
    unsigned int default_majority = 0;
    struct hlsl_type *new_type;

    if (!(*modifiers & HLSL_MODIFIERS_MAJORITY_MASK)
            && !(type->modifiers & HLSL_MODIFIERS_MAJORITY_MASK)
            && type->class == HLSL_CLASS_MATRIX)
    {
        if (!(default_majority = ctx->matrix_majority) && force_majority)
            default_majority = HLSL_MODIFIER_COLUMN_MAJOR;
    }
    else if (type->class != HLSL_CLASS_MATRIX && (*modifiers & HLSL_MODIFIERS_MAJORITY_MASK))
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                "'row_major' and 'column_major' modifiers are only allowed for matrices.");
    }

    if (!default_majority && !(*modifiers & HLSL_TYPE_MODIFIERS_MASK))
        return type;

    if (!(new_type = hlsl_type_clone(ctx, type, default_majority, *modifiers & HLSL_TYPE_MODIFIERS_MASK)))
        return NULL;

    *modifiers &= ~HLSL_TYPE_MODIFIERS_MASK;

    if ((new_type->modifiers & HLSL_MODIFIER_ROW_MAJOR) && (new_type->modifiers & HLSL_MODIFIER_COLUMN_MAJOR))
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                "'row_major' and 'column_major' modifiers are mutually exclusive.");

    return new_type;
}

static void free_parse_variable_def(struct parse_variable_def *v)
{
    free_parse_initializer(&v->initializer);
    vkd3d_free(v->arrays.sizes);
    vkd3d_free(v->name);
    hlsl_cleanup_semantic(&v->semantic);
    VKD3D_ASSERT(!v->state_blocks);
    vkd3d_free(v);
}

static bool gen_struct_fields(struct hlsl_ctx *ctx, struct parse_fields *fields,
        struct hlsl_type *type, uint32_t modifiers, struct list *defs)
{
    struct parse_variable_def *v, *v_next;
    size_t i = 0;

    if (type->class == HLSL_CLASS_MATRIX)
        VKD3D_ASSERT(type->modifiers & HLSL_MODIFIERS_MAJORITY_MASK);

    memset(fields, 0, sizeof(*fields));
    fields->count = list_count(defs);
    if (!hlsl_array_reserve(ctx, (void **)&fields->fields, &fields->capacity, fields->count, sizeof(*fields->fields)))
        return false;

    LIST_FOR_EACH_ENTRY_SAFE(v, v_next, defs, struct parse_variable_def, entry)
    {
        struct hlsl_struct_field *field = &fields->fields[i++];
        bool unbounded_res_array = false;
        unsigned int k;

        field->type = type;

        if (hlsl_version_ge(ctx, 5, 1) && hlsl_type_is_resource(type))
        {
            for (k = 0; k < v->arrays.count; ++k)
                unbounded_res_array |= (v->arrays.sizes[k] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT);
        }

        if (unbounded_res_array)
        {
            if (v->arrays.count == 1)
            {
                hlsl_fixme(ctx, &v->loc, "Unbounded resource arrays as struct fields.");
                free_parse_variable_def(v);
                vkd3d_free(field);
                continue;
            }
            else
            {
                hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "Unbounded resource arrays cannot be multi-dimensional.");
            }
        }
        else
        {
            for (k = 0; k < v->arrays.count; ++k)
            {
                if (v->arrays.sizes[k] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT)
                {
                    hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Implicit size arrays not allowed in struct fields.");
                }

                field->type = hlsl_new_array_type(ctx, field->type, v->arrays.sizes[k]);
            }
        }

        if (hlsl_version_ge(ctx, 5, 1) && field->type->class == HLSL_CLASS_ARRAY && hlsl_type_is_resource(field->type))
            hlsl_fixme(ctx, &v->loc, "Shader model 5.1+ resource array.");

        vkd3d_free(v->arrays.sizes);
        field->loc = v->loc;
        field->name = v->name;
        field->semantic = v->semantic;
        field->storage_modifiers = modifiers;
        if (v->initializer.args_count)
        {
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Illegal initializer on a struct field.");
            free_parse_initializer(&v->initializer);
        }
        if (v->reg_reservation.offset_type)
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                "packoffset() is not allowed inside struct definitions.");
        vkd3d_free(v);
    }
    vkd3d_free(defs);
    return true;
}

static bool add_typedef(struct hlsl_ctx *ctx, struct hlsl_type *const orig_type, struct list *list)
{
    struct parse_variable_def *v, *v_next;
    struct hlsl_type *type;
    unsigned int i;
    bool ret;

    LIST_FOR_EACH_ENTRY_SAFE(v, v_next, list, struct parse_variable_def, entry)
    {
        if (!v->arrays.count)
        {
            if (!(type = hlsl_type_clone(ctx, orig_type, 0, 0)))
            {
                free_parse_variable_def(v);
                continue;
            }
        }
        else
        {
            uint32_t var_modifiers = 0;

            if (!(type = apply_type_modifiers(ctx, orig_type, &var_modifiers, true, &v->loc)))
            {
                free_parse_variable_def(v);
                continue;
            }
        }

        ret = true;
        for (i = 0; i < v->arrays.count; ++i)
        {
            if (v->arrays.sizes[i] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT)
            {
                hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "Implicit size arrays not allowed in typedefs.");
            }

            if (!(type = hlsl_new_array_type(ctx, type, v->arrays.sizes[i])))
            {
                free_parse_variable_def(v);
                ret = false;
                break;
            }
        }
        if (!ret)
            continue;
        vkd3d_free(v->arrays.sizes);

        vkd3d_free((void *)type->name);
        type->name = v->name;

        ret = hlsl_scope_add_type(ctx->cur_scope, type);
        if (!ret)
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                    "Type '%s' is already defined.", v->name);
        free_parse_initializer(&v->initializer);
        vkd3d_free(v);
    }
    vkd3d_free(list);
    return true;
}

static void initialize_var_components(struct hlsl_ctx *ctx, struct hlsl_block *instrs,
        struct hlsl_ir_var *dst, unsigned int *store_index, struct hlsl_ir_node *src);

static bool add_func_parameter(struct hlsl_ctx *ctx, struct hlsl_func_parameters *parameters,
        struct parse_parameter *param, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_var *var;

    if (param->type->class == HLSL_CLASS_MATRIX)
        VKD3D_ASSERT(param->type->modifiers & HLSL_MODIFIERS_MAJORITY_MASK);

    if ((param->modifiers & HLSL_STORAGE_OUT) && (param->modifiers & HLSL_STORAGE_UNIFORM))
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                "Parameter '%s' is declared as both \"out\" and \"uniform\".", param->name);

    if (param->reg_reservation.offset_type)
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                "packoffset() is not allowed on function parameters.");

    if (parameters->count && parameters->vars[parameters->count - 1]->default_values
                && !param->initializer.args_count)
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_MISSING_INITIALIZER,
                "Missing default value for parameter '%s'.", param->name);

    if (param->initializer.args_count && (param->modifiers & HLSL_STORAGE_OUT))
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                "Output parameter '%s' has a default value.", param->name);

    if (!(var = hlsl_new_var(ctx, param->name, param->type, loc, &param->semantic, param->modifiers,
            &param->reg_reservation)))
        return false;
    var->is_param = 1;

    if (param->initializer.args_count)
    {
        unsigned int component_count = hlsl_type_component_count(param->type);
        unsigned int store_index = 0;
        unsigned int size, i;

        if (!(var->default_values = hlsl_calloc(ctx, component_count, sizeof(*var->default_values))))
            return false;

        if (!param->initializer.braces)
        {
            if (!(add_implicit_conversion(ctx, param->initializer.instrs, param->initializer.args[0], param->type, loc)))
                return false;

            param->initializer.args[0] = node_from_block(param->initializer.instrs);
        }

        size = initializer_size(&param->initializer);
        if (component_count != size)
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                    "Expected %u components in initializer, but got %u.", component_count, size);
        }

        for (i = 0; i < param->initializer.args_count; ++i)
        {
            initialize_var_components(ctx, param->initializer.instrs, var, &store_index, param->initializer.args[i]);
        }

        free_parse_initializer(&param->initializer);
    }

    if (!hlsl_add_var(ctx, var, false))
    {
        hlsl_free_var(var);
        return false;
    }

    if (!hlsl_array_reserve(ctx, (void **)&parameters->vars, &parameters->capacity,
            parameters->count + 1, sizeof(*parameters->vars)))
        return false;
    parameters->vars[parameters->count++] = var;
    return true;
}

static bool add_pass(struct hlsl_ctx *ctx, const char *name, struct hlsl_scope *annotations,
        struct hlsl_state_block *state_block, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_var *var;
    struct hlsl_type *type;

    type = hlsl_get_type(ctx->globals, "pass", false, false);
    if (!(var = hlsl_new_var(ctx, name, type, loc, NULL, 0, NULL)))
        return false;
    var->annotations = annotations;

    var->state_blocks = hlsl_alloc(ctx, sizeof(*var->state_blocks));
    var->state_blocks[0] = state_block;
    var->state_block_count = 1;
    var->state_block_capacity = 1;

    if (!hlsl_add_var(ctx, var, false))
    {
        struct hlsl_ir_var *old = hlsl_get_var(ctx->cur_scope, var->name);

        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                "Identifier \"%s\" was already declared in this scope.", var->name);
        hlsl_note(ctx, &old->loc, VKD3D_SHADER_LOG_ERROR, "\"%s\" was previously declared here.", old->name);
        hlsl_free_var(var);
        return false;
    }

    return true;
}

static bool add_technique(struct hlsl_ctx *ctx, const char *name, struct hlsl_scope *scope,
        struct hlsl_scope *annotations, const char *typename, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_var *var;
    struct hlsl_type *type;

    type = hlsl_get_type(ctx->globals, typename, false, false);
    if (!(var = hlsl_new_var(ctx, name, type, loc, NULL, 0, NULL)))
        return false;
    var->scope = scope;
    var->annotations = annotations;

    if (!hlsl_add_var(ctx, var, false))
    {
        struct hlsl_ir_var *old = hlsl_get_var(ctx->cur_scope, var->name);

        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                "Identifier \"%s\" was already declared in this scope.", var->name);
        hlsl_note(ctx, &old->loc, VKD3D_SHADER_LOG_ERROR, "\"%s\" was previously declared here.", old->name);
        hlsl_free_var(var);
        return false;
    }

    return true;
}

static bool add_effect_group(struct hlsl_ctx *ctx, const char *name, struct hlsl_scope *scope,
        struct hlsl_scope *annotations, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_var *var;
    struct hlsl_type *type;

    type = hlsl_get_type(ctx->globals, "fxgroup", false, false);
    if (!(var = hlsl_new_var(ctx, name, type, loc, NULL, 0, NULL)))
        return false;
    var->scope = scope;
    var->annotations = annotations;

    if (!hlsl_add_var(ctx, var, false))
    {
        struct hlsl_ir_var *old = hlsl_get_var(ctx->cur_scope, var->name);

        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                "Identifier \"%s\" was already declared in this scope.", var->name);
        hlsl_note(ctx, &old->loc, VKD3D_SHADER_LOG_ERROR, "\"%s\" was previously declared here.", old->name);
        hlsl_free_var(var);
        return false;
    }

    return true;
}

static bool parse_reservation_index(struct hlsl_ctx *ctx, const char *string, unsigned int bracket_offset,
        struct hlsl_reg_reservation *reservation)
{
    char *endptr;

    reservation->reg_type = ascii_tolower(string[0]);

    /* Prior to SM5.1, fxc simply ignored bracket offsets for 'b' types. */
    if (reservation->reg_type == 'b' && hlsl_version_lt(ctx, 5, 1))
    {
        bracket_offset = 0;
    }

    if (string[1] == '\0')
    {
        reservation->reg_index = bracket_offset;
        return true;
    }

    reservation->reg_index = strtoul(string + 1, &endptr, 10) + bracket_offset;

    if (*endptr)
    {
        /* fxc for SM >= 4 treats all parse failures for 'b' types as successes,
         * setting index to -1. It will later fail while validating slot limits. */
        if (reservation->reg_type == 'b' && hlsl_version_ge(ctx, 4, 0))
        {
            reservation->reg_index = -1;
            return true;
        }

        /* All other types tolerate leftover characters. */
        if (endptr == string + 1)
            return false;
    }

    return true;
}

static bool parse_reservation_space(const char *string, uint32_t *space)
{
    return !ascii_strncasecmp(string, "space", 5) && sscanf(string + 5, "%u", space);
}

static struct hlsl_reg_reservation parse_packoffset(struct hlsl_ctx *ctx, const char *reg_string,
        const char *swizzle, const struct vkd3d_shader_location *loc)
{
    struct hlsl_reg_reservation reservation = {0};
    char *endptr;

    if (hlsl_version_lt(ctx, 4, 0))
        return reservation;

    reservation.offset_index = strtoul(reg_string + 1, &endptr, 10);
    if (*endptr)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                "Invalid packoffset() syntax.");
        return reservation;
    }

    reservation.offset_type = ascii_tolower(reg_string[0]);
    if (reservation.offset_type != 'c')
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                "Only 'c' registers are allowed in packoffset().");
        return reservation;
    }

    reservation.offset_index *= 4;

    if (swizzle)
    {
        if (strlen(swizzle) != 1)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                    "Invalid packoffset() component \"%s\".", swizzle);

        if (swizzle[0] == 'x' || swizzle[0] == 'r')
            reservation.offset_index += 0;
        else if (swizzle[0] == 'y' || swizzle[0] == 'g')
            reservation.offset_index += 1;
        else if (swizzle[0] == 'z' || swizzle[0] == 'b')
            reservation.offset_index += 2;
        else if (swizzle[0] == 'w' || swizzle[0] == 'a')
            reservation.offset_index += 3;
        else
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                    "Invalid packoffset() component \"%s\".", swizzle);
    }

    return reservation;
}

static struct hlsl_block *make_block(struct hlsl_ctx *ctx, struct hlsl_ir_node *instr)
{
    struct hlsl_block *block;

    if (!(block = make_empty_block(ctx)))
    {
        hlsl_free_instr(instr);
        return NULL;
    }
    hlsl_block_add_instr(block, instr);
    return block;
}

static bool expr_compatible_data_types(struct hlsl_type *t1, struct hlsl_type *t2)
{
    /* Scalar vars can be converted to pretty much everything */
    if ((t1->dimx == 1 && t1->dimy == 1) || (t2->dimx == 1 && t2->dimy == 1))
        return true;

    if (t1->class == HLSL_CLASS_VECTOR && t2->class == HLSL_CLASS_VECTOR)
        return true;

    if (t1->class == HLSL_CLASS_MATRIX || t2->class == HLSL_CLASS_MATRIX)
    {
        /* Matrix-vector conversion is apparently allowed if either they have the same components
           count or the matrix is nx1 or 1xn */
        if (t1->class == HLSL_CLASS_VECTOR || t2->class == HLSL_CLASS_VECTOR)
        {
            if (hlsl_type_component_count(t1) == hlsl_type_component_count(t2))
                return true;

            return (t1->class == HLSL_CLASS_MATRIX && (t1->dimx == 1 || t1->dimy == 1))
                    || (t2->class == HLSL_CLASS_MATRIX && (t2->dimx == 1 || t2->dimy == 1));
        }

        /* Both matrices */
        if ((t1->dimx >= t2->dimx && t1->dimy >= t2->dimy)
                || (t1->dimx <= t2->dimx && t1->dimy <= t2->dimy))
            return true;
    }

    return false;
}

static enum hlsl_base_type expr_common_base_type(enum hlsl_base_type t1, enum hlsl_base_type t2)
{
    if (t1 == t2)
        return t1 == HLSL_TYPE_BOOL ? HLSL_TYPE_INT : t1;
    if (t1 == HLSL_TYPE_DOUBLE || t2 == HLSL_TYPE_DOUBLE)
        return HLSL_TYPE_DOUBLE;
    if (t1 == HLSL_TYPE_FLOAT || t2 == HLSL_TYPE_FLOAT
            || t1 == HLSL_TYPE_HALF || t2 == HLSL_TYPE_HALF)
        return HLSL_TYPE_FLOAT;
    if (t1 == HLSL_TYPE_UINT || t2 == HLSL_TYPE_UINT)
        return HLSL_TYPE_UINT;
    return HLSL_TYPE_INT;
}

static bool expr_common_shape(struct hlsl_ctx *ctx, struct hlsl_type *t1, struct hlsl_type *t2,
        const struct vkd3d_shader_location *loc, enum hlsl_type_class *type, unsigned int *dimx, unsigned int *dimy)
{
    if (!hlsl_is_numeric_type(t1))
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, t1)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Expression of type \"%s\" cannot be used in a numeric expression.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!hlsl_is_numeric_type(t2))
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, t2)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Expression of type \"%s\" cannot be used in a numeric expression.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!expr_compatible_data_types(t1, t2))
    {
        struct vkd3d_string_buffer *t1_string = hlsl_type_to_string(ctx, t1);
        struct vkd3d_string_buffer *t2_string = hlsl_type_to_string(ctx, t2);

        if (t1_string && t2_string)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Expression data types \"%s\" and \"%s\" are incompatible.",
                    t1_string->buffer, t2_string->buffer);
        hlsl_release_string_buffer(ctx, t1_string);
        hlsl_release_string_buffer(ctx, t2_string);
        return false;
    }

    if (t1->dimx == 1 && t1->dimy == 1)
    {
        *type = t2->class;
        *dimx = t2->dimx;
        *dimy = t2->dimy;
    }
    else if (t2->dimx == 1 && t2->dimy == 1)
    {
        *type = t1->class;
        *dimx = t1->dimx;
        *dimy = t1->dimy;
    }
    else if (t1->class == HLSL_CLASS_MATRIX && t2->class == HLSL_CLASS_MATRIX)
    {
        *type = HLSL_CLASS_MATRIX;
        *dimx = min(t1->dimx, t2->dimx);
        *dimy = min(t1->dimy, t2->dimy);
    }
    else
    {
        if (t1->dimx * t1->dimy <= t2->dimx * t2->dimy)
        {
            *type = t1->class;
            *dimx = t1->dimx;
            *dimy = t1->dimy;
        }
        else
        {
            *type = t2->class;
            *dimx = t2->dimx;
            *dimy = t2->dimy;
        }
    }

    return true;
}

static struct hlsl_ir_node *add_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS],
        struct hlsl_type *type, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *expr;
    unsigned int i;

    if (type->class == HLSL_CLASS_MATRIX)
    {
        struct hlsl_type *scalar_type;
        struct hlsl_ir_load *var_load;
        struct hlsl_deref var_deref;
        struct hlsl_ir_node *load;
        struct hlsl_ir_var *var;

        scalar_type = hlsl_get_scalar_type(ctx, type->e.numeric.type);

        if (!(var = hlsl_new_synthetic_var(ctx, "split_op", type, loc)))
            return NULL;
        hlsl_init_simple_deref_from_var(&var_deref, var);

        for (i = 0; i < type->dimy * type->dimx; ++i)
        {
            struct hlsl_ir_node *value, *cell_operands[HLSL_MAX_OPERANDS] = { NULL };
            struct hlsl_block store_block;
            unsigned int j;

            for (j = 0; j < HLSL_MAX_OPERANDS; j++)
            {
                if (operands[j])
                {
                    if (!(load = hlsl_add_load_component(ctx, block, operands[j], i, loc)))
                        return NULL;

                    cell_operands[j] = load;
                }
            }

            if (!(value = add_expr(ctx, block, op, cell_operands, scalar_type, loc)))
                return NULL;

            if (!hlsl_new_store_component(ctx, &store_block, &var_deref, i, value))
                return NULL;
            hlsl_block_add_block(block, &store_block);
        }

        if (!(var_load = hlsl_new_var_load(ctx, var, loc)))
            return NULL;
        hlsl_block_add_instr(block, &var_load->node);

        return &var_load->node;
    }

    if (!(expr = hlsl_new_expr(ctx, op, operands, type, loc)))
        return NULL;
    hlsl_block_add_instr(block, expr);

    return expr;
}

static void check_integer_type(struct hlsl_ctx *ctx, const struct hlsl_ir_node *instr)
{
    const struct hlsl_type *type = instr->data_type;
    struct vkd3d_string_buffer *string;

    switch (type->e.numeric.type)
    {
        case HLSL_TYPE_BOOL:
        case HLSL_TYPE_INT:
        case HLSL_TYPE_UINT:
            break;

        default:
            if ((string = hlsl_type_to_string(ctx, type)))
                hlsl_error(ctx, &instr->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "Expression type '%s' is not integer.", string->buffer);
            hlsl_release_string_buffer(ctx, string);
            break;
    }
}

static struct hlsl_ir_node *add_unary_arithmetic_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {arg};

    return add_expr(ctx, block, op, args, arg->data_type, loc);
}

static struct hlsl_ir_node *add_unary_bitwise_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg, const struct vkd3d_shader_location *loc)
{
    check_integer_type(ctx, arg);

    return add_unary_arithmetic_expr(ctx, block, op, arg, loc);
}

static struct hlsl_ir_node *add_unary_logical_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *bool_type;

    bool_type = hlsl_get_numeric_type(ctx, arg->data_type->class, HLSL_TYPE_BOOL,
            arg->data_type->dimx, arg->data_type->dimy);

    if (!(args[0] = add_implicit_conversion(ctx, block, arg, bool_type, loc)))
        return NULL;

    return add_expr(ctx, block, op, args, bool_type, loc);
}

static struct hlsl_type *get_common_numeric_type(struct hlsl_ctx *ctx, const struct hlsl_ir_node *arg1,
        const struct hlsl_ir_node *arg2, const struct vkd3d_shader_location *loc)
{
    enum hlsl_type_class type;
    enum hlsl_base_type base;
    unsigned int dimx, dimy;

    if (!expr_common_shape(ctx, arg1->data_type, arg2->data_type, loc, &type, &dimx, &dimy))
        return NULL;
    base = expr_common_base_type(arg1->data_type->e.numeric.type, arg2->data_type->e.numeric.type);
    return hlsl_get_numeric_type(ctx, type, base, dimx, dimy);
}

static struct hlsl_ir_node *add_binary_arithmetic_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *common_type;

    common_type = get_common_numeric_type(ctx, arg1, arg2, loc);

    if (!(args[0] = add_implicit_conversion(ctx, block, arg1, common_type, loc)))
        return NULL;

    if (!(args[1] = add_implicit_conversion(ctx, block, arg2, common_type, loc)))
        return NULL;

    return add_expr(ctx, block, op, args, common_type, loc);
}

static struct hlsl_ir_node *add_binary_bitwise_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    check_integer_type(ctx, arg1);
    check_integer_type(ctx, arg2);

    return add_binary_arithmetic_expr(ctx, block, op, arg1, arg2, loc);
}

static struct hlsl_ir_node *add_binary_comparison_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *common_type, *return_type;
    enum hlsl_type_class type;
    enum hlsl_base_type base;
    unsigned int dimx, dimy;
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};

    if (!expr_common_shape(ctx, arg1->data_type, arg2->data_type, loc, &type, &dimx, &dimy))
        return NULL;

    base = expr_common_base_type(arg1->data_type->e.numeric.type, arg2->data_type->e.numeric.type);
    common_type = hlsl_get_numeric_type(ctx, type, base, dimx, dimy);
    return_type = hlsl_get_numeric_type(ctx, type, HLSL_TYPE_BOOL, dimx, dimy);

    if (!(args[0] = add_implicit_conversion(ctx, block, arg1, common_type, loc)))
        return NULL;

    if (!(args[1] = add_implicit_conversion(ctx, block, arg2, common_type, loc)))
        return NULL;

    return add_expr(ctx, block, op, args, return_type, loc);
}

static struct hlsl_ir_node *add_binary_logical_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *common_type;
    enum hlsl_type_class type;
    unsigned int dimx, dimy;

    if (!expr_common_shape(ctx, arg1->data_type, arg2->data_type, loc, &type, &dimx, &dimy))
        return NULL;

    common_type = hlsl_get_numeric_type(ctx, type, HLSL_TYPE_BOOL, dimx, dimy);

    if (!(args[0] = add_implicit_conversion(ctx, block, arg1, common_type, loc)))
        return NULL;

    if (!(args[1] = add_implicit_conversion(ctx, block, arg2, common_type, loc)))
        return NULL;

    return add_expr(ctx, block, op, args, common_type, loc);
}

static struct hlsl_ir_node *add_binary_shift_expr(struct hlsl_ctx *ctx, struct hlsl_block *block,
        enum hlsl_ir_expr_op op, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    enum hlsl_base_type base = arg1->data_type->e.numeric.type;
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *return_type, *integer_type;
    enum hlsl_type_class type;
    unsigned int dimx, dimy;

    check_integer_type(ctx, arg1);
    check_integer_type(ctx, arg2);

    if (base == HLSL_TYPE_BOOL)
        base = HLSL_TYPE_INT;

    if (!expr_common_shape(ctx, arg1->data_type, arg2->data_type, loc, &type, &dimx, &dimy))
        return NULL;

    return_type = hlsl_get_numeric_type(ctx, type, base, dimx, dimy);
    integer_type = hlsl_get_numeric_type(ctx, type, HLSL_TYPE_INT, dimx, dimy);

    if (!(args[0] = add_implicit_conversion(ctx, block, arg1, return_type, loc)))
        return NULL;

    if (!(args[1] = add_implicit_conversion(ctx, block, arg2, integer_type, loc)))
        return NULL;

    return add_expr(ctx, block, op, args, return_type, loc);
}

static struct hlsl_ir_node *add_binary_dot_expr(struct hlsl_ctx *ctx, struct hlsl_block *instrs,
        struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2, const struct vkd3d_shader_location *loc)
{
    enum hlsl_base_type base = expr_common_base_type(arg1->data_type->e.numeric.type, arg2->data_type->e.numeric.type);
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *common_type, *ret_type;
    enum hlsl_ir_expr_op op;
    unsigned dim;

    if (arg1->data_type->class == HLSL_CLASS_MATRIX)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, arg1->data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Invalid type %s.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return NULL;
    }

    if (arg2->data_type->class == HLSL_CLASS_MATRIX)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, arg2->data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Invalid type %s.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return NULL;
    }

    if (arg1->data_type->class == HLSL_CLASS_SCALAR)
        dim = arg2->data_type->dimx;
    else if (arg2->data_type->class == HLSL_CLASS_SCALAR)
        dim = arg1->data_type->dimx;
    else
        dim = min(arg1->data_type->dimx, arg2->data_type->dimx);

    if (dim == 1)
        op = HLSL_OP2_MUL;
    else
        op = HLSL_OP2_DOT;

    common_type = hlsl_get_vector_type(ctx, base, dim);
    ret_type = hlsl_get_scalar_type(ctx, base);

    if (!(args[0] = add_implicit_conversion(ctx, instrs, arg1, common_type, loc)))
        return NULL;

    if (!(args[1] = add_implicit_conversion(ctx, instrs, arg2, common_type, loc)))
        return NULL;

    return add_expr(ctx, instrs, op, args, ret_type, loc);
}

static struct hlsl_ir_node *add_binary_expr(struct hlsl_ctx *ctx, struct hlsl_block *block, enum hlsl_ir_expr_op op,
        struct hlsl_ir_node *lhs, struct hlsl_ir_node *rhs, const struct vkd3d_shader_location *loc)
{
    switch (op)
    {
        case HLSL_OP2_ADD:
        case HLSL_OP2_DIV:
        case HLSL_OP2_MOD:
        case HLSL_OP2_MUL:
            return add_binary_arithmetic_expr(ctx, block, op, lhs, rhs, loc);

        case HLSL_OP2_BIT_AND:
        case HLSL_OP2_BIT_OR:
        case HLSL_OP2_BIT_XOR:
            return add_binary_bitwise_expr(ctx, block, op, lhs, rhs, loc);

        case HLSL_OP2_LESS:
        case HLSL_OP2_GEQUAL:
        case HLSL_OP2_EQUAL:
        case HLSL_OP2_NEQUAL:
            return add_binary_comparison_expr(ctx, block, op, lhs, rhs, loc);

        case HLSL_OP2_LOGIC_AND:
        case HLSL_OP2_LOGIC_OR:
            return add_binary_logical_expr(ctx, block, op, lhs, rhs, loc);

        case HLSL_OP2_LSHIFT:
        case HLSL_OP2_RSHIFT:
            return add_binary_shift_expr(ctx, block, op, lhs, rhs, loc);

        default:
            vkd3d_unreachable();
    }
}

static struct hlsl_block *add_binary_expr_merge(struct hlsl_ctx *ctx, struct hlsl_block *block1,
        struct hlsl_block *block2, enum hlsl_ir_expr_op op, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg1 = node_from_block(block1), *arg2 = node_from_block(block2);

    hlsl_block_add_block(block1, block2);
    destroy_block(block2);

    if (add_binary_expr(ctx, block1, op, arg1, arg2, loc) == NULL)
        return NULL;

    return block1;
}

static enum hlsl_ir_expr_op op_from_assignment(enum parse_assign_op op)
{
    static const enum hlsl_ir_expr_op ops[] =
    {
        0,
        HLSL_OP2_ADD,
        0,
        HLSL_OP2_MUL,
        HLSL_OP2_DIV,
        HLSL_OP2_MOD,
        HLSL_OP2_LSHIFT,
        HLSL_OP2_RSHIFT,
        HLSL_OP2_BIT_AND,
        HLSL_OP2_BIT_OR,
        HLSL_OP2_BIT_XOR,
    };

    return ops[op];
}

static bool invert_swizzle(uint32_t *swizzle, unsigned int *writemask, unsigned int *ret_width)
{
    unsigned int i, j, bit = 0, inverted = 0, width, new_writemask = 0, new_swizzle = 0;

    /* Apply the writemask to the swizzle to get a new writemask and swizzle. */
    for (i = 0; i < 4; ++i)
    {
        if (*writemask & (1 << i))
        {
            unsigned int s = (*swizzle >> (i * 2)) & 3;
            new_swizzle |= s << (bit++ * 2);
            if (new_writemask & (1 << s))
                return false;
            new_writemask |= 1 << s;
        }
    }
    width = bit;

    /* Invert the swizzle. */
    bit = 0;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < width; ++j)
        {
            unsigned int s = (new_swizzle >> (j * 2)) & 3;
            if (s == i)
                inverted |= j << (bit++ * 2);
        }
    }

    *swizzle = inverted;
    *writemask = new_writemask;
    *ret_width = width;
    return true;
}

static bool invert_swizzle_matrix(uint32_t *swizzle, unsigned int *writemask, unsigned int *ret_width)
{
    /* swizzle is 8 bits per component, each component is (from LSB) 4 bits X, then 4 bits Y.
     * components are indexed by their sources. i.e. the first component comes from the first
     * component of the rhs. */
    unsigned int i, j, bit = 0, inverted = 0, width, new_writemask = 0, new_swizzle = 0;

    /* First, we filter the swizzle to remove components that aren't enabled by writemask. */
    for (i = 0; i < 4; ++i)
    {
        if (*writemask & (1 << i))
        {
            unsigned int s = (*swizzle >> (i * 8)) & 0xff;
            unsigned int x = s & 0xf, y = (s >> 4) & 0xf;
            unsigned int idx = x + y * 4;
            new_swizzle |= s << (bit++ * 8);
            if (new_writemask & (1 << idx))
                return false;
            new_writemask |= 1 << idx;
        }
    }
    width = bit;

    /* Then we invert the swizzle. The resulting swizzle has 2 bits per component, because it's for the
     * incoming vector. */
    bit = 0;
    for (i = 0; i < 16; ++i)
    {
        for (j = 0; j < width; ++j)
        {
            unsigned int s = (new_swizzle >> (j * 8)) & 0xff;
            unsigned int x = s & 0xf, y = (s >> 4) & 0xf;
            unsigned int idx = x + y * 4;
            if (idx == i)
                inverted |= j << (bit++ * 2);
        }
    }

    *swizzle = inverted;
    *writemask = new_writemask;
    *ret_width = width;
    return true;
}

static struct hlsl_ir_node *add_assignment(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *lhs,
        enum parse_assign_op assign_op, struct hlsl_ir_node *rhs)
{
    struct hlsl_type *lhs_type = lhs->data_type;
    struct hlsl_ir_node *copy;
    unsigned int writemask = 0, width = 0;
    bool matrix_writemask = false;

    if (assign_op == ASSIGN_OP_SUB)
    {
        if (!(rhs = add_unary_arithmetic_expr(ctx, block, HLSL_OP1_NEG, rhs, &rhs->loc)))
            return NULL;
        assign_op = ASSIGN_OP_ADD;
    }
    if (assign_op != ASSIGN_OP_ASSIGN)
    {
        enum hlsl_ir_expr_op op = op_from_assignment(assign_op);

        VKD3D_ASSERT(op);
        if (!(rhs = add_binary_expr(ctx, block, op, lhs, rhs, &rhs->loc)))
            return NULL;
    }

    if (hlsl_is_numeric_type(lhs_type))
    {
        writemask = (1 << lhs_type->dimx) - 1;
        width = lhs_type->dimx;
    }

    if (!(rhs = add_implicit_conversion(ctx, block, rhs, lhs_type, &rhs->loc)))
        return NULL;

    while (lhs->type != HLSL_IR_LOAD && lhs->type != HLSL_IR_INDEX)
    {
        if (lhs->type == HLSL_IR_EXPR && hlsl_ir_expr(lhs)->op == HLSL_OP1_CAST)
        {
            hlsl_fixme(ctx, &lhs->loc, "Cast on the LHS.");
            return NULL;
        }
        else if (lhs->type == HLSL_IR_SWIZZLE)
        {
            struct hlsl_ir_swizzle *swizzle = hlsl_ir_swizzle(lhs);
            struct hlsl_ir_node *new_swizzle;
            uint32_t s = swizzle->swizzle;

            VKD3D_ASSERT(!matrix_writemask);

            if (swizzle->val.node->data_type->class == HLSL_CLASS_MATRIX)
            {
                if (swizzle->val.node->type != HLSL_IR_LOAD && swizzle->val.node->type != HLSL_IR_INDEX)
                {
                    hlsl_fixme(ctx, &lhs->loc, "Unhandled source of matrix swizzle.");
                    return NULL;
                }
                if (!invert_swizzle_matrix(&s, &writemask, &width))
                {
                    hlsl_error(ctx, &lhs->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_WRITEMASK, "Invalid writemask for matrix.");
                    return NULL;
                }
                matrix_writemask = true;
            }
            else if (!invert_swizzle(&s, &writemask, &width))
            {
                hlsl_error(ctx, &lhs->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_WRITEMASK, "Invalid writemask.");
                return NULL;
            }

            if (!(new_swizzle = hlsl_new_swizzle(ctx, s, width, rhs, &swizzle->node.loc)))
            {
                return NULL;
            }
            hlsl_block_add_instr(block, new_swizzle);

            lhs = swizzle->val.node;
            rhs = new_swizzle;
        }
        else
        {
            hlsl_error(ctx, &lhs->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_LVALUE, "Invalid lvalue.");
            return NULL;
        }
    }

    if (lhs->type == HLSL_IR_INDEX && hlsl_index_chain_has_resource_access(hlsl_ir_index(lhs)))
    {
        struct hlsl_ir_node *coords = hlsl_ir_index(lhs)->idx.node;
        struct hlsl_deref resource_deref;
        struct hlsl_type *resource_type;
        struct hlsl_ir_node *store;
        unsigned int dim_count;

        if (!hlsl_index_is_resource_access(hlsl_ir_index(lhs)))
        {
            hlsl_fixme(ctx, &lhs->loc, "Non-direct structured resource store.");
            return NULL;
        }

        if (!hlsl_init_deref_from_index_chain(ctx, &resource_deref, hlsl_ir_index(lhs)->val.node))
            return NULL;

        resource_type = hlsl_deref_get_type(ctx, &resource_deref);
        VKD3D_ASSERT(resource_type->class == HLSL_CLASS_TEXTURE || resource_type->class == HLSL_CLASS_UAV);

        if (resource_type->class != HLSL_CLASS_UAV)
            hlsl_error(ctx, &lhs->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Read-only resources cannot be stored to.");

        dim_count = hlsl_sampler_dim_count(resource_type->sampler_dim);

        if (width != resource_type->e.resource.format->dimx * resource_type->e.resource.format->dimy)
            hlsl_error(ctx, &lhs->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_WRITEMASK,
                    "Resource store expressions must write to all components.");

        VKD3D_ASSERT(coords->data_type->class == HLSL_CLASS_VECTOR);
        VKD3D_ASSERT(coords->data_type->e.numeric.type == HLSL_TYPE_UINT);
        VKD3D_ASSERT(coords->data_type->dimx == dim_count);

        if (!(store = hlsl_new_resource_store(ctx, &resource_deref, coords, rhs, &lhs->loc)))
        {
            hlsl_cleanup_deref(&resource_deref);
            return NULL;
        }
        hlsl_block_add_instr(block, store);
        hlsl_cleanup_deref(&resource_deref);
    }
    else if (matrix_writemask)
    {
        struct hlsl_deref deref;
        unsigned int i, j, k = 0;

        hlsl_init_deref_from_index_chain(ctx, &deref, lhs);

        for (i = 0; i < lhs->data_type->dimy; ++i)
        {
            for (j = 0; j < lhs->data_type->dimx; ++j)
            {
                struct hlsl_ir_node *load;
                struct hlsl_block store_block;
                const unsigned int idx = i * 4 + j;
                const unsigned int component = i * lhs->data_type->dimx + j;

                if (!(writemask & (1 << idx)))
                    continue;

                if (!(load = hlsl_add_load_component(ctx, block, rhs, k++, &rhs->loc)))
                {
                    hlsl_cleanup_deref(&deref);
                    return NULL;
                }

                if (!hlsl_new_store_component(ctx, &store_block, &deref, component, load))
                {
                    hlsl_cleanup_deref(&deref);
                    return NULL;
                }
                hlsl_block_add_block(block, &store_block);
            }
        }

        hlsl_cleanup_deref(&deref);
    }
    else if (lhs->type == HLSL_IR_INDEX && hlsl_index_is_noncontiguous(hlsl_ir_index(lhs)))
    {
        struct hlsl_ir_index *row = hlsl_ir_index(lhs);
        struct hlsl_ir_node *mat = row->val.node;
        unsigned int i, k = 0;

        VKD3D_ASSERT(!matrix_writemask);

        for (i = 0; i < mat->data_type->dimx; ++i)
        {
            struct hlsl_ir_node *cell, *load, *store, *c;
            struct hlsl_deref deref;

            if (!(writemask & (1 << i)))
                continue;

            if (!(c = hlsl_new_uint_constant(ctx, i, &lhs->loc)))
                return NULL;
            hlsl_block_add_instr(block, c);

            if (!(cell = hlsl_new_index(ctx, &row->node, c, &lhs->loc)))
                return NULL;
            hlsl_block_add_instr(block, cell);

            if (!(load = hlsl_add_load_component(ctx, block, rhs, k++, &rhs->loc)))
                return NULL;

            if (!hlsl_init_deref_from_index_chain(ctx, &deref, cell))
                return NULL;

            if (!(store = hlsl_new_store_index(ctx, &deref, NULL, load, 0, &rhs->loc)))
            {
                hlsl_cleanup_deref(&deref);
                return NULL;
            }
            hlsl_block_add_instr(block, store);
            hlsl_cleanup_deref(&deref);
        }
    }
    else
    {
        struct hlsl_ir_node *store;
        struct hlsl_deref deref;

        if (!hlsl_init_deref_from_index_chain(ctx, &deref, lhs))
            return NULL;

        if (!(store = hlsl_new_store_index(ctx, &deref, NULL, rhs, writemask, &rhs->loc)))
        {
            hlsl_cleanup_deref(&deref);
            return NULL;
        }
        hlsl_block_add_instr(block, store);
        hlsl_cleanup_deref(&deref);
    }

    /* Don't use the instruction itself as a source, as this makes structure
     * splitting easier. Instead copy it here. Since we retrieve sources from
     * the last instruction in the list, we do need to copy. */
    if (!(copy = hlsl_new_copy(ctx, rhs)))
        return NULL;
    hlsl_block_add_instr(block, copy);
    return copy;
}

static bool add_increment(struct hlsl_ctx *ctx, struct hlsl_block *block, bool decrement, bool post,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *lhs = node_from_block(block);
    struct hlsl_ir_node *one;

    if (lhs->data_type->modifiers & HLSL_MODIFIER_CONST)
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_MODIFIES_CONST,
                "Argument to %s%screment operator is const.", post ? "post" : "pre", decrement ? "de" : "in");

    if (!(one = hlsl_new_int_constant(ctx, 1, loc)))
        return false;
    hlsl_block_add_instr(block, one);

    if (!add_assignment(ctx, block, lhs, decrement ? ASSIGN_OP_SUB : ASSIGN_OP_ADD, one))
        return false;

    if (post)
    {
        struct hlsl_ir_node *copy;

        if (!(copy = hlsl_new_copy(ctx, lhs)))
            return false;
        hlsl_block_add_instr(block, copy);

        /* Post increment/decrement expressions are considered const. */
        if (!(copy->data_type = hlsl_type_clone(ctx, copy->data_type, 0, HLSL_MODIFIER_CONST)))
            return false;
    }

    return true;
}

/* For some reason, for matrices, values from default value initializers end up in different
 * components than from regular initializers. Default value initializers fill the matrix in
 * vertical reading order (left-to-right top-to-bottom) instead of regular reading order
 * (top-to-bottom left-to-right), so they have to be adjusted.
 * An exception is that the order of matrix initializers for function parameters are row-major
 * (top-to-bottom left-to-right). */
static unsigned int get_component_index_from_default_initializer_index(struct hlsl_ctx *ctx,
        struct hlsl_type *type, unsigned int index)
{
    unsigned int element_comp_count, element, x, y, i;
    unsigned int base = 0;

    if (ctx->profile->major_version < 4)
        return index;

    if (ctx->profile->type == VKD3D_SHADER_TYPE_EFFECT)
        return index;

    switch (type->class)
    {
        case HLSL_CLASS_MATRIX:
            x = index / type->dimy;
            y = index % type->dimy;
            return y * type->dimx + x;

        case HLSL_CLASS_ARRAY:
            element_comp_count = hlsl_type_component_count(type->e.array.type);
            element = index / element_comp_count;
            base = element * element_comp_count;
            return base + get_component_index_from_default_initializer_index(ctx, type->e.array.type, index - base);

        case HLSL_CLASS_STRUCT:
            for (i = 0; i < type->e.record.field_count; ++i)
            {
                struct hlsl_type *field_type = type->e.record.fields[i].type;

                element_comp_count = hlsl_type_component_count(field_type);
                if (index - base < element_comp_count)
                    return base + get_component_index_from_default_initializer_index(ctx, field_type, index - base);
                base += element_comp_count;
            }
            break;

        default:
            return index;
    }
    vkd3d_unreachable();
}

static void initialize_var_components(struct hlsl_ctx *ctx, struct hlsl_block *instrs,
        struct hlsl_ir_var *dst, unsigned int *store_index, struct hlsl_ir_node *src)
{
    unsigned int src_comp_count = hlsl_type_component_count(src->data_type);
    struct hlsl_deref dst_deref;
    unsigned int k;

    hlsl_init_simple_deref_from_var(&dst_deref, dst);

    for (k = 0; k < src_comp_count; ++k)
    {
        struct hlsl_ir_node *conv, *load;
        struct hlsl_type *dst_comp_type;
        struct hlsl_block block;

        if (!(load = hlsl_add_load_component(ctx, instrs, src, k, &src->loc)))
            return;

        dst_comp_type = hlsl_type_get_component_type(ctx, dst->data_type, *store_index);

        if (dst->default_values)
        {
            struct hlsl_default_value default_value = {0};
            unsigned int dst_index;

            if (!hlsl_clone_block(ctx, &block, instrs))
                return;
            default_value = evaluate_static_expression(ctx, &block, dst_comp_type, &src->loc);

            if (dst->is_param)
                dst_index = *store_index;
            else
                dst_index = get_component_index_from_default_initializer_index(ctx, dst->data_type, *store_index);

            dst->default_values[dst_index] = default_value;

            hlsl_block_cleanup(&block);
        }
        else
        {
            if (!(conv = add_implicit_conversion(ctx, instrs, load, dst_comp_type, &src->loc)))
                return;

            if (!hlsl_new_store_component(ctx, &block, &dst_deref, *store_index, conv))
                return;
            hlsl_block_add_block(instrs, &block);
        }

        ++*store_index;
    }
}

static bool type_has_object_components(const struct hlsl_type *type)
{
    if (type->class == HLSL_CLASS_ARRAY)
        return type_has_object_components(type->e.array.type);

    if (type->class == HLSL_CLASS_STRUCT)
    {
        for (unsigned int i = 0; i < type->e.record.field_count; ++i)
        {
            if (type_has_object_components(type->e.record.fields[i].type))
                return true;
        }

        return false;
    }

    return !hlsl_is_numeric_type(type);
}

static bool type_has_numeric_components(struct hlsl_type *type)
{
    if (hlsl_is_numeric_type(type))
        return true;
    if (type->class == HLSL_CLASS_ARRAY)
        return type_has_numeric_components(type->e.array.type);

    if (type->class == HLSL_CLASS_STRUCT)
    {
        unsigned int i;

        for (i = 0; i < type->e.record.field_count; ++i)
        {
            if (type_has_numeric_components(type->e.record.fields[i].type))
                return true;
        }
    }
    return false;
}

static void check_invalid_in_out_modifiers(struct hlsl_ctx *ctx, unsigned int modifiers,
        const struct vkd3d_shader_location *loc)
{
    modifiers &= (HLSL_STORAGE_IN | HLSL_STORAGE_OUT);
    if (modifiers)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_modifiers_to_string(ctx, modifiers)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                    "Modifiers '%s' are not allowed on non-parameter variables.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
}

static void check_invalid_object_fields(struct hlsl_ctx *ctx, const struct hlsl_ir_var *var)
{
    const struct hlsl_type *type = var->data_type;

    while (type->class == HLSL_CLASS_ARRAY)
        type = type->e.array.type;

    if (type->class == HLSL_CLASS_STRUCT && type_has_object_components(type))
        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                "Target profile doesn't support objects as struct members in uniform variables.");
}

static void declare_var(struct hlsl_ctx *ctx, struct parse_variable_def *v)
{
    struct hlsl_type *basic_type = v->basic_type;
    struct hlsl_ir_function_decl *func;
    struct hlsl_semantic new_semantic;
    uint32_t modifiers = v->modifiers;
    bool unbounded_res_array = false;
    bool constant_buffer = false;
    struct hlsl_ir_var *var;
    struct hlsl_type *type;
    bool local = true;
    char *var_name;
    unsigned int i;

    VKD3D_ASSERT(basic_type);

    if (basic_type->class == HLSL_CLASS_MATRIX)
        VKD3D_ASSERT(basic_type->modifiers & HLSL_MODIFIERS_MAJORITY_MASK);

    type = basic_type;

    if (hlsl_version_ge(ctx, 5, 1) && hlsl_type_is_resource(type))
    {
        for (i = 0; i < v->arrays.count; ++i)
            unbounded_res_array |= (v->arrays.sizes[i] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT);
    }

    if (type->class == HLSL_CLASS_CONSTANT_BUFFER)
    {
        type = type->e.resource.format;
        constant_buffer = true;
    }

    if (unbounded_res_array)
    {
        if (v->arrays.count == 1)
        {
            hlsl_fixme(ctx, &v->loc, "Unbounded resource arrays.");
            return;
        }
        else
        {
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Unbounded resource arrays cannot be multi-dimensional.");
        }
    }
    else
    {
        for (i = 0; i < v->arrays.count; ++i)
        {
            if (v->arrays.sizes[i] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT)
            {
                unsigned int size = initializer_size(&v->initializer);
                unsigned int elem_components = hlsl_type_component_count(type);

                if (i < v->arrays.count - 1)
                {
                    hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Only innermost array size can be implicit.");
                    v->initializer.args_count = 0;
                }
                else if (elem_components == 0)
                {
                    hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Cannot declare an implicit size array of a size 0 type.");
                    v->initializer.args_count = 0;
                }
                else if (size == 0)
                {
                    hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Implicit size arrays need to be initialized.");
                    v->initializer.args_count = 0;
                }
                else if (size % elem_components != 0)
                {
                    hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                            "Cannot initialize implicit size array with %u components, expected a multiple of %u.",
                            size, elem_components);
                    v->initializer.args_count = 0;
                }
                else
                {
                    v->arrays.sizes[i] = size / elem_components;
                }
            }
            type = hlsl_new_array_type(ctx, type, v->arrays.sizes[i]);
        }
    }

    if (hlsl_version_ge(ctx, 5, 1) && type->class == HLSL_CLASS_ARRAY && hlsl_type_is_resource(type))
    {
        /* SM 5.1/6.x descriptor arrays act differently from previous versions.
         * Not only are they treated as a single object in reflection, but they
         * act as a single component for the purposes of assignment and
         * initialization. */
        hlsl_fixme(ctx, &v->loc, "Shader model 5.1+ resource array.");
    }

    if (!(var_name = vkd3d_strdup(v->name)))
        return;

    if (!hlsl_clone_semantic(ctx, &new_semantic, &v->semantic))
    {
        vkd3d_free(var_name);
        return;
    }

    if (!(var = hlsl_new_var(ctx, var_name, type, &v->loc, &new_semantic, modifiers, &v->reg_reservation)))
    {
        hlsl_cleanup_semantic(&new_semantic);
        vkd3d_free(var_name);
        return;
    }

    var->annotations = v->annotations;

    if (constant_buffer && ctx->cur_scope == ctx->globals)
    {
        if (!(var_name = vkd3d_strdup(v->name)))
            return;
        var->buffer = hlsl_new_buffer(ctx, HLSL_BUFFER_CONSTANT, var_name, modifiers, &v->reg_reservation, NULL, &v->loc);
    }
    else
    {
        var->buffer = ctx->cur_buffer;
    }

    if (var->buffer == ctx->globals_buffer)
    {
        if (var->reg_reservation.offset_type)
            hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                    "packoffset() is only allowed inside constant buffer declarations.");
    }

    if (ctx->cur_scope == ctx->globals)
    {
        local = false;

        if ((modifiers & HLSL_STORAGE_UNIFORM) && (modifiers & HLSL_STORAGE_STATIC))
            hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                    "Variable '%s' is declared as both \"uniform\" and \"static\".", var->name);

        /* Mark it as uniform. We need to do this here since synthetic
            * variables also get put in the global scope, but shouldn't be
            * considered uniforms, and we have no way of telling otherwise. */
        if (!(modifiers & HLSL_STORAGE_STATIC))
            var->storage_modifiers |= HLSL_STORAGE_UNIFORM;

        if ((ctx->profile->major_version < 5 || ctx->profile->type == VKD3D_SHADER_TYPE_EFFECT)
                && (var->storage_modifiers & HLSL_STORAGE_UNIFORM))
        {
            check_invalid_object_fields(ctx, var);
        }

        if ((func = hlsl_get_first_func_decl(ctx, var->name)))
        {
            hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                    "'%s' is already defined as a function.", var->name);
            hlsl_note(ctx, &func->loc, VKD3D_SHADER_LOG_ERROR,
                    "'%s' was previously defined here.", var->name);
        }
    }
    else
    {
        static const unsigned int invalid = HLSL_STORAGE_EXTERN | HLSL_STORAGE_SHARED
                | HLSL_STORAGE_GROUPSHARED | HLSL_STORAGE_UNIFORM;

        if (modifiers & invalid)
        {
            struct vkd3d_string_buffer *string;

            if ((string = hlsl_modifiers_to_string(ctx, modifiers & invalid)))
                hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Modifiers '%s' are not allowed on local variables.", string->buffer);
            hlsl_release_string_buffer(ctx, string);
        }
        if (var->semantic.name)
            hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SEMANTIC,
                    "Semantics are not allowed on local variables.");

        if ((type->modifiers & HLSL_MODIFIER_CONST) && !v->initializer.args_count && !(modifiers & HLSL_STORAGE_STATIC))
        {
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_MISSING_INITIALIZER,
                "Const variable \"%s\" is missing an initializer.", var->name);
        }

        if (var->annotations)
        {
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                    "Annotations are only allowed for objects in the global scope.");
        }
    }

    if ((var->storage_modifiers & HLSL_STORAGE_STATIC) && type_has_numeric_components(var->data_type)
            && type_has_object_components(var->data_type))
    {
        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                "Static variables cannot have both numeric and resource components.");
    }

    if (!hlsl_add_var(ctx, var, local))
    {
        struct hlsl_ir_var *old = hlsl_get_var(ctx->cur_scope, var->name);

        hlsl_error(ctx, &var->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                "Variable \"%s\" was already declared in this scope.", var->name);
        hlsl_note(ctx, &old->loc, VKD3D_SHADER_LOG_ERROR, "\"%s\" was previously declared here.", old->name);
        hlsl_free_var(var);
        return;
    }
}

static struct hlsl_block *initialize_vars(struct hlsl_ctx *ctx, struct list *var_list)
{
    struct parse_variable_def *v, *v_next;
    struct hlsl_block *initializers;
    unsigned int component_count;
    struct hlsl_ir_var *var;
    struct hlsl_type *type;

    if (!(initializers = make_empty_block(ctx)))
    {
        LIST_FOR_EACH_ENTRY_SAFE(v, v_next, var_list, struct parse_variable_def, entry)
        {
            free_parse_variable_def(v);
        }
        vkd3d_free(var_list);
        return NULL;
    }

    LIST_FOR_EACH_ENTRY_SAFE(v, v_next, var_list, struct parse_variable_def, entry)
    {
        /* If this fails, the variable failed to be declared. */
        if (!(var = hlsl_get_var(ctx->cur_scope, v->name)))
        {
            free_parse_variable_def(v);
            continue;
        }

        type = var->data_type;
        component_count = hlsl_type_component_count(type);

        var->state_blocks = v->state_blocks;
        var->state_block_count = v->state_block_count;
        var->state_block_capacity = v->state_block_capacity;
        v->state_block_count = 0;
        v->state_block_capacity = 0;
        v->state_blocks = NULL;

        if (var->state_blocks && component_count != var->state_block_count)
        {
            hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                    "Expected %u state blocks, but got %u.", component_count, var->state_block_count);
            free_parse_variable_def(v);
            continue;
        }

        if (v->initializer.args_count)
        {
            unsigned int store_index = 0;
            bool is_default_values_initializer;
            unsigned int size, k;

            is_default_values_initializer = (ctx->cur_buffer != ctx->globals_buffer)
                    || (var->storage_modifiers & HLSL_STORAGE_UNIFORM)
                    || ctx->cur_scope->annotations;

            if (is_default_values_initializer)
            {
                /* Default values might have been allocated already for another variable of the same name,
                   in the same scope. */
                if (var->default_values)
                {
                    free_parse_variable_def(v);
                    continue;
                }

                if (!(var->default_values = hlsl_calloc(ctx, component_count, sizeof(*var->default_values))))
                {
                    free_parse_variable_def(v);
                    continue;
                }
            }

            if (!v->initializer.braces)
            {
                if (!(add_implicit_conversion(ctx, v->initializer.instrs, v->initializer.args[0], type, &v->loc)))
                {
                    free_parse_variable_def(v);
                    continue;
                }

                v->initializer.args[0] = node_from_block(v->initializer.instrs);
            }

            size = initializer_size(&v->initializer);
            if (component_count != size)
            {
                hlsl_error(ctx, &v->loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                        "Expected %u components in initializer, but got %u.", component_count, size);
                free_parse_variable_def(v);
                continue;
            }

            for (k = 0; k < v->initializer.args_count; ++k)
            {
                initialize_var_components(ctx, v->initializer.instrs, var, &store_index, v->initializer.args[k]);
            }

            if (is_default_values_initializer)
            {
                hlsl_dump_var_default_values(var);
            }
            else if (var->storage_modifiers & HLSL_STORAGE_STATIC)
            {
                hlsl_block_add_block(&ctx->static_initializers, v->initializer.instrs);
            }
            else
            {
                hlsl_block_add_block(initializers, v->initializer.instrs);
            }
        }
        else if (var->storage_modifiers & HLSL_STORAGE_STATIC)
        {
            struct hlsl_ir_node *cast, *store, *zero;

            /* Initialize statics to zero by default. */

            if (type_has_object_components(var->data_type))
            {
                free_parse_variable_def(v);
                continue;
            }

            if (!(zero = hlsl_new_uint_constant(ctx, 0, &var->loc)))
            {
                free_parse_variable_def(v);
                continue;
            }
            hlsl_block_add_instr(&ctx->static_initializers, zero);

            if (!(cast = add_cast(ctx, &ctx->static_initializers, zero, var->data_type, &var->loc)))
            {
                free_parse_variable_def(v);
                continue;
            }

            if (!(store = hlsl_new_simple_store(ctx, var, cast)))
            {
                free_parse_variable_def(v);
                continue;
            }
            hlsl_block_add_instr(&ctx->static_initializers, store);
        }
        free_parse_variable_def(v);
    }

    vkd3d_free(var_list);
    return initializers;
}

static bool func_is_compatible_match(struct hlsl_ctx *ctx,
        const struct hlsl_ir_function_decl *decl, const struct parse_initializer *args)
{
    unsigned int i;

    if (decl->parameters.count < args->args_count)
        return false;

    for (i = 0; i < args->args_count; ++i)
    {
        if (!implicit_compatible_data_types(ctx, args->args[i]->data_type, decl->parameters.vars[i]->data_type))
            return false;
    }

    if (args->args_count < decl->parameters.count && !decl->parameters.vars[args->args_count]->default_values)
        return false;

    return true;
}

static struct hlsl_ir_function_decl *find_function_call(struct hlsl_ctx *ctx,
        const char *name, const struct parse_initializer *args,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *decl, *compatible_match = NULL;
    struct hlsl_ir_function *func;
    struct rb_entry *entry;

    if (!(entry = rb_get(&ctx->functions, name)))
        return NULL;
    func = RB_ENTRY_VALUE(entry, struct hlsl_ir_function, entry);

    LIST_FOR_EACH_ENTRY(decl, &func->overloads, struct hlsl_ir_function_decl, entry)
    {
        if (func_is_compatible_match(ctx, decl, args))
        {
            if (compatible_match)
            {
                hlsl_fixme(ctx, loc, "Prioritize between multiple compatible function overloads.");
                break;
            }
            compatible_match = decl;
        }
    }

    return compatible_match;
}

static struct hlsl_ir_node *hlsl_new_void_expr(struct hlsl_ctx *ctx, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};

    return hlsl_new_expr(ctx, HLSL_OP0_VOID, operands, ctx->builtin_types.Void, loc);
}

static bool add_user_call(struct hlsl_ctx *ctx, struct hlsl_ir_function_decl *func,
        const struct parse_initializer *args, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *call;
    unsigned int i, j;

    VKD3D_ASSERT(args->args_count <= func->parameters.count);

    for (i = 0; i < args->args_count; ++i)
    {
        struct hlsl_ir_var *param = func->parameters.vars[i];
        struct hlsl_ir_node *arg = args->args[i];

        if (!hlsl_types_are_equal(arg->data_type, param->data_type))
        {
            struct hlsl_ir_node *cast;

            if (!(cast = add_cast(ctx, args->instrs, arg, param->data_type, &arg->loc)))
                return false;
            args->args[i] = cast;
            arg = cast;
        }

        if (param->storage_modifiers & HLSL_STORAGE_IN)
        {
            struct hlsl_ir_node *store;

            if (!(store = hlsl_new_simple_store(ctx, param, arg)))
                return false;
            hlsl_block_add_instr(args->instrs, store);
        }
    }

    /* Add default values for the remaining parameters. */
    for (i = args->args_count; i < func->parameters.count; ++i)
    {
        struct hlsl_ir_var *param = func->parameters.vars[i];
        unsigned int comp_count = hlsl_type_component_count(param->data_type);
        struct hlsl_deref param_deref;

        VKD3D_ASSERT(param->default_values);

        hlsl_init_simple_deref_from_var(&param_deref, param);

        for (j = 0; j < comp_count; ++j)
        {
            struct hlsl_type *type = hlsl_type_get_component_type(ctx, param->data_type, j);
            struct hlsl_constant_value value;
            struct hlsl_ir_node *comp;
            struct hlsl_block store_block;

            if (!param->default_values[j].string)
            {
                value.u[0] = param->default_values[j].number;
                if (!(comp = hlsl_new_constant(ctx, type, &value, loc)))
                    return false;
                hlsl_block_add_instr(args->instrs, comp);

                if (!hlsl_new_store_component(ctx, &store_block, &param_deref, j, comp))
                    return false;
                hlsl_block_add_block(args->instrs, &store_block);
            }
        }
    }

    if (!(call = hlsl_new_call(ctx, func, loc)))
        return false;
    hlsl_block_add_instr(args->instrs, call);

    for (i = 0; i < args->args_count; ++i)
    {
        struct hlsl_ir_var *param = func->parameters.vars[i];
        struct hlsl_ir_node *arg = args->args[i];

        if (param->storage_modifiers & HLSL_STORAGE_OUT)
        {
            struct hlsl_ir_load *load;

            if (arg->data_type->modifiers & HLSL_MODIFIER_CONST)
                hlsl_error(ctx, &arg->loc, VKD3D_SHADER_ERROR_HLSL_MODIFIES_CONST,
                        "Output argument to \"%s\" is const.", func->func->name);

            if (!(load = hlsl_new_var_load(ctx, param, &arg->loc)))
                return false;
            hlsl_block_add_instr(args->instrs, &load->node);

            if (!add_assignment(ctx, args->instrs, arg, ASSIGN_OP_ASSIGN, &load->node))
                return false;
        }
    }

    if (func->return_var)
    {
        struct hlsl_ir_load *load;

        if (!(load = hlsl_new_var_load(ctx, func->return_var, loc)))
            return false;
        hlsl_block_add_instr(args->instrs, &load->node);
    }
    else
    {
        struct hlsl_ir_node *expr;

        if (!(expr = hlsl_new_void_expr(ctx, loc)))
            return false;
        hlsl_block_add_instr(args->instrs, expr);
    }

    return true;
}

static struct hlsl_ir_node *intrinsic_float_convert_arg(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, struct hlsl_ir_node *arg, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *type = arg->data_type;

    if (type->e.numeric.type == HLSL_TYPE_FLOAT || type->e.numeric.type == HLSL_TYPE_HALF)
        return arg;

    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);
    return add_implicit_conversion(ctx, params->instrs, arg, type, loc);
}

static bool convert_args(struct hlsl_ctx *ctx, const struct parse_initializer *params,
        struct hlsl_type *type, const struct vkd3d_shader_location *loc)
{
    unsigned int i;

    for (i = 0; i < params->args_count; ++i)
    {
        struct hlsl_ir_node *new_arg;

        if (!(new_arg = add_implicit_conversion(ctx, params->instrs, params->args[i], type, loc)))
            return false;
        params->args[i] = new_arg;
    }

    return true;
}

static struct hlsl_type *elementwise_intrinsic_get_common_type(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    enum hlsl_base_type base = params->args[0]->data_type->e.numeric.type;
    bool vectors = false, matrices = false;
    unsigned int dimx = 4, dimy = 4;
    struct hlsl_type *common_type;
    unsigned int i;

    for (i = 0; i < params->args_count; ++i)
    {
        struct hlsl_type *arg_type = params->args[i]->data_type;

        base = expr_common_base_type(base, arg_type->e.numeric.type);

        if (arg_type->class == HLSL_CLASS_VECTOR)
        {
            vectors = true;
            dimx = min(dimx, arg_type->dimx);
        }
        else if (arg_type->class == HLSL_CLASS_MATRIX)
        {
            matrices = true;
            dimx = min(dimx, arg_type->dimx);
            dimy = min(dimy, arg_type->dimy);
        }
    }

    if (matrices && vectors)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                "Cannot use both matrices and vectors in an elementwise intrinsic.");
        return NULL;
    }
    else if (matrices)
    {
        common_type = hlsl_get_matrix_type(ctx, base, dimx, dimy);
    }
    else if (vectors)
    {
        common_type = hlsl_get_vector_type(ctx, base, dimx);
    }
    else
    {
        common_type = hlsl_get_scalar_type(ctx, base);
    }

    return common_type;
}

static bool elementwise_intrinsic_convert_args(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *common_type;

    if (!(common_type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;

    return convert_args(ctx, params, common_type, loc);
}

static bool elementwise_intrinsic_float_convert_args(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    enum hlsl_base_type base_type;
    struct hlsl_type *type;

    if (!(type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;

    base_type = type->e.numeric.type == HLSL_TYPE_HALF ? HLSL_TYPE_HALF : HLSL_TYPE_FLOAT;
    type = hlsl_get_numeric_type(ctx, type->class, base_type, type->dimx, type->dimy);

    return convert_args(ctx, params, type, loc);
}

static bool elementwise_intrinsic_uint_convert_args(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *type;

    if (!(type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;

    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_UINT, type->dimx, type->dimy);

    return convert_args(ctx, params, type, loc);
}

static bool intrinsic_abs(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_ABS, params->args[0], loc);
}

static bool write_acos_or_asin(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc, bool asin_mode)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_type *type;
    char *body;

    static const char template[] =
            "%s %s(%s x)\n"
            "{\n"
            "    %s abs_arg = abs(x);\n"
            "    %s poly_approx = (((-0.018729\n"
            "        * abs_arg + 0.074261)\n"
            "        * abs_arg - 0.212114)\n"
            "        * abs_arg + 1.570729);\n"
            "    %s correction = sqrt(1.0 - abs_arg);\n"
            "    %s zero_flip = (x < 0.0) * (-2.0 * correction * poly_approx + 3.141593);\n"
            "    %s result = poly_approx * correction + zero_flip;\n"
            "    return %s;\n"
            "}";
    static const char fn_name_acos[] = "acos";
    static const char fn_name_asin[] = "asin";
    static const char return_stmt_acos[] = "result";
    static const char return_stmt_asin[] = "-result + 1.570796";

    const char *fn_name = asin_mode ? fn_name_asin : fn_name_acos;

    type = params->args[0]->data_type;
    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);

    if (!(body = hlsl_sprintf_alloc(ctx, template,
            type->name, fn_name, type->name,
            type->name, type->name, type->name, type->name, type->name,
            (asin_mode ? return_stmt_asin : return_stmt_acos))))
        return false;
    func = hlsl_compile_internal_function(ctx, fn_name, body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_acos(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_acos_or_asin(ctx, params, loc, false);
}

/* Find the type corresponding to the given source type, with the same
 * dimensions but a different base type. */
static struct hlsl_type *convert_numeric_type(const struct hlsl_ctx *ctx,
        const struct hlsl_type *type, enum hlsl_base_type base_type)
{
    return hlsl_get_numeric_type(ctx, type->class, base_type, type->dimx, type->dimy);
}

static bool add_combine_components(struct hlsl_ctx *ctx, const struct parse_initializer *params,
        struct hlsl_ir_node *arg, enum hlsl_ir_expr_op op, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *res, *load;
    unsigned int i, count;

    count = hlsl_type_component_count(arg->data_type);

    if (!(res = hlsl_add_load_component(ctx, params->instrs, arg, 0, loc)))
        return false;

    for (i = 1; i < count; ++i)
    {
        if (!(load = hlsl_add_load_component(ctx, params->instrs, arg, i, loc)))
            return false;

        if (!(res = hlsl_new_binary_expr(ctx, op, res, load)))
                return NULL;
        hlsl_block_add_instr(params->instrs, res);
    }

    return true;
}

static bool intrinsic_all(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg = params->args[0], *cast;
    struct hlsl_type *bool_type;

    bool_type = convert_numeric_type(ctx, arg->data_type, HLSL_TYPE_BOOL);
    if (!(cast = add_cast(ctx, params->instrs, arg, bool_type, loc)))
        return false;

    return add_combine_components(ctx, params, cast, HLSL_OP2_LOGIC_AND, loc);
}

static bool intrinsic_any(struct hlsl_ctx *ctx, const struct parse_initializer *params,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg = params->args[0], *cast;
    struct hlsl_type *bool_type;

    bool_type = convert_numeric_type(ctx, arg->data_type, HLSL_TYPE_BOOL);
    if (!(cast = add_cast(ctx, params->instrs, arg, bool_type, loc)))
        return false;

    return add_combine_components(ctx, params, cast, HLSL_OP2_LOGIC_OR, loc);
}

static bool intrinsic_asin(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_acos_or_asin(ctx, params, loc, true);
}

static bool write_atan_or_atan2(struct hlsl_ctx *ctx,
        const struct parse_initializer *params,
        const struct vkd3d_shader_location *loc, bool atan2_mode)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_type *type;
    struct vkd3d_string_buffer *buf;
    int ret;

    static const char atan2_name[] = "atan2";
    static const char atan_name[] = "atan";

    static const char atan2_header_template[] =
            "%s atan2(%s y, %s x)\n"
            "{\n"
            "    %s in_y, in_x;\n"
            "    in_y = y;\n"
            "    in_x = x;\n";
    static const char atan_header_template[] =
            "%s atan(%s y)\n"
            "{\n"
            "    %s in_y, in_x;\n"
            "    in_y = y;\n"
            "    in_x = 1.0;\n";

    static const char body_template[] =
            "    %s recip, input, x2, poly_approx, flipped;"
            "    recip = 1.0 / max(abs(in_y), abs(in_x));\n"
            "    input = recip * min(abs(in_y), abs(in_x));\n"
            "    x2 = input * input;\n"
            "    poly_approx = ((((0.020835\n"
            "        * x2 - 0.085133)\n"
            "        * x2 + 0.180141)\n"
            "        * x2 - 0.330299)\n"
            "        * x2 + 0.999866)\n"
            "        * input;\n"
            "    flipped = poly_approx * -2.0 + 1.570796;\n"
            "    poly_approx += abs(in_x) < abs(in_y) ? flipped : 0.0;\n"
            "    poly_approx += in_x < 0.0 ? -3.1415927 : 0.0;\n"
            "    return (min(in_x, in_y) < 0.0 && max(in_x, in_y) >= 0.0)\n"
            "        ? -poly_approx\n"
            "        : poly_approx;\n"
            "}";

    if (!(type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;
    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);

    if (!(buf = hlsl_get_string_buffer(ctx)))
        return false;

    if (atan2_mode)
        ret = vkd3d_string_buffer_printf(buf, atan2_header_template,
                type->name, type->name, type->name, type->name);
    else
        ret = vkd3d_string_buffer_printf(buf, atan_header_template,
                type->name, type->name, type->name);
    if (ret < 0)
    {
        hlsl_release_string_buffer(ctx, buf);
        return false;
    }

    ret = vkd3d_string_buffer_printf(buf, body_template, type->name);
    if (ret < 0)
    {
        hlsl_release_string_buffer(ctx, buf);
        return false;
    }

    func = hlsl_compile_internal_function(ctx,
            atan2_mode ? atan2_name : atan_name, buf->buffer);
    hlsl_release_string_buffer(ctx, buf);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_atan(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_atan_or_atan2(ctx, params, loc, false);
}


static bool intrinsic_atan2(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_atan_or_atan2(ctx, params, loc, true);
}

static bool intrinsic_asfloat(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *data_type;

    data_type = params->args[0]->data_type;
    if (data_type->e.numeric.type == HLSL_TYPE_BOOL || data_type->e.numeric.type == HLSL_TYPE_DOUBLE)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong argument type of asfloat(): expected 'int', 'uint', 'float', or 'half', but got '%s'.",
                    string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
    data_type = convert_numeric_type(ctx, data_type, HLSL_TYPE_FLOAT);

    operands[0] = params->args[0];
    return add_expr(ctx, params->instrs, HLSL_OP1_REINTERPRET, operands, data_type, loc);
}

static bool intrinsic_asint(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *data_type;

    data_type = params->args[0]->data_type;
    if (data_type->e.numeric.type == HLSL_TYPE_BOOL || data_type->e.numeric.type == HLSL_TYPE_DOUBLE)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong argument type of asint(): expected 'int', 'uint', 'float', or 'half', but got '%s'.",
                    string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
    data_type = convert_numeric_type(ctx, data_type, HLSL_TYPE_INT);

    operands[0] = params->args[0];
    return add_expr(ctx, params->instrs, HLSL_OP1_REINTERPRET, operands, data_type, loc);
}

static bool intrinsic_asuint(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *data_type;

    if (params->args_count != 1 && params->args_count != 3)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to function 'asuint': expected 1 or 3, but got %u.", params->args_count);
        return false;
    }

    if (params->args_count == 3)
    {
        hlsl_fixme(ctx, loc, "Double-to-integer conversion.");
        return false;
    }

    data_type = params->args[0]->data_type;
    if (data_type->e.numeric.type == HLSL_TYPE_BOOL || data_type->e.numeric.type == HLSL_TYPE_DOUBLE)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 0 of asuint(): expected 'int', 'uint', 'float', or 'half', but got '%s'.",
                    string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
    data_type = convert_numeric_type(ctx, data_type, HLSL_TYPE_UINT);

    operands[0] = params->args[0];
    return add_expr(ctx, params->instrs, HLSL_OP1_REINTERPRET, operands, data_type, loc);
}

static bool intrinsic_ceil(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_CEIL, arg, loc);
}

static bool intrinsic_clamp(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *max;

    if (!elementwise_intrinsic_convert_args(ctx, params, loc))
        return false;

    if (!(max = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MAX, params->args[0], params->args[1], loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MIN, max, params->args[2], loc);
}

static bool intrinsic_clip(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *condition, *jump;

    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;

    condition = params->args[0];

    if (ctx->profile->major_version < 4 && hlsl_type_component_count(condition->data_type) > 4)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, condition->data_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Argument type cannot exceed 4 components, got type \"%s\".", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!(jump = hlsl_new_jump(ctx, HLSL_IR_JUMP_DISCARD_NEG, condition, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, jump);

    return true;
}

static bool intrinsic_cos(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_COS, arg, loc);
}

static bool write_cosh_or_sinh(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc, bool sinh_mode)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_ir_node *arg;
    const char *fn_name, *type_name;
    char *body;

    static const char template[] =
            "%s %s(%s x)\n"
            "{\n"
            "    return (exp(x) %s exp(-x)) / 2;\n"
            "}\n";
    static const char fn_name_sinh[] = "sinh";
    static const char fn_name_cosh[] = "cosh";

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    type_name = arg->data_type->name;
    fn_name = sinh_mode ? fn_name_sinh : fn_name_cosh;

    if (!(body = hlsl_sprintf_alloc(ctx, template,
            type_name, fn_name, type_name, sinh_mode ? "-" : "+")))
        return false;

    func = hlsl_compile_internal_function(ctx, fn_name, body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_cosh(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_cosh_or_sinh(ctx, params, loc, false);
}

static bool intrinsic_cross(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg1_swzl1, *arg1_swzl2, *arg2_swzl1, *arg2_swzl2;
    struct hlsl_ir_node *arg1 = params->args[0], *arg2 = params->args[1];
    struct hlsl_ir_node *arg1_cast, *arg2_cast, *mul1_neg, *mul1, *mul2;
    struct hlsl_type *cast_type;
    enum hlsl_base_type base;

    if (arg1->data_type->e.numeric.type == HLSL_TYPE_HALF && arg2->data_type->e.numeric.type == HLSL_TYPE_HALF)
        base = HLSL_TYPE_HALF;
    else
        base = HLSL_TYPE_FLOAT;

    cast_type = hlsl_get_vector_type(ctx, base, 3);

    if (!(arg1_cast = add_implicit_conversion(ctx, params->instrs, arg1, cast_type, loc)))
        return false;

    if (!(arg2_cast = add_implicit_conversion(ctx, params->instrs, arg2, cast_type, loc)))
        return false;

    if (!(arg1_swzl1 = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(Z, X, Y, Z), 3, arg1_cast, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, arg1_swzl1);

    if (!(arg2_swzl1 = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(Y, Z, X, Y), 3, arg2_cast, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, arg2_swzl1);

    if (!(mul1 = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg1_swzl1, arg2_swzl1, loc)))
        return false;

    if (!(mul1_neg = hlsl_new_unary_expr(ctx, HLSL_OP1_NEG, mul1, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, mul1_neg);

    if (!(arg1_swzl2 = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(Y, Z, X, Y), 3, arg1_cast, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, arg1_swzl2);

    if (!(arg2_swzl2 = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(Z, X, Y, Z), 3, arg2_cast, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, arg2_swzl2);

    if (!(mul2 = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg1_swzl2, arg2_swzl2, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, mul2, mul1_neg, loc);
}

static bool intrinsic_ddx(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSX, arg, loc);
}

static bool intrinsic_ddx_coarse(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSX_COARSE, arg, loc);
}

static bool intrinsic_ddx_fine(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSX_FINE, arg, loc);
}

static bool intrinsic_ddy(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSY, arg, loc);
}

static bool intrinsic_ddy_coarse(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSY_COARSE, arg, loc);
}

static bool intrinsic_degrees(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg, *deg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    /* 1 rad = 180/pi degree = 57.2957795 degree */
    if (!(deg = hlsl_new_float_constant(ctx, 57.2957795f, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, deg);

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg, deg, loc);
}

static bool intrinsic_ddy_fine(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_DSY_FINE, arg, loc);
}

static bool intrinsic_determinant(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    static const char determinant2x2[] =
            "%s determinant(%s2x2 m)\n"
            "{\n"
            "    return m._11 * m._22 - m._12 * m._21;\n"
            "}";
    static const char determinant3x3[] =
            "%s determinant(%s3x3 m)\n"
            "{\n"
            "    %s2x2 m1 = { m._22, m._23, m._32, m._33 };\n"
            "    %s2x2 m2 = { m._21, m._23, m._31, m._33 };\n"
            "    %s2x2 m3 = { m._21, m._22, m._31, m._32 };\n"
            "    %s3 v1 = { m._11, -m._12, m._13 };\n"
            "    %s3 v2 = { determinant(m1), determinant(m2), determinant(m3) };\n"
            "    return dot(v1, v2);\n"
            "}";
    static const char determinant4x4[] =
            "%s determinant(%s4x4 m)\n"
            "{\n"
            "    %s3x3 m1 = { m._22, m._23, m._24, m._32, m._33, m._34, m._42, m._43, m._44 };\n"
            "    %s3x3 m2 = { m._21, m._23, m._24, m._31, m._33, m._34, m._41, m._43, m._44 };\n"
            "    %s3x3 m3 = { m._21, m._22, m._24, m._31, m._32, m._34, m._41, m._42, m._44 };\n"
            "    %s3x3 m4 = { m._21, m._22, m._23, m._31, m._32, m._33, m._41, m._42, m._43 };\n"
            "    %s4 v1 = { m._11, -m._12, m._13, -m._14 };\n"
            "    %s4 v2 = { determinant(m1), determinant(m2), determinant(m3), determinant(m4) };\n"
            "    return dot(v1, v2);\n"
            "}";
    static const char *templates[] =
    {
        [2] = determinant2x2,
        [3] = determinant3x3,
        [4] = determinant4x4,
    };

    struct hlsl_ir_node *arg = params->args[0];
    const struct hlsl_type *type = arg->data_type;
    struct hlsl_ir_function_decl *func;
    const char *typename, *template;
    unsigned int dim;
    char *body;

    if (type->class != HLSL_CLASS_SCALAR && type->class != HLSL_CLASS_MATRIX)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Invalid argument type.");
        return false;
    }

    dim = min(type->dimx, type->dimy);
    if (dim == 1)
    {
        if (!(arg = intrinsic_float_convert_arg(ctx, params, arg, loc)))
            return false;
        return hlsl_add_load_component(ctx, params->instrs, arg, 0, loc);
    }

    typename = type->e.numeric.type == HLSL_TYPE_HALF ? "half" : "float";
    template = templates[dim];

    switch (dim)
    {
        case 2:
            body = hlsl_sprintf_alloc(ctx, template, typename, typename);
            break;
        case 3:
            body = hlsl_sprintf_alloc(ctx, template, typename, typename, typename,
                    typename, typename, typename, typename);
            break;
        case 4:
            body = hlsl_sprintf_alloc(ctx, template, typename, typename, typename,
                    typename, typename, typename, typename, typename);
            break;
        default:
            vkd3d_unreachable();
    }

    if (!body)
        return false;

    func = hlsl_compile_internal_function(ctx, "determinant", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_distance(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg1, *arg2, *neg, *add, *dot;

    if (!(arg1 = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(arg2 = intrinsic_float_convert_arg(ctx, params, params->args[1], loc)))
        return false;

    if (!(neg = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_NEG, arg2, loc)))
        return false;

    if (!(add = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, arg1, neg, loc)))
        return false;

    if (!(dot = add_binary_dot_expr(ctx, params->instrs, add, add, loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SQRT, dot, loc);
}

static bool intrinsic_dot(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return !!add_binary_dot_expr(ctx, params->instrs, params->args[0], params->args[1], loc);
}

static bool intrinsic_exp(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg, *mul, *coeff;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    /* 1/ln(2) */
    if (!(coeff = hlsl_new_float_constant(ctx, 1.442695f, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, coeff);

    if (!(mul = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, coeff, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_EXP2, mul, loc);
}

static bool intrinsic_exp2(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_EXP2, arg, loc);
}

static bool intrinsic_faceforward(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_type *type;
    char *body;

    static const char template[] =
            "%s faceforward(%s n, %s i, %s ng)\n"
            "{\n"
            "    return dot(i, ng) < 0 ? n : -n;\n"
            "}\n";

    if (!(type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;
    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);

    if (!(body = hlsl_sprintf_alloc(ctx, template,
            type->name, type->name, type->name, type->name)))
        return false;
    func = hlsl_compile_internal_function(ctx, "faceforward", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_f16tof32(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *type;

    if (!elementwise_intrinsic_uint_convert_args(ctx, params, loc))
        return false;

    type = convert_numeric_type(ctx, params->args[0]->data_type, HLSL_TYPE_FLOAT);

    operands[0] = params->args[0];
    return add_expr(ctx, params->instrs, HLSL_OP1_F16TOF32, operands, type, loc);
}

static bool intrinsic_floor(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_FLOOR, arg, loc);
}

static bool intrinsic_fmod(struct hlsl_ctx *ctx, const struct parse_initializer *params,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *x, *y, *div, *abs, *frac, *neg_frac, *ge, *select, *zero;
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = { 0 };
    static const struct hlsl_constant_value zero_value;

    if (!(x = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(y = intrinsic_float_convert_arg(ctx, params, params->args[1], loc)))
        return false;

    if (!(div = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_DIV, x, y, loc)))
        return false;

    if (!(zero = hlsl_new_constant(ctx, div->data_type, &zero_value, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, zero);

    if (!(abs = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_ABS, div, loc)))
        return false;

    if (!(frac = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_FRACT, abs, loc)))
        return false;

    if (!(neg_frac = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_NEG, frac, loc)))
        return false;

    if (!(ge = add_binary_comparison_expr(ctx, params->instrs, HLSL_OP2_GEQUAL, div, zero, loc)))
        return false;

    operands[0] = ge;
    operands[1] = frac;
    operands[2] = neg_frac;
    if (!(select = add_expr(ctx, params->instrs, HLSL_OP3_TERNARY, operands, x->data_type, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, select, y, loc);
}

static bool intrinsic_frac(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_FRACT, arg, loc);
}

static bool intrinsic_fwidth(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_type *type;
    char *body;

    static const char template[] =
            "%s fwidth(%s x)\n"
            "{\n"
            "    return abs(ddx(x)) + abs(ddy(x));\n"
            "}";

    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;
    type = params->args[0]->data_type;

    if (!(body = hlsl_sprintf_alloc(ctx, template, type->name, type->name)))
        return false;
    func = hlsl_compile_internal_function(ctx, "fwidth", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_ldexp(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;

    if (!(arg = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_EXP2, params->args[1], loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, params->args[0], arg, loc);
}

static bool intrinsic_length(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *type = params->args[0]->data_type;
    struct hlsl_ir_node *arg, *dot;

    if (type->class == HLSL_CLASS_MATRIX)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Invalid type %s.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(dot = add_binary_dot_expr(ctx, params->instrs, arg, arg, loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SQRT, dot, loc);
}

static bool intrinsic_lerp(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *neg, *add, *mul;

    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;

    if (!(neg = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_NEG, params->args[0], loc)))
        return false;

    if (!(add = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, params->args[1], neg, loc)))
        return false;

    if (!(mul = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, params->args[2], add, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, params->args[0], mul, loc);
}

static struct hlsl_ir_node * add_pow_expr(struct hlsl_ctx *ctx,
        struct hlsl_block *instrs, struct hlsl_ir_node *arg1, struct hlsl_ir_node *arg2,
        const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *log, *mul;

    if (!(log = add_unary_arithmetic_expr(ctx, instrs, HLSL_OP1_LOG2, arg1, loc)))
        return NULL;

    if (!(mul = add_binary_arithmetic_expr(ctx, instrs, HLSL_OP2_MUL, arg2, log, loc)))
        return NULL;

    return add_unary_arithmetic_expr(ctx, instrs, HLSL_OP1_EXP2, mul, loc);
}

static bool intrinsic_lit(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *func;

    static const char body[] =
            "float4 lit(float n_l, float n_h, float m)\n"
            "{\n"
            "    float4 ret;\n"
            "    ret.xw = 1.0;\n"
            "    ret.y = max(n_l, 0);\n"
            "    ret.z = (n_l < 0 || n_h < 0) ? 0 : pow(n_h, m);\n"
            "    return ret;\n"
            "}";

    if (params->args[0]->data_type->class != HLSL_CLASS_SCALAR
            || params->args[1]->data_type->class != HLSL_CLASS_SCALAR
            || params->args[2]->data_type->class != HLSL_CLASS_SCALAR)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Invalid argument type.");
        return false;
    }

    if (!(func = hlsl_compile_internal_function(ctx, "lit", body)))
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_log(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *log, *arg, *coeff;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(log = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_LOG2, arg, loc)))
        return false;

    /* ln(2) */
    if (!(coeff = hlsl_new_float_constant(ctx, 0.69314718055f, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, coeff);

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, log, coeff, loc);
}

static bool intrinsic_log10(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *log, *arg, *coeff;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(log = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_LOG2, arg, loc)))
        return false;

    /* 1 / log2(10) */
    if (!(coeff = hlsl_new_float_constant(ctx, 0.301029996f, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, coeff);

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, log, coeff, loc);
}

static bool intrinsic_log2(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_LOG2, arg, loc);
}

static bool intrinsic_max(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    if (!elementwise_intrinsic_convert_args(ctx, params, loc))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MAX, params->args[0], params->args[1], loc);
}

static bool intrinsic_min(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    if (!elementwise_intrinsic_convert_args(ctx, params, loc))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MIN, params->args[0], params->args[1], loc);
}

static bool intrinsic_mul(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg1 = params->args[0], *arg2 = params->args[1], *cast1, *cast2;
    enum hlsl_base_type base = expr_common_base_type(arg1->data_type->e.numeric.type, arg2->data_type->e.numeric.type);
    struct hlsl_type *cast_type1 = arg1->data_type, *cast_type2 = arg2->data_type, *matrix_type, *ret_type;
    unsigned int i, j, k, vect_count = 0;
    struct hlsl_deref var_deref;
    struct hlsl_ir_load *load;
    struct hlsl_ir_var *var;

    if (arg1->data_type->class == HLSL_CLASS_SCALAR || arg2->data_type->class == HLSL_CLASS_SCALAR)
        return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg1, arg2, loc);

    if (arg1->data_type->class == HLSL_CLASS_VECTOR)
    {
        vect_count++;
        cast_type1 = hlsl_get_matrix_type(ctx, base, arg1->data_type->dimx, 1);
    }
    if (arg2->data_type->class == HLSL_CLASS_VECTOR)
    {
        vect_count++;
        cast_type2 = hlsl_get_matrix_type(ctx, base, 1, arg2->data_type->dimx);
    }

    matrix_type = hlsl_get_matrix_type(ctx, base, cast_type2->dimx, cast_type1->dimy);

    if (vect_count == 0)
    {
        ret_type = matrix_type;
    }
    else if (vect_count == 1)
    {
        VKD3D_ASSERT(matrix_type->dimx == 1 || matrix_type->dimy == 1);
        ret_type = hlsl_get_vector_type(ctx, base, matrix_type->dimx * matrix_type->dimy);
    }
    else
    {
        VKD3D_ASSERT(matrix_type->dimx == 1 && matrix_type->dimy == 1);
        ret_type = hlsl_get_scalar_type(ctx, base);
    }

    if (!(cast1 = add_implicit_conversion(ctx, params->instrs, arg1, cast_type1, loc)))
        return false;

    if (!(cast2 = add_implicit_conversion(ctx, params->instrs, arg2, cast_type2, loc)))
        return false;

    if (!(var = hlsl_new_synthetic_var(ctx, "mul", matrix_type, loc)))
        return false;
    hlsl_init_simple_deref_from_var(&var_deref, var);

    for (i = 0; i < matrix_type->dimx; ++i)
    {
        for (j = 0; j < matrix_type->dimy; ++j)
        {
            struct hlsl_ir_node *instr = NULL;
            struct hlsl_block block;

            for (k = 0; k < cast_type1->dimx && k < cast_type2->dimy; ++k)
            {
                struct hlsl_ir_node *value1, *value2, *mul;

                if (!(value1 = hlsl_add_load_component(ctx, params->instrs,
                        cast1, j * cast1->data_type->dimx + k, loc)))
                    return false;

                if (!(value2 = hlsl_add_load_component(ctx, params->instrs,
                        cast2, k * cast2->data_type->dimx + i, loc)))
                    return false;

                if (!(mul = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, value1, value2, loc)))
                    return false;

                if (instr)
                {
                    if (!(instr = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, instr, mul, loc)))
                        return false;
                }
                else
                {
                    instr = mul;
                }
            }

            if (!hlsl_new_store_component(ctx, &block, &var_deref, j * matrix_type->dimx + i, instr))
                return false;
            hlsl_block_add_block(params->instrs, &block);
        }
    }

    if (!(load = hlsl_new_var_load(ctx, var, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, &load->node);

    return !!add_implicit_conversion(ctx, params->instrs, &load->node, ret_type, loc);
}

static bool intrinsic_normalize(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *type = params->args[0]->data_type;
    struct hlsl_ir_node *dot, *rsq, *arg;

    if (type->class == HLSL_CLASS_MATRIX)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Invalid type %s.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    if (!(dot = add_binary_dot_expr(ctx, params->instrs, arg, arg, loc)))
        return false;

    if (!(rsq = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_RSQ, dot, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, rsq, arg, loc);
}

static bool intrinsic_pow(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;

    return !!add_pow_expr(ctx, params->instrs, params->args[0], params->args[1], loc);
}

static bool intrinsic_radians(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg, *rad;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    /* 1 degree = pi/180 rad = 0.0174532925f rad */
    if (!(rad = hlsl_new_float_constant(ctx, 0.0174532925f, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, rad);

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg, rad, loc);
}

static bool intrinsic_rcp(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_RCP, arg, loc);
}

static bool intrinsic_reflect(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *i = params->args[0], *n = params->args[1];
    struct hlsl_ir_node *dot, *mul_n, *two_dot, *neg;

    if (!(dot = add_binary_dot_expr(ctx, params->instrs, i, n, loc)))
        return false;

    if (!(two_dot = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, dot, dot, loc)))
        return false;

    if (!(mul_n = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, n, two_dot, loc)))
        return false;

    if (!(neg = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_NEG, mul_n, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, i, neg, loc);
}

static bool intrinsic_refract(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_type *r_type = params->args[0]->data_type;
    struct hlsl_type *n_type = params->args[1]->data_type;
    struct hlsl_type *i_type = params->args[2]->data_type;
    struct hlsl_type *res_type, *idx_type, *scal_type;
    struct parse_initializer mut_params;
    struct hlsl_ir_function_decl *func;
    enum hlsl_base_type base;
    char *body;

    static const char template[] =
            "%s refract(%s r, %s n, %s i)\n"
            "{\n"
            "    %s d, t;\n"
            "    d = dot(r, n);\n"
            "    t = 1 - i.x * i.x * (1 - d * d);\n"
            "    return t >= 0.0 ? i.x * r - (i.x * d + sqrt(t)) * n : 0;\n"
            "}";

    if (r_type->class == HLSL_CLASS_MATRIX
            || n_type->class == HLSL_CLASS_MATRIX
            || i_type->class == HLSL_CLASS_MATRIX)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Matrix arguments are not supported.");
        return false;
    }

    VKD3D_ASSERT(params->args_count == 3);
    mut_params = *params;
    mut_params.args_count = 2;
    if (!(res_type = elementwise_intrinsic_get_common_type(ctx, &mut_params, loc)))
        return false;

    base = expr_common_base_type(res_type->e.numeric.type, i_type->e.numeric.type);
    base = base == HLSL_TYPE_HALF ? HLSL_TYPE_HALF : HLSL_TYPE_FLOAT;
    res_type = convert_numeric_type(ctx, res_type, base);
    idx_type = convert_numeric_type(ctx, i_type, base);
    scal_type = hlsl_get_scalar_type(ctx, base);

    if (!(body = hlsl_sprintf_alloc(ctx, template, res_type->name, res_type->name,
            res_type->name, idx_type->name, scal_type->name)))
        return false;

    func = hlsl_compile_internal_function(ctx, "refract", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_round(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_ROUND, arg, loc);
}

static bool intrinsic_rsqrt(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_RSQ, arg, loc);
}

static bool intrinsic_saturate(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SAT, arg, loc);
}

static bool intrinsic_sign(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *lt, *neg, *op1, *op2, *zero, *arg = params->args[0];
    static const struct hlsl_constant_value zero_value;

    struct hlsl_type *int_type = hlsl_get_numeric_type(ctx, arg->data_type->class, HLSL_TYPE_INT,
            arg->data_type->dimx, arg->data_type->dimy);

    if (!(zero = hlsl_new_constant(ctx, hlsl_get_scalar_type(ctx, arg->data_type->e.numeric.type), &zero_value, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, zero);

    /* Check if 0 < arg, cast bool to int */

    if (!(lt = add_binary_comparison_expr(ctx, params->instrs, HLSL_OP2_LESS, zero, arg, loc)))
        return false;

    if (!(op1 = add_implicit_conversion(ctx, params->instrs, lt, int_type, loc)))
        return false;

    /* Check if arg < 0, cast bool to int and invert (meaning true is -1) */

    if (!(lt = add_binary_comparison_expr(ctx, params->instrs, HLSL_OP2_LESS, arg, zero, loc)))
        return false;

    if (!(op2 = add_implicit_conversion(ctx, params->instrs, lt, int_type, loc)))
        return false;

    if (!(neg = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_NEG, op2, loc)))
        return false;

    /* Adding these two together will make 1 when > 0, -1 when < 0, and 0 when neither */
    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_ADD, neg, op1, loc);
}

static bool intrinsic_sin(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SIN, arg, loc);
}

static bool intrinsic_sinh(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return write_cosh_or_sinh(ctx, params, loc, true);
}

/* smoothstep(a, b, x) = p^2 (3 - 2p), where p = saturate((x - a)/(b - a)) */
static bool intrinsic_smoothstep(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_type *type;
    char *body;

    static const char template[] =
            "%s smoothstep(%s low, %s high, %s x)\n"
            "{\n"
            "    %s p = saturate((x - low) / (high - low));\n"
            "    return (p * p) * (3 - 2 * p);\n"
            "}";

    if (!(type = elementwise_intrinsic_get_common_type(ctx, params, loc)))
        return false;
    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);

    if (!(body = hlsl_sprintf_alloc(ctx, template, type->name, type->name, type->name, type->name, type->name)))
        return false;
    func = hlsl_compile_internal_function(ctx, "smoothstep", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_sqrt(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SQRT, arg, loc);
}

static bool intrinsic_step(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *ge;
    struct hlsl_type *type;

    if (!elementwise_intrinsic_float_convert_args(ctx, params, loc))
        return false;

    if (!(ge = add_binary_comparison_expr(ctx, params->instrs, HLSL_OP2_GEQUAL,
            params->args[1], params->args[0], loc)))
        return false;

    type = ge->data_type;
    type = hlsl_get_numeric_type(ctx, type->class, HLSL_TYPE_FLOAT, type->dimx, type->dimy);
    return !!add_implicit_conversion(ctx, params->instrs, ge, type, loc);
}

static bool intrinsic_tan(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg = params->args[0], *sin, *cos;

    if (!(sin = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_SIN, arg, loc)))
        return false;

    if (!(cos = add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_COS, arg, loc)))
        return false;

    return !!add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_DIV, sin, cos, loc);
}

static bool intrinsic_tanh(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_function_decl *func;
    struct hlsl_ir_node *arg;
    struct hlsl_type *type;
    char *body;

    static const char template[] =
            "%s tanh(%s x)\n"
            "{\n"
            "    %s exp_pos, exp_neg;\n"
            "    exp_pos = exp(x);\n"
            "    exp_neg = exp(-x);\n"
            "    return (exp_pos - exp_neg) / (exp_pos + exp_neg);\n"
            "}\n";

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;
    type = arg->data_type;

    if (!(body = hlsl_sprintf_alloc(ctx, template,
            type->name, type->name, type->name)))
        return false;

    func = hlsl_compile_internal_function(ctx, "tanh", body);
    vkd3d_free(body);
    if (!func)
        return false;

    return add_user_call(ctx, func, params, loc);
}

static bool intrinsic_tex(struct hlsl_ctx *ctx, const struct parse_initializer *params,
        const struct vkd3d_shader_location *loc, const char *name, enum hlsl_sampler_dim dim)
{
    unsigned int sampler_dim = hlsl_sampler_dim_count(dim);
    struct hlsl_resource_load_params load_params = { 0 };
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *coords, *sample;

    if (params->args_count != 2 && params->args_count != 4)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to function '%s': expected 2 or 4, but got %u.", name, params->args_count);
        return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER
            || (sampler_type->sampler_dim != dim && sampler_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC))
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 1 of '%s': expected 'sampler' or '%s', but got '%s'.",
                    name, ctx->builtin_types.sampler[dim]->name, string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }

    if (!strcmp(name, "tex2Dbias")
            || !strcmp(name, "tex2Dlod"))
    {
        struct hlsl_ir_node *lod, *c;

        if (!strcmp(name, "tex2Dlod"))
            load_params.type = HLSL_RESOURCE_SAMPLE_LOD;
        else
            load_params.type = HLSL_RESOURCE_SAMPLE_LOD_BIAS;

        if (!(c = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(X, Y, Z, W), sampler_dim, params->args[1], loc)))
            return false;
        hlsl_block_add_instr(params->instrs, c);

        if (!(coords = add_implicit_conversion(ctx, params->instrs, c,
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        {
            return false;
        }

        if (!(lod = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(W, W, W, W), 1, params->args[1], loc)))
            return false;
        hlsl_block_add_instr(params->instrs, lod);

        if (!(load_params.lod = add_implicit_conversion(ctx, params->instrs, lod,
                hlsl_get_scalar_type(ctx, HLSL_TYPE_FLOAT), loc)))
        {
            return false;
        }
    }
    else if (!strcmp(name, "tex2Dproj")
            || !strcmp(name, "tex3Dproj")
            || !strcmp(name, "texCUBEproj"))
    {
        if (!(coords = add_implicit_conversion(ctx, params->instrs, params->args[1],
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, 4), loc)))
        {
            return false;
        }

        if (hlsl_version_ge(ctx, 4, 0))
        {
            struct hlsl_ir_node *divisor;

            if (!(divisor = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(W, W, W, W), sampler_dim, coords, loc)))
                return false;
            hlsl_block_add_instr(params->instrs, divisor);

            if (!(coords = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(X, Y, Z, W), sampler_dim, coords, loc)))
                return false;
            hlsl_block_add_instr(params->instrs, coords);

            if (!(coords = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_DIV, coords, divisor, loc)))
                return false;

            load_params.type = HLSL_RESOURCE_SAMPLE;
        }
        else
        {
            load_params.type = HLSL_RESOURCE_SAMPLE_PROJ;
        }
    }
    else if (params->args_count == 4) /* Gradient sampling. */
    {
        if (!(coords = add_implicit_conversion(ctx, params->instrs, params->args[1],
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        {
            return false;
        }

        if (!(load_params.ddx = add_implicit_conversion(ctx, params->instrs, params->args[2],
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        {
            return false;
        }

        if (!(load_params.ddy = add_implicit_conversion(ctx, params->instrs, params->args[3],
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        {
            return false;
        }

        load_params.type = HLSL_RESOURCE_SAMPLE_GRAD;
    }
    else
    {
        load_params.type = HLSL_RESOURCE_SAMPLE;

        if (!(coords = add_implicit_conversion(ctx, params->instrs, params->args[1],
                hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        {
            return false;
        }
    }

    /* tex1D() functions never produce 1D resource declarations. For newer profiles half offset
       is used for the second coordinate, while older ones appear to replicate first coordinate.*/
    if (dim == HLSL_SAMPLER_DIM_1D)
    {
        struct hlsl_ir_load *load;
        struct hlsl_ir_node *half;
        struct hlsl_ir_var *var;
        unsigned int idx = 0;

        if (!(var = hlsl_new_synthetic_var(ctx, "coords", hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, 2), loc)))
            return false;

        initialize_var_components(ctx, params->instrs, var, &idx, coords);
        if (hlsl_version_ge(ctx, 4, 0))
        {
            if (!(half = hlsl_new_float_constant(ctx, 0.5f, loc)))
                return false;
            hlsl_block_add_instr(params->instrs, half);

            initialize_var_components(ctx, params->instrs, var, &idx, half);
        }
        else
            initialize_var_components(ctx, params->instrs, var, &idx, coords);

        if (!(load = hlsl_new_var_load(ctx, var, loc)))
            return false;
        hlsl_block_add_instr(params->instrs, &load->node);

        coords = &load->node;

        dim = HLSL_SAMPLER_DIM_2D;
    }

    load_params.coords = coords;
    load_params.resource = params->args[0];
    load_params.format = hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, 4);
    load_params.sampling_dim = dim;

    if (!(sample = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, sample);
    return true;
}

static bool intrinsic_tex1D(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex1D", HLSL_SAMPLER_DIM_1D);
}

static bool intrinsic_tex1Dgrad(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex1Dgrad", HLSL_SAMPLER_DIM_1D);
}

static bool intrinsic_tex2D(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex2D", HLSL_SAMPLER_DIM_2D);
}

static bool intrinsic_tex2Dbias(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex2Dbias", HLSL_SAMPLER_DIM_2D);
}

static bool intrinsic_tex2Dgrad(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex2Dgrad", HLSL_SAMPLER_DIM_2D);
}

static bool intrinsic_tex2Dlod(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex2Dlod", HLSL_SAMPLER_DIM_2D);
}

static bool intrinsic_tex2Dproj(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex2Dproj", HLSL_SAMPLER_DIM_2D);
}

static bool intrinsic_tex3D(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex3D", HLSL_SAMPLER_DIM_3D);
}

static bool intrinsic_tex3Dgrad(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex3Dgrad", HLSL_SAMPLER_DIM_3D);
}

static bool intrinsic_tex3Dproj(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "tex3Dproj", HLSL_SAMPLER_DIM_3D);
}

static bool intrinsic_texCUBE(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "texCUBE", HLSL_SAMPLER_DIM_CUBE);
}

static bool intrinsic_texCUBEgrad(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "texCUBEgrad", HLSL_SAMPLER_DIM_CUBE);
}

static bool intrinsic_texCUBEproj(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    return intrinsic_tex(ctx, params, loc, "texCUBEproj", HLSL_SAMPLER_DIM_CUBE);
}

static bool intrinsic_transpose(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg = params->args[0];
    struct hlsl_type *arg_type = arg->data_type;
    struct hlsl_ir_load *var_load;
    struct hlsl_deref var_deref;
    struct hlsl_type *mat_type;
    struct hlsl_ir_node *load;
    struct hlsl_ir_var *var;
    unsigned int i, j;

    if (arg_type->class != HLSL_CLASS_SCALAR && arg_type->class != HLSL_CLASS_MATRIX)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, arg_type)))
            hlsl_error(ctx, &arg->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                   "Wrong type for argument 1 of transpose(): expected a matrix or scalar type, but got '%s'.",
                   string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (arg_type->class == HLSL_CLASS_SCALAR)
    {
        hlsl_block_add_instr(params->instrs, arg);
        return true;
    }

    mat_type = hlsl_get_matrix_type(ctx, arg_type->e.numeric.type, arg_type->dimy, arg_type->dimx);

    if (!(var = hlsl_new_synthetic_var(ctx, "transpose", mat_type, loc)))
        return false;
    hlsl_init_simple_deref_from_var(&var_deref, var);

    for (i = 0; i < arg_type->dimx; ++i)
    {
        for (j = 0; j < arg_type->dimy; ++j)
        {
            struct hlsl_block block;

            if (!(load = hlsl_add_load_component(ctx, params->instrs, arg, j * arg->data_type->dimx + i, loc)))
                return false;

            if (!hlsl_new_store_component(ctx, &block, &var_deref, i * var->data_type->dimx + j, load))
                return false;
            hlsl_block_add_block(params->instrs, &block);
        }
    }

    if (!(var_load = hlsl_new_var_load(ctx, var, loc)))
        return false;
    hlsl_block_add_instr(params->instrs, &var_load->node);

    return true;
}

static bool intrinsic_trunc(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg;

    if (!(arg = intrinsic_float_convert_arg(ctx, params, params->args[0], loc)))
        return false;

    return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_TRUNC, arg, loc);
}

static bool intrinsic_d3dcolor_to_ubyte4(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *arg = params->args[0], *ret, *c, *swizzle;
    struct hlsl_type *arg_type = arg->data_type;

    if (arg_type->class != HLSL_CLASS_SCALAR && !(arg_type->class == HLSL_CLASS_VECTOR && arg_type->dimx == 4))
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, arg_type)))
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Wrong argument type '%s'.", string->buffer);
            hlsl_release_string_buffer(ctx, string);
        }

        return false;
    }

    if (!(arg = intrinsic_float_convert_arg(ctx, params, arg, loc)))
        return false;

    if (!(c = hlsl_new_float_constant(ctx, 255.0f + (0.5f / 256.0f), loc)))
        return false;
    hlsl_block_add_instr(params->instrs, c);

    if (arg_type->class == HLSL_CLASS_VECTOR)
    {
        if (!(swizzle = hlsl_new_swizzle(ctx, HLSL_SWIZZLE(Z, Y, X, W), 4, arg, loc)))
            return false;
        hlsl_block_add_instr(params->instrs, swizzle);

        arg = swizzle;
    }

    if (!(ret = add_binary_arithmetic_expr(ctx, params->instrs, HLSL_OP2_MUL, arg, c, loc)))
        return false;

    if (hlsl_version_ge(ctx, 4, 0))
        return !!add_unary_arithmetic_expr(ctx, params->instrs, HLSL_OP1_TRUNC, ret, loc);

    return true;
}

static bool intrinsic_GetRenderTargetSampleCount(struct hlsl_ctx *ctx,
        const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *operands[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_ir_node *expr;

    if (!(expr = hlsl_new_expr(ctx, HLSL_OP0_RASTERIZER_SAMPLE_COUNT,
            operands, hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT), loc)))
        return false;
    hlsl_block_add_instr(params->instrs, expr);

    return true;
}

static const struct intrinsic_function
{
    const char *name;
    int param_count;
    bool check_numeric;
    bool (*handler)(struct hlsl_ctx *ctx, const struct parse_initializer *params,
            const struct vkd3d_shader_location *loc);
}
intrinsic_functions[] =
{
    /* Note: these entries should be kept in alphabetical order. */
    {"D3DCOLORtoUBYTE4",                    1, true,  intrinsic_d3dcolor_to_ubyte4},
    {"GetRenderTargetSampleCount",          0, true,  intrinsic_GetRenderTargetSampleCount},
    {"abs",                                 1, true,  intrinsic_abs},
    {"acos",                                1, true,  intrinsic_acos},
    {"all",                                 1, true,  intrinsic_all},
    {"any",                                 1, true,  intrinsic_any},
    {"asfloat",                             1, true,  intrinsic_asfloat},
    {"asin",                                1, true,  intrinsic_asin},
    {"asint",                               1, true,  intrinsic_asint},
    {"asuint",                             -1, true,  intrinsic_asuint},
    {"atan",                                1, true,  intrinsic_atan},
    {"atan2",                               2, true,  intrinsic_atan2},
    {"ceil",                                1, true,  intrinsic_ceil},
    {"clamp",                               3, true,  intrinsic_clamp},
    {"clip",                                1, true,  intrinsic_clip},
    {"cos",                                 1, true,  intrinsic_cos},
    {"cosh",                                1, true,  intrinsic_cosh},
    {"cross",                               2, true,  intrinsic_cross},
    {"ddx",                                 1, true,  intrinsic_ddx},
    {"ddx_coarse",                          1, true,  intrinsic_ddx_coarse},
    {"ddx_fine",                            1, true,  intrinsic_ddx_fine},
    {"ddy",                                 1, true,  intrinsic_ddy},
    {"ddy_coarse",                          1, true,  intrinsic_ddy_coarse},
    {"ddy_fine",                            1, true,  intrinsic_ddy_fine},
    {"degrees",                             1, true,  intrinsic_degrees},
    {"determinant",                         1, true,  intrinsic_determinant},
    {"distance",                            2, true,  intrinsic_distance},
    {"dot",                                 2, true,  intrinsic_dot},
    {"exp",                                 1, true,  intrinsic_exp},
    {"exp2",                                1, true,  intrinsic_exp2},
    {"f16tof32",                            1, true,  intrinsic_f16tof32},
    {"faceforward",                         3, true,  intrinsic_faceforward},
    {"floor",                               1, true,  intrinsic_floor},
    {"fmod",                                2, true,  intrinsic_fmod},
    {"frac",                                1, true,  intrinsic_frac},
    {"fwidth",                              1, true,  intrinsic_fwidth},
    {"ldexp",                               2, true,  intrinsic_ldexp},
    {"length",                              1, true,  intrinsic_length},
    {"lerp",                                3, true,  intrinsic_lerp},
    {"lit",                                 3, true,  intrinsic_lit},
    {"log",                                 1, true,  intrinsic_log},
    {"log10",                               1, true,  intrinsic_log10},
    {"log2",                                1, true,  intrinsic_log2},
    {"max",                                 2, true,  intrinsic_max},
    {"min",                                 2, true,  intrinsic_min},
    {"mul",                                 2, true,  intrinsic_mul},
    {"normalize",                           1, true,  intrinsic_normalize},
    {"pow",                                 2, true,  intrinsic_pow},
    {"radians",                             1, true,  intrinsic_radians},
    {"rcp",                                 1, true,  intrinsic_rcp},
    {"reflect",                             2, true,  intrinsic_reflect},
    {"refract",                             3, true,  intrinsic_refract},
    {"round",                               1, true,  intrinsic_round},
    {"rsqrt",                               1, true,  intrinsic_rsqrt},
    {"saturate",                            1, true,  intrinsic_saturate},
    {"sign",                                1, true,  intrinsic_sign},
    {"sin",                                 1, true,  intrinsic_sin},
    {"sinh",                                1, true,  intrinsic_sinh},
    {"smoothstep",                          3, true,  intrinsic_smoothstep},
    {"sqrt",                                1, true,  intrinsic_sqrt},
    {"step",                                2, true,  intrinsic_step},
    {"tan",                                 1, true,  intrinsic_tan},
    {"tanh",                                1, true,  intrinsic_tanh},
    {"tex1D",                              -1, false, intrinsic_tex1D},
    {"tex1Dgrad",                           4, false, intrinsic_tex1Dgrad},
    {"tex2D",                              -1, false, intrinsic_tex2D},
    {"tex2Dbias",                           2, false, intrinsic_tex2Dbias},
    {"tex2Dgrad",                           4, false, intrinsic_tex2Dgrad},
    {"tex2Dlod",                            2, false, intrinsic_tex2Dlod},
    {"tex2Dproj",                           2, false, intrinsic_tex2Dproj},
    {"tex3D",                              -1, false, intrinsic_tex3D},
    {"tex3Dgrad",                           4, false, intrinsic_tex3Dgrad},
    {"tex3Dproj",                           2, false, intrinsic_tex3Dproj},
    {"texCUBE",                            -1, false, intrinsic_texCUBE},
    {"texCUBEgrad",                         4, false, intrinsic_texCUBEgrad},
    {"texCUBEproj",                         2, false, intrinsic_texCUBEproj},
    {"transpose",                           1, true,  intrinsic_transpose},
    {"trunc",                               1, true,  intrinsic_trunc},
};

static int intrinsic_function_name_compare(const void *a, const void *b)
{
    const struct intrinsic_function *func = b;

    return strcmp(a, func->name);
}

static struct hlsl_block *add_call(struct hlsl_ctx *ctx, const char *name,
        struct parse_initializer *args, const struct vkd3d_shader_location *loc)
{
    struct intrinsic_function *intrinsic;
    struct hlsl_ir_function_decl *decl;

    if ((decl = find_function_call(ctx, name, args, loc)))
    {
        if (!add_user_call(ctx, decl, args, loc))
            goto fail;
    }
    else if ((intrinsic = bsearch(name, intrinsic_functions, ARRAY_SIZE(intrinsic_functions),
            sizeof(*intrinsic_functions), intrinsic_function_name_compare)))
    {
        if (intrinsic->param_count >= 0 && args->args_count != intrinsic->param_count)
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                    "Wrong number of arguments to function '%s': expected %u, but got %u.",
                    name, intrinsic->param_count, args->args_count);
            goto fail;
        }

        if (intrinsic->check_numeric)
        {
            unsigned int i;

            for (i = 0; i < args->args_count; ++i)
            {
                if (!hlsl_is_numeric_type(args->args[i]->data_type))
                {
                    struct vkd3d_string_buffer *string;

                    if ((string = hlsl_type_to_string(ctx, args->args[i]->data_type)))
                        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                                "Wrong type for argument %u of '%s': expected a numeric type, but got '%s'.",
                                i + 1, name, string->buffer);
                    hlsl_release_string_buffer(ctx, string);
                    goto fail;
                }
            }
        }

        if (!intrinsic->handler(ctx, args, loc))
            goto fail;
    }
    else if (rb_get(&ctx->functions, name))
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED, "No compatible %u parameter declaration for \"%s\" found.",
                args->args_count, name);
        goto fail;
    }
    else
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED, "Function \"%s\" is not defined.", name);
        goto fail;
    }
    vkd3d_free(args->args);
    return args->instrs;

fail:
    free_parse_initializer(args);
    return NULL;
}

static struct hlsl_block *add_constructor(struct hlsl_ctx *ctx, struct hlsl_type *type,
        struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_load *load;
    struct hlsl_ir_var *var;
    unsigned int i, idx = 0;

    if (!(var = hlsl_new_synthetic_var(ctx, "constructor", type, loc)))
        return NULL;

    for (i = 0; i < params->args_count; ++i)
        initialize_var_components(ctx, params->instrs, var, &idx, params->args[i]);

    if (!(load = hlsl_new_var_load(ctx, var, loc)))
        return NULL;
    hlsl_block_add_instr(params->instrs, &load->node);

    vkd3d_free(params->args);
    return params->instrs;
}

static bool add_ternary(struct hlsl_ctx *ctx, struct hlsl_block *block,
        struct hlsl_ir_node *cond, struct hlsl_ir_node *first, struct hlsl_ir_node *second)
{
    struct hlsl_ir_node *args[HLSL_MAX_OPERANDS] = {0};
    struct hlsl_type *cond_type = cond->data_type;
    struct hlsl_type *common_type;

    if (cond_type->class > HLSL_CLASS_LAST_NUMERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, cond_type)))
            hlsl_error(ctx, &cond->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Ternary condition type '%s' is not numeric.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }

    if (first->data_type->class <= HLSL_CLASS_LAST_NUMERIC
            && second->data_type->class <= HLSL_CLASS_LAST_NUMERIC)
    {
        if (!(common_type = get_common_numeric_type(ctx, first, second, &first->loc)))
            return false;

        if (cond_type->dimx == 1 && cond_type->dimy == 1)
        {
            cond_type = hlsl_get_numeric_type(ctx, common_type->class,
                    HLSL_TYPE_BOOL, common_type->dimx, common_type->dimy);
            if (!(cond = add_implicit_conversion(ctx, block, cond, cond_type, &cond->loc)))
                return false;
        }
        else
        {
            cond_type = hlsl_get_numeric_type(ctx, cond_type->class, HLSL_TYPE_BOOL,
                    cond_type->dimx, cond_type->dimy);
            if (!(cond = add_implicit_conversion(ctx, block, cond, cond_type, &cond->loc)))
                return false;

            if (common_type->dimx == 1 && common_type->dimy == 1)
            {
                common_type = hlsl_get_numeric_type(ctx, cond_type->class,
                        common_type->e.numeric.type, cond_type->dimx, cond_type->dimy);
            }
            else if (cond_type->dimx != common_type->dimx || cond_type->dimy != common_type->dimy)
            {
                /* This condition looks wrong but is correct.
                * floatN is compatible with float1xN, but not with floatNx1. */

                struct vkd3d_string_buffer *cond_string, *value_string;

                cond_string = hlsl_type_to_string(ctx, cond_type);
                value_string = hlsl_type_to_string(ctx, common_type);
                if (cond_string && value_string)
                    hlsl_error(ctx, &first->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Ternary condition type '%s' is not compatible with value type '%s'.",
                            cond_string->buffer, value_string->buffer);
                hlsl_release_string_buffer(ctx, cond_string);
                hlsl_release_string_buffer(ctx, value_string);
            }
        }

        if (!(first = add_implicit_conversion(ctx, block, first, common_type, &first->loc)))
            return false;

        if (!(second = add_implicit_conversion(ctx, block, second, common_type, &second->loc)))
            return false;
    }
    else
    {
        struct vkd3d_string_buffer *first_string, *second_string;

        if (!hlsl_types_are_equal(first->data_type, second->data_type))
        {
            first_string = hlsl_type_to_string(ctx, first->data_type);
            second_string = hlsl_type_to_string(ctx, second->data_type);
            if (first_string && second_string)
                hlsl_error(ctx, &first->loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "Ternary argument types '%s' and '%s' do not match.",
                        first_string->buffer, second_string->buffer);
            hlsl_release_string_buffer(ctx, first_string);
            hlsl_release_string_buffer(ctx, second_string);
        }

        cond_type = hlsl_get_numeric_type(ctx, cond_type->class, HLSL_TYPE_BOOL,
                cond_type->dimx, cond_type->dimy);
        if (!(cond = add_implicit_conversion(ctx, block, cond, cond_type, &cond->loc)))
            return false;

        common_type = first->data_type;
    }

    VKD3D_ASSERT(cond->data_type->e.numeric.type == HLSL_TYPE_BOOL);

    args[0] = cond;
    args[1] = first;
    args[2] = second;
    return add_expr(ctx, block, HLSL_OP3_TERNARY, args, common_type, &first->loc);
}

static unsigned int hlsl_offset_dim_count(enum hlsl_sampler_dim dim)
{
    switch (dim)
    {
        case HLSL_SAMPLER_DIM_1D:
        case HLSL_SAMPLER_DIM_1DARRAY:
            return 1;
        case HLSL_SAMPLER_DIM_2D:
        case HLSL_SAMPLER_DIM_2DMS:
        case HLSL_SAMPLER_DIM_2DARRAY:
        case HLSL_SAMPLER_DIM_2DMSARRAY:
            return 2;
        case HLSL_SAMPLER_DIM_3D:
            return 3;
        case HLSL_SAMPLER_DIM_CUBE:
        case HLSL_SAMPLER_DIM_CUBEARRAY:
        case HLSL_SAMPLER_DIM_BUFFER:
            /* Offset parameters not supported for these types. */
            return 0;
        default:
            vkd3d_unreachable();
    }
}

static bool raise_invalid_method_object_type(struct hlsl_ctx *ctx, const struct hlsl_type *object_type,
        const char *method, const struct vkd3d_shader_location *loc)
{
    struct vkd3d_string_buffer *string;

    if ((string = hlsl_type_to_string(ctx, object_type)))
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED,
                "Method '%s' is not defined on type '%s'.", method, string->buffer);
    hlsl_release_string_buffer(ctx, string);
    return false;
}

static bool add_load_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = {.type = HLSL_RESOURCE_LOAD};
    unsigned int sampler_dim, offset_dim;
    struct hlsl_ir_node *load;
    bool multisampled;

    if (object_type->sampler_dim == HLSL_SAMPLER_DIM_STRUCTURED_BUFFER)
    {
        hlsl_fixme(ctx, loc, "Method '%s' for structured buffers.", name);
        return false;
    }

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    multisampled = object_type->sampler_dim == HLSL_SAMPLER_DIM_2DMS
            || object_type->sampler_dim == HLSL_SAMPLER_DIM_2DMSARRAY;

    if (params->args_count < 1 + multisampled || params->args_count > 2 + multisampled + !!offset_dim)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method 'Load': expected between %u and %u, but got %u.",
                1 + multisampled, 2 + multisampled + !!offset_dim, params->args_count);
        return false;
    }

    if (multisampled)
    {
        if (!(load_params.sample_index = add_implicit_conversion(ctx, block, params->args[1],
                hlsl_get_scalar_type(ctx, HLSL_TYPE_INT), loc)))
            return false;
    }

    if (!!offset_dim && params->args_count > 1 + multisampled)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[1 + multisampled],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    if (params->args_count > 1 + multisampled + !!offset_dim)
    {
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");
    }

    /* +1 for the mipmap level for non-multisampled textures */
    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[0],
            hlsl_get_vector_type(ctx, HLSL_TYPE_INT, sampler_dim + !multisampled), loc)))
        return false;

    load_params.format = object_type->e.resource.format;
    load_params.resource = object;

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);
    return true;
}

static bool add_sample_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = {.type = HLSL_RESOURCE_SAMPLE};
    unsigned int sampler_dim, offset_dim;
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *load;

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    if (params->args_count < 2 || params->args_count > 4 + !!offset_dim)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method 'Sample': expected from 2 to %u, but got %u.",
                4 + !!offset_dim, params->args_count);
        return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER || sampler_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 0 of Sample(): expected 'sampler', but got '%s'.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[1],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        return false;

    if (offset_dim && params->args_count > 2)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[2],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    if (params->args_count > 2 + !!offset_dim)
        hlsl_fixme(ctx, loc, "Sample() clamp parameter.");
    if (params->args_count > 3 + !!offset_dim)
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");

    load_params.format = object_type->e.resource.format;
    load_params.resource = object;
    load_params.sampler = params->args[0];

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);

    return true;
}

static bool add_sample_cmp_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = { 0 };
    unsigned int sampler_dim, offset_dim;
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *load;

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    if (!strcmp(name, "SampleCmpLevelZero"))
        load_params.type = HLSL_RESOURCE_SAMPLE_CMP_LZ;
    else
        load_params.type = HLSL_RESOURCE_SAMPLE_CMP;

    if (params->args_count < 3 || params->args_count > 5 + !!offset_dim)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method '%s': expected from 3 to %u, but got %u.",
                name, 5 + !!offset_dim, params->args_count);
        return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER || sampler_type->sampler_dim != HLSL_SAMPLER_DIM_COMPARISON)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 0 of %s(): expected 'SamplerComparisonState', but got '%s'.",
                    name, string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[1],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        return false;

    if (!(load_params.cmp = add_implicit_conversion(ctx, block, params->args[2],
            hlsl_get_scalar_type(ctx, HLSL_TYPE_FLOAT), loc)))
        load_params.cmp = params->args[2];

    if (offset_dim && params->args_count > 3)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[2],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    if (params->args_count > 3 + !!offset_dim)
        hlsl_fixme(ctx, loc, "%s() clamp parameter.", name);
    if (params->args_count > 4 + !!offset_dim)
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");

    load_params.format = object_type->e.resource.format;
    load_params.resource = object;
    load_params.sampler = params->args[0];

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);

    return true;
}

static bool add_gather_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = {0};
    unsigned int sampler_dim, offset_dim;
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *load;
    unsigned int read_channel;

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    if (!strcmp(name, "GatherGreen"))
    {
        load_params.type = HLSL_RESOURCE_GATHER_GREEN;
        read_channel = 1;
    }
    else if (!strcmp(name, "GatherBlue"))
    {
        load_params.type = HLSL_RESOURCE_GATHER_BLUE;
        read_channel = 2;
    }
    else if (!strcmp(name, "GatherAlpha"))
    {
        load_params.type = HLSL_RESOURCE_GATHER_ALPHA;
        read_channel = 3;
    }
    else
    {
        load_params.type = HLSL_RESOURCE_GATHER_RED;
        read_channel = 0;
    }

    if (!strcmp(name, "Gather") || !offset_dim)
    {
        if (params->args_count < 2 || params->args_count > 3 + !!offset_dim)
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                    "Wrong number of arguments to method '%s': expected from 2 to %u, but got %u.",
                    name, 3 + !!offset_dim, params->args_count);
            return false;
        }
    }
    else if (params->args_count < 2 || params->args_count == 5 || params->args_count > 7)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method '%s': expected 2, 3, 4, 6 or 7, but got %u.",
                name, params->args_count);
        return false;
    }

    if (params->args_count == 3 + !!offset_dim || params->args_count == 7)
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");

    if (params->args_count == 6 || params->args_count == 7)
    {
        hlsl_fixme(ctx, loc, "Multiple %s() offset parameters.", name);
    }
    else if (offset_dim && params->args_count > 2)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[2],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER || sampler_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 1 of %s(): expected 'sampler', but got '%s'.", name, string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (read_channel >= object_type->e.resource.format->dimx)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                "Method %s() requires at least %u channels.", name, read_channel + 1);
        return false;
    }

    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[1],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        return false;

    load_params.format = hlsl_get_vector_type(ctx, object_type->e.resource.format->e.numeric.type, 4);
    load_params.resource = object;
    load_params.sampler = params->args[0];

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);
    return true;
}

static bool add_assignment_from_component(struct hlsl_ctx *ctx, struct hlsl_block *instrs, struct hlsl_ir_node *dest,
        struct hlsl_ir_node *src, unsigned int component, const struct vkd3d_shader_location *loc)
{
    struct hlsl_ir_node *load;

    if (!dest)
        return true;

    if (!(load = hlsl_add_load_component(ctx, instrs, src, component, loc)))
        return false;

    if (!add_assignment(ctx, instrs, dest, ASSIGN_OP_ASSIGN, load))
        return false;

    return true;
}

static bool add_getdimensions_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    bool uint_resinfo, has_uint_arg, has_float_arg;
    struct hlsl_resource_load_params load_params;
    struct hlsl_ir_node *sample_info, *res_info;
    struct hlsl_ir_node *zero = NULL, *void_ret;
    struct hlsl_type *uint_type, *float_type;
    unsigned int i, j;
    enum func_argument
    {
        ARG_MIP_LEVEL,
        ARG_WIDTH,
        ARG_HEIGHT,
        ARG_ELEMENT_COUNT,
        ARG_LEVEL_COUNT,
        ARG_SAMPLE_COUNT,
        ARG_MAX_ARGS,
    };
    struct hlsl_ir_node *args[ARG_MAX_ARGS] = { 0 };
    static const struct overload
    {
        enum hlsl_sampler_dim sampler_dim;
        unsigned int args_count;
        enum func_argument args[ARG_MAX_ARGS];
    }
    overloads[] =
    {
        { HLSL_SAMPLER_DIM_1D, 1, { ARG_WIDTH } },
        { HLSL_SAMPLER_DIM_1D, 3, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_1DARRAY, 2, { ARG_WIDTH, ARG_ELEMENT_COUNT } },
        { HLSL_SAMPLER_DIM_1DARRAY, 4, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_ELEMENT_COUNT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_2D, 2, { ARG_WIDTH, ARG_HEIGHT } },
        { HLSL_SAMPLER_DIM_2D, 4, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_HEIGHT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_2DARRAY, 3, { ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT } },
        { HLSL_SAMPLER_DIM_2DARRAY, 5, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_3D, 3, { ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT } },
        { HLSL_SAMPLER_DIM_3D, 5, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_CUBE, 2, { ARG_WIDTH, ARG_HEIGHT } },
        { HLSL_SAMPLER_DIM_CUBE, 4, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_HEIGHT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_CUBEARRAY, 3, { ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT } },
        { HLSL_SAMPLER_DIM_CUBEARRAY, 5, { ARG_MIP_LEVEL, ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT, ARG_LEVEL_COUNT } },
        { HLSL_SAMPLER_DIM_2DMS, 3, { ARG_WIDTH, ARG_HEIGHT, ARG_SAMPLE_COUNT } },
        { HLSL_SAMPLER_DIM_2DMSARRAY, 4, { ARG_WIDTH, ARG_HEIGHT, ARG_ELEMENT_COUNT, ARG_SAMPLE_COUNT } },
        { HLSL_SAMPLER_DIM_BUFFER, 1, { ARG_WIDTH} },
    };
    const struct overload *o = NULL;

    if (object_type->sampler_dim == HLSL_SAMPLER_DIM_STRUCTURED_BUFFER)
    {
        hlsl_fixme(ctx, loc, "Method '%s' for structured buffers.", name);
        return false;
    }

    uint_type = hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT);
    float_type = hlsl_get_scalar_type(ctx, HLSL_TYPE_FLOAT);
    has_uint_arg = has_float_arg = false;
    for (i = 0; i < ARRAY_SIZE(overloads); ++i)
    {
        const struct overload *iter = &overloads[i];

        if (iter->sampler_dim == object_type->sampler_dim && iter->args_count == params->args_count)
        {
            for (j = 0; j < params->args_count; ++j)
            {
                args[iter->args[j]] = params->args[j];

                /* Input parameter. */
                if (iter->args[j] == ARG_MIP_LEVEL)
                {
                    if (!(args[ARG_MIP_LEVEL] = add_implicit_conversion(ctx, block, args[ARG_MIP_LEVEL],
                            hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT), loc)))
                    {
                        return false;
                    }

                    continue;
                }

                has_float_arg |= hlsl_types_are_equal(params->args[j]->data_type, float_type);
                has_uint_arg |= hlsl_types_are_equal(params->args[j]->data_type, uint_type);

                if (params->args[j]->data_type->class != HLSL_CLASS_SCALAR)
                {
                    hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Expected scalar arguments.");
                    break;
                }
            }
            o = iter;
            break;
        }
    }
    uint_resinfo = !has_float_arg && has_uint_arg;

    if (!o)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, object_type)))
        {
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                    "Unexpected number of arguments %u for %s.%s().", params->args_count, string->buffer, name);
            hlsl_release_string_buffer(ctx, string);
        }
    }

    if (!args[ARG_MIP_LEVEL])
    {
        if (!(zero = hlsl_new_uint_constant(ctx, 0, loc)))
            return false;
        hlsl_block_add_instr(block, zero);
        args[ARG_MIP_LEVEL] = zero;
    }

    memset(&load_params, 0, sizeof(load_params));
    load_params.type = HLSL_RESOURCE_RESINFO;
    load_params.resource = object;
    load_params.lod = args[ARG_MIP_LEVEL];
    load_params.format = hlsl_get_vector_type(ctx, uint_resinfo ? HLSL_TYPE_UINT : HLSL_TYPE_FLOAT, 4);

    if (!(res_info = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, res_info);

    if (!add_assignment_from_component(ctx, block, args[ARG_WIDTH], res_info, 0, loc))
        return false;

    if (!add_assignment_from_component(ctx, block, args[ARG_HEIGHT], res_info, 1, loc))
        return false;

    if (!add_assignment_from_component(ctx, block, args[ARG_ELEMENT_COUNT], res_info,
            object_type->sampler_dim == HLSL_SAMPLER_DIM_1DARRAY ? 1 : 2, loc))
    {
        return false;
    }

    if (!add_assignment_from_component(ctx, block, args[ARG_LEVEL_COUNT], res_info, 3, loc))
        return false;

    if (args[ARG_SAMPLE_COUNT])
    {
        memset(&load_params, 0, sizeof(load_params));
        load_params.type = HLSL_RESOURCE_SAMPLE_INFO;
        load_params.resource = object;
        load_params.format = args[ARG_SAMPLE_COUNT]->data_type;
        if (!(sample_info = hlsl_new_resource_load(ctx, &load_params, loc)))
            return false;
        hlsl_block_add_instr(block, sample_info);

        if (!add_assignment(ctx, block, args[ARG_SAMPLE_COUNT], ASSIGN_OP_ASSIGN, sample_info))
            return false;
    }

    if (!(void_ret = hlsl_new_void_expr(ctx, loc)))
        return false;
    hlsl_block_add_instr(block, void_ret);

    return true;
}

static bool add_sample_lod_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = { 0 };
    unsigned int sampler_dim, offset_dim;
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *load;

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    if (!strcmp(name, "SampleLevel"))
        load_params.type = HLSL_RESOURCE_SAMPLE_LOD;
    else
        load_params.type = HLSL_RESOURCE_SAMPLE_LOD_BIAS;

    if (params->args_count < 3 || params->args_count > 4 + !!offset_dim)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method '%s': expected from 3 to %u, but got %u.",
                name, 4 + !!offset_dim, params->args_count);
        return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER || sampler_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 0 of %s(): expected 'sampler', but got '%s'.", name, string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[1],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        load_params.coords = params->args[1];

    if (!(load_params.lod = add_implicit_conversion(ctx, block, params->args[2],
            hlsl_get_scalar_type(ctx, HLSL_TYPE_FLOAT), loc)))
        load_params.lod = params->args[2];

    if (offset_dim && params->args_count > 3)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[3],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    if (params->args_count > 3 + !!offset_dim)
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");

    load_params.format = object_type->e.resource.format;
    load_params.resource = object;
    load_params.sampler = params->args[0];

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);
    return true;
}

static bool add_sample_grad_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    struct hlsl_resource_load_params load_params = { 0 };
    unsigned int sampler_dim, offset_dim;
    const struct hlsl_type *sampler_type;
    struct hlsl_ir_node *load;

    sampler_dim = hlsl_sampler_dim_count(object_type->sampler_dim);
    offset_dim = hlsl_offset_dim_count(object_type->sampler_dim);

    load_params.type = HLSL_RESOURCE_SAMPLE_GRAD;

    if (params->args_count < 4 || params->args_count > 5 + !!offset_dim)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                "Wrong number of arguments to method '%s': expected from 4 to %u, but got %u.",
                name, 5 + !!offset_dim, params->args_count);
        return false;
    }

    sampler_type = params->args[0]->data_type;
    if (sampler_type->class != HLSL_CLASS_SAMPLER || sampler_type->sampler_dim != HLSL_SAMPLER_DIM_GENERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, sampler_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Wrong type for argument 0 of %s(): expected 'sampler', but got '%s'.", name, string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    if (!(load_params.coords = add_implicit_conversion(ctx, block, params->args[1],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        load_params.coords = params->args[1];

    if (!(load_params.ddx = add_implicit_conversion(ctx, block, params->args[2],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        load_params.ddx = params->args[2];

    if (!(load_params.ddy = add_implicit_conversion(ctx, block, params->args[3],
            hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, sampler_dim), loc)))
        load_params.ddy = params->args[3];

    if (offset_dim && params->args_count > 4)
    {
        if (!(load_params.texel_offset = add_implicit_conversion(ctx, block, params->args[4],
                hlsl_get_vector_type(ctx, HLSL_TYPE_INT, offset_dim), loc)))
            return false;
    }

    if (params->args_count > 4 + !!offset_dim)
        hlsl_fixme(ctx, loc, "Tiled resource status argument.");

    load_params.format = object_type->e.resource.format;
    load_params.resource = object;
    load_params.sampler = params->args[0];

    if (!(load = hlsl_new_resource_load(ctx, &load_params, loc)))
        return false;
    hlsl_block_add_instr(block, load);
    return true;
}

static const struct method_function
{
    const char *name;
    bool (*handler)(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
            const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc);
    bool valid_dims[HLSL_SAMPLER_DIM_MAX + 1];
}
object_methods[] =
{
                                                        /*  g c   1d  2d  3d  cube  1darr  2darr  2dms  2dmsarr  cubearr  buff  sbuff*/
    { "Gather",             add_gather_method_call,        {0,0,  0,  1,  0,  1,    0,     1,     0,    0,       1,       0,    0}},
    { "GatherAlpha",        add_gather_method_call,        {0,0,  0,  1,  0,  1,    0,     1,     0,    0,       1,       0,    0}},
    { "GatherBlue",         add_gather_method_call,        {0,0,  0,  1,  0,  1,    0,     1,     0,    0,       1,       0,    0}},
    { "GatherGreen",        add_gather_method_call,        {0,0,  0,  1,  0,  1,    0,     1,     0,    0,       1,       0,    0}},
    { "GatherRed",          add_gather_method_call,        {0,0,  0,  1,  0,  1,    0,     1,     0,    0,       1,       0,    0}},

    { "GetDimensions",      add_getdimensions_method_call, {0,0,  1,  1,  1,  1,    1,     1,     1,    1,       1,       1,    1}},

    { "Load",               add_load_method_call,          {0,0,  1,  1,  1,  0,    1,     1,     1,    1,       0,       1,    1}},

    { "Sample",             add_sample_method_call,        {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
    { "SampleBias",         add_sample_lod_method_call,    {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
    { "SampleCmp",          add_sample_cmp_method_call,    {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
    { "SampleCmpLevelZero", add_sample_cmp_method_call,    {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
    { "SampleGrad",         add_sample_grad_method_call,   {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
    { "SampleLevel",        add_sample_lod_method_call,    {0,0,  1,  1,  1,  1,    1,     1,     0,    0,       1,       0,    0}},
};

static int object_method_function_name_compare(const void *a, const void *b)
{
    const struct method_function *func = b;

    return strcmp(a, func->name);
}

static bool add_method_call(struct hlsl_ctx *ctx, struct hlsl_block *block, struct hlsl_ir_node *object,
        const char *name, const struct parse_initializer *params, const struct vkd3d_shader_location *loc)
{
    const struct hlsl_type *object_type = object->data_type;
    const struct method_function *method;

    if (object_type->class != HLSL_CLASS_TEXTURE || object_type->sampler_dim == HLSL_SAMPLER_DIM_GENERIC)
    {
        struct vkd3d_string_buffer *string;

        if ((string = hlsl_type_to_string(ctx, object_type)))
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Type '%s' does not have methods.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
        return false;
    }

    method = bsearch(name, object_methods, ARRAY_SIZE(object_methods), sizeof(*method),
            object_method_function_name_compare);

    if (method && method->valid_dims[object_type->sampler_dim])
    {
        return method->handler(ctx, block, object, name, params, loc);
    }
    else
    {
        return raise_invalid_method_object_type(ctx, object_type, name, loc);
    }
}

static void validate_texture_format_type(struct hlsl_ctx *ctx, struct hlsl_type *format,
        const struct vkd3d_shader_location *loc)
{
    if (format->class > HLSL_CLASS_VECTOR)
    {
        struct vkd3d_string_buffer *string;

        string = hlsl_type_to_string(ctx, format);
        if (string)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "Texture data type %s is not scalar or vector.", string->buffer);
        hlsl_release_string_buffer(ctx, string);
    }
}

static bool check_continue(struct hlsl_ctx *ctx, const struct hlsl_scope *scope, const struct vkd3d_shader_location *loc)
{
    if (scope->_switch)
    {
        hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                "The 'continue' statement is not allowed in 'switch' statements.");
        return false;
    }

    if (scope->loop)
        return true;

    if (scope->upper)
        return check_continue(ctx, scope->upper, loc);

    hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "The 'continue' statement is only allowed in loops.");
    return false;
}

static bool is_break_allowed(const struct hlsl_scope *scope)
{
    if (scope->loop || scope->_switch)
        return true;

    return scope->upper ? is_break_allowed(scope->upper) : false;
}

static void check_duplicated_switch_cases(struct hlsl_ctx *ctx, const struct hlsl_ir_switch_case *check, struct list *cases)
{
    struct hlsl_ir_switch_case *c;
    bool found_duplicate = false;

    LIST_FOR_EACH_ENTRY(c, cases, struct hlsl_ir_switch_case, entry)
    {
        if (check->is_default)
        {
            if ((found_duplicate = c->is_default))
            {
                hlsl_error(ctx, &check->loc, VKD3D_SHADER_ERROR_HLSL_DUPLICATE_SWITCH_CASE,
                        "Found multiple 'default' statements.");
                hlsl_note(ctx, &c->loc, VKD3D_SHADER_LOG_ERROR, "The 'default' statement was previously found here.");
            }
        }
        else
        {
            if (c->is_default) continue;
            if ((found_duplicate = (c->value == check->value)))
            {
                hlsl_error(ctx, &check->loc, VKD3D_SHADER_ERROR_HLSL_DUPLICATE_SWITCH_CASE,
                        "Found duplicate 'case' statement.");
                hlsl_note(ctx, &c->loc, VKD3D_SHADER_LOG_ERROR, "The same 'case %d' statement was previously found here.",
                        c->value);
            }
        }

        if (found_duplicate)
            break;
    }
}

static void validate_uav_type(struct hlsl_ctx *ctx, enum hlsl_sampler_dim dim,
        struct hlsl_type *format, const struct vkd3d_shader_location* loc)
{
    struct vkd3d_string_buffer *string = hlsl_type_to_string(ctx, format);

    if (!type_contains_only_numerics(format))
    {
        if (string)
            hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                    "UAV type %s is not numeric.", string->buffer);
    }

    switch (dim)
    {
        case HLSL_SAMPLER_DIM_BUFFER:
        case HLSL_SAMPLER_DIM_1D:
        case HLSL_SAMPLER_DIM_1DARRAY:
        case HLSL_SAMPLER_DIM_2D:
        case HLSL_SAMPLER_DIM_2DARRAY:
        case HLSL_SAMPLER_DIM_3D:
            if (format->class == HLSL_CLASS_ARRAY)
            {
                if (string)
                    hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "This type of UAV does not support array type.");
            }
            else if (hlsl_type_component_count(format) > 4)
            {
                if (string)
                    hlsl_error(ctx, loc, VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "UAV data type %s size exceeds maximum size.", string->buffer);
            }
            break;
        case HLSL_SAMPLER_DIM_STRUCTURED_BUFFER:
            break;
        default:
            vkd3d_unreachable();
    }

    hlsl_release_string_buffer(ctx, string);
}

static bool state_block_add_entry(struct hlsl_state_block *state_block, struct hlsl_state_block_entry *entry)
{
    if (!vkd3d_array_reserve((void **)&state_block->entries, &state_block->capacity, state_block->count + 1,
            sizeof(*state_block->entries)))
        return false;

    state_block->entries[state_block->count++] = entry;
    return true;
}


#line 6578 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"

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
         || (defined HLSL_YYLTYPE_IS_TRIVIAL && HLSL_YYLTYPE_IS_TRIVIAL \
             && defined HLSL_YYSTYPE_IS_TRIVIAL && HLSL_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  107
/* YYNRULES -- Number of rules.  */
#define YYNRULES  321
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  588

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   383


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
       2,     2,     2,   145,     2,     2,     2,   148,   149,     2,
     136,   137,   146,   142,   139,   143,   140,   147,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   138,   129,
     132,   141,   133,   152,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   134,     2,   135,   150,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   130,   151,   131,   144,     2,     2,     2,
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
     125,   126,   127,   128
};

#if HLSL_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,  6293,  6293,  6294,  6295,  6296,  6301,  6302,  6303,  6304,
    6307,  6311,  6314,  6321,  6328,  6337,  6341,  6346,  6355,  6356,
    6359,  6360,  6363,  6373,  6383,  6397,  6398,  6399,  6402,  6403,
    6406,  6407,  6410,  6419,  6429,  6435,  6439,  6445,  6446,  6449,
    6471,  6486,  6487,  6490,  6511,  6517,  6518,  6519,  6522,  6528,
    6556,  6557,  6560,  6581,  6593,  6614,  6624,  6639,  6644,  6647,
    6703,  6710,  6827,  6828,  6843,  6848,  6855,  6861,  6868,  6875,
    6882,  6883,  6886,  6892,  6898,  6903,  6910,  6929,  6938,  6950,
    6972,  6990,  7005,  7022,  7044,  7050,  7059,  7063,  7067,  7073,
    7082,  7094,  7095,  7102,  7139,  7143,  7147,  7151,  7155,  7159,
    7163,  7167,  7173,  7177,  7183,  7187,  7191,  7195,  7199,  7203,
    7207,  7213,  7217,  7221,  7225,  7229,  7233,  7237,  7243,  7266,
    7270,  7299,  7303,  7307,  7311,  7315,  7319,  7323,  7327,  7331,
    7335,  7340,  7346,  7362,  7367,  7372,  7376,  7393,  7413,  7420,
    7424,  7428,  7432,  7436,  7440,  7444,  7448,  7452,  7456,  7463,
    7467,  7473,  7474,  7480,  7481,  7482,  7489,  7490,  7493,  7521,
    7527,  7534,  7543,  7550,  7556,  7563,  7571,  7590,  7602,  7608,
    7612,  7617,  7624,  7629,  7642,  7647,  7671,  7701,  7711,  7722,
    7723,  7728,  7738,  7753,  7768,  7785,  7789,  7811,  7816,  7833,
    7837,  7841,  7845,  7849,  7853,  7857,  7861,  7865,  7869,  7873,
    7877,  7881,  7885,  7889,  7893,  7897,  7901,  7905,  7909,  7923,
    7935,  7940,  7947,  7948,  7968,  7971,  7983,  8001,  8005,  8011,
    8012,  8020,  8021,  8022,  8023,  8024,  8025,  8026,  8029,  8045,
    8058,  8064,  8071,  8088,  8139,  8144,  8151,  8157,  8163,  8169,
    8177,  8209,  8225,  8240,  8252,  8262,  8272,  8280,  8285,  8288,
    8294,  8302,  8305,  8314,  8323,  8332,  8344,  8361,  8373,  8390,
    8394,  8403,  8424,  8425,  8434,  8443,  8490,  8506,  8541,  8559,
    8560,  8569,  8578,  8582,  8587,  8592,  8598,  8645,  8646,  8650,
    8654,  8660,  8661,  8665,  8675,  8676,  8680,  8686,  8687,  8691,
    8695,  8699,  8705,  8706,  8710,  8716,  8717,  8723,  8724,  8730,
    8731,  8737,  8738,  8744,  8745,  8751,  8752,  8770,  8771,  8788,
    8792,  8796,  8800,  8804,  8808,  8812,  8816,  8820,  8824,  8828,
    8834,  8835
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
  "\"end of file\"", "error", "\"invalid token\"", "KW_BLENDSTATE",
  "KW_BREAK", "KW_BUFFER", "KW_CASE", "KW_CONSTANTBUFFER", "KW_CBUFFER",
  "KW_CENTROID", "KW_COLUMN_MAJOR", "KW_COMPILE", "KW_COMPUTESHADER",
  "KW_CONST", "KW_CONTINUE", "KW_DEFAULT", "KW_DEPTHSTENCILSTATE",
  "KW_DEPTHSTENCILVIEW", "KW_DISCARD", "KW_DO", "KW_DOMAINSHADER",
  "KW_DOUBLE", "KW_ELSE", "KW_EXPORT", "KW_EXTERN", "KW_FALSE", "KW_FOR",
  "KW_FXGROUP", "KW_GEOMETRYSHADER", "KW_GROUPSHARED", "KW_HULLSHADER",
  "KW_IF", "KW_IN", "KW_INLINE", "KW_INOUT", "KW_LINEAR", "KW_MATRIX",
  "KW_NAMESPACE", "KW_NOINTERPOLATION", "KW_NOPERSPECTIVE", "KW_NULL",
  "KW_OUT", "KW_PACKOFFSET", "KW_PASS", "KW_PIXELSHADER",
  "KW_RASTERIZERORDEREDBUFFER", "KW_RASTERIZERORDEREDSTRUCTUREDBUFFER",
  "KW_RASTERIZERORDEREDTEXTURE1D", "KW_RASTERIZERORDEREDTEXTURE1DARRAY",
  "KW_RASTERIZERORDEREDTEXTURE2D", "KW_RASTERIZERORDEREDTEXTURE2DARRAY",
  "KW_RASTERIZERORDEREDTEXTURE3D", "KW_RASTERIZERSTATE",
  "KW_RENDERTARGETVIEW", "KW_RETURN", "KW_REGISTER", "KW_ROW_MAJOR",
  "KW_RWBUFFER", "KW_RWSTRUCTUREDBUFFER", "KW_RWTEXTURE1D",
  "KW_RWTEXTURE1DARRAY", "KW_RWTEXTURE2D", "KW_RWTEXTURE2DARRAY",
  "KW_RWTEXTURE3D", "KW_SAMPLER", "KW_SAMPLER1D", "KW_SAMPLER2D",
  "KW_SAMPLER3D", "KW_SAMPLERCUBE", "KW_SAMPLER_STATE",
  "KW_SAMPLERCOMPARISONSTATE", "KW_SHARED", "KW_STATEBLOCK",
  "KW_STATEBLOCK_STATE", "KW_STATIC", "KW_STRING", "KW_STRUCT",
  "KW_SWITCH", "KW_TBUFFER", "KW_TECHNIQUE", "KW_TECHNIQUE10",
  "KW_TECHNIQUE11", "KW_TEXTURE", "KW_TEXTURE1D", "KW_TEXTURE1DARRAY",
  "KW_TEXTURE2D", "KW_TEXTURE2DARRAY", "KW_TEXTURE2DMS",
  "KW_TEXTURE2DMSARRAY", "KW_TEXTURE3D", "KW_TEXTURECUBE",
  "KW_TEXTURECUBEARRAY", "KW_TRUE", "KW_TYPEDEF", "KW_UNSIGNED",
  "KW_UNIFORM", "KW_VECTOR", "KW_VERTEXSHADER", "KW_VOID", "KW_VOLATILE",
  "KW_WHILE", "OP_INC", "OP_DEC", "OP_AND", "OP_OR", "OP_EQ",
  "OP_LEFTSHIFT", "OP_LEFTSHIFTASSIGN", "OP_RIGHTSHIFT",
  "OP_RIGHTSHIFTASSIGN", "OP_LE", "OP_GE", "OP_NE", "OP_ADDASSIGN",
  "OP_SUBASSIGN", "OP_MULASSIGN", "OP_DIVASSIGN", "OP_MODASSIGN",
  "OP_ANDASSIGN", "OP_ORASSIGN", "OP_XORASSIGN", "C_FLOAT", "C_INTEGER",
  "C_UNSIGNED", "PRE_LINE", "VAR_IDENTIFIER", "NEW_IDENTIFIER", "STRING",
  "TYPE_IDENTIFIER", "';'", "'{'", "'}'", "'<'", "'>'", "'['", "']'",
  "'('", "')'", "':'", "','", "'.'", "'='", "'+'", "'-'", "'~'", "'!'",
  "'*'", "'/'", "'%'", "'&'", "'^'", "'|'", "'?'", "$accept", "hlsl_prog",
  "name_opt", "pass", "annotations_list", "annotations_opt", "pass_list",
  "passes", "technique9", "technique10", "technique11", "global_technique",
  "group_technique", "group_techniques", "effect_group",
  "buffer_declaration", "buffer_body", "buffer_type",
  "declaration_statement_list", "preproc_directive",
  "struct_declaration_without_vars", "struct_spec", "named_struct_spec",
  "unnamed_struct_spec", "any_identifier", "fields_list", "field_type",
  "field", "attribute", "attribute_list", "attribute_list_optional",
  "func_declaration", "func_prototype_no_attrs", "func_prototype",
  "compound_statement", "scope_start", "loop_scope_start",
  "switch_scope_start", "annotations_scope_start", "var_identifier",
  "colon_attribute", "semantic", "register_reservation",
  "packoffset_reservation", "parameters", "param_list", "parameter",
  "parameter_decl", "texture_type", "texture_ms_type", "uav_type",
  "rov_type", "type_no_void", "type", "declaration_statement",
  "typedef_type", "typedef", "type_specs", "type_spec", "declaration",
  "variables_def", "variables_def_typed", "variable_decl",
  "state_block_start", "stateblock_lhs_identifier",
  "state_block_index_opt", "state_block", "state_block_list",
  "variable_def", "variable_def_typed", "array", "arrays", "var_modifiers",
  "complex_initializer", "complex_initializer_list", "initializer_expr",
  "initializer_expr_list", "boolean", "statement_list", "statement",
  "jump_statement", "selection_statement", "if_body", "loop_statement",
  "switch_statement", "switch_case", "switch_cases", "expr_optional",
  "expr_statement", "func_arguments", "primary_expr", "postfix_expr",
  "unary_expr", "mul_expr", "add_expr", "shift_expr", "relational_expr",
  "equality_expr", "bitand_expr", "bitxor_expr", "bitor_expr",
  "logicand_expr", "logicor_expr", "conditional_expr", "assignment_expr",
  "assign_op", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-388)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-262)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -388,  2406,  -388,  3383,  3383,  3383,  3383,  3383,   140,  3383,
    3383,  3383,  3383,  3383,  3383,  3383,  3383,  3383,  3383,  3383,
     140,   140,   140,  3383,  3383,  3383,   -45,  -388,  -388,  -388,
     140,  -388,  -388,  -388,  -388,  -388,   -40,  -388,  -388,  -388,
    3082,  -388,  -388,   206,  3383,  -388,  -388,  -388,   -18,  -388,
    2607,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,   -14,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,   -14,  -388,   -14,   -14,  2703,  -388,  -388,  -388,   205,
    -388,  -388,  -388,  -388,  2799,  -388,    23,  -388,  -388,  -388,
     140,  -388,  -388,    -3,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,    14,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,    92,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,    39,    53,
    -388,  -388,  -388,   140,   122,  -388,  -388,    67,    71,    84,
      87,  -388,   144,  -388,    96,   119,   131,   134,  -388,  -388,
     140,  -388,  2282,  3238,   114,   223,  -388,  1284,   123,   -31,
    -388,  2799,  2799,   141,  -388,   152,  -388,  2799,   136,  -388,
    -388,  2799,  2799,  2799,  2799,   178,   194,   201,  -388,  3116,
    -388,  -388,  -388,  -388,   123,   -15,  -388,  -388,  -388,  -388,
    2282,  2282,  -388,  -388,  -388,  3382,  3434,  -388,  2282,  2282,
    2282,  2282,  2282,  2514,  2799,  -388,   -34,  -388,  -388,    -4,
     177,   133,   208,   169,    31,     3,   156,   160,   191,   241,
     -32,  -388,  -388,  -388,  -388,  2703,  -388,   217,   230,   233,
    1536,   221,    40,  -388,  -388,  2703,  1147,  -388,  -388,  -388,
    -388,  -388,   242,  -388,  -388,   239,  1660,   123,   136,  -388,
    1784,   252,   247,  3272,  -388,   248,    64,   -14,  -388,  -388,
    -388,   255,    47,   256,   257,  -388,  -388,  3165,    -2,  2703,
     272,   260,   354,   267,   269,  -388,  -388,   140,  -388,  -388,
    2799,   146,  -388,  -388,  -388,  -388,  1908,   265,   268,  2282,
    -388,  -388,  2282,   140,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  2282,  2282,  2282,  2282,  2282,
    2282,  2282,  2282,  2282,  2282,  2282,  2282,  2282,  2282,  2282,
    2282,  2282,  2282,  2282,  2282,   140,  -388,  -388,  -388,  -388,
      19,   266,    51,   327,   -24,  -388,  -388,  -388,  2282,  -388,
      66,  -388,   -14,   276,  1784,  -388,  -388,  -388,   285,  -388,
    -388,  2895,  3306,   288,   275,   277,  -388,  -388,  -388,  -388,
    2282,  -388,  -388,  2480,   278,  -388,    20,  -388,   140,  -388,
    -388,  -388,     0,  -388,   140,  -388,   354,  -388,  -388,  -388,
     167,  -388,   273,   280,  2282,  -388,  -388,    75,   282,  -388,
    -388,  -388,  -388,  -388,   133,   133,   208,   208,   169,   169,
     169,   169,    31,    31,     3,   156,   160,   191,   241,   219,
    -388,  2282,  1284,   283,   284,   286,  -388,  -388,  -388,  -388,
      48,   -53,  -388,    52,   287,   174,  -388,   140,  -388,  -388,
     281,   140,   140,   -17,  -388,   289,  -388,   290,  2991,   136,
    -388,  -388,  -388,   -14,  -388,   292,  -388,   172,  -388,  1908,
    2282,   180,   323,  2033,  2282,  2282,    56,  -388,  -388,  -388,
     294,   291,  -388,   302,  -388,  1412,   311,    21,  -388,  -388,
       7,    91,  -388,  3383,  1784,   140,  -388,   304,  2282,  -388,
     298,  -388,  1284,   300,  2033,  2703,  2033,   184,   185,  -388,
    1908,   316,   299,  -388,  -388,  -388,   306,  -388,   140,  -388,
     140,  2282,  -388,   140,  -388,  -388,   123,  -388,  -388,  -388,
     402,  -388,  2282,  2157,  2157,  1284,   313,   307,   310,  1784,
     112,  -388,  -388,   312,   100,    97,   136,  -388,  1284,   188,
     314,   315,  -388,   187,   318,  -388,   319,  -388,  -388,   189,
    2282,  -388,   140,  -388,   127,  -388,   321,  1284,  1284,  2282,
     303,  -388,    69,  -388,  -388,  -388,   140,   124,   320,  -388,
    -388,  -388,  -388,   226,   584,  -388,  -388,   322,   192,  -388,
     726,   868,  -388,  -388,   140,  1010,   324,  -388
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,   189,     1,   189,   189,   189,   189,   189,     0,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
      10,    10,    10,   189,   189,   189,     0,    70,    71,     9,
       0,    25,    26,    27,     7,     8,     0,     6,   154,    55,
     189,     3,    62,     0,   189,     5,   155,   153,     0,   165,
       0,   192,   202,   200,   207,   190,    45,    47,    46,    15,
     196,   203,   206,   205,   193,   191,   194,   204,   201,   195,
     197,    15,    11,    15,    15,     0,   198,   199,    39,     0,
      37,     4,    56,    63,     0,    60,    66,    59,   208,   162,
       0,   150,    94,     0,    35,   144,   140,   141,   145,   147,
     146,   121,   143,   111,   112,   113,   114,   115,   116,   117,
     149,   139,   104,   105,   106,   107,   108,   109,   110,   122,
     124,   125,   126,   127,   123,   135,     0,    36,   128,    95,
      99,    96,   100,   102,   103,    97,    98,   101,     0,   119,
     142,   152,   136,     0,     0,    41,    42,   129,     0,     0,
       0,   151,     0,    69,     0,     0,     0,     0,   157,   156,
       0,    53,   189,   189,     0,     0,    64,   189,   187,   179,
     166,     0,     0,   138,    48,     0,   137,     0,    72,    40,
     183,     0,     0,     0,     0,    45,    47,     0,   184,   189,
      66,    66,    66,    66,   187,     0,   159,   218,   257,   217,
     189,   189,   252,   253,   254,    70,    71,   256,   189,   189,
     189,   189,   189,   189,     0,   215,     0,   255,   262,   269,
     277,   281,   284,   287,   292,   295,   297,   299,   301,   303,
     305,   307,   214,    34,    38,     0,   138,     0,     0,     0,
     189,    58,    67,   223,   221,     0,   189,   219,   224,   225,
     226,   227,     0,   222,   320,   248,   189,   187,    72,   168,
     189,     0,     0,   189,    48,     0,     0,    15,    73,    74,
      75,     0,     0,     0,     0,    66,    16,   189,     0,     0,
       0,     0,    20,     0,     0,   161,   158,     0,   270,   271,
       0,     0,   272,   273,   274,   275,   189,     0,     0,   189,
     263,   264,   189,     0,   315,   316,   310,   311,   312,   313,
     314,   317,   318,   319,   309,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,     0,   228,   229,   232,   231,
       0,     0,     0,     0,     0,    65,   220,   249,   189,   185,
       0,   188,    15,   174,   189,   180,   209,   148,     0,    44,
      49,     0,   189,     0,     0,     0,    76,    33,   130,   131,
     189,   133,   134,   189,     0,    17,     0,    13,     0,    28,
      29,    30,     0,    22,    10,    18,    21,    23,    24,   160,
     187,   259,   251,     0,   189,    54,   216,     0,   265,   308,
     278,   279,   280,   277,   282,   283,   285,   286,   290,   291,
     288,   289,   293,   294,   296,   298,   300,   302,   304,     0,
     230,   189,   189,     0,     0,     0,   321,   186,   167,   174,
       0,     0,   212,     0,     0,     0,    51,     0,    50,    43,
       0,     0,     0,     0,    87,    88,    89,    91,     0,    72,
      14,    32,    31,    15,    19,     0,   260,     0,   266,   189,
     189,     0,     0,   189,   189,   189,     0,   170,   171,   181,
     169,   172,   182,     0,   210,   189,     0,     0,   163,   118,
       0,     0,   132,   189,   189,     0,    61,     0,   189,   267,
       0,   306,   189,     0,   189,     0,   189,     0,     0,   177,
     189,     0,     0,   174,   211,   213,     0,    52,     0,    84,
       0,   189,    77,     0,    90,    92,   187,   168,   276,   268,
     234,   233,   189,   189,   189,   189,     0,     0,     0,   189,
       0,   120,   164,     0,     0,     0,    72,   174,   189,     0,
       0,     0,   236,     0,     0,   173,     0,   178,    85,     0,
     189,    79,     0,    93,     0,   235,     0,   189,   189,   189,
       0,   245,     0,   176,   175,    78,     0,     0,     0,    12,
     237,   239,   238,     0,   189,   240,   246,     0,     0,    82,
     189,   189,    80,    81,     0,   189,     0,    83
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -388,  -388,    15,    70,  -388,   -44,  -388,   175,  -388,   454,
     457,  -388,    78,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,   -68,  -388,   102,    12,   200,  -388,  -388,     5,   464,
    -388,  -388,   426,  -388,   424,   -21,  -388,  -388,  -388,    43,
    -220,  -388,  -388,  -388,  -388,  -388,   -13,  -388,  -388,  -388,
    -388,  -388,    24,   -49,    50,  -388,  -388,  -388,   181,     6,
    -388,  -125,  -388,   -46,  -388,  -388,  -360,  -388,   -71,  -388,
    -388,  -169,    -1,  -314,  -388,  -186,  -134,  -388,  -376,  -225,
    -388,  -388,  -388,  -388,  -388,   -89,  -388,  -154,  -387,  -374,
    -388,  -388,   183,    55,    59,  -230,    49,   145,   147,   148,
     143,   150,  -388,  -388,  -121,  -388,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    71,   385,   277,   154,   386,   281,    31,   379,
     380,    34,   381,   382,    35,    36,    81,   143,   163,    37,
      38,   144,   145,   146,   168,   263,   437,   360,    39,   241,
     242,    41,    42,    43,   243,   282,   342,   343,   189,   213,
     267,   268,   269,   270,   374,   445,   446,   447,   147,   148,
     149,   150,   151,   335,   244,   160,    46,   195,   196,    47,
     477,    48,   169,   353,   471,   502,   430,   431,   188,    49,
     257,   258,   214,   355,   433,   215,   392,   217,   246,   247,
     248,   249,   521,   250,   251,   561,   562,   252,   253,   393,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   254,   315,   255
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   152,    51,    52,    53,    54,    55,   158,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   170,
      59,   346,    75,    76,    77,   285,   159,   155,   216,   156,
     157,   291,    72,    72,    72,   165,    73,    74,   352,    84,
     432,   232,    79,    88,    44,    82,    44,    44,    44,    44,
      44,    45,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,   340,   278,   167,    44,    44,    44,   466,
     422,   341,   333,   180,   356,   559,   496,   423,   472,   350,
      21,    22,    78,    44,   560,   490,   473,    44,   351,   321,
      80,   322,   467,   408,   409,   410,   411,   300,   301,   259,
     467,    56,    57,   298,    58,   299,   364,   523,   327,   524,
     260,    89,   394,   396,   286,   328,   482,   -68,   153,   365,
     334,    90,   261,   262,   287,   397,   527,   377,   265,   171,
     302,   451,   271,   272,   273,   274,   303,    90,   175,   232,
     443,   323,   324,   530,   509,   468,   172,   510,   420,   450,
     507,   424,   376,   468,   166,   178,   467,   419,   348,    90,
     508,   505,   235,   325,   326,   297,   245,   176,   356,   280,
     515,   467,   194,    56,    57,   232,    58,   554,   232,   469,
     369,    56,    57,   474,    58,   177,   370,   499,   279,    56,
      57,   475,    58,   559,   399,   187,   344,   462,   581,   181,
     575,   427,   560,   182,   585,   348,    44,   290,   187,   468,
     458,   378,    88,   234,   348,   546,   183,    56,    57,   184,
     173,   455,   174,   367,   468,   511,   190,   426,   512,   486,
     513,   550,    44,   232,   551,   549,   552,    56,    57,   348,
      58,   390,   236,   547,   461,   245,    82,    56,    57,   191,
      58,   179,    56,    57,   373,    58,    44,   256,   569,   578,
     457,   192,   361,   348,   193,    56,    57,   520,    58,   185,
     186,   -46,    58,   232,   266,   321,   279,   322,   366,   316,
     317,   318,   264,   391,   304,   348,   305,   497,   498,   356,
     306,   307,   308,   309,   310,   311,   312,   313,   356,   194,
     542,   256,   236,   394,   174,   329,    44,   180,   428,   489,
     330,   299,   438,   555,   -70,   398,   553,   492,   314,   348,
      44,   525,   526,   348,   348,   556,   565,   348,   566,   583,
     -71,   584,   571,   572,   534,    85,    86,   275,   232,   491,
     161,   162,   331,   356,   332,   539,   336,   536,    27,    28,
     319,   320,    21,    22,   232,    30,   346,   460,   348,   337,
     346,   361,   338,   232,   580,   348,   478,   283,   284,   540,
     541,   347,   448,   567,   404,   405,   412,   413,   348,   232,
     406,   407,   573,   288,   289,   357,   358,   363,   368,   371,
     372,   383,   292,   293,   294,   295,    72,   384,   387,   453,
     388,   394,   421,   395,   425,    44,   429,   434,   232,   487,
     440,   441,   299,   442,   479,   449,    44,   456,   459,   463,
     464,   245,   465,   493,   538,   501,   476,   378,   483,   488,
     500,   484,   503,   506,   517,   519,   522,   532,   528,   531,
     529,   574,   470,   543,   544,   545,   344,   563,   564,   548,
     570,   557,   558,   480,   481,    32,   454,   579,    33,   582,
     452,   587,   495,   436,   362,    40,    83,    87,   389,   494,
     514,   537,   485,   576,   414,   417,     0,   415,   470,   416,
       0,     0,   448,   418,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,   516,     0,   400,
     401,   402,   403,   403,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,     0,     0,     0,
       0,     0,   533,     0,   245,   535,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,     0,     0,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,     0,     0,   245,   245,     0,     0,
       0,     0,     0,     0,   568,     0,   470,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,   577,   245,
     245,     0,     0,     0,   245,     0,     0,     0,   237,     0,
    -244,     0,     0,     3,     4,     0,   586,     5,   238,  -244,
       0,     0,   239,   -57,     0,     0,     0,     6,     7,   197,
     -57,     0,     0,     9,     0,   -57,    10,    11,    12,    13,
       0,     0,    14,    15,   198,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    19,     0,
       0,   -57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   518,     0,     0,     0,     0,   199,    23,     0,    24,
       0,     0,     0,    25,   -57,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,   204,     0,   205,
     206,   207,     0,  -247,    86,  -244,     0,     0,    30,     0,
     208,     0,     0,     0,     0,     0,   209,   210,   211,   212,
     237,     0,  -242,     0,     0,     3,     4,     0,     0,     5,
     238,  -242,     0,     0,   239,   -57,     0,     0,     0,     6,
       7,   197,   -57,     0,     0,     9,     0,   -57,    10,    11,
      12,    13,     0,     0,    14,    15,   198,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
      19,     0,     0,   -57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,    23,
       0,    24,     0,     0,     0,    25,   -57,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   204,
       0,   205,   206,   207,     0,  -247,    86,  -242,     0,     0,
      30,     0,   208,     0,     0,     0,     0,     0,   209,   210,
     211,   212,   237,     0,  -243,     0,     0,     3,     4,     0,
       0,     5,   238,  -243,     0,     0,   239,   -57,     0,     0,
       0,     6,     7,   197,   -57,     0,     0,     9,     0,   -57,
      10,    11,    12,    13,     0,     0,    14,    15,   198,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    19,     0,     0,   -57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,    23,     0,    24,     0,     0,     0,    25,   -57,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,   204,     0,   205,   206,   207,     0,  -247,    86,  -243,
       0,     0,    30,     0,   208,     0,     0,     0,     0,     0,
     209,   210,   211,   212,   237,     0,  -241,     0,     0,     3,
       4,     0,     0,     5,   238,  -241,     0,     0,   239,   -57,
       0,     0,     0,     6,     7,   197,   -57,     0,     0,     9,
       0,   -57,    10,    11,    12,    13,     0,     0,    14,    15,
     198,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    19,     0,     0,   -57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,    23,     0,    24,     0,     0,     0,    25,
     -57,   200,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,   204,     0,   205,   206,   207,     0,  -247,
      86,  -241,     0,     0,    30,     0,   208,     0,     0,     0,
       0,   237,   209,   210,   211,   212,     3,     4,     0,     0,
       5,   238,     0,     0,     0,   239,   -57,     0,     0,     0,
       6,     7,   197,   -57,     0,     0,     9,     0,   -57,    10,
      11,    12,    13,     0,     0,    14,    15,   198,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,    19,     0,     0,   -57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
      23,     0,    24,     0,     0,     0,    25,   -57,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   205,   206,   207,     0,  -247,    86,   345,     0,
       0,    30,     0,   208,     0,     0,     0,     0,   237,   209,
     210,   211,   212,     3,     4,     0,     0,     5,   238,     0,
       0,     0,   239,   -57,     0,     0,     0,     6,     7,   197,
     -57,     0,     0,     9,     0,   -57,    10,    11,    12,    13,
       0,     0,    14,    15,   198,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    19,     0,
       0,   -57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,    23,     0,    24,
       0,     0,     0,    25,   -57,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,   204,     0,   205,
     206,   207,     0,  -247,    86,     0,     0,     0,    30,     0,
     208,     3,     4,     0,     0,     5,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     6,     7,   197,     0,     0,
       0,     9,     0,     0,    10,    11,    12,    13,     0,     0,
      14,    15,   198,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,    24,     0,     0,
       0,    25,     0,   200,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,   204,     0,   205,   206,   207,
       0,     0,   354,   504,     0,     3,     4,     0,   208,     5,
       0,     0,     0,     0,   209,   210,   211,   212,     0,     6,
       7,   197,     0,     0,     0,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,   198,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,    24,     0,     0,     0,    25,     0,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,   204,
       0,   205,   206,   207,     0,   339,     0,     0,     0,     3,
       4,     0,   208,     5,     0,     0,     0,     0,   209,   210,
     211,   212,     0,     6,     7,   197,     0,     0,     0,     9,
       0,     0,    10,    11,    12,    13,     0,     0,    14,    15,
     198,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   199,     0,     0,    24,     0,     0,     0,    25,
       0,   200,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   202,   203,   204,     0,   205,   206,   207,     0,     0,
       0,     0,     0,     3,     4,   349,   208,     5,     0,     0,
       0,     0,   209,   210,   211,   212,     0,     6,     7,   197,
       0,     0,     0,     9,     0,     0,    10,    11,    12,    13,
       0,     0,    14,    15,   198,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,    24,
       0,     0,     0,    25,     0,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   203,   204,     0,   205,
     206,   207,     0,     0,   354,     0,     0,     3,     4,     0,
     208,     5,     0,     0,     0,     0,   209,   210,   211,   212,
       0,     6,     7,   197,     0,     0,     0,     9,     0,     0,
      10,    11,    12,    13,     0,     0,    14,    15,   198,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,    24,     0,     0,     0,    25,     0,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
     203,   204,     0,   205,   206,   207,     0,     0,     0,     0,
       0,     0,     3,     4,   208,  -250,     5,     0,     0,     0,
     209,   210,   211,   212,     0,     0,     6,     7,   197,     0,
       0,     0,     9,     0,     0,    10,    11,    12,    13,     0,
       0,    14,    15,   198,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,    24,     0,
       0,     0,    25,     0,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,   204,     0,   205,   206,
     207,     0,  -247,     0,     0,     0,     3,     4,     0,   208,
       5,     0,     0,     0,     0,   209,   210,   211,   212,     0,
       6,     7,   197,     0,     0,     0,     9,     0,     0,    10,
      11,    12,    13,     0,     0,    14,    15,   198,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,    24,     0,     0,     0,    25,     0,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   202,   203,
     204,     0,   205,   206,   207,     0,     0,     0,     0,     0,
       0,     3,     4,   208,  -247,     5,     0,     0,     0,   209,
     210,   211,   212,     0,     0,     6,     7,   197,     0,     0,
       0,     9,     0,     0,    10,    11,    12,    13,     0,     0,
      14,    15,   198,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   199,     0,     0,    24,     0,     0,
       0,    25,     0,   200,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,   204,     2,   205,   206,   207,
       0,     0,     0,     0,     0,     3,     4,     0,   208,     5,
       0,     0,     0,     0,   209,   210,   211,   212,     0,     6,
       7,     0,     0,     8,     0,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,    20,    21,    22,     0,     3,
       4,     0,     0,     5,     0,     0,     0,     0,     0,    23,
       0,    24,     0,     6,     7,    25,     0,     0,     0,     9,
       0,     0,    10,    11,    12,    13,     0,     0,    14,    15,
       0,    16,     0,     3,     4,     0,     0,     5,     0,     0,
      26,    27,    28,     0,     0,    29,    17,     6,     7,     0,
      30,     0,     0,     9,     0,     0,    10,    11,    12,    13,
       0,    18,    14,    15,    19,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    24,     0,     0,   444,    25,
       0,     0,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,     0,    24,
      91,     0,    92,    25,    93,    94,     0,   -86,     0,    95,
       0,     0,     0,    96,    97,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,    99,     0,   100,     0,    27,
      28,     0,     0,   101,     0,     0,     0,     0,     0,     0,
     296,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,   124,     0,     0,
       0,     0,   125,   126,     0,   127,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,   138,     0,   139,   140,   141,    91,     0,    92,     0,
      93,     0,     0,     0,     0,    95,     0,     0,     0,    96,
      97,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,    99,     0,   100,     0,   142,     0,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,   124,     0,     0,     0,     0,   125,   126,
       0,     0,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,   138,     0,   139,
     140,   141,    91,     0,    92,     0,    93,     0,     0,     0,
       0,    95,     0,     0,     0,    96,    97,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,    99,     0,   100,
       0,   142,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,     0,   124,
       0,     0,     0,     0,   125,   164,     0,     0,     0,     0,
       0,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,   138,     0,   139,   140,   141,    91,     0,
      92,     0,    93,     0,     0,     0,     0,    95,     0,     0,
       0,    96,    97,     0,     0,    98,     0,     0,     0,     0,
       0,     0,     0,    99,     0,   100,     0,   142,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,   124,     0,     0,     0,     0,
     125,   435,     0,     0,     0,     0,     0,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,   138,
       0,   139,   140,   141,    91,     0,    92,     0,    93,     0,
       0,     0,     0,    95,     0,     0,     0,    96,    97,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,    99,
       0,   100,     0,   142,     0,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,   124,     0,     0,     0,     0,   125,   164,     0,     0,
       0,     0,     0,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,   138,     0,   139,   140,     0,
       0,     3,     4,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     0,
       0,     9,     0,     0,    10,    11,    12,    13,     0,   142,
      14,    15,     0,    16,     0,     3,     4,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     6,
       7,     0,     0,     0,     0,     9,     0,     0,    10,    11,
      12,    13,     0,    18,    14,    15,    19,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     3,     4,     0,    24,     5,     0,
       0,    25,     0,     0,     0,     0,     0,    18,     6,     7,
      19,     0,     0,     0,     9,     0,     0,    10,    11,    12,
      13,     0,     0,    14,    15,     0,    16,    27,    28,     0,
       0,    24,     0,     0,     0,    25,    30,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,    19,
       0,    27,    28,     0,     0,     0,     0,     3,     4,   276,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     6,     7,     0,    25,     0,     0,     9,     0,     0,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    16,
       0,     3,     4,     0,     0,     5,     0,     0,     0,     0,
      27,    28,     0,     0,    17,     6,     7,     0,   375,     0,
       0,     9,     0,     0,    10,    11,    12,    13,     0,    18,
      14,    15,    19,    16,     0,     3,     4,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     6,
       7,    23,     0,    24,     0,     9,     0,    25,    10,    11,
      12,    13,     0,    18,    14,    15,    19,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    27,    28,     0,     0,    24,     0,   233,
       0,    25,     0,     0,     0,     0,     0,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     0,     0,     5,    27,    28,     0,
       0,    24,     0,   359,     0,    25,     6,     7,     0,     0,
       0,     0,     9,     0,     0,    10,    11,    12,    13,     0,
       0,    14,    15,     0,    16,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,     0,   439,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,     0,     0,     0,     0,     0,    27,    28,
       0,  -258,     0,  -258,  -258,  -258,  -258,  -258,     0,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,     0,     0,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,     0,     0,     0,     0,     0,
       0,     0,     0,  -261,     0,  -261,  -261,  -261,  -261,  -261,
       0,  -261,  -261,  -261,  -261,  -261,  -261,  -261,     0,     0,
    -261,  -261,  -261,  -261,  -261,  -261,  -261
};

static const yytype_int16 yycheck[] =
{
       1,    50,     3,     4,     5,     6,     7,    75,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    90,
       8,   246,    23,    24,    25,   194,    75,    71,   162,    73,
      74,   208,    20,    21,    22,    84,    21,    22,   258,    40,
     354,   162,    30,    44,     1,    40,     3,     4,     5,     6,
       7,     1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   240,   189,    86,    23,    24,    25,   429,
      19,    31,   104,   144,   260,     6,   463,    26,   131,   256,
      80,    81,   127,    40,    15,   459,   139,    44,   257,   106,
     130,   108,    44,   323,   324,   325,   326,   101,   102,   130,
      44,   125,   126,   137,   128,   139,    42,   494,   105,   496,
     141,   129,   136,   299,   129,   112,   133,    77,   132,    55,
     152,   139,   171,   172,   139,   302,   500,   129,   177,   132,
     134,   131,   181,   182,   183,   184,   140,   139,   126,   260,
     370,   110,   111,   503,   137,    97,   132,   140,   129,   129,
     129,   100,   277,    97,   131,   143,    44,   334,   139,   139,
     139,   475,   163,   132,   133,   214,   167,   128,   354,   190,
     484,    44,   160,   125,   126,   296,   128,   537,   299,   131,
     133,   125,   126,   131,   128,   132,   139,   131,   189,   125,
     126,   139,   128,     6,   315,   152,   245,   422,   574,   132,
     131,   135,    15,   132,   580,   139,   163,   208,   165,    97,
     135,   279,   213,   163,   139,   529,   132,   125,   126,   132,
     128,   390,   130,   267,    97,   134,   130,   348,   137,   449,
     139,   134,   189,   354,   137,   135,   139,   125,   126,   139,
     128,   290,   128,   131,   421,   246,   241,   125,   126,   130,
     128,   129,   125,   126,   275,   128,   213,   134,   131,   135,
     394,   130,   263,   139,   130,   125,   126,   492,   128,   125,
     126,   130,   128,   394,   138,   106,   277,   108,   266,   146,
     147,   148,   130,   137,   107,   139,   109,   464,   465,   475,
     113,   114,   115,   116,   117,   118,   119,   120,   484,   287,
     525,   134,   128,   136,   130,   149,   263,   378,   352,   137,
     150,   139,   361,   538,   136,   303,   536,   137,   141,   139,
     277,   137,   137,   139,   139,   137,   137,   139,   139,   137,
     136,   139,   557,   558,   511,   129,   130,   136,   459,   460,
     135,   136,   151,   529,   103,   522,   129,   516,   125,   126,
     142,   143,    80,    81,   475,   134,   581,   138,   139,   129,
     585,   362,   129,   484,   138,   139,   437,   192,   193,   523,
     524,   129,   373,   550,   319,   320,   327,   328,   139,   500,
     321,   322,   559,   200,   201,   133,   139,   139,   133,   133,
     133,   131,   209,   210,   211,   212,   384,    43,   131,   384,
     131,   136,   136,   135,    77,   362,   130,   122,   529,   453,
     122,   136,   139,   136,   133,   137,   373,   137,   136,   136,
     136,   422,   136,   100,    22,   134,   139,   495,   139,   137,
     136,   141,   130,   122,   130,   137,   136,   508,   122,   133,
     141,   138,   430,   130,   137,   135,   495,   129,   129,   137,
     129,   137,   137,   441,   442,     1,   386,   137,     1,   137,
     382,   137,   463,   361,   264,     1,    40,    43,   287,   463,
     483,   517,   448,   562,   329,   332,    -1,   330,   466,   331,
      -1,    -1,   483,   333,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   492,    -1,    -1,    -1,    -1,    -1,   485,    -1,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,    -1,    -1,    -1,
      -1,    -1,   510,    -1,   525,   513,   483,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,
      -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,    -1,    -1,   557,   558,    -1,    -1,
      -1,    -1,    -1,    -1,   552,    -1,   554,    -1,    -1,    -1,
      -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,   566,   580,
     581,    -1,    -1,    -1,   585,    -1,    -1,    -1,     4,    -1,
       6,    -1,    -1,     9,    10,    -1,   584,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   488,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,   125,
     126,   127,    -1,   129,   130,   131,    -1,    -1,   134,    -1,
     136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
       4,    -1,     6,    -1,    -1,     9,    10,    -1,    -1,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
      -1,   125,   126,   127,    -1,   129,   130,   131,    -1,    -1,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,     4,    -1,     6,    -1,    -1,     9,    10,    -1,
      -1,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    35,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,   127,    -1,   129,   130,   131,
      -1,    -1,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,     4,    -1,     6,    -1,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,    -1,   125,   126,   127,    -1,   129,
     130,   131,    -1,    -1,   134,    -1,   136,    -1,    -1,    -1,
      -1,     4,   142,   143,   144,   145,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,    -1,   125,   126,   127,    -1,   129,   130,   131,    -1,
      -1,   134,    -1,   136,    -1,    -1,    -1,    -1,     4,   142,
     143,   144,   145,     9,    10,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,   125,
     126,   127,    -1,   129,   130,    -1,    -1,    -1,   134,    -1,
     136,     9,    10,    -1,    -1,    13,   142,   143,   144,   145,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,   127,
      -1,    -1,   130,   131,    -1,     9,    10,    -1,   136,    13,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,    -1,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    99,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
      -1,   125,   126,   127,    -1,   129,    -1,    -1,    -1,     9,
      10,    -1,   136,    13,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,    -1,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    99,
      -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,   123,    -1,   125,   126,   127,    -1,    -1,
      -1,    -1,    -1,     9,    10,   135,   136,    13,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,    -1,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    99,    -1,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,   125,
     126,   127,    -1,    -1,   130,    -1,    -1,     9,    10,    -1,
     136,    13,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
      -1,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,   136,   137,    13,    -1,    -1,    -1,
     142,   143,   144,   145,    -1,    -1,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,     9,    10,    -1,   136,
      13,    -1,    -1,    -1,    -1,   142,   143,   144,   145,    -1,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,
      33,    34,    35,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,   136,   137,    13,    -1,    -1,    -1,   142,
     143,   144,   145,    -1,    -1,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,     0,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,     9,    10,    -1,   136,    13,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,    -1,    23,
      24,    -1,    -1,    27,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,     9,
      10,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    95,    -1,    23,    24,    99,    -1,    -1,    -1,    29,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    38,    39,
      -1,    41,    -1,     9,    10,    -1,    -1,    13,    -1,    -1,
     124,   125,   126,    -1,    -1,   129,    56,    23,    24,    -1,
     134,    -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,
      -1,    71,    38,    39,    74,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    99,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,    -1,    -1,    95,
       3,    -1,     5,    99,     7,     8,    -1,   137,    -1,    12,
      -1,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,   125,
     126,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    -1,
      -1,    -1,    75,    76,    -1,    78,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      -1,    94,    -1,    96,    97,    98,     3,    -1,     5,    -1,
       7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,   128,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    -1,    94,    -1,    96,
      97,    98,     3,    -1,     5,    -1,     7,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,   128,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    -1,    94,    -1,    96,    97,    98,     3,    -1,
       5,    -1,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,   128,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    -1,    94,
      -1,    96,    97,    98,     3,    -1,     5,    -1,     7,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    -1,   128,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    94,    -1,    96,    97,    -1,
      -1,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,   128,
      38,    39,    -1,    41,    -1,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,
      34,    35,    -1,    71,    38,    39,    74,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,     9,    10,    -1,    95,    13,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    71,    23,    24,
      74,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    34,
      35,    -1,    -1,    38,    39,    -1,    41,   125,   126,    -1,
      -1,    95,    -1,    -1,    -1,    99,   134,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,   125,   126,    -1,    -1,    -1,    -1,     9,    10,   133,
      -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    23,    24,    -1,    99,    -1,    -1,    29,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    38,    39,    -1,    41,
      -1,     9,    10,    -1,    -1,    13,    -1,    -1,    -1,    -1,
     125,   126,    -1,    -1,    56,    23,    24,    -1,   133,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,    71,
      38,    39,    74,    41,    -1,     9,    10,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    23,
      24,    93,    -1,    95,    -1,    29,    -1,    99,    32,    33,
      34,    35,    -1,    71,    38,    39,    74,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,   125,   126,    -1,    -1,    95,    -1,   131,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    -1,    13,   125,   126,    -1,
      -1,    95,    -1,   131,    -1,    99,    23,    24,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,    -1,    -1,    -1,    -1,   131,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    99,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,   129,    -1,   131,   132,   133,   134,   135,    -1,   137,
     138,   139,   140,   141,   142,   143,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    -1,   131,   132,   133,   134,   135,
      -1,   137,   138,   139,   140,   141,   142,   143,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   154,     0,     9,    10,    13,    23,    24,    27,    29,
      32,    33,    34,    35,    38,    39,    41,    56,    71,    74,
      79,    80,    81,    93,    95,    99,   124,   125,   126,   129,
     134,   161,   162,   163,   164,   167,   168,   172,   173,   181,
     182,   184,   185,   186,   192,   207,   209,   212,   214,   222,
     225,   225,   225,   225,   225,   225,   125,   126,   128,   177,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   155,   177,   155,   155,   225,   225,   225,   127,   177,
     130,   169,   181,   185,   225,   129,   130,   187,   225,   129,
     139,     3,     5,     7,     8,    12,    16,    17,    20,    28,
      30,    36,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    70,    75,    76,    78,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    94,    96,
      97,    98,   128,   170,   174,   175,   176,   201,   202,   203,
     204,   205,   206,   132,   158,   158,   158,   158,   174,   206,
     208,   135,   136,   171,    76,   206,   131,   188,   177,   215,
     221,   132,   132,   128,   130,   177,   128,   132,   177,   129,
     221,   132,   132,   132,   132,   125,   126,   192,   221,   191,
     130,   130,   130,   130,   177,   210,   211,    25,    40,    92,
     101,   102,   121,   122,   123,   125,   126,   127,   136,   142,
     143,   144,   145,   192,   225,   228,   229,   230,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   131,   207,   225,   128,     4,    14,    18,
      54,   182,   183,   187,   207,   225,   231,   232,   233,   234,
     236,   237,   240,   241,   257,   259,   134,   223,   224,   130,
     141,   206,   206,   178,   130,   206,   138,   193,   194,   195,
     196,   206,   206,   206,   206,   136,   133,   157,   214,   225,
     188,   160,   188,   160,   160,   224,   129,   139,   245,   245,
     225,   259,   245,   245,   245,   245,   136,   206,   137,   139,
     101,   102,   134,   140,   107,   109,   113,   114,   115,   116,
     117,   118,   119,   120,   141,   258,   146,   147,   148,   142,
     143,   106,   108,   110,   111,   132,   133,   105,   112,   149,
     150,   151,   103,   104,   152,   206,   129,   129,   129,   129,
     259,    31,   189,   190,   206,   131,   232,   129,   139,   135,
     259,   224,   193,   216,   130,   226,   228,   133,   139,   131,
     180,   225,   178,   139,    42,    55,   177,   158,   133,   133,
     139,   133,   133,   188,   197,   133,   214,   129,   174,   162,
     163,   165,   166,   131,    43,   156,   159,   131,   131,   211,
     206,   137,   229,   242,   136,   135,   228,   259,   177,   257,
     245,   245,   245,   245,   246,   246,   247,   247,   248,   248,
     248,   248,   249,   249,   250,   251,   252,   253,   254,   259,
     129,   136,    19,    26,   100,    77,   257,   135,   158,   130,
     219,   220,   226,   227,   122,    76,   176,   179,   206,   131,
     122,   136,   136,   248,    98,   198,   199,   200,   225,   137,
     129,   131,   165,   155,   156,   224,   137,   229,   135,   136,
     138,   259,   232,   136,   136,   136,   219,    44,    97,   131,
     177,   217,   131,   139,   131,   139,   139,   213,   221,   133,
     177,   177,   133,   139,   141,   205,   193,   158,   137,   137,
     242,   257,   137,   100,   212,   225,   241,   259,   259,   131,
     136,   134,   218,   130,   131,   226,   122,   129,   139,   137,
     140,   134,   137,   139,   199,   226,   177,   130,   245,   137,
     232,   235,   136,   241,   241,   137,   137,   242,   122,   141,
     219,   133,   221,   177,   259,   177,   224,   216,    22,   259,
     240,   240,   232,   130,   137,   135,   226,   131,   137,   135,
     134,   137,   139,   193,   219,   232,   137,   137,   137,     6,
      15,   238,   239,   129,   129,   137,   139,   259,   177,   131,
     129,   232,   232,   259,   138,   131,   238,   177,   135,   137,
     138,   231,   137,   137,   139,   231,   177,   137
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   153,   154,   154,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   157,   157,   158,   158,   158,   159,   159,
     160,   160,   161,   162,   163,   164,   164,   164,   165,   165,
     166,   166,   167,   168,   169,   170,   170,   171,   171,   172,
     173,   174,   174,   175,   176,   177,   177,   177,   178,   178,
     179,   179,   180,   181,   181,   182,   182,   183,   183,   184,
     184,   185,   186,   186,   187,   187,   188,   189,   190,   191,
     192,   192,   193,   193,   193,   193,   194,   195,   195,   195,
     195,   195,   195,   195,   196,   196,   197,   197,   197,   198,
     198,   199,   199,   200,   201,   201,   201,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   203,   203,   203,   203,
     203,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   206,   206,   207,   207,   207,   208,   208,   209,   210,
     210,   211,   212,   213,   213,   214,   214,   215,   216,   217,
     217,   217,   218,   218,   219,   219,   219,   220,   220,   221,
     221,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     226,   226,   227,   227,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   232,   232,   232,   232,   232,   233,   233,
     233,   233,   233,   234,   235,   235,   236,   236,   236,   236,
     237,   238,   238,   238,   238,   239,   239,   240,   240,   241,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   244,   244,   244,   244,   244,   244,   244,   245,
     245,   245,   245,   245,   245,   245,   245,   246,   246,   246,
     246,   247,   247,   247,   248,   248,   248,   249,   249,   249,
     249,   249,   250,   250,   250,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   256,   256,   257,   257,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     259,   259
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     2,     2,     2,     2,
       0,     1,     7,     2,     3,     0,     3,     4,     1,     2,
       1,     2,     6,     6,     6,     1,     1,     1,     1,     1,
       1,     2,     7,     5,     3,     1,     1,     0,     2,     2,
       3,     1,     1,     5,     4,     1,     1,     1,     0,     2,
       1,     1,     4,     3,     6,     1,     2,     0,     1,     2,
       2,     7,     1,     2,     2,     4,     0,     0,     0,     0,
       1,     1,     0,     1,     1,     1,     2,     5,     8,     7,
      10,    10,     9,    12,     5,     7,     1,     2,     2,     1,
       3,     1,     3,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     6,     1,
       8,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     6,     4,     4,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       3,     2,     2,     1,     3,     1,     3,     4,     0,     1,
       1,     1,     0,     3,     0,     6,     6,     3,     5,     1,
       3,     5,     5,     3,     3,     2,     3,     0,     2,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     4,     1,     3,     1,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     2,     6,     1,     3,     7,     9,     9,     9,
       9,     4,     3,     3,     2,     1,     2,     0,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     2,     2,     3,     4,     5,     6,     1,
       2,     2,     2,     2,     2,     2,     6,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = HLSL_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == HLSL_YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, scanner, ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use HLSL_YYerror or HLSL_YYUNDEF. */
#define YYERRCODE HLSL_YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HLSL_YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined HLSL_YYLTYPE_IS_TRIVIAL && HLSL_YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, scanner, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, struct hlsl_ctx *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, struct hlsl_ctx *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner, ctx);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, void *scanner, struct hlsl_ctx *ctx)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), scanner, ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, ctx); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HLSL_YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HLSL_YYDEBUG */


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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner, struct hlsl_ctx *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
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
yyparse (void *scanner, struct hlsl_ctx *ctx)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HLSL_YYLTYPE_IS_TRIVIAL && HLSL_YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = HLSL_YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yychar == HLSL_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= HLSL_YYEOF)
    {
      yychar = HLSL_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == HLSL_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = HLSL_YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = HLSL_YYEMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* hlsl_prog: hlsl_prog declaration_statement  */
#line 6297 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_block_add_block(&ctx->static_initializers, (yyvsp[0].block));
            destroy_block((yyvsp[0].block));
        }
#line 9002 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 10: /* name_opt: %empty  */
#line 6308 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.name) = NULL;
        }
#line 9010 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 12: /* pass: KW_PASS name_opt annotations_opt '{' state_block_start state_block '}'  */
#line 6315 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!add_pass(ctx, (yyvsp[-5].name), (yyvsp[-4].scope), (yyvsp[-1].state_block), &(yylsp[-6])))
                YYABORT;
        }
#line 9019 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 13: /* annotations_list: variables_def_typed ';'  */
#line 6322 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_block *block;

            block = initialize_vars(ctx, (yyvsp[-1].list));
            destroy_block(block);
        }
#line 9030 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 14: /* annotations_list: annotations_list variables_def_typed ';'  */
#line 6329 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_block *block;

            block = initialize_vars(ctx, (yyvsp[-1].list));
            destroy_block(block);
        }
#line 9041 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 15: /* annotations_opt: %empty  */
#line 6338 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.scope) = NULL;
        }
#line 9049 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 16: /* annotations_opt: '<' annotations_scope_start '>'  */
#line 6342 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_pop_scope(ctx);
            (yyval.scope) = NULL;
        }
#line 9058 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 17: /* annotations_opt: '<' annotations_scope_start annotations_list '>'  */
#line 6347 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_scope *scope = ctx->cur_scope;

            hlsl_pop_scope(ctx);
            (yyval.scope) = scope;
        }
#line 9069 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 22: /* technique9: KW_TECHNIQUE name_opt annotations_opt '{' passes '}'  */
#line 6364 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_scope *scope = ctx->cur_scope;
            hlsl_pop_scope(ctx);

            if (!add_technique(ctx, (yyvsp[-4].name), scope, (yyvsp[-3].scope), "technique", &(yylsp[-5])))
                YYABORT;
        }
#line 9081 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 23: /* technique10: KW_TECHNIQUE10 name_opt annotations_opt '{' passes '}'  */
#line 6374 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_scope *scope = ctx->cur_scope;
            hlsl_pop_scope(ctx);

            if (!add_technique(ctx, (yyvsp[-4].name), scope, (yyvsp[-3].scope), "technique10", &(yylsp[-5])))
                YYABORT;
        }
#line 9093 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 24: /* technique11: KW_TECHNIQUE11 name_opt annotations_opt '{' passes '}'  */
#line 6384 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_scope *scope = ctx->cur_scope;
            hlsl_pop_scope(ctx);

            if (ctx->profile->type == VKD3D_SHADER_TYPE_EFFECT && ctx->profile->major_version == 2)
                hlsl_error(ctx, &(yylsp[-5]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                        "The 'technique11' keyword is invalid for this profile.");

            if (!add_technique(ctx, (yyvsp[-4].name), scope, (yyvsp[-3].scope), "technique11", &(yylsp[-5])))
                YYABORT;
        }
#line 9109 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 32: /* effect_group: KW_FXGROUP any_identifier annotations_opt '{' scope_start group_techniques '}'  */
#line 6411 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_scope *scope = ctx->cur_scope;
            hlsl_pop_scope(ctx);
            if (!(add_effect_group(ctx, (yyvsp[-5].name), scope, (yyvsp[-4].scope), &(yylsp[-5]))))
                YYABORT;
        }
#line 9120 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 33: /* buffer_declaration: var_modifiers buffer_type any_identifier colon_attribute annotations_opt  */
#line 6420 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[-1].colon_attribute).semantic.name)
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SEMANTIC, "Semantics are not allowed on buffers.");

            if (!(ctx->cur_buffer = hlsl_new_buffer(ctx, (yyvsp[-3].buffer_type), (yyvsp[-2].name), (yyvsp[-4].modifiers), &(yyvsp[-1].colon_attribute).reg_reservation, (yyvsp[0].scope), &(yylsp[-2]))))
                YYABORT;
        }
#line 9132 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 34: /* buffer_body: '{' declaration_statement_list '}'  */
#line 6430 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            ctx->cur_buffer = ctx->globals_buffer;
        }
#line 9140 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 35: /* buffer_type: KW_CBUFFER  */
#line 6436 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.buffer_type) = HLSL_BUFFER_CONSTANT;
        }
#line 9148 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 36: /* buffer_type: KW_TBUFFER  */
#line 6440 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.buffer_type) = HLSL_BUFFER_TEXTURE;
        }
#line 9156 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 39: /* preproc_directive: PRE_LINE STRING  */
#line 6450 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            const char **new_array = NULL;

            ctx->location.line = (yyvsp[-1].intval);
            if (strcmp((yyvsp[0].name), ctx->location.source_name))
                new_array = hlsl_realloc(ctx, ctx->source_files,
                        sizeof(*ctx->source_files) * (ctx->source_files_count + 1));

            if (new_array)
            {
                ctx->source_files = new_array;
                ctx->source_files[ctx->source_files_count++] = (yyvsp[0].name);
                ctx->location.source_name = (yyvsp[0].name);
            }
            else
            {
                vkd3d_free((yyvsp[0].name));
            }
        }
#line 9180 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 40: /* struct_declaration_without_vars: var_modifiers struct_spec ';'  */
#line 6472 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!(yyvsp[-1].type)->name)
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                    "Anonymous struct type must declare a variable.");

            if ((yyvsp[-2].modifiers))
                hlsl_error(ctx, &(yylsp[-2]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Modifiers are not allowed on struct type declarations.");

            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
        }
#line 9197 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 43: /* named_struct_spec: KW_STRUCT any_identifier '{' fields_list '}'  */
#line 6491 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            bool ret;

            (yyval.type) = hlsl_new_struct_type(ctx, (yyvsp[-3].name), (yyvsp[-1].fields).fields, (yyvsp[-1].fields).count);

            if (hlsl_get_var(ctx->cur_scope, (yyvsp[-3].name)))
            {
                hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_REDEFINED, "\"%s\" is already declared as a variable.", (yyvsp[-3].name));
                YYABORT;
            }

            ret = hlsl_scope_add_type(ctx->cur_scope, (yyval.type));
            if (!ret)
            {
                hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_REDEFINED, "Struct \"%s\" is already defined.", (yyvsp[-3].name));
                YYABORT;
            }
        }
#line 9220 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 44: /* unnamed_struct_spec: KW_STRUCT '{' fields_list '}'  */
#line 6512 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_new_struct_type(ctx, NULL, (yyvsp[-1].fields).fields, (yyvsp[-1].fields).count);
        }
#line 9228 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 48: /* fields_list: %empty  */
#line 6523 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.fields).fields = NULL;
            (yyval.fields).count = 0;
            (yyval.fields).capacity = 0;
        }
#line 9238 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 49: /* fields_list: fields_list field  */
#line 6529 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            size_t i;

            for (i = 0; i < (yyvsp[0].fields).count; ++i)
            {
                const struct hlsl_struct_field *field = &(yyvsp[0].fields).fields[i];
                const struct hlsl_struct_field *existing;

                if ((existing = get_struct_field((yyvsp[-1].fields).fields, (yyvsp[-1].fields).count, field->name)))
                {
                    hlsl_error(ctx, &field->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                            "Field \"%s\" is already defined.", field->name);
                    hlsl_note(ctx, &existing->loc, VKD3D_SHADER_LOG_ERROR,
                            "'%s' was previously defined here.", field->name);
                }
            }

            if (!hlsl_array_reserve(ctx, (void **)&(yyvsp[-1].fields).fields, &(yyvsp[-1].fields).capacity, (yyvsp[-1].fields).count + (yyvsp[0].fields).count, sizeof(*(yyvsp[-1].fields).fields)))
                YYABORT;
            memcpy((yyvsp[-1].fields).fields + (yyvsp[-1].fields).count, (yyvsp[0].fields).fields, (yyvsp[0].fields).count * sizeof(*(yyvsp[0].fields).fields));
            (yyvsp[-1].fields).count += (yyvsp[0].fields).count;
            vkd3d_free((yyvsp[0].fields).fields);

            (yyval.fields) = (yyvsp[-1].fields);
        }
#line 9268 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 52: /* field: var_modifiers field_type variables_def ';'  */
#line 6561 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_type *type;
            uint32_t modifiers = (yyvsp[-3].modifiers);

            if (!(type = apply_type_modifiers(ctx, (yyvsp[-2].type), &modifiers, true, &(yylsp[-3]))))
                YYABORT;
            if (modifiers & ~HLSL_INTERPOLATION_MODIFIERS_MASK)
            {
                struct vkd3d_string_buffer *string;

                if ((string = hlsl_modifiers_to_string(ctx, modifiers)))
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                            "Modifiers '%s' are not allowed on struct fields.", string->buffer);
                hlsl_release_string_buffer(ctx, string);
            }
            if (!gen_struct_fields(ctx, &(yyval.fields), type, modifiers, (yyvsp[-1].list)))
                YYABORT;
        }
#line 9291 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 53: /* attribute: '[' any_identifier ']'  */
#line 6582 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.attr) = hlsl_alloc(ctx, offsetof(struct hlsl_attribute, args[0]))))
            {
                vkd3d_free((yyvsp[-1].name));
                YYABORT;
            }
            (yyval.attr)->name = (yyvsp[-1].name);
            hlsl_block_init(&(yyval.attr)->instrs);
            (yyval.attr)->loc = (yyloc);
            (yyval.attr)->args_count = 0;
        }
#line 9307 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 54: /* attribute: '[' any_identifier '(' initializer_expr_list ')' ']'  */
#line 6594 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            unsigned int i;

            if (!((yyval.attr) = hlsl_alloc(ctx, offsetof(struct hlsl_attribute, args[(yyvsp[-2].initializer).args_count]))))
            {
                vkd3d_free((yyvsp[-4].name));
                free_parse_initializer(&(yyvsp[-2].initializer));
                YYABORT;
            }
            (yyval.attr)->name = (yyvsp[-4].name);
            hlsl_block_init(&(yyval.attr)->instrs);
            hlsl_block_add_block(&(yyval.attr)->instrs, (yyvsp[-2].initializer).instrs);
            (yyval.attr)->loc = (yyloc);
            (yyval.attr)->args_count = (yyvsp[-2].initializer).args_count;
            for (i = 0; i < (yyvsp[-2].initializer).args_count; ++i)
                hlsl_src_from_node(&(yyval.attr)->args[i], (yyvsp[-2].initializer).args[i]);
            free_parse_initializer(&(yyvsp[-2].initializer));
        }
#line 9330 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 55: /* attribute_list: attribute  */
#line 6615 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.attr_list).count = 1;
            if (!((yyval.attr_list).attrs = hlsl_alloc(ctx, sizeof(*(yyval.attr_list).attrs))))
            {
                hlsl_free_attribute((yyvsp[0].attr));
                YYABORT;
            }
            (yyval.attr_list).attrs[0] = (yyvsp[0].attr);
        }
#line 9344 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 56: /* attribute_list: attribute_list attribute  */
#line 6625 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            const struct hlsl_attribute **new_array;

            (yyval.attr_list) = (yyvsp[-1].attr_list);
            if (!(new_array = vkd3d_realloc((yyval.attr_list).attrs, ((yyval.attr_list).count + 1) * sizeof(*(yyval.attr_list).attrs))))
            {
                cleanup_parse_attribute_list(&(yyval.attr_list));
                YYABORT;
            }
            (yyval.attr_list).attrs = new_array;
            (yyval.attr_list).attrs[(yyval.attr_list).count++] = (yyvsp[0].attr);
        }
#line 9361 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 57: /* attribute_list_optional: %empty  */
#line 6640 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.attr_list).count = 0;
            (yyval.attr_list).attrs = NULL;
        }
#line 9370 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 59: /* func_declaration: func_prototype compound_statement  */
#line 6648 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_function_decl *decl = (yyvsp[-1].function).decl;

            if (decl->has_body)
            {
                hlsl_error(ctx, &decl->loc, VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                         "Function \"%s\" is already defined.", decl->func->name);
                hlsl_note(ctx, &decl->loc, VKD3D_SHADER_LOG_ERROR,
                         "\"%s\" was previously defined here.", decl->func->name);
                destroy_block((yyvsp[0].block));
            }
            else
            {
                size_t i;

                decl->has_body = true;
                hlsl_block_add_block(&decl->body, (yyvsp[0].block));
                destroy_block((yyvsp[0].block));

                /* Semantics are taken from whichever definition has a body.
                 * We can't just replace the hlsl_ir_var pointers, though: if
                 * the function was already declared but not defined, the
                 * callers would have used the old declaration's parameters to
                 * transfer arguments. */

                if (!(yyvsp[-1].function).first)
                {
                    VKD3D_ASSERT(decl->parameters.count == (yyvsp[-1].function).parameters.count);

                    for (i = 0; i < (yyvsp[-1].function).parameters.count; ++i)
                    {
                        struct hlsl_ir_var *dst = decl->parameters.vars[i];
                        struct hlsl_ir_var *src = (yyvsp[-1].function).parameters.vars[i];

                        hlsl_cleanup_semantic(&dst->semantic);
                        dst->semantic = src->semantic;
                        memset(&src->semantic, 0, sizeof(src->semantic));
                    }

                    if (decl->return_var)
                    {
                        hlsl_cleanup_semantic(&decl->return_var->semantic);
                        decl->return_var->semantic = (yyvsp[-1].function).return_semantic;
                        memset(&(yyvsp[-1].function).return_semantic, 0, sizeof((yyvsp[-1].function).return_semantic));
                    }
                }
            }
            hlsl_pop_scope(ctx);

            if (!(yyvsp[-1].function).first)
            {
                vkd3d_free((yyvsp[-1].function).parameters.vars);
                hlsl_cleanup_semantic(&(yyvsp[-1].function).return_semantic);
            }
        }
#line 9430 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 60: /* func_declaration: func_prototype ';'  */
#line 6704 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_pop_scope(ctx);
        }
#line 9438 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 61: /* func_prototype_no_attrs: var_modifiers type var_identifier '(' parameters ')' colon_attribute  */
#line 6711 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            uint32_t modifiers = (yyvsp[-6].modifiers);
            struct hlsl_ir_var *var;
            struct hlsl_type *type;

            /* Functions are unconditionally inlined. */
            modifiers &= ~HLSL_MODIFIER_INLINE;

            if (modifiers & ~(HLSL_MODIFIERS_MAJORITY_MASK | HLSL_MODIFIER_EXPORT))
                hlsl_error(ctx, &(yylsp[-6]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Unexpected modifier used on a function.");
            if (!(type = apply_type_modifiers(ctx, (yyvsp[-5].type), &modifiers, true, &(yylsp[-6]))))
                YYABORT;
            if ((var = hlsl_get_var(ctx->globals, (yyvsp[-4].name))))
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                        "\"%s\" is already declared as a variable.", (yyvsp[-4].name));
                hlsl_note(ctx, &var->loc, VKD3D_SHADER_LOG_ERROR,
                        "\"%s\" was previously declared here.", (yyvsp[-4].name));
            }
            if (hlsl_types_are_equal(type, ctx->builtin_types.Void) && (yyvsp[0].colon_attribute).semantic.name)
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_INVALID_SEMANTIC,
                        "Semantics are not allowed on void functions.");
            }

            if ((yyvsp[0].colon_attribute).reg_reservation.reg_type)
                FIXME("Unexpected register reservation for a function.\n");
            if ((yyvsp[0].colon_attribute).reg_reservation.offset_type)
                hlsl_error(ctx, &(yylsp[-2]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "packoffset() is not allowed on functions.");

            if (((yyval.function).decl = hlsl_get_func_decl(ctx, (yyvsp[-4].name), &(yyvsp[-2].parameters))))
            {
                const struct hlsl_func_parameters *params = &(yyval.function).decl->parameters;
                size_t i;

                if (!hlsl_types_are_equal((yyvsp[-5].type), (yyval.function).decl->return_type))
                {
                    hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                            "\"%s\" was already declared with a different return type.", (yyvsp[-4].name));
                    hlsl_note(ctx, &(yyval.function).decl->loc, VKD3D_SHADER_LOG_ERROR, "\"%s\" was previously declared here.", (yyvsp[-4].name));
                }

                vkd3d_free((yyvsp[-4].name));

                /* We implement function invocation by copying to input
                 * parameters, emitting a HLSL_IR_CALL instruction, then copying
                 * from output parameters. As a result, we need to use the same
                 * parameter variables for every invocation of this function,
                 * which means we use the parameters created by the first
                 * declaration. If we're not the first declaration, the
                 * parameter variables that just got created will end up being
                 * mostly ignored—in particular, they won't be used in actual
                 * IR.
                 *
                 * There is a hitch: if this is the actual definition, the
                 * function body will look up parameter variables by name. We
                 * must return the original parameters, and not the ones we just
                 * created, but we're in the wrong scope, and the parameters
                 * might not even have the same names.
                 *
                 * Therefore we need to shuffle the parameters we just created
                 * into a dummy scope where they'll never be looked up, and
                 * rename the original parameters so they have the expected
                 * names. We actually do this for every prototype: we don't know
                 * whether this is the function definition yet, but it doesn't
                 * really matter. The variables can only be used in the
                 * actual definition, and don't do anything in a declaration.
                 *
                 * This is complex, and it seems tempting to avoid this logic by
                 * putting arguments into the HLSL_IR_CALL instruction, letting
                 * the canonical variables be the ones attached to the function
                 * definition, and resolving the copies when inlining. The
                 * problem with this is output parameters. We would have to use
                 * a lot of parsing logic on already lowered IR, which is
                 * brittle and ugly.
                 */

                VKD3D_ASSERT((yyvsp[-2].parameters).count == params->count);
                for (i = 0; i < params->count; ++i)
                {
                    struct hlsl_ir_var *orig_param = params->vars[i];
                    struct hlsl_ir_var *new_param = (yyvsp[-2].parameters).vars[i];
                    char *new_name;

                    list_remove(&orig_param->scope_entry);
                    list_add_tail(&ctx->cur_scope->vars, &orig_param->scope_entry);

                    list_remove(&new_param->scope_entry);
                    list_add_tail(&ctx->dummy_scope->vars, &new_param->scope_entry);

                    if (!(new_name = hlsl_strdup(ctx, new_param->name)))
                        YYABORT;
                    vkd3d_free((void *)orig_param->name);
                    orig_param->name = new_name;
                }

                (yyval.function).first = false;
                (yyval.function).parameters = (yyvsp[-2].parameters);
                (yyval.function).return_semantic = (yyvsp[0].colon_attribute).semantic;
            }
            else
            {
                if (!((yyval.function).decl = hlsl_new_func_decl(ctx, type, &(yyvsp[-2].parameters), &(yyvsp[0].colon_attribute).semantic, &(yylsp[-4]))))
                    YYABORT;

                hlsl_add_function(ctx, (yyvsp[-4].name), (yyval.function).decl);

                (yyval.function).first = true;
            }

            ctx->cur_function = (yyval.function).decl;
        }
#line 9557 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 63: /* func_prototype: attribute_list func_prototype_no_attrs  */
#line 6829 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[0].function).first)
            {
                (yyvsp[0].function).decl->attr_count = (yyvsp[-1].attr_list).count;
                (yyvsp[0].function).decl->attrs = (yyvsp[-1].attr_list).attrs;
            }
            else
            {
                cleanup_parse_attribute_list(&(yyvsp[-1].attr_list));
            }
            (yyval.function) = (yyvsp[0].function);
        }
#line 9574 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 64: /* compound_statement: '{' '}'  */
#line 6844 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
        }
#line 9583 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 65: /* compound_statement: '{' scope_start statement_list '}'  */
#line 6849 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_pop_scope(ctx);
            (yyval.block) = (yyvsp[-1].block);
        }
#line 9592 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 66: /* scope_start: %empty  */
#line 6856 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_push_scope(ctx);
        }
#line 9600 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 67: /* loop_scope_start: %empty  */
#line 6862 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_push_scope(ctx);
            ctx->cur_scope->loop = true;
        }
#line 9609 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 68: /* switch_scope_start: %empty  */
#line 6869 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_push_scope(ctx);
            ctx->cur_scope->_switch = true;
        }
#line 9618 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 69: /* annotations_scope_start: %empty  */
#line 6876 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_push_scope(ctx);
            ctx->cur_scope->annotations = true;
        }
#line 9627 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 72: /* colon_attribute: %empty  */
#line 6887 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.colon_attribute).semantic = (struct hlsl_semantic){0};
            (yyval.colon_attribute).reg_reservation.reg_type = 0;
            (yyval.colon_attribute).reg_reservation.offset_type = 0;
        }
#line 9637 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 73: /* colon_attribute: semantic  */
#line 6893 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.colon_attribute).semantic = (yyvsp[0].semantic);
            (yyval.colon_attribute).reg_reservation.reg_type = 0;
            (yyval.colon_attribute).reg_reservation.offset_type = 0;
        }
#line 9647 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 74: /* colon_attribute: register_reservation  */
#line 6899 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.colon_attribute).semantic = (struct hlsl_semantic){0};
            (yyval.colon_attribute).reg_reservation = (yyvsp[0].reg_reservation);
        }
#line 9656 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 75: /* colon_attribute: packoffset_reservation  */
#line 6904 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.colon_attribute).semantic = (struct hlsl_semantic){0};
            (yyval.colon_attribute).reg_reservation = (yyvsp[0].reg_reservation);
        }
#line 9665 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 76: /* semantic: ':' any_identifier  */
#line 6911 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            char *p;

            if (!((yyval.semantic).raw_name = hlsl_strdup(ctx, (yyvsp[0].name))))
                YYABORT;

            for (p = (yyvsp[0].name) + strlen((yyvsp[0].name)); p > (yyvsp[0].name) && isdigit(p[-1]); --p)
                ;
            (yyval.semantic).name = (yyvsp[0].name);
            (yyval.semantic).index = atoi(p);
            (yyval.semantic).reported_missing = false;
            (yyval.semantic).reported_duplicated_output_next_index = 0;
            (yyval.semantic).reported_duplicated_input_incompatible_next_index = 0;
            *p = 0;
        }
#line 9685 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 77: /* register_reservation: ':' KW_REGISTER '(' any_identifier ')'  */
#line 6930 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (!parse_reservation_index(ctx, (yyvsp[-1].name), 0, &(yyval.reg_reservation)))
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-1].name));

            vkd3d_free((yyvsp[-1].name));
        }
#line 9698 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 78: /* register_reservation: ':' KW_REGISTER '(' any_identifier '[' expr ']' ')'  */
#line 6939 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (!parse_reservation_index(ctx, (yyvsp[-4].name), evaluate_static_expression_as_uint(ctx, (yyvsp[-2].block), &(yylsp[-2])), &(yyval.reg_reservation)))
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-4].name));
            }

            vkd3d_free((yyvsp[-4].name));
            vkd3d_free((yyvsp[-2].block));
        }
#line 9714 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 79: /* register_reservation: ':' KW_REGISTER '(' any_identifier ',' any_identifier ')'  */
#line 6951 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (parse_reservation_index(ctx, (yyvsp[-1].name), 0, &(yyval.reg_reservation)))
            {
                hlsl_fixme(ctx, &(yylsp[-3]), "Reservation shader target %s.", (yyvsp[-3].name));
            }
            else if (parse_reservation_space((yyvsp[-1].name), &(yyval.reg_reservation).reg_space))
            {
                if (!parse_reservation_index(ctx, (yyvsp[-3].name), 0, &(yyval.reg_reservation)))
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                            "Invalid register reservation '%s'.", (yyvsp[-3].name));
            }
            else
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register or space reservation '%s'.", (yyvsp[-1].name));
            }

            vkd3d_free((yyvsp[-3].name));
            vkd3d_free((yyvsp[-1].name));
        }
#line 9740 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 80: /* register_reservation: ':' KW_REGISTER '(' any_identifier '[' expr ']' ',' any_identifier ')'  */
#line 6973 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));

            if (!parse_reservation_space((yyvsp[-1].name), &(yyval.reg_reservation).reg_space))
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register space reservation '%s'.", (yyvsp[-1].name));

            if (!parse_reservation_index(ctx, (yyvsp[-6].name), evaluate_static_expression_as_uint(ctx, (yyvsp[-4].block), &(yylsp[-4])), &(yyval.reg_reservation)))
            {
                hlsl_error(ctx, &(yylsp[-6]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-6].name));
            }

            vkd3d_free((yyvsp[-6].name));
            vkd3d_free((yyvsp[-4].block));
            vkd3d_free((yyvsp[-1].name));
        }
#line 9762 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 81: /* register_reservation: ':' KW_REGISTER '(' any_identifier ',' any_identifier '[' expr ']' ')'  */
#line 6991 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_fixme(ctx, &(yylsp[-6]), "Reservation shader target %s.", (yyvsp[-6].name));

            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (!parse_reservation_index(ctx, (yyvsp[-4].name), evaluate_static_expression_as_uint(ctx, (yyvsp[-2].block), &(yylsp[-2])), &(yyval.reg_reservation)))
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-4].name));
            }

            vkd3d_free((yyvsp[-6].name));
            vkd3d_free((yyvsp[-4].name));
            vkd3d_free((yyvsp[-2].block));
        }
#line 9781 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 82: /* register_reservation: ':' KW_REGISTER '(' any_identifier ',' any_identifier ',' any_identifier ')'  */
#line 7006 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_fixme(ctx, &(yylsp[-5]), "Reservation shader target %s.", (yyvsp[-5].name));

            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (!parse_reservation_index(ctx, (yyvsp[-3].name), 0, &(yyval.reg_reservation)))
                hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-3].name));

            if (!parse_reservation_space((yyvsp[-1].name), &(yyval.reg_reservation).reg_space))
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register space reservation '%s'.", (yyvsp[-1].name));

            vkd3d_free((yyvsp[-5].name));
            vkd3d_free((yyvsp[-3].name));
            vkd3d_free((yyvsp[-1].name));
        }
#line 9802 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 83: /* register_reservation: ':' KW_REGISTER '(' any_identifier ',' any_identifier '[' expr ']' ',' any_identifier ')'  */
#line 7023 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            hlsl_fixme(ctx, &(yylsp[-8]), "Reservation shader target %s.", (yyvsp[-8].name));

            memset(&(yyval.reg_reservation), 0, sizeof((yyval.reg_reservation)));
            if (!parse_reservation_index(ctx, (yyvsp[-6].name), evaluate_static_expression_as_uint(ctx, (yyvsp[-4].block), &(yylsp[-4])), &(yyval.reg_reservation)))
            {
                hlsl_error(ctx, &(yylsp[-6]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register reservation '%s'.", (yyvsp[-6].name));
            }

            if (!parse_reservation_space((yyvsp[-1].name), &(yyval.reg_reservation).reg_space))
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_RESERVATION,
                        "Invalid register space reservation '%s'.", (yyvsp[-1].name));

            vkd3d_free((yyvsp[-8].name));
            vkd3d_free((yyvsp[-6].name));
            vkd3d_free((yyvsp[-4].block));
            vkd3d_free((yyvsp[-1].name));
        }
#line 9826 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 84: /* packoffset_reservation: ':' KW_PACKOFFSET '(' any_identifier ')'  */
#line 7045 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.reg_reservation) = parse_packoffset(ctx, (yyvsp[-1].name), NULL, &(yyloc));

            vkd3d_free((yyvsp[-1].name));
        }
#line 9836 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 85: /* packoffset_reservation: ':' KW_PACKOFFSET '(' any_identifier '.' any_identifier ')'  */
#line 7051 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.reg_reservation) = parse_packoffset(ctx, (yyvsp[-3].name), (yyvsp[-1].name), &(yyloc));

            vkd3d_free((yyvsp[-3].name));
            vkd3d_free((yyvsp[-1].name));
        }
#line 9847 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 86: /* parameters: scope_start  */
#line 7060 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.parameters), 0, sizeof((yyval.parameters)));
        }
#line 9855 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 87: /* parameters: scope_start KW_VOID  */
#line 7064 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.parameters), 0, sizeof((yyval.parameters)));
        }
#line 9863 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 88: /* parameters: scope_start param_list  */
#line 7068 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.parameters) = (yyvsp[0].parameters);
        }
#line 9871 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 89: /* param_list: parameter  */
#line 7074 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            memset(&(yyval.parameters), 0, sizeof((yyval.parameters)));
            if (!add_func_parameter(ctx, &(yyval.parameters), &(yyvsp[0].parameter), &(yylsp[0])))
            {
                ERR("Error adding function parameter %s.\n", (yyvsp[0].parameter).name);
                YYABORT;
            }
        }
#line 9884 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 90: /* param_list: param_list ',' parameter  */
#line 7083 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.parameters) = (yyvsp[-2].parameters);
            if (!add_func_parameter(ctx, &(yyval.parameters), &(yyvsp[0].parameter), &(yylsp[0])))
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_REDEFINED,
                        "Parameter \"%s\" is already declared.", (yyvsp[0].parameter).name);
                YYABORT;
            }
        }
#line 9898 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 92: /* parameter: parameter_decl '=' complex_initializer  */
#line 7096 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.parameter) = (yyvsp[-2].parameter);
            (yyval.parameter).initializer = (yyvsp[0].initializer);
        }
#line 9907 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 93: /* parameter_decl: var_modifiers type_no_void any_identifier arrays colon_attribute  */
#line 7103 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            uint32_t modifiers = (yyvsp[-4].modifiers);
            struct hlsl_type *type;
            unsigned int i;

            if (!(type = apply_type_modifiers(ctx, (yyvsp[-3].type), &modifiers, true, &(yylsp[-4]))))
                YYABORT;

            (yyval.parameter).modifiers = modifiers;
            if (!((yyval.parameter).modifiers & (HLSL_STORAGE_IN | HLSL_STORAGE_OUT)))
                (yyval.parameter).modifiers |= HLSL_STORAGE_IN;

            for (i = 0; i < (yyvsp[-1].arrays).count; ++i)
            {
                if ((yyvsp[-1].arrays).sizes[i] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT)
                {
                    hlsl_error(ctx, &(yylsp[-2]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Implicit size arrays not allowed in function parameters.");
                }
                type = hlsl_new_array_type(ctx, type, (yyvsp[-1].arrays).sizes[i]);
            }
            vkd3d_free((yyvsp[-1].arrays).sizes);

            (yyval.parameter).type = type;

            if (hlsl_version_ge(ctx, 5, 1) && type->class == HLSL_CLASS_ARRAY && hlsl_type_is_resource(type))
                hlsl_fixme(ctx, &(yylsp[-3]), "Shader model 5.1+ resource array.");

            (yyval.parameter).name = (yyvsp[-2].name);
            (yyval.parameter).semantic = (yyvsp[0].colon_attribute).semantic;
            (yyval.parameter).reg_reservation = (yyvsp[0].colon_attribute).reg_reservation;

            memset(&(yyval.parameter).initializer, 0, sizeof((yyval.parameter).initializer));
        }
#line 9946 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 94: /* texture_type: KW_BUFFER  */
#line 7140 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_BUFFER;
        }
#line 9954 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 95: /* texture_type: KW_TEXTURE1D  */
#line 7144 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1D;
        }
#line 9962 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 96: /* texture_type: KW_TEXTURE2D  */
#line 7148 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2D;
        }
#line 9970 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 97: /* texture_type: KW_TEXTURE3D  */
#line 7152 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_3D;
        }
#line 9978 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 98: /* texture_type: KW_TEXTURECUBE  */
#line 7156 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_CUBE;
        }
#line 9986 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 99: /* texture_type: KW_TEXTURE1DARRAY  */
#line 7160 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1DARRAY;
        }
#line 9994 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 100: /* texture_type: KW_TEXTURE2DARRAY  */
#line 7164 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2DARRAY;
        }
#line 10002 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 101: /* texture_type: KW_TEXTURECUBEARRAY  */
#line 7168 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_CUBEARRAY;
        }
#line 10010 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 102: /* texture_ms_type: KW_TEXTURE2DMS  */
#line 7174 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2DMS;
        }
#line 10018 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 103: /* texture_ms_type: KW_TEXTURE2DMSARRAY  */
#line 7178 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2DMSARRAY;
        }
#line 10026 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 104: /* uav_type: KW_RWBUFFER  */
#line 7184 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_BUFFER;
        }
#line 10034 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 105: /* uav_type: KW_RWSTRUCTUREDBUFFER  */
#line 7188 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_STRUCTURED_BUFFER;
        }
#line 10042 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 106: /* uav_type: KW_RWTEXTURE1D  */
#line 7192 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1D;
        }
#line 10050 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 107: /* uav_type: KW_RWTEXTURE1DARRAY  */
#line 7196 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1DARRAY;
        }
#line 10058 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 108: /* uav_type: KW_RWTEXTURE2D  */
#line 7200 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2D;
        }
#line 10066 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 109: /* uav_type: KW_RWTEXTURE2DARRAY  */
#line 7204 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2DARRAY;
        }
#line 10074 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 110: /* uav_type: KW_RWTEXTURE3D  */
#line 7208 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_3D;
        }
#line 10082 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 111: /* rov_type: KW_RASTERIZERORDEREDBUFFER  */
#line 7214 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_BUFFER;
        }
#line 10090 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 112: /* rov_type: KW_RASTERIZERORDEREDSTRUCTUREDBUFFER  */
#line 7218 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_STRUCTURED_BUFFER;
        }
#line 10098 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 113: /* rov_type: KW_RASTERIZERORDEREDTEXTURE1D  */
#line 7222 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1D;
        }
#line 10106 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 114: /* rov_type: KW_RASTERIZERORDEREDTEXTURE1DARRAY  */
#line 7226 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_1DARRAY;
        }
#line 10114 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 115: /* rov_type: KW_RASTERIZERORDEREDTEXTURE2D  */
#line 7230 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2D;
        }
#line 10122 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 116: /* rov_type: KW_RASTERIZERORDEREDTEXTURE2DARRAY  */
#line 7234 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_2DARRAY;
        }
#line 10130 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 117: /* rov_type: KW_RASTERIZERORDEREDTEXTURE3D  */
#line 7238 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.sampler_dim) = HLSL_SAMPLER_DIM_3D;
        }
#line 10138 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 118: /* type_no_void: KW_VECTOR '<' type ',' C_INTEGER '>'  */
#line 7244 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[-3].type)->class != HLSL_CLASS_SCALAR)
            {
                struct vkd3d_string_buffer *string;

                string = hlsl_type_to_string(ctx, (yyvsp[-3].type));
                if (string)
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Vector base type %s is not scalar.", string->buffer);
                hlsl_release_string_buffer(ctx, string);
                YYABORT;
            }
            if ((yyvsp[-1].intval) < 1 || (yyvsp[-1].intval) > 4)
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SIZE,
                        "Vector size %d is not between 1 and 4.", (yyvsp[-1].intval));
                YYABORT;
            }

            (yyval.type) = hlsl_type_clone(ctx, hlsl_get_vector_type(ctx, (yyvsp[-3].type)->e.numeric.type, (yyvsp[-1].intval)), 0, 0);
            (yyval.type)->is_minimum_precision = (yyvsp[-3].type)->is_minimum_precision;
        }
#line 10165 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 119: /* type_no_void: KW_VECTOR  */
#line 7267 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, 4);
        }
#line 10173 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 120: /* type_no_void: KW_MATRIX '<' type ',' C_INTEGER ',' C_INTEGER '>'  */
#line 7271 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[-5].type)->class != HLSL_CLASS_SCALAR)
            {
                struct vkd3d_string_buffer *string;

                string = hlsl_type_to_string(ctx, (yyvsp[-5].type));
                if (string)
                    hlsl_error(ctx, &(yylsp[-5]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Matrix base type %s is not scalar.", string->buffer);
                hlsl_release_string_buffer(ctx, string);
                YYABORT;
            }
            if ((yyvsp[-3].intval) < 1 || (yyvsp[-3].intval) > 4)
            {
                hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_SIZE,
                        "Matrix row count %d is not between 1 and 4.", (yyvsp[-3].intval));
                YYABORT;
            }
            if ((yyvsp[-1].intval) < 1 || (yyvsp[-1].intval) > 4)
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SIZE,
                        "Matrix column count %d is not between 1 and 4.", (yyvsp[-1].intval));
                YYABORT;
            }

            (yyval.type) = hlsl_type_clone(ctx, hlsl_get_matrix_type(ctx, (yyvsp[-5].type)->e.numeric.type, (yyvsp[-1].intval), (yyvsp[-3].intval)), 0, 0);
            (yyval.type)->is_minimum_precision = (yyvsp[-5].type)->is_minimum_precision;
        }
#line 10206 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 121: /* type_no_void: KW_MATRIX  */
#line 7300 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_matrix_type(ctx, HLSL_TYPE_FLOAT, 4, 4);
        }
#line 10214 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 122: /* type_no_void: KW_SAMPLER  */
#line 7304 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_GENERIC];
        }
#line 10222 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 123: /* type_no_void: KW_SAMPLERCOMPARISONSTATE  */
#line 7308 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_COMPARISON];
        }
#line 10230 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 124: /* type_no_void: KW_SAMPLER1D  */
#line 7312 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_1D];
        }
#line 10238 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 125: /* type_no_void: KW_SAMPLER2D  */
#line 7316 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_2D];
        }
#line 10246 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 126: /* type_no_void: KW_SAMPLER3D  */
#line 7320 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_3D];
        }
#line 10254 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 127: /* type_no_void: KW_SAMPLERCUBE  */
#line 7324 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.sampler[HLSL_SAMPLER_DIM_CUBE];
        }
#line 10262 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 128: /* type_no_void: KW_TEXTURE  */
#line 7328 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_new_texture_type(ctx, HLSL_SAMPLER_DIM_GENERIC, NULL, 0);
        }
#line 10270 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 129: /* type_no_void: texture_type  */
#line 7332 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_new_texture_type(ctx, (yyvsp[0].sampler_dim), hlsl_get_vector_type(ctx, HLSL_TYPE_FLOAT, 4), 0);
        }
#line 10278 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 130: /* type_no_void: texture_type '<' type '>'  */
#line 7336 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            validate_texture_format_type(ctx, (yyvsp[-1].type), &(yylsp[-1]));
            (yyval.type) = hlsl_new_texture_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), 0);
        }
#line 10287 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 131: /* type_no_void: texture_ms_type '<' type '>'  */
#line 7341 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            validate_texture_format_type(ctx, (yyvsp[-1].type), &(yylsp[-1]));

            (yyval.type) = hlsl_new_texture_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), 0);
        }
#line 10297 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 132: /* type_no_void: texture_ms_type '<' type ',' shift_expr '>'  */
#line 7347 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            unsigned int sample_count;
            struct hlsl_block block;

            hlsl_block_init(&block);
            hlsl_block_add_block(&block, (yyvsp[-1].block));

            sample_count = evaluate_static_expression_as_uint(ctx, &block, &(yylsp[-1]));

            hlsl_block_cleanup(&block);

            vkd3d_free((yyvsp[-1].block));

            (yyval.type) = hlsl_new_texture_type(ctx, (yyvsp[-5].sampler_dim), (yyvsp[-3].type), sample_count);
        }
#line 10317 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 133: /* type_no_void: uav_type '<' type '>'  */
#line 7363 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            validate_uav_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), &(yylsp[-1]));
            (yyval.type) = hlsl_new_uav_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), false);
        }
#line 10326 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 134: /* type_no_void: rov_type '<' type '>'  */
#line 7368 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            validate_uav_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), &(yylsp[-1]));
            (yyval.type) = hlsl_new_uav_type(ctx, (yyvsp[-3].sampler_dim), (yyvsp[-1].type), true);
        }
#line 10335 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 135: /* type_no_void: KW_STRING  */
#line 7373 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.string;
        }
#line 10343 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 136: /* type_no_void: TYPE_IDENTIFIER  */
#line 7377 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, (yyvsp[0].name), true, true);
            if ((yyval.type)->is_minimum_precision)
            {
                if (hlsl_version_lt(ctx, 4, 0))
                {
                    hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Target profile doesn't support minimum-precision types.");
                }
                else
                {
                    FIXME("Reinterpreting type %s.\n", (yyval.type)->name);
                }
            }
            vkd3d_free((yyvsp[0].name));
        }
#line 10364 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 137: /* type_no_void: KW_UNSIGNED TYPE_IDENTIFIER  */
#line 7394 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_type *type = hlsl_get_type(ctx->cur_scope, (yyvsp[0].name), true, true);

            if (hlsl_is_numeric_type(type) && type->e.numeric.type == HLSL_TYPE_INT)
            {
                if (!(type = hlsl_type_clone(ctx, type, 0, 0)))
                    YYABORT;
                vkd3d_free((void *)type->name);
                type->name = NULL;
                type->e.numeric.type = HLSL_TYPE_UINT;
            }
            else
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "The 'unsigned' keyword can't be used with type %s.", (yyvsp[0].name));
            }

            (yyval.type) = type;
        }
#line 10388 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 138: /* type_no_void: KW_STRUCT TYPE_IDENTIFIER  */
#line 7414 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, (yyvsp[0].name), true, true);
            if ((yyval.type)->class != HLSL_CLASS_STRUCT)
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_REDEFINED, "\"%s\" redefined as a structure.", (yyvsp[0].name));
            vkd3d_free((yyvsp[0].name));
        }
#line 10399 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 139: /* type_no_void: KW_RENDERTARGETVIEW  */
#line 7421 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "RenderTargetView", true, true);
        }
#line 10407 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 140: /* type_no_void: KW_DEPTHSTENCILSTATE  */
#line 7425 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "DepthStencilState", true, true);
        }
#line 10415 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 141: /* type_no_void: KW_DEPTHSTENCILVIEW  */
#line 7429 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "DepthStencilView", true, true);
        }
#line 10423 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 142: /* type_no_void: KW_VERTEXSHADER  */
#line 7433 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "VertexShader", true, true);
        }
#line 10431 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 143: /* type_no_void: KW_PIXELSHADER  */
#line 7437 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "PixelShader", true, true);
        }
#line 10439 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 144: /* type_no_void: KW_COMPUTESHADER  */
#line 7441 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "ComputeShader", true, true);
        }
#line 10447 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 145: /* type_no_void: KW_DOMAINSHADER  */
#line 7445 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "DomainShader", true, true);
        }
#line 10455 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 146: /* type_no_void: KW_HULLSHADER  */
#line 7449 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "HullShader", true, true);
        }
#line 10463 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 147: /* type_no_void: KW_GEOMETRYSHADER  */
#line 7453 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "GeometryShader", true, true);
        }
#line 10471 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 148: /* type_no_void: KW_CONSTANTBUFFER '<' type '>'  */
#line 7457 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[-1].type)->class != HLSL_CLASS_STRUCT)
                hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                        "ConstantBuffer<...> requires user-defined structure type.");
            (yyval.type) = hlsl_new_cb_type(ctx, (yyvsp[-1].type));
        }
#line 10482 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 149: /* type_no_void: KW_RASTERIZERSTATE  */
#line 7464 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "RasterizerState", true, true);
        }
#line 10490 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 150: /* type_no_void: KW_BLENDSTATE  */
#line 7468 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = hlsl_get_type(ctx->cur_scope, "BlendState", true, true);
        }
#line 10498 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 152: /* type: KW_VOID  */
#line 7475 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.type) = ctx->builtin_types.Void;
        }
#line 10506 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 155: /* declaration_statement: typedef  */
#line 7483 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
        }
#line 10515 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 158: /* typedef: KW_TYPEDEF var_modifiers typedef_type type_specs ';'  */
#line 7494 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct parse_variable_def *v, *v_next;
            uint32_t modifiers = (yyvsp[-3].modifiers);
            struct hlsl_type *type;

            if (!(type = apply_type_modifiers(ctx, (yyvsp[-2].type), &modifiers, false, &(yylsp[-3]))))
            {
                LIST_FOR_EACH_ENTRY_SAFE(v, v_next, (yyvsp[-1].list), struct parse_variable_def, entry)
                    free_parse_variable_def(v);
                vkd3d_free((yyvsp[-1].list));
                YYABORT;
            }

            if (modifiers)
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Storage modifiers are not allowed on typedefs.");
                LIST_FOR_EACH_ENTRY_SAFE(v, v_next, (yyvsp[-1].list), struct parse_variable_def, entry)
                    vkd3d_free(v);
                vkd3d_free((yyvsp[-1].list));
                YYABORT;
            }
            if (!add_typedef(ctx, type, (yyvsp[-1].list)))
                YYABORT;
        }
#line 10545 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 159: /* type_specs: type_spec  */
#line 7522 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.list) = make_empty_list(ctx)))
                YYABORT;
            list_add_head((yyval.list), &(yyvsp[0].variable_def)->entry);
        }
#line 10555 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 160: /* type_specs: type_specs ',' type_spec  */
#line 7528 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.list) = (yyvsp[-2].list);
            list_add_tail((yyval.list), &(yyvsp[0].variable_def)->entry);
        }
#line 10564 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 161: /* type_spec: any_identifier arrays  */
#line 7535 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = hlsl_alloc(ctx, sizeof(*(yyval.variable_def)));
            (yyval.variable_def)->loc = (yylsp[-1]);
            (yyval.variable_def)->name = (yyvsp[-1].name);
            (yyval.variable_def)->arrays = (yyvsp[0].arrays);
        }
#line 10575 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 162: /* declaration: variables_def_typed ';'  */
#line 7544 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = initialize_vars(ctx, (yyvsp[-1].list))))
                YYABORT;
        }
#line 10584 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 163: /* variables_def: variable_def  */
#line 7551 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.list) = make_empty_list(ctx)))
                YYABORT;
            list_add_head((yyval.list), &(yyvsp[0].variable_def)->entry);
        }
#line 10594 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 164: /* variables_def: variables_def ',' variable_def  */
#line 7557 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.list) = (yyvsp[-2].list);
            list_add_tail((yyval.list), &(yyvsp[0].variable_def)->entry);
        }
#line 10603 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 165: /* variables_def_typed: variable_def_typed  */
#line 7564 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.list) = make_empty_list(ctx)))
                YYABORT;
            list_add_head((yyval.list), &(yyvsp[0].variable_def)->entry);

            declare_var(ctx, (yyvsp[0].variable_def));
        }
#line 10615 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 166: /* variables_def_typed: variables_def_typed ',' variable_def  */
#line 7572 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct parse_variable_def *head_def;

            VKD3D_ASSERT(!list_empty((yyvsp[-2].list)));
            head_def = LIST_ENTRY(list_head((yyvsp[-2].list)), struct parse_variable_def, entry);

            VKD3D_ASSERT(head_def->basic_type);
            (yyvsp[0].variable_def)->basic_type = head_def->basic_type;
            (yyvsp[0].variable_def)->modifiers = head_def->modifiers;
            (yyvsp[0].variable_def)->modifiers_loc = head_def->modifiers_loc;

            declare_var(ctx, (yyvsp[0].variable_def));

            (yyval.list) = (yyvsp[-2].list);
            list_add_tail((yyval.list), &(yyvsp[0].variable_def)->entry);
        }
#line 10636 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 167: /* variable_decl: any_identifier arrays colon_attribute annotations_opt  */
#line 7591 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = hlsl_alloc(ctx, sizeof(*(yyval.variable_def)));
            (yyval.variable_def)->loc = (yylsp[-3]);
            (yyval.variable_def)->name = (yyvsp[-3].name);
            (yyval.variable_def)->arrays = (yyvsp[-2].arrays);
            (yyval.variable_def)->semantic = (yyvsp[-1].colon_attribute).semantic;
            (yyval.variable_def)->reg_reservation = (yyvsp[-1].colon_attribute).reg_reservation;
            (yyval.variable_def)->annotations = (yyvsp[0].scope);
        }
#line 10650 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 168: /* state_block_start: %empty  */
#line 7603 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            ctx->in_state_block = 1;
        }
#line 10658 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 169: /* stateblock_lhs_identifier: any_identifier  */
#line 7609 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.name) = (yyvsp[0].name);
        }
#line 10666 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 170: /* stateblock_lhs_identifier: KW_PIXELSHADER  */
#line 7613 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.name) = hlsl_strdup(ctx, "pixelshader")))
                YYABORT;
        }
#line 10675 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 171: /* stateblock_lhs_identifier: KW_VERTEXSHADER  */
#line 7618 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.name) = hlsl_strdup(ctx, "vertexshader")))
                YYABORT;
        }
#line 10684 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 172: /* state_block_index_opt: %empty  */
#line 7625 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.state_block_index).has_index = false;
            (yyval.state_block_index).index = 0;
        }
#line 10693 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 173: /* state_block_index_opt: '[' C_INTEGER ']'  */
#line 7630 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
       {
            if ((yyvsp[-1].intval) < 0)
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_INDEX,
                        "State block array index is not a positive integer constant.");
                YYABORT;
            }
            (yyval.state_block_index).has_index = true;
            (yyval.state_block_index).index = (yyvsp[-1].intval);
       }
#line 10708 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 174: /* state_block: %empty  */
#line 7643 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.state_block) = hlsl_alloc(ctx, sizeof(*(yyval.state_block)))))
                YYABORT;
        }
#line 10717 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 175: /* state_block: state_block stateblock_lhs_identifier state_block_index_opt '=' complex_initializer ';'  */
#line 7648 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_state_block_entry *entry;
            unsigned int i;

            if (!(entry = hlsl_alloc(ctx, sizeof(*entry))))
                YYABORT;

            entry->name = (yyvsp[-4].name);
            entry->lhs_has_index = (yyvsp[-3].state_block_index).has_index;
            entry->lhs_index = (yyvsp[-3].state_block_index).index;

            entry->instrs = (yyvsp[-1].initializer).instrs;

            entry->args_count = (yyvsp[-1].initializer).args_count;
            if (!(entry->args = hlsl_alloc(ctx, sizeof(*entry->args) * entry->args_count)))
                YYABORT;
            for (i = 0; i < entry->args_count; ++i)
                hlsl_src_from_node(&entry->args[i], (yyvsp[-1].initializer).args[i]);
            vkd3d_free((yyvsp[-1].initializer).args);

            (yyval.state_block) = (yyvsp[-5].state_block);
            state_block_add_entry((yyval.state_block), entry);
        }
#line 10745 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 176: /* state_block: state_block any_identifier '(' func_arguments ')' ';'  */
#line 7672 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_state_block_entry *entry;
            unsigned int i;

            if (!(entry = hlsl_alloc(ctx, sizeof(*entry))))
                YYABORT;

            entry->is_function_call = true;

            entry->name = (yyvsp[-4].name);
            entry->lhs_has_index = false;
            entry->lhs_index = 0;

            entry->instrs = (yyvsp[-2].initializer).instrs;

            entry->args_count = (yyvsp[-2].initializer).args_count;
            if (!(entry->args = hlsl_alloc(ctx, sizeof(*entry->args) * entry->args_count)))
                YYABORT;
            for (i = 0; i < entry->args_count; ++i)
                hlsl_src_from_node(&entry->args[i], (yyvsp[-2].initializer).args[i]);
            vkd3d_free((yyvsp[-2].initializer).args);

            hlsl_validate_state_block_entry(ctx, entry, &(yylsp[-2]));

            (yyval.state_block) = (yyvsp[-5].state_block);
            state_block_add_entry((yyval.state_block), entry);
        }
#line 10777 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 177: /* state_block_list: '{' state_block '}'  */
#line 7702 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.variable_def) = hlsl_alloc(ctx, sizeof(*(yyval.variable_def)))))
                YYABORT;

            if(!(vkd3d_array_reserve((void **)&(yyval.variable_def)->state_blocks, &(yyval.variable_def)->state_block_capacity,
                    (yyval.variable_def)->state_block_count + 1, sizeof(*(yyval.variable_def)->state_blocks))))
                YYABORT;
            (yyval.variable_def)->state_blocks[(yyval.variable_def)->state_block_count++] = (yyvsp[-1].state_block);
        }
#line 10791 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 178: /* state_block_list: state_block_list ',' '{' state_block '}'  */
#line 7712 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = (yyvsp[-4].variable_def);

            if(!(vkd3d_array_reserve((void **)&(yyval.variable_def)->state_blocks, &(yyval.variable_def)->state_block_capacity,
                    (yyval.variable_def)->state_block_count + 1, sizeof(*(yyval.variable_def)->state_blocks))))
                YYABORT;
            (yyval.variable_def)->state_blocks[(yyval.variable_def)->state_block_count++] = (yyvsp[-1].state_block);
        }
#line 10804 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 180: /* variable_def: variable_decl '=' complex_initializer  */
#line 7724 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = (yyvsp[-2].variable_def);
            (yyval.variable_def)->initializer = (yyvsp[0].initializer);
        }
#line 10813 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 181: /* variable_def: variable_decl '{' state_block_start state_block '}'  */
#line 7729 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = (yyvsp[-4].variable_def);
            ctx->in_state_block = 0;

            if(!(vkd3d_array_reserve((void **)&(yyval.variable_def)->state_blocks, &(yyval.variable_def)->state_block_capacity,
                    (yyval.variable_def)->state_block_count + 1, sizeof(*(yyval.variable_def)->state_blocks))))
                YYABORT;
            (yyval.variable_def)->state_blocks[(yyval.variable_def)->state_block_count++] = (yyvsp[-1].state_block);
        }
#line 10827 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 182: /* variable_def: variable_decl '{' state_block_start state_block_list '}'  */
#line 7739 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.variable_def) = (yyvsp[-4].variable_def);
            ctx->in_state_block = 0;

            (yyval.variable_def)->state_blocks = (yyvsp[-1].variable_def)->state_blocks;
            (yyval.variable_def)->state_block_count = (yyvsp[-1].variable_def)->state_block_count;
            (yyval.variable_def)->state_block_capacity = (yyvsp[-1].variable_def)->state_block_capacity;
            (yyvsp[-1].variable_def)->state_blocks = NULL;
            (yyvsp[-1].variable_def)->state_block_count = 0;
            (yyvsp[-1].variable_def)->state_block_capacity = 0;
            free_parse_variable_def((yyvsp[-1].variable_def));
        }
#line 10844 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 183: /* variable_def_typed: var_modifiers struct_spec variable_def  */
#line 7754 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            uint32_t modifiers = (yyvsp[-2].modifiers);
            struct hlsl_type *type;

            if (!(type = apply_type_modifiers(ctx, (yyvsp[-1].type), &modifiers, true, &(yylsp[-2]))))
                YYABORT;

            check_invalid_in_out_modifiers(ctx, modifiers, &(yylsp[-2]));

            (yyval.variable_def) = (yyvsp[0].variable_def);
            (yyval.variable_def)->basic_type = type;
            (yyval.variable_def)->modifiers = modifiers;
            (yyval.variable_def)->modifiers_loc = (yylsp[-2]);
        }
#line 10863 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 184: /* variable_def_typed: var_modifiers type variable_def  */
#line 7769 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            uint32_t modifiers = (yyvsp[-2].modifiers);
            struct hlsl_type *type;

            if (!(type = apply_type_modifiers(ctx, (yyvsp[-1].type), &modifiers, true, &(yylsp[-2]))))
                YYABORT;

            check_invalid_in_out_modifiers(ctx, modifiers, &(yylsp[-2]));

            (yyval.variable_def) = (yyvsp[0].variable_def);
            (yyval.variable_def)->basic_type = type;
            (yyval.variable_def)->modifiers = modifiers;
            (yyval.variable_def)->modifiers_loc = (yylsp[-2]);
        }
#line 10882 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 185: /* array: '[' ']'  */
#line 7786 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.intval) = HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT;
        }
#line 10890 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 186: /* array: '[' expr ']'  */
#line 7790 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.intval) = evaluate_static_expression_as_uint(ctx, (yyvsp[-1].block), &(yylsp[-1]));

            if (!(yyval.intval))
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SIZE,
                        "Array size is not a positive integer constant.");
                YYABORT;
            }

            if ((yyval.intval) > 65536)
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SIZE,
                        "Array size %u is not between 1 and 65536.", (yyval.intval));
                YYABORT;
            }

            destroy_block((yyvsp[-1].block));
        }
#line 10914 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 187: /* arrays: %empty  */
#line 7812 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.arrays).sizes = NULL;
            (yyval.arrays).count = 0;
        }
#line 10923 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 188: /* arrays: array arrays  */
#line 7817 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            uint32_t *new_array;

            (yyval.arrays) = (yyvsp[0].arrays);

            if (!(new_array = hlsl_realloc(ctx, (yyval.arrays).sizes, ((yyval.arrays).count + 1) * sizeof(*new_array))))
            {
                vkd3d_free((yyval.arrays).sizes);
                YYABORT;
            }

            (yyval.arrays).sizes = new_array;
            (yyval.arrays).sizes[(yyval.arrays).count++] = (yyvsp[-1].intval);
        }
#line 10942 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 189: /* var_modifiers: %empty  */
#line 7834 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = 0;
        }
#line 10950 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 190: /* var_modifiers: KW_EXTERN var_modifiers  */
#line 7838 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_EXTERN, &(yylsp[-1]));
        }
#line 10958 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 191: /* var_modifiers: KW_NOINTERPOLATION var_modifiers  */
#line 7842 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_NOINTERPOLATION, &(yylsp[-1]));
        }
#line 10966 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 192: /* var_modifiers: KW_CENTROID var_modifiers  */
#line 7846 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_CENTROID, &(yylsp[-1]));
        }
#line 10974 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 193: /* var_modifiers: KW_LINEAR var_modifiers  */
#line 7850 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_LINEAR, &(yylsp[-1]));
        }
#line 10982 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 194: /* var_modifiers: KW_NOPERSPECTIVE var_modifiers  */
#line 7854 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_NOPERSPECTIVE, &(yylsp[-1]));
        }
#line 10990 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 195: /* var_modifiers: KW_SHARED var_modifiers  */
#line 7858 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_SHARED, &(yylsp[-1]));
        }
#line 10998 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 196: /* var_modifiers: KW_GROUPSHARED var_modifiers  */
#line 7862 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_GROUPSHARED, &(yylsp[-1]));
        }
#line 11006 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 197: /* var_modifiers: KW_STATIC var_modifiers  */
#line 7866 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_STATIC, &(yylsp[-1]));
        }
#line 11014 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 198: /* var_modifiers: KW_UNIFORM var_modifiers  */
#line 7870 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_UNIFORM, &(yylsp[-1]));
        }
#line 11022 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 199: /* var_modifiers: KW_VOLATILE var_modifiers  */
#line 7874 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_VOLATILE, &(yylsp[-1]));
        }
#line 11030 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 200: /* var_modifiers: KW_CONST var_modifiers  */
#line 7878 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_CONST, &(yylsp[-1]));
        }
#line 11038 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 201: /* var_modifiers: KW_ROW_MAJOR var_modifiers  */
#line 7882 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_ROW_MAJOR, &(yylsp[-1]));
        }
#line 11046 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 202: /* var_modifiers: KW_COLUMN_MAJOR var_modifiers  */
#line 7886 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_COLUMN_MAJOR, &(yylsp[-1]));
        }
#line 11054 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 203: /* var_modifiers: KW_IN var_modifiers  */
#line 7890 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_IN, &(yylsp[-1]));
        }
#line 11062 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 204: /* var_modifiers: KW_OUT var_modifiers  */
#line 7894 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_OUT, &(yylsp[-1]));
        }
#line 11070 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 205: /* var_modifiers: KW_INOUT var_modifiers  */
#line 7898 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_STORAGE_IN | HLSL_STORAGE_OUT, &(yylsp[-1]));
        }
#line 11078 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 206: /* var_modifiers: KW_INLINE var_modifiers  */
#line 7902 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_INLINE, &(yylsp[-1]));
        }
#line 11086 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 207: /* var_modifiers: KW_EXPORT var_modifiers  */
#line 7906 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_EXPORT, &(yylsp[-1]));
        }
#line 11094 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 208: /* var_modifiers: var_identifier var_modifiers  */
#line 7910 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.modifiers) = (yyvsp[0].modifiers);

            if (!strcmp((yyvsp[-1].name), "precise"))
                (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_PRECISE, &(yylsp[-1]));
            else if (!strcmp((yyvsp[-1].name), "single"))
                (yyval.modifiers) = add_modifiers(ctx, (yyvsp[0].modifiers), HLSL_MODIFIER_SINGLE, &(yylsp[-1]));
            else
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_UNKNOWN_MODIFIER,
                        "Unknown modifier %s.", debugstr_a((yyvsp[-1].name)));
        }
#line 11110 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 209: /* complex_initializer: initializer_expr  */
#line 7924 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.initializer).args_count = 1;
            if (!((yyval.initializer).args = hlsl_alloc(ctx, sizeof(*(yyval.initializer).args))))
            {
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.initializer).args[0] = node_from_block((yyvsp[0].block));
            (yyval.initializer).instrs = (yyvsp[0].block);
            (yyval.initializer).braces = false;
        }
#line 11126 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 210: /* complex_initializer: '{' complex_initializer_list '}'  */
#line 7936 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.initializer) = (yyvsp[-1].initializer);
            (yyval.initializer).braces = true;
        }
#line 11135 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 211: /* complex_initializer: '{' complex_initializer_list ',' '}'  */
#line 7941 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.initializer) = (yyvsp[-2].initializer);
            (yyval.initializer).braces = true;
        }
#line 11144 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 213: /* complex_initializer_list: complex_initializer_list ',' complex_initializer  */
#line 7949 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node **new_args;
            unsigned int i;

            (yyval.initializer) = (yyvsp[-2].initializer);
            if (!(new_args = hlsl_realloc(ctx, (yyval.initializer).args, ((yyval.initializer).args_count + (yyvsp[0].initializer).args_count) * sizeof(*(yyval.initializer).args))))
            {
                free_parse_initializer(&(yyval.initializer));
                free_parse_initializer(&(yyvsp[0].initializer));
                YYABORT;
            }
            (yyval.initializer).args = new_args;
            for (i = 0; i < (yyvsp[0].initializer).args_count; ++i)
                (yyval.initializer).args[(yyval.initializer).args_count++] = (yyvsp[0].initializer).args[i];
            hlsl_block_add_block((yyval.initializer).instrs, (yyvsp[0].initializer).instrs);
            free_parse_initializer(&(yyvsp[0].initializer));
        }
#line 11166 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 215: /* initializer_expr_list: initializer_expr  */
#line 7972 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.initializer).args_count = 1;
            if (!((yyval.initializer).args = hlsl_alloc(ctx, sizeof(*(yyval.initializer).args))))
            {
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.initializer).args[0] = node_from_block((yyvsp[0].block));
            (yyval.initializer).instrs = (yyvsp[0].block);
            (yyval.initializer).braces = false;
        }
#line 11182 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 216: /* initializer_expr_list: initializer_expr_list ',' initializer_expr  */
#line 7984 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node **new_args;

            (yyval.initializer) = (yyvsp[-2].initializer);
            if (!(new_args = hlsl_realloc(ctx, (yyval.initializer).args, ((yyval.initializer).args_count + 1) * sizeof(*(yyval.initializer).args))))
            {
                free_parse_initializer(&(yyval.initializer));
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.initializer).args = new_args;
            (yyval.initializer).args[(yyval.initializer).args_count++] = node_from_block((yyvsp[0].block));
            hlsl_block_add_block((yyval.initializer).instrs, (yyvsp[0].block));
            destroy_block((yyvsp[0].block));
        }
#line 11202 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 217: /* boolean: KW_TRUE  */
#line 8002 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.boolval) = true;
        }
#line 11210 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 218: /* boolean: KW_FALSE  */
#line 8006 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.boolval) = false;
        }
#line 11218 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 220: /* statement_list: statement_list statement  */
#line 8013 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[-1].block);
            hlsl_block_add_block((yyval.block), (yyvsp[0].block));
            destroy_block((yyvsp[0].block));
        }
#line 11228 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 228: /* jump_statement: KW_BREAK ';'  */
#line 8030 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *jump;

            if (!is_break_allowed(ctx->cur_scope))
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX,
                        "The 'break' statement must be used inside of a loop or a switch.");
            }

            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
            if (!(jump = hlsl_new_jump(ctx, HLSL_IR_JUMP_BREAK, NULL, &(yylsp[-1]))))
                YYABORT;
            hlsl_block_add_instr((yyval.block), jump);
        }
#line 11248 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 229: /* jump_statement: KW_CONTINUE ';'  */
#line 8046 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *jump;

            check_continue(ctx, ctx->cur_scope, &(yylsp[-1]));

            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;

            if (!(jump = hlsl_new_jump(ctx, HLSL_IR_JUMP_UNRESOLVED_CONTINUE, NULL, &(yylsp[-1]))))
                YYABORT;
            hlsl_block_add_instr((yyval.block), jump);
        }
#line 11265 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 230: /* jump_statement: KW_RETURN expr ';'  */
#line 8059 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[-1].block);
            if (!add_return(ctx, (yyval.block), node_from_block((yyval.block)), &(yylsp[-2])))
                YYABORT;
        }
#line 11275 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 231: /* jump_statement: KW_RETURN ';'  */
#line 8065 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
            if (!add_return(ctx, (yyval.block), NULL, &(yylsp[-1])))
                YYABORT;
        }
#line 11286 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 232: /* jump_statement: KW_DISCARD ';'  */
#line 8072 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *discard, *c;

            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;

            if (!(c = hlsl_new_uint_constant(ctx, ~0u, &(yylsp[-1]))))
                return false;
            hlsl_block_add_instr((yyval.block), c);

            if (!(discard = hlsl_new_jump(ctx, HLSL_IR_JUMP_DISCARD_NZ, c, &(yylsp[-1]))))
                return false;
            hlsl_block_add_instr((yyval.block), discard);
        }
#line 11305 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 233: /* selection_statement: attribute_list_optional KW_IF '(' expr ')' if_body  */
#line 8089 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *condition = node_from_block((yyvsp[-2].block));
            const struct parse_attribute_list *attributes = &(yyvsp[-5].attr_list);
            struct hlsl_ir_node *instr;
            unsigned int i;

            if (attribute_list_has_duplicates(attributes))
                hlsl_error(ctx, &(yylsp[-5]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Found duplicate attribute.");

            for (i = 0; i < attributes->count; ++i)
            {
                const struct hlsl_attribute *attr = attributes->attrs[i];

                if (!strcmp(attr->name, "branch")
                        || !strcmp(attr->name, "flatten"))
                {
                    hlsl_warning(ctx, &(yylsp[-5]), VKD3D_SHADER_WARNING_HLSL_IGNORED_ATTRIBUTE, "Unhandled attribute '%s'.", attr->name);
                }
                else
                {
                    hlsl_warning(ctx, &(yylsp[-5]), VKD3D_SHADER_WARNING_HLSL_UNKNOWN_ATTRIBUTE, "Unrecognized attribute '%s'.", attr->name);
                }
            }

            check_condition_type(ctx, condition);

            if (!(condition = add_cast(ctx, (yyvsp[-2].block), condition, hlsl_get_scalar_type(ctx, HLSL_TYPE_BOOL), &(yylsp[-2]))))
            {
                destroy_block((yyvsp[0].if_body).then_block);
                destroy_block((yyvsp[0].if_body).else_block);
                cleanup_parse_attribute_list(&(yyvsp[-5].attr_list));
                YYABORT;
            }

            if (!(instr = hlsl_new_if(ctx, condition, (yyvsp[0].if_body).then_block, (yyvsp[0].if_body).else_block, &(yylsp[-4]))))
            {
                destroy_block((yyvsp[0].if_body).then_block);
                destroy_block((yyvsp[0].if_body).else_block);
                cleanup_parse_attribute_list(&(yyvsp[-5].attr_list));
                YYABORT;
            }
            destroy_block((yyvsp[0].if_body).then_block);
            destroy_block((yyvsp[0].if_body).else_block);
            cleanup_parse_attribute_list(&(yyvsp[-5].attr_list));

            (yyval.block) = (yyvsp[-2].block);
            hlsl_block_add_instr((yyval.block), instr);
        }
#line 11358 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 234: /* if_body: statement  */
#line 8140 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.if_body).then_block = (yyvsp[0].block);
            (yyval.if_body).else_block = NULL;
        }
#line 11367 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 235: /* if_body: statement KW_ELSE statement  */
#line 8145 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.if_body).then_block = (yyvsp[-2].block);
            (yyval.if_body).else_block = (yyvsp[0].block);
        }
#line 11376 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 236: /* loop_statement: attribute_list_optional loop_scope_start KW_WHILE '(' expr ')' statement  */
#line 8152 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = create_loop(ctx, LOOP_WHILE, &(yyvsp[-6].attr_list), NULL, (yyvsp[-2].block), NULL, (yyvsp[0].block), &(yylsp[-4]));
            hlsl_pop_scope(ctx);
            cleanup_parse_attribute_list(&(yyvsp[-6].attr_list));
        }
#line 11386 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 237: /* loop_statement: attribute_list_optional loop_scope_start KW_DO statement KW_WHILE '(' expr ')' ';'  */
#line 8158 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = create_loop(ctx, LOOP_DO_WHILE, &(yyvsp[-8].attr_list), NULL, (yyvsp[-2].block), NULL, (yyvsp[-5].block), &(yylsp[-6]));
            hlsl_pop_scope(ctx);
            cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
        }
#line 11396 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 238: /* loop_statement: attribute_list_optional loop_scope_start KW_FOR '(' expr_statement expr_statement expr_optional ')' statement  */
#line 8164 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = create_loop(ctx, LOOP_FOR, &(yyvsp[-8].attr_list), (yyvsp[-4].block), (yyvsp[-3].block), (yyvsp[-2].block), (yyvsp[0].block), &(yylsp[-6]));
            hlsl_pop_scope(ctx);
            cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
        }
#line 11406 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 239: /* loop_statement: attribute_list_optional loop_scope_start KW_FOR '(' declaration expr_statement expr_optional ')' statement  */
#line 8170 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = create_loop(ctx, LOOP_FOR, &(yyvsp[-8].attr_list), (yyvsp[-4].block), (yyvsp[-3].block), (yyvsp[-2].block), (yyvsp[0].block), &(yylsp[-6]));
            hlsl_pop_scope(ctx);
            cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
        }
#line 11416 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 240: /* switch_statement: attribute_list_optional switch_scope_start KW_SWITCH '(' expr ')' '{' switch_cases '}'  */
#line 8178 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *selector = node_from_block((yyvsp[-4].block));
            struct hlsl_ir_node *s;

            if (!(selector = add_implicit_conversion(ctx, (yyvsp[-4].block), selector, hlsl_get_scalar_type(ctx, HLSL_TYPE_UINT), &(yylsp[-4]))))
            {
                destroy_switch_cases((yyvsp[-1].list));
                destroy_block((yyvsp[-4].block));
                cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
                YYABORT;
            }

            s = hlsl_new_switch(ctx, selector, (yyvsp[-1].list), &(yylsp[-6]));

            destroy_switch_cases((yyvsp[-1].list));

            if (!s)
            {
                destroy_block((yyvsp[-4].block));
                cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
                YYABORT;
            }

            (yyval.block) = (yyvsp[-4].block);
            hlsl_block_add_instr((yyval.block), s);

            hlsl_pop_scope(ctx);
            cleanup_parse_attribute_list(&(yyvsp[-8].attr_list));
        }
#line 11450 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 241: /* switch_case: KW_CASE expr ':' statement_list  */
#line 8210 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_switch_case *c;
            unsigned int value;

            value = evaluate_static_expression_as_uint(ctx, (yyvsp[-2].block), &(yylsp[-2]));

            c = hlsl_new_switch_case(ctx, value, false, (yyvsp[0].block), &(yylsp[-2]));

            destroy_block((yyvsp[-2].block));
            destroy_block((yyvsp[0].block));

            if (!c)
                YYABORT;
            (yyval.switch_case) = c;
        }
#line 11470 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 242: /* switch_case: KW_CASE expr ':'  */
#line 8226 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_switch_case *c;
            unsigned int value;

            value = evaluate_static_expression_as_uint(ctx, (yyvsp[-1].block), &(yylsp[-1]));

            c = hlsl_new_switch_case(ctx, value, false, NULL, &(yylsp[-1]));

            destroy_block((yyvsp[-1].block));

            if (!c)
                YYABORT;
            (yyval.switch_case) = c;
        }
#line 11489 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 243: /* switch_case: KW_DEFAULT ':' statement_list  */
#line 8241 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_switch_case *c;

            c = hlsl_new_switch_case(ctx, 0, true, (yyvsp[0].block), &(yylsp[-2]));

            destroy_block((yyvsp[0].block));

            if (!c)
                YYABORT;
            (yyval.switch_case) = c;
        }
#line 11505 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 244: /* switch_case: KW_DEFAULT ':'  */
#line 8253 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_switch_case *c;

            if (!(c = hlsl_new_switch_case(ctx, 0, true, NULL, &(yylsp[-1]))))
                YYABORT;
            (yyval.switch_case) = c;
        }
#line 11517 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 245: /* switch_cases: switch_case  */
#line 8263 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_switch_case *c = LIST_ENTRY((yyvsp[0].switch_case), struct hlsl_ir_switch_case, entry);
            if (!((yyval.list) = make_empty_list(ctx)))
            {
                hlsl_free_ir_switch_case(c);
                YYABORT;
            }
            list_add_head((yyval.list), &(yyvsp[0].switch_case)->entry);
        }
#line 11531 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 246: /* switch_cases: switch_cases switch_case  */
#line 8273 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.list) = (yyvsp[-1].list);
            check_duplicated_switch_cases(ctx, (yyvsp[0].switch_case), (yyval.list));
            list_add_tail((yyval.list), &(yyvsp[0].switch_case)->entry);
        }
#line 11541 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 247: /* expr_optional: %empty  */
#line 8281 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = make_empty_block(ctx)))
                YYABORT;
        }
#line 11550 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 249: /* expr_statement: expr_optional ';'  */
#line 8289 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[-1].block);
        }
#line 11558 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 250: /* func_arguments: %empty  */
#line 8295 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.initializer).args = NULL;
            (yyval.initializer).args_count = 0;
            if (!((yyval.initializer).instrs = make_empty_block(ctx)))
                YYABORT;
            (yyval.initializer).braces = false;
        }
#line 11570 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 252: /* primary_expr: C_FLOAT  */
#line 8306 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_float_constant(ctx, (yyvsp[0].floatval), &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, c)))
                YYABORT;
        }
#line 11583 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 253: /* primary_expr: C_INTEGER  */
#line 8315 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_int_constant(ctx, (yyvsp[0].intval), &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, c)))
                YYABORT;
        }
#line 11596 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 254: /* primary_expr: C_UNSIGNED  */
#line 8324 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_uint_constant(ctx, (yyvsp[0].intval), &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, c)))
                YYABORT;
        }
#line 11609 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 255: /* primary_expr: boolean  */
#line 8333 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_bool_constant(ctx, (yyvsp[0].boolval), &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, c)))
            {
                hlsl_free_instr(c);
                YYABORT;
            }
        }
#line 11625 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 256: /* primary_expr: STRING  */
#line 8345 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_string_constant(ctx, (yyvsp[0].name), &(yylsp[0]))))
            {
                vkd3d_free((yyvsp[0].name));
                YYABORT;
            }
            vkd3d_free((yyvsp[0].name));

            if (!((yyval.block) = make_block(ctx, c)))
            {
                hlsl_free_instr(c);
                YYABORT;
            }
        }
#line 11646 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 257: /* primary_expr: KW_NULL  */
#line 8362 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *c;

            if (!(c = hlsl_new_null_constant(ctx, &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, c)))
            {
                hlsl_free_instr(c);
                YYABORT;
            }
        }
#line 11662 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 258: /* primary_expr: VAR_IDENTIFIER  */
#line 8374 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_load *load;
            struct hlsl_ir_var *var;

            if (!(var = hlsl_get_var(ctx->cur_scope, (yyvsp[0].name))))
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED, "Variable \"%s\" is not defined.", (yyvsp[0].name));
                vkd3d_free((yyvsp[0].name));
                YYABORT;
            }
            vkd3d_free((yyvsp[0].name));
            if (!(load = hlsl_new_var_load(ctx, var, &(yylsp[0]))))
                YYABORT;
            if (!((yyval.block) = make_block(ctx, &load->node)))
                YYABORT;
        }
#line 11683 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 259: /* primary_expr: '(' expr ')'  */
#line 8391 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[-1].block);
        }
#line 11691 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 260: /* primary_expr: var_identifier '(' func_arguments ')'  */
#line 8395 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!((yyval.block) = add_call(ctx, (yyvsp[-3].name), &(yyvsp[-1].initializer), &(yylsp[-3]))))
            {
                vkd3d_free((yyvsp[-3].name));
                YYABORT;
            }
            vkd3d_free((yyvsp[-3].name));
        }
#line 11704 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 261: /* primary_expr: NEW_IDENTIFIER  */
#line 8404 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (ctx->in_state_block)
            {
                struct hlsl_ir_node *constant;

                if (!(constant = hlsl_new_stateblock_constant(ctx, (yyvsp[0].name), &(yylsp[0]))))
                    YYABORT;
                vkd3d_free((yyvsp[0].name));

                if (!((yyval.block) = make_block(ctx, constant)))
                    YYABORT;
            }
            else
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED, "Identifier \"%s\" is not declared.", (yyvsp[0].name));
                YYABORT;
            }
        }
#line 11727 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 263: /* postfix_expr: postfix_expr OP_INC  */
#line 8426 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!add_increment(ctx, (yyvsp[-1].block), false, true, &(yylsp[0])))
            {
                destroy_block((yyvsp[-1].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[-1].block);
        }
#line 11740 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 264: /* postfix_expr: postfix_expr OP_DEC  */
#line 8435 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!add_increment(ctx, (yyvsp[-1].block), true, true, &(yylsp[0])))
            {
                destroy_block((yyvsp[-1].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[-1].block);
        }
#line 11753 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 265: /* postfix_expr: postfix_expr '.' any_identifier  */
#line 8444 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *node = node_from_block((yyvsp[-2].block));

            if (node->data_type->class == HLSL_CLASS_STRUCT)
            {
                struct hlsl_type *type = node->data_type;
                const struct hlsl_struct_field *field;
                unsigned int field_idx = 0;

                if (!(field = get_struct_field(type->e.record.fields, type->e.record.field_count, (yyvsp[0].name))))
                {
                    hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_NOT_DEFINED, "Field \"%s\" is not defined.", (yyvsp[0].name));
                    vkd3d_free((yyvsp[0].name));
                    YYABORT;
                }

                field_idx = field - type->e.record.fields;
                if (!add_record_access(ctx, (yyvsp[-2].block), node, field_idx, &(yylsp[-1])))
                {
                    vkd3d_free((yyvsp[0].name));
                    YYABORT;
                }
                vkd3d_free((yyvsp[0].name));
                (yyval.block) = (yyvsp[-2].block);
            }
            else if (hlsl_is_numeric_type(node->data_type))
            {
                struct hlsl_ir_node *swizzle;

                if (!(swizzle = get_swizzle(ctx, node, (yyvsp[0].name), &(yylsp[0]))))
                {
                    hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Invalid swizzle \"%s\".", (yyvsp[0].name));
                    vkd3d_free((yyvsp[0].name));
                    YYABORT;
                }
                hlsl_block_add_instr((yyvsp[-2].block), swizzle);
                vkd3d_free((yyvsp[0].name));
                (yyval.block) = (yyvsp[-2].block);
            }
            else
            {
                hlsl_error(ctx, &(yylsp[0]), VKD3D_SHADER_ERROR_HLSL_INVALID_SYNTAX, "Invalid subscript \"%s\".", (yyvsp[0].name));
                vkd3d_free((yyvsp[0].name));
                YYABORT;
            }
        }
#line 11804 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 266: /* postfix_expr: postfix_expr '[' expr ']'  */
#line 8491 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *array = node_from_block((yyvsp[-3].block)), *index = node_from_block((yyvsp[-1].block));

            hlsl_block_add_block((yyvsp[-1].block), (yyvsp[-3].block));
            destroy_block((yyvsp[-3].block));

            if (!add_array_access(ctx, (yyvsp[-1].block), array, index, &(yylsp[-2])))
            {
                destroy_block((yyvsp[-1].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[-1].block);
        }
#line 11822 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 267: /* postfix_expr: var_modifiers type '(' initializer_expr_list ')'  */
#line 8507 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if ((yyvsp[-4].modifiers))
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Modifiers are not allowed on constructors.");
                free_parse_initializer(&(yyvsp[-1].initializer));
                YYABORT;
            }
            if (!hlsl_is_numeric_type((yyvsp[-3].type)))
            {
                struct vkd3d_string_buffer *string;

                if ((string = hlsl_type_to_string(ctx, (yyvsp[-3].type))))
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Constructor data type %s is not numeric.", string->buffer);
                hlsl_release_string_buffer(ctx, string);
                free_parse_initializer(&(yyvsp[-1].initializer));
                YYABORT;
            }
            if ((yyvsp[-3].type)->dimx * (yyvsp[-3].type)->dimy != initializer_size(&(yyvsp[-1].initializer)))
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_WRONG_PARAMETER_COUNT,
                        "Expected %u components in constructor, but got %u.",
                        (yyvsp[-3].type)->dimx * (yyvsp[-3].type)->dimy, initializer_size(&(yyvsp[-1].initializer)));
                free_parse_initializer(&(yyvsp[-1].initializer));
                YYABORT;
            }

            if (!((yyval.block) = add_constructor(ctx, (yyvsp[-3].type), &(yyvsp[-1].initializer), &(yylsp[-3]))))
            {
                free_parse_initializer(&(yyvsp[-1].initializer));
                YYABORT;
            }
        }
#line 11861 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 268: /* postfix_expr: postfix_expr '.' any_identifier '(' func_arguments ')'  */
#line 8542 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *object = node_from_block((yyvsp[-5].block));

            hlsl_block_add_block((yyvsp[-5].block), (yyvsp[-1].initializer).instrs);
            vkd3d_free((yyvsp[-1].initializer).instrs);

            if (!add_method_call(ctx, (yyvsp[-5].block), object, (yyvsp[-3].name), &(yyvsp[-1].initializer), &(yylsp[-3])))
            {
                destroy_block((yyvsp[-5].block));
                vkd3d_free((yyvsp[-1].initializer).args);
                YYABORT;
            }
            vkd3d_free((yyvsp[-1].initializer).args);
            (yyval.block) = (yyvsp[-5].block);
        }
#line 11881 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 270: /* unary_expr: OP_INC unary_expr  */
#line 8561 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!add_increment(ctx, (yyvsp[0].block), false, false, &(yylsp[-1])))
            {
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[0].block);
        }
#line 11894 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 271: /* unary_expr: OP_DEC unary_expr  */
#line 8570 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            if (!add_increment(ctx, (yyvsp[0].block), true, false, &(yylsp[-1])))
            {
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[0].block);
        }
#line 11907 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 272: /* unary_expr: '+' unary_expr  */
#line 8579 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[0].block);
        }
#line 11915 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 273: /* unary_expr: '-' unary_expr  */
#line 8583 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            add_unary_arithmetic_expr(ctx, (yyvsp[0].block), HLSL_OP1_NEG, node_from_block((yyvsp[0].block)), &(yylsp[-1]));
            (yyval.block) = (yyvsp[0].block);
        }
#line 11924 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 274: /* unary_expr: '~' unary_expr  */
#line 8588 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            add_unary_bitwise_expr(ctx, (yyvsp[0].block), HLSL_OP1_BIT_NOT, node_from_block((yyvsp[0].block)), &(yylsp[-1]));
            (yyval.block) = (yyvsp[0].block);
        }
#line 11933 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 275: /* unary_expr: '!' unary_expr  */
#line 8593 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            add_unary_logical_expr(ctx, (yyvsp[0].block), HLSL_OP1_LOGIC_NOT, node_from_block((yyvsp[0].block)), &(yylsp[-1]));
            (yyval.block) = (yyvsp[0].block);
        }
#line 11942 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 276: /* unary_expr: '(' var_modifiers type arrays ')' unary_expr  */
#line 8599 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_type *src_type = node_from_block((yyvsp[0].block))->data_type;
            struct hlsl_type *dst_type;
            unsigned int i;

            if ((yyvsp[-4].modifiers))
            {
                hlsl_error(ctx, &(yylsp[-4]), VKD3D_SHADER_ERROR_HLSL_INVALID_MODIFIER,
                        "Modifiers are not allowed on casts.");
                YYABORT;
            }

            dst_type = (yyvsp[-3].type);
            for (i = 0; i < (yyvsp[-2].arrays).count; ++i)
            {
                if ((yyvsp[-2].arrays).sizes[i] == HLSL_ARRAY_ELEMENTS_COUNT_IMPLICIT)
                {
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE,
                            "Implicit size arrays not allowed in casts.");
                }
                dst_type = hlsl_new_array_type(ctx, dst_type, (yyvsp[-2].arrays).sizes[i]);
            }

            if (!explicit_compatible_data_types(ctx, src_type, dst_type))
            {
                struct vkd3d_string_buffer *src_string, *dst_string;

                src_string = hlsl_type_to_string(ctx, src_type);
                dst_string = hlsl_type_to_string(ctx, dst_type);
                if (src_string && dst_string)
                    hlsl_error(ctx, &(yylsp[-3]), VKD3D_SHADER_ERROR_HLSL_INVALID_TYPE, "Can't cast from %s to %s.",
                            src_string->buffer, dst_string->buffer);
                hlsl_release_string_buffer(ctx, src_string);
                hlsl_release_string_buffer(ctx, dst_string);
                YYABORT;
            }

            if (!add_cast(ctx, (yyvsp[0].block), node_from_block((yyvsp[0].block)), dst_type, &(yylsp[-3])))
            {
                destroy_block((yyvsp[0].block));
                YYABORT;
            }
            (yyval.block) = (yyvsp[0].block);
        }
#line 11991 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 278: /* mul_expr: mul_expr '*' unary_expr  */
#line 8647 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_MUL, &(yylsp[-1]));
        }
#line 11999 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 279: /* mul_expr: mul_expr '/' unary_expr  */
#line 8651 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_DIV, &(yylsp[-1]));
        }
#line 12007 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 280: /* mul_expr: mul_expr '%' unary_expr  */
#line 8655 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_MOD, &(yylsp[-1]));
        }
#line 12015 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 282: /* add_expr: add_expr '+' mul_expr  */
#line 8662 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_ADD, &(yylsp[-1]));
        }
#line 12023 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 283: /* add_expr: add_expr '-' mul_expr  */
#line 8666 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *neg;

            if (!(neg = add_unary_arithmetic_expr(ctx, (yyvsp[0].block), HLSL_OP1_NEG, node_from_block((yyvsp[0].block)), &(yylsp[-1]))))
                YYABORT;
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_ADD, &(yylsp[-1]));
        }
#line 12035 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 285: /* shift_expr: shift_expr OP_LEFTSHIFT add_expr  */
#line 8677 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_LSHIFT, &(yylsp[-1]));
        }
#line 12043 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 286: /* shift_expr: shift_expr OP_RIGHTSHIFT add_expr  */
#line 8681 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_RSHIFT, &(yylsp[-1]));
        }
#line 12051 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 288: /* relational_expr: relational_expr '<' shift_expr  */
#line 8688 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_LESS, &(yylsp[-1]));
        }
#line 12059 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 289: /* relational_expr: relational_expr '>' shift_expr  */
#line 8692 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[0].block), (yyvsp[-2].block), HLSL_OP2_LESS, &(yylsp[-1]));
        }
#line 12067 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 290: /* relational_expr: relational_expr OP_LE shift_expr  */
#line 8696 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[0].block), (yyvsp[-2].block), HLSL_OP2_GEQUAL, &(yylsp[-1]));
        }
#line 12075 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 291: /* relational_expr: relational_expr OP_GE shift_expr  */
#line 8700 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_GEQUAL, &(yylsp[-1]));
        }
#line 12083 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 293: /* equality_expr: equality_expr OP_EQ relational_expr  */
#line 8707 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_EQUAL, &(yylsp[-1]));
        }
#line 12091 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 294: /* equality_expr: equality_expr OP_NE relational_expr  */
#line 8711 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_NEQUAL, &(yylsp[-1]));
        }
#line 12099 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 296: /* bitand_expr: bitand_expr '&' equality_expr  */
#line 8718 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_BIT_AND, &(yylsp[-1]));
        }
#line 12107 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 298: /* bitxor_expr: bitxor_expr '^' bitand_expr  */
#line 8725 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_BIT_XOR, &(yylsp[-1]));
        }
#line 12115 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 300: /* bitor_expr: bitor_expr '|' bitxor_expr  */
#line 8732 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_BIT_OR, &(yylsp[-1]));
        }
#line 12123 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 302: /* logicand_expr: logicand_expr OP_AND bitor_expr  */
#line 8739 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_LOGIC_AND, &(yylsp[-1]));
        }
#line 12131 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 304: /* logicor_expr: logicor_expr OP_OR logicand_expr  */
#line 8746 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = add_binary_expr_merge(ctx, (yyvsp[-2].block), (yyvsp[0].block), HLSL_OP2_LOGIC_OR, &(yylsp[-1]));
        }
#line 12139 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 306: /* conditional_expr: logicor_expr '?' expr ':' assignment_expr  */
#line 8753 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *cond = node_from_block((yyvsp[-4].block));
            struct hlsl_ir_node *first = node_from_block((yyvsp[-2].block));
            struct hlsl_ir_node *second = node_from_block((yyvsp[0].block));

            hlsl_block_add_block((yyvsp[-4].block), (yyvsp[-2].block));
            hlsl_block_add_block((yyvsp[-4].block), (yyvsp[0].block));
            destroy_block((yyvsp[-2].block));
            destroy_block((yyvsp[0].block));

            if (!add_ternary(ctx, (yyvsp[-4].block), cond, first, second))
                YYABORT;
            (yyval.block) = (yyvsp[-4].block);
        }
#line 12158 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 308: /* assignment_expr: unary_expr assign_op assignment_expr  */
#line 8772 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            struct hlsl_ir_node *lhs = node_from_block((yyvsp[-2].block)), *rhs = node_from_block((yyvsp[0].block));

            if (lhs->data_type->modifiers & HLSL_MODIFIER_CONST)
            {
                hlsl_error(ctx, &(yylsp[-1]), VKD3D_SHADER_ERROR_HLSL_MODIFIES_CONST, "Statement modifies a const expression.");
                YYABORT;
            }
            hlsl_block_add_block((yyvsp[0].block), (yyvsp[-2].block));
            destroy_block((yyvsp[-2].block));
            if (!add_assignment(ctx, (yyvsp[0].block), lhs, (yyvsp[-1].assign_op), rhs))
                YYABORT;
            (yyval.block) = (yyvsp[0].block);
        }
#line 12177 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 309: /* assign_op: '='  */
#line 8789 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_ASSIGN;
        }
#line 12185 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 310: /* assign_op: OP_ADDASSIGN  */
#line 8793 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_ADD;
        }
#line 12193 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 311: /* assign_op: OP_SUBASSIGN  */
#line 8797 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_SUB;
        }
#line 12201 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 312: /* assign_op: OP_MULASSIGN  */
#line 8801 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_MUL;
        }
#line 12209 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 313: /* assign_op: OP_DIVASSIGN  */
#line 8805 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_DIV;
        }
#line 12217 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 314: /* assign_op: OP_MODASSIGN  */
#line 8809 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_MOD;
        }
#line 12225 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 315: /* assign_op: OP_LEFTSHIFTASSIGN  */
#line 8813 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_LSHIFT;
        }
#line 12233 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 316: /* assign_op: OP_RIGHTSHIFTASSIGN  */
#line 8817 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_RSHIFT;
        }
#line 12241 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 317: /* assign_op: OP_ANDASSIGN  */
#line 8821 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_AND;
        }
#line 12249 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 318: /* assign_op: OP_ORASSIGN  */
#line 8825 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_OR;
        }
#line 12257 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 319: /* assign_op: OP_XORASSIGN  */
#line 8829 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.assign_op) = ASSIGN_OP_XOR;
        }
#line 12265 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;

  case 321: /* expr: expr ',' assignment_expr  */
#line 8836 "libs/vkd3d/libs/vkd3d-shader/hlsl.y"
        {
            (yyval.block) = (yyvsp[-2].block);
            hlsl_block_add_block((yyval.block), (yyvsp[0].block));
            destroy_block((yyvsp[0].block));
        }
#line 12275 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"
    break;


#line 12279 "libs/vkd3d/libs/vkd3d-shader/hlsl.tab.c"

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
  *++yylsp = yyloc;

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
  yytoken = yychar == HLSL_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
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
        yyerror (&yylloc, scanner, ctx, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= HLSL_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == HLSL_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, ctx);
          yychar = HLSL_YYEMPTY;
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, scanner, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, scanner, ctx, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != HLSL_YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, scanner, ctx);
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

