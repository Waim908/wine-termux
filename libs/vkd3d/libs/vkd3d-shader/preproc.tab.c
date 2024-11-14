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
#define YYSTYPE         PREPROC_YYSTYPE
#define YYLTYPE         PREPROC_YYLTYPE
/* Substitute the variable and function names.  */
#define yyparse         preproc_yyparse
#define yylex           preproc_yylex
#define yyerror         preproc_yyerror
#define yydebug         preproc_yydebug
#define yynerrs         preproc_yynerrs


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
#ifndef PREPROC_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PREPROC_YYDEBUG 1
#  else
#   define PREPROC_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PREPROC_YYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PREPROC_YYDEBUG */
#if PREPROC_YYDEBUG
extern int preproc_yydebug;
#endif
/* "%code requires" blocks.  */
#line 22 "libs/vkd3d/libs/vkd3d-shader/preproc.y"


#include "vkd3d_shader_private.h"
#include "preproc.h"
#include <stdio.h>
#include <sys/stat.h>

#define PREPROC_YYLTYPE struct vkd3d_shader_location

struct parse_arg_names
{
    char **args;
    size_t count;
};


#line 133 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"

/* Token kinds.  */
#ifndef PREPROC_YYTOKENTYPE
# define PREPROC_YYTOKENTYPE
  enum preproc_yytokentype
  {
    PREPROC_YYEMPTY = -2,
    PREPROC_YYEOF = 0,             /* "end of file"  */
    PREPROC_YYerror = 256,         /* error  */
    PREPROC_YYUNDEF = 257,         /* "invalid token"  */
    T_HASHSTRING = 258,            /* T_HASHSTRING  */
    T_IDENTIFIER = 259,            /* T_IDENTIFIER  */
    T_IDENTIFIER_PAREN = 260,      /* T_IDENTIFIER_PAREN  */
    T_INTEGER = 261,               /* T_INTEGER  */
    T_STRING = 262,                /* T_STRING  */
    T_TEXT = 263,                  /* T_TEXT  */
    T_NEWLINE = 264,               /* T_NEWLINE  */
    T_DEFINE = 265,                /* "#define"  */
    T_ERROR = 266,                 /* "#error"  */
    T_ELIF = 267,                  /* "#elif"  */
    T_ELSE = 268,                  /* "#else"  */
    T_ENDIF = 269,                 /* "#endif"  */
    T_IF = 270,                    /* "#if"  */
    T_IFDEF = 271,                 /* "#ifdef"  */
    T_IFNDEF = 272,                /* "#ifndef"  */
    T_INCLUDE = 273,               /* "#include"  */
    T_LINE = 274,                  /* "#line"  */
    T_PRAGMA = 275,                /* "#pragma"  */
    T_UNDEF = 276,                 /* "#undef"  */
    T_CONCAT = 277,                /* "##"  */
    T_LE = 278,                    /* "<="  */
    T_GE = 279,                    /* ">="  */
    T_EQ = 280,                    /* "=="  */
    T_NE = 281,                    /* "!="  */
    T_AND = 282,                   /* "&&"  */
    T_OR = 283,                    /* "||"  */
    T_DEFINED = 284                /* "defined"  */
  };
  typedef enum preproc_yytokentype preproc_yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined PREPROC_YYSTYPE && ! defined PREPROC_YYSTYPE_IS_DECLARED
union PREPROC_YYSTYPE
{
#line 276 "libs/vkd3d/libs/vkd3d-shader/preproc.y"

    char *string;
    const char *const_string;
    uint32_t integer;
    struct vkd3d_string_buffer string_buffer;
    struct parse_arg_names arg_names;

#line 187 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"

};
typedef union PREPROC_YYSTYPE PREPROC_YYSTYPE;
# define PREPROC_YYSTYPE_IS_TRIVIAL 1
# define PREPROC_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined PREPROC_YYLTYPE && ! defined PREPROC_YYLTYPE_IS_DECLARED
typedef struct PREPROC_YYLTYPE PREPROC_YYLTYPE;
struct PREPROC_YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define PREPROC_YYLTYPE_IS_DECLARED 1
# define PREPROC_YYLTYPE_IS_TRIVIAL 1
#endif




int preproc_yyparse (void *scanner, struct preproc_ctx *ctx);

/* "%code provides" blocks.  */
#line 40 "libs/vkd3d/libs/vkd3d-shader/preproc.y"


int preproc_yylex(PREPROC_YYSTYPE *yylval_param, PREPROC_YYLTYPE *yylloc_param, void *scanner);


#line 221 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_HASHSTRING = 3,               /* T_HASHSTRING  */
  YYSYMBOL_T_IDENTIFIER = 4,               /* T_IDENTIFIER  */
  YYSYMBOL_T_IDENTIFIER_PAREN = 5,         /* T_IDENTIFIER_PAREN  */
  YYSYMBOL_T_INTEGER = 6,                  /* T_INTEGER  */
  YYSYMBOL_T_STRING = 7,                   /* T_STRING  */
  YYSYMBOL_T_TEXT = 8,                     /* T_TEXT  */
  YYSYMBOL_T_NEWLINE = 9,                  /* T_NEWLINE  */
  YYSYMBOL_T_DEFINE = 10,                  /* "#define"  */
  YYSYMBOL_T_ERROR = 11,                   /* "#error"  */
  YYSYMBOL_T_ELIF = 12,                    /* "#elif"  */
  YYSYMBOL_T_ELSE = 13,                    /* "#else"  */
  YYSYMBOL_T_ENDIF = 14,                   /* "#endif"  */
  YYSYMBOL_T_IF = 15,                      /* "#if"  */
  YYSYMBOL_T_IFDEF = 16,                   /* "#ifdef"  */
  YYSYMBOL_T_IFNDEF = 17,                  /* "#ifndef"  */
  YYSYMBOL_T_INCLUDE = 18,                 /* "#include"  */
  YYSYMBOL_T_LINE = 19,                    /* "#line"  */
  YYSYMBOL_T_PRAGMA = 20,                  /* "#pragma"  */
  YYSYMBOL_T_UNDEF = 21,                   /* "#undef"  */
  YYSYMBOL_T_CONCAT = 22,                  /* "##"  */
  YYSYMBOL_T_LE = 23,                      /* "<="  */
  YYSYMBOL_T_GE = 24,                      /* ">="  */
  YYSYMBOL_T_EQ = 25,                      /* "=="  */
  YYSYMBOL_T_NE = 26,                      /* "!="  */
  YYSYMBOL_T_AND = 27,                     /* "&&"  */
  YYSYMBOL_T_OR = 28,                      /* "||"  */
  YYSYMBOL_T_DEFINED = 29,                 /* "defined"  */
  YYSYMBOL_30_ = 30,                       /* ','  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* ']'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '!'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '>'  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_45_ = 45,                       /* '|'  */
  YYSYMBOL_46_ = 46,                       /* '^'  */
  YYSYMBOL_47_ = 47,                       /* '?'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_shader_text = 50,               /* shader_text  */
  YYSYMBOL_identifier_list = 51,           /* identifier_list  */
  YYSYMBOL_body_text = 52,                 /* body_text  */
  YYSYMBOL_body_token = 53,                /* body_token  */
  YYSYMBOL_body_token_const = 54,          /* body_token_const  */
  YYSYMBOL_directive = 55,                 /* directive  */
  YYSYMBOL_primary_expr = 56,              /* primary_expr  */
  YYSYMBOL_unary_expr = 57,                /* unary_expr  */
  YYSYMBOL_mul_expr = 58,                  /* mul_expr  */
  YYSYMBOL_add_expr = 59,                  /* add_expr  */
  YYSYMBOL_ineq_expr = 60,                 /* ineq_expr  */
  YYSYMBOL_eq_expr = 61,                   /* eq_expr  */
  YYSYMBOL_bitand_expr = 62,               /* bitand_expr  */
  YYSYMBOL_bitxor_expr = 63,               /* bitxor_expr  */
  YYSYMBOL_bitor_expr = 64,                /* bitor_expr  */
  YYSYMBOL_logicand_expr = 65,             /* logicand_expr  */
  YYSYMBOL_logicor_expr = 66,              /* logicor_expr  */
  YYSYMBOL_expr = 67                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 47 "libs/vkd3d/libs/vkd3d-shader/preproc.y"


#define YYLLOC_DEFAULT(cur, rhs, n) (cur) = YYRHSLOC(rhs, !!n)

#ifndef S_ISREG
# define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif

static void preproc_error(struct preproc_ctx *ctx, const struct vkd3d_shader_location *loc,
        enum vkd3d_shader_error error, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vkd3d_shader_verror(ctx->message_context, loc, error, format, args);
    va_end(args);
    ctx->error = true;
}

void preproc_warning(struct preproc_ctx *ctx, const struct vkd3d_shader_location *loc,
        enum vkd3d_shader_error error, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vkd3d_shader_vwarning(ctx->message_context, loc, error, format, args);
    va_end(args);
}

static void yyerror(const YYLTYPE *loc, void *scanner, struct preproc_ctx *ctx, const char *string)
{
    preproc_error(ctx, loc, VKD3D_SHADER_ERROR_PP_INVALID_SYNTAX, "%s", string);
}

struct preproc_macro *preproc_find_macro(struct preproc_ctx *ctx, const char *name)
{
    struct rb_entry *entry;

    if ((entry = rb_get(&ctx->macros, name)))
        return RB_ENTRY_VALUE(entry, struct preproc_macro, entry);
    return NULL;
}

bool preproc_add_macro(struct preproc_ctx *ctx, const struct vkd3d_shader_location *loc, char *name, char **arg_names,
        size_t arg_count, const struct vkd3d_shader_location *body_loc, struct vkd3d_string_buffer *body)
{
    struct preproc_macro *macro;
    unsigned int i;
    int ret;

    if ((macro = preproc_find_macro(ctx, name)))
    {
        preproc_warning(ctx, loc, VKD3D_SHADER_WARNING_PP_ALREADY_DEFINED, "Redefinition of %s.", name);
        rb_remove(&ctx->macros, &macro->entry);
        preproc_free_macro(macro);
    }

    TRACE("Defining new macro %s with %zu arguments.\n", debugstr_a(name), arg_count);

    if (!(macro = vkd3d_malloc(sizeof(*macro))))
        return false;
    macro->name = name;
    macro->arg_names = arg_names;
    macro->arg_count = arg_count;
    macro->arg_values = NULL;
    if (arg_count && !(macro->arg_values = vkd3d_calloc(arg_count, sizeof(*macro->arg_values))))
    {
        vkd3d_free(macro);
        return false;
    }
    for (i = 0; i < arg_count; ++i)
        vkd3d_string_buffer_init(&macro->arg_values[i].text);
    macro->body.text = *body;
    macro->body.location = *body_loc;
    ret = rb_put(&ctx->macros, name, &macro->entry);
    VKD3D_ASSERT(!ret);
    return true;
}

void preproc_free_macro(struct preproc_macro *macro)
{
    unsigned int i;

    vkd3d_free(macro->name);
    for (i = 0; i < macro->arg_count; ++i)
    {
        vkd3d_string_buffer_cleanup(&macro->arg_values[i].text);
        vkd3d_free(macro->arg_names[i]);
    }
    vkd3d_free(macro->arg_names);
    vkd3d_free(macro->arg_values);
    vkd3d_string_buffer_cleanup(&macro->body.text);
    vkd3d_free(macro);
}

static bool preproc_was_writing(struct preproc_ctx *ctx)
{
    const struct preproc_file *file = preproc_get_top_file(ctx);

    /* This applies across files, since we can't #include anyway if we weren't
     * writing. */
    if (file->if_count < 2)
        return true;
    return file->if_stack[file->if_count - 2].current_true;
}

static bool preproc_push_if(struct preproc_ctx *ctx, bool condition)
{
    struct preproc_file *file = preproc_get_top_file(ctx);
    struct preproc_if_state *state;

    if (!vkd3d_array_reserve((void **)&file->if_stack, &file->if_stack_size,
            file->if_count + 1, sizeof(*file->if_stack)))
        return false;
    state = &file->if_stack[file->if_count++];
    state->current_true = condition && preproc_was_writing(ctx);
    state->seen_true = condition;
    state->seen_else = false;
    return true;
}

static int default_open_include(const char *filename, bool local,
        const char *parent_data, void *context, struct vkd3d_shader_code *out)
{
    uint8_t *data, *new_data;
    size_t size = 4096;
    struct stat st;
    size_t pos = 0;
    size_t ret;
    FILE *f;

    if (!(f = fopen(filename, "rb")))
    {
        ERR("Unable to open %s for reading.\n", debugstr_a(filename));
        return VKD3D_ERROR;
    }

    if (fstat(fileno(f), &st) == -1)
    {
        ERR("Could not stat file %s.\n", debugstr_a(filename));
        fclose(f);
        return VKD3D_ERROR;
    }

    if (S_ISREG(st.st_mode))
        size = st.st_size;

    if (!(data = vkd3d_malloc(size)))
    {
        fclose(f);
        return VKD3D_ERROR_OUT_OF_MEMORY;
    }

    for (;;)
    {
        if (pos >= size)
        {
            if (size > SIZE_MAX / 2 || !(new_data = vkd3d_realloc(data, size * 2)))
            {
                vkd3d_free(data);
                fclose(f);
                return VKD3D_ERROR_OUT_OF_MEMORY;
            }
            data = new_data;
            size *= 2;
        }

        if (!(ret = fread(&data[pos], 1, size - pos, f)))
            break;
        pos += ret;
    }

    if (!feof(f))
    {
        vkd3d_free(data);
        return VKD3D_ERROR;
    }

    fclose(f);

    out->code = data;
    out->size = pos;

    return VKD3D_OK;
}

static void default_close_include(const struct vkd3d_shader_code *code, void *context)
{
    vkd3d_free((void *)code->code);
}

void preproc_close_include(struct preproc_ctx *ctx, const struct vkd3d_shader_code *code)
{
    PFN_vkd3d_shader_close_include close_include = ctx->preprocess_info->pfn_close_include;

    if (!close_include)
        close_include = default_close_include;

    close_include(code, ctx->preprocess_info->include_context);
}

static const void *get_parent_data(struct preproc_ctx *ctx)
{
    if (ctx->file_count == 1)
        return NULL;
    return preproc_get_top_file(ctx)->code.code;
}

static void free_parse_arg_names(struct parse_arg_names *args)
{
    unsigned int i;

    for (i = 0; i < args->count; ++i)
        vkd3d_free(args->args[i]);
    vkd3d_free(args->args);
}


#line 521 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"

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
         || (defined PREPROC_YYLTYPE_IS_TRIVIAL && PREPROC_YYLTYPE_IS_TRIVIAL \
             && defined PREPROC_YYSTYPE_IS_TRIVIAL && PREPROC_YYSTYPE_IS_TRIVIAL)))

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
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,    39,     2,     2,     2,     2,    44,     2,
      31,    32,    40,    37,    30,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,     2,
      42,     2,    43,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,    45,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if PREPROC_YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   336,   336,   337,   343,   350,   365,   369,   378,   385,
     386,   387,   388,   389,   392,   396,   400,   404,   408,   412,
     416,   420,   424,   428,   432,   436,   440,   444,   448,   452,
     456,   460,   464,   468,   472,   476,   480,   484,   488,   492,
     496,   502,   511,   521,   533,   538,   543,   548,   572,   596,
     606,   610,   615,   647,   652,   660,   665,   670,   675,   680,
     686,   687,   691,   695,   701,   702,   706,   717,   718,   722,
     728,   729,   733,   737,   741,   747,   748,   752,   758,   759,
     765,   766,   772,   773,   779,   780,   786,   787,   793,   794
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
  "\"end of file\"", "error", "\"invalid token\"", "T_HASHSTRING",
  "T_IDENTIFIER", "T_IDENTIFIER_PAREN", "T_INTEGER", "T_STRING", "T_TEXT",
  "T_NEWLINE", "\"#define\"", "\"#error\"", "\"#elif\"", "\"#else\"",
  "\"#endif\"", "\"#if\"", "\"#ifdef\"", "\"#ifndef\"", "\"#include\"",
  "\"#line\"", "\"#pragma\"", "\"#undef\"", "\"##\"", "\"<=\"", "\">=\"",
  "\"==\"", "\"!=\"", "\"&&\"", "\"||\"", "\"defined\"", "','", "'('",
  "')'", "'['", "']'", "'{'", "'}'", "'+'", "'-'", "'!'", "'*'", "'/'",
  "'<'", "'>'", "'&'", "'|'", "'^'", "'?'", "':'", "$accept",
  "shader_text", "identifier_list", "body_text", "body_token",
  "body_token_const", "directive", "primary_expr", "unary_expr",
  "mul_expr", "add_expr", "ineq_expr", "eq_expr", "bitand_expr",
  "bitxor_expr", "bitor_expr", "logicand_expr", "logicor_expr", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -72,    98,   -72,    55,     8,    91,    -1,    44,    91,    53,
      59,    95,    60,   100,   -72,   -72,    90,   117,   -72,   -72,
     -72,    92,    91,    91,    91,    91,   -72,   -72,    21,    27,
      82,   108,    96,    93,    97,   114,   115,     0,   -72,   -72,
       1,   135,   136,   137,     9,   138,    -2,   144,   -72,   -72,
     145,    71,   -72,   -72,   -72,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
     -72,    91,   -72,   -72,   -72,   -72,   141,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,    26,   119,   -72,   -72,   -72,
      21,    21,    27,    27,    27,    27,    82,    82,   108,    96,
      93,    97,   114,    79,   -72,   148,   -72,   -72,    91,   -72,
      46,   115,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     6,     0,     0,    50,    56,
      55,     0,     0,     0,     0,     0,    60,    64,    67,    70,
      75,    78,    80,    82,    84,    86,    88,     0,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    57,
       0,     0,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,    44,    45,    46,    52,     0,    53,    43,     9,
      10,    11,    12,    13,    41,    33,    34,    35,    36,    37,
      38,    39,    40,    20,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,     7,     8,     4,     0,     0,    59,    65,    66,
      68,    69,    73,    74,    71,    72,    76,    77,    79,    81,
      83,    85,    87,     0,    54,     0,     6,    58,     0,     5,
       0,    89,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,    17,   -72,   -72,   -72,   -72,    76,    78,
     -48,    74,    89,    94,    88,    99,    87,   -71,    -3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,   115,    46,   112,   113,    14,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     133,    79,    80,    81,    82,    40,    83,    84,    38,    70,
      72,   122,   123,   124,   125,    17,    76,    18,    77,    51,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    71,    71,    79,
      80,    81,    82,    39,    83,   142,   135,    41,   136,    15,
      16,    55,    56,    42,    57,    58,    44,   141,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    19,    49,    20,     2,    52,
      53,    54,    43,   117,    45,    59,    60,    69,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    71,    13,
      21,    47,    22,    50,    61,    62,    48,   138,    23,    24,
      25,   118,   119,    63,    64,   120,   121,   126,   127,    66,
      65,    68,    67,    69,    73,    74,    75,    78,   114,   116,
     134,   137,   139,   140,   128,   130,   132,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,   131
};

static const yytype_int16 yycheck[] =
{
      71,     3,     4,     5,     6,     8,     8,     9,     9,     9,
       9,    59,    60,    61,    62,     7,     7,     9,     9,    22,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    47,    47,     3,
       4,     5,     6,     9,     8,     9,    30,     4,    32,     4,
       5,    40,    41,     4,    37,    38,     6,   138,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     4,     4,     6,     0,    23,
      24,    25,     7,    32,     4,    23,    24,    28,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    47,    21,
      29,    31,    31,    31,    42,    43,     9,    48,    37,    38,
      39,    55,    56,    25,    26,    57,    58,    63,    64,    46,
      44,    27,    45,    28,     9,     9,     9,     9,     4,     4,
       9,    32,     4,   136,    65,    67,    69,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    21,    55,     4,     5,     7,     9,     4,
       6,    29,    31,    37,    38,    39,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     9,     9,
      67,     4,     4,     7,     6,     4,    52,    31,     9,     4,
      31,    67,    57,    57,    57,    40,    41,    37,    38,    23,
      24,    42,    43,    25,    26,    44,    46,    45,    27,    28,
       9,    47,     9,     9,     9,     9,     7,     9,     9,     3,
       4,     5,     6,     8,     9,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    53,    54,     4,    51,     4,    32,    57,    57,
      58,    58,    59,    59,    59,    59,    60,    60,    61,    62,
      63,    64,    65,    66,     9,    30,    32,    32,    48,     4,
      52,    66,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    58,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     3,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     3,     3,     4,     1,     1,     2,     4,     3,
       1,     2,     2,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PREPROC_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PREPROC_YYEMPTY)                                        \
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
   Use PREPROC_YYerror or PREPROC_YYUNDEF. */
#define YYERRCODE PREPROC_YYUNDEF

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
#if PREPROC_YYDEBUG

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

#  elif defined PREPROC_YYLTYPE_IS_TRIVIAL && PREPROC_YYLTYPE_IS_TRIVIAL

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
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, struct preproc_ctx *ctx)
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner, struct preproc_ctx *ctx)
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
                 int yyrule, void *scanner, struct preproc_ctx *ctx)
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
#else /* !PREPROC_YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PREPROC_YYDEBUG */


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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner, struct preproc_ctx *ctx)
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
yyparse (void *scanner, struct preproc_ctx *ctx)
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
# if defined PREPROC_YYLTYPE_IS_TRIVIAL && PREPROC_YYLTYPE_IS_TRIVIAL
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

  yychar = PREPROC_YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == PREPROC_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= PREPROC_YYEOF)
    {
      yychar = PREPROC_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PREPROC_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PREPROC_YYUNDEF;
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
  yychar = PREPROC_YYEMPTY;
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
  case 3: /* shader_text: shader_text directive  */
#line 338 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            vkd3d_string_buffer_printf(&ctx->buffer, "\n");
        }
#line 1975 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 4: /* identifier_list: T_IDENTIFIER  */
#line 344 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (!((yyval.arg_names).args = vkd3d_malloc(sizeof(*(yyval.arg_names).args))))
                YYABORT;
            (yyval.arg_names).args[0] = (yyvsp[0].string);
            (yyval.arg_names).count = 1;
        }
#line 1986 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 5: /* identifier_list: identifier_list ',' T_IDENTIFIER  */
#line 351 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            char **new_array;

            if (!(new_array = vkd3d_realloc((yyvsp[-2].arg_names).args, ((yyvsp[-2].arg_names).count + 1) * sizeof(*(yyval.arg_names).args))))
            {
                free_parse_arg_names(&(yyvsp[-2].arg_names));
                YYABORT;
            }
            (yyval.arg_names).args = new_array;
            (yyval.arg_names).count = (yyvsp[-2].arg_names).count + 1;
            (yyval.arg_names).args[(yyvsp[-2].arg_names).count] = (yyvsp[0].string);
        }
#line 2003 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 6: /* body_text: %empty  */
#line 366 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            vkd3d_string_buffer_init(&(yyval.string_buffer));
        }
#line 2011 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 7: /* body_text: body_text body_token  */
#line 370 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (vkd3d_string_buffer_printf(&(yyval.string_buffer), "%s ", (yyvsp[0].string)) < 0)
            {
                vkd3d_free((yyvsp[0].string));
                YYABORT;
            }
            vkd3d_free((yyvsp[0].string));
        }
#line 2024 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 8: /* body_text: body_text body_token_const  */
#line 379 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (vkd3d_string_buffer_printf(&(yyval.string_buffer), "%s ", (yyvsp[0].const_string)) < 0)
                YYABORT;
        }
#line 2033 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 14: /* body_token_const: '('  */
#line 393 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "(";
        }
#line 2041 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 15: /* body_token_const: ')'  */
#line 397 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = ")";
        }
#line 2049 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 16: /* body_token_const: '['  */
#line 401 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "[";
        }
#line 2057 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 17: /* body_token_const: ']'  */
#line 405 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "]";
        }
#line 2065 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 18: /* body_token_const: '{'  */
#line 409 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "{";
        }
#line 2073 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 19: /* body_token_const: '}'  */
#line 413 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "}";
        }
#line 2081 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 20: /* body_token_const: ','  */
#line 417 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = ",";
        }
#line 2089 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 21: /* body_token_const: '+'  */
#line 421 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "+";
        }
#line 2097 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 22: /* body_token_const: '-'  */
#line 425 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "-";
        }
#line 2105 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 23: /* body_token_const: '!'  */
#line 429 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "!";
        }
#line 2113 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 24: /* body_token_const: '*'  */
#line 433 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "*";
        }
#line 2121 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 25: /* body_token_const: '/'  */
#line 437 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "/";
        }
#line 2129 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 26: /* body_token_const: '<'  */
#line 441 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "<";
        }
#line 2137 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 27: /* body_token_const: '>'  */
#line 445 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = ">";
        }
#line 2145 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 28: /* body_token_const: '&'  */
#line 449 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "&";
        }
#line 2153 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 29: /* body_token_const: '|'  */
#line 453 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "|";
        }
#line 2161 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 30: /* body_token_const: '^'  */
#line 457 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "^";
        }
#line 2169 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 31: /* body_token_const: '?'  */
#line 461 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "?";
        }
#line 2177 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 32: /* body_token_const: ':'  */
#line 465 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = ":";
        }
#line 2185 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 33: /* body_token_const: "##"  */
#line 469 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "##";
        }
#line 2193 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 34: /* body_token_const: "<="  */
#line 473 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "<=";
        }
#line 2201 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 35: /* body_token_const: ">="  */
#line 477 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = ">=";
        }
#line 2209 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 36: /* body_token_const: "=="  */
#line 481 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "==";
        }
#line 2217 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 37: /* body_token_const: "!="  */
#line 485 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "!=";
        }
#line 2225 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 38: /* body_token_const: "&&"  */
#line 489 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "&&";
        }
#line 2233 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 39: /* body_token_const: "||"  */
#line 493 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "||";
        }
#line 2241 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 40: /* body_token_const: "defined"  */
#line 497 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.const_string) = "defined";
        }
#line 2249 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 41: /* directive: "#define" T_IDENTIFIER body_text T_NEWLINE  */
#line 503 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (!preproc_add_macro(ctx, &(yyloc), (yyvsp[-2].string), NULL, 0, &(yylsp[-1]), &(yyvsp[-1].string_buffer)))
            {
                vkd3d_free((yyvsp[-2].string));
                vkd3d_string_buffer_cleanup(&(yyvsp[-1].string_buffer));
                YYABORT;
            }
        }
#line 2262 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 42: /* directive: "#define" T_IDENTIFIER_PAREN '(' identifier_list ')' body_text T_NEWLINE  */
#line 512 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (!preproc_add_macro(ctx, &(yylsp[-1]), (yyvsp[-5].string), (yyvsp[-3].arg_names).args, (yyvsp[-3].arg_names).count, &(yylsp[-1]), &(yyvsp[-1].string_buffer)))
            {
                vkd3d_free((yyvsp[-5].string));
                free_parse_arg_names(&(yyvsp[-3].arg_names));
                vkd3d_string_buffer_cleanup(&(yyvsp[-1].string_buffer));
                YYABORT;
            }
        }
#line 2276 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 43: /* directive: "#undef" T_IDENTIFIER T_NEWLINE  */
#line 522 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            struct preproc_macro *macro;

            if ((macro = preproc_find_macro(ctx, (yyvsp[-1].string))))
            {
                TRACE("Removing macro definition %s.\n", debugstr_a((yyvsp[-1].string)));
                rb_remove(&ctx->macros, &macro->entry);
                preproc_free_macro(macro);
            }
            vkd3d_free((yyvsp[-1].string));
        }
#line 2292 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 44: /* directive: "#if" expr T_NEWLINE  */
#line 534 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (!preproc_push_if(ctx, !!(yyvsp[-1].integer)))
                YYABORT;
        }
#line 2301 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 45: /* directive: "#ifdef" T_IDENTIFIER T_NEWLINE  */
#line 539 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            preproc_push_if(ctx, !!preproc_find_macro(ctx, (yyvsp[-1].string)));
            vkd3d_free((yyvsp[-1].string));
        }
#line 2310 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 46: /* directive: "#ifndef" T_IDENTIFIER T_NEWLINE  */
#line 544 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            preproc_push_if(ctx, !preproc_find_macro(ctx, (yyvsp[-1].string)));
            vkd3d_free((yyvsp[-1].string));
        }
#line 2319 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 47: /* directive: "#elif" expr T_NEWLINE  */
#line 549 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            const struct preproc_file *file = preproc_get_top_file(ctx);

            if (file->if_count)
            {
                struct preproc_if_state *state = &file->if_stack[file->if_count - 1];

                if (state->seen_else)
                {
                    preproc_warning(ctx, &(yyloc), VKD3D_SHADER_WARNING_PP_INVALID_DIRECTIVE, "Ignoring #elif after #else.");
                }
                else
                {
                    state->current_true = (yyvsp[-1].integer) && !state->seen_true && preproc_was_writing(ctx);
                    state->seen_true = (yyvsp[-1].integer) || state->seen_true;
                }
            }
            else
            {
                preproc_warning(ctx, &(yyloc), VKD3D_SHADER_WARNING_PP_INVALID_DIRECTIVE,
                        "Ignoring #elif without prior #if.");
            }
        }
#line 2347 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 48: /* directive: "#else" T_NEWLINE  */
#line 573 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            const struct preproc_file *file = preproc_get_top_file(ctx);

            if (file->if_count)
            {
                struct preproc_if_state *state = &file->if_stack[file->if_count - 1];

                if (state->seen_else)
                {
                    preproc_warning(ctx, &(yyloc), VKD3D_SHADER_WARNING_PP_INVALID_DIRECTIVE, "Ignoring #else after #else.");
                }
                else
                {
                    state->current_true = !state->seen_true && preproc_was_writing(ctx);
                    state->seen_else = true;
                }
            }
            else
            {
                preproc_warning(ctx, &(yyloc), VKD3D_SHADER_WARNING_PP_INVALID_DIRECTIVE,
                        "Ignoring #else without prior #if.");
            }
        }
#line 2375 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 49: /* directive: "#endif" T_NEWLINE  */
#line 597 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            struct preproc_file *file = preproc_get_top_file(ctx);

            if (file->if_count)
                --file->if_count;
            else
                preproc_warning(ctx, &(yyloc), VKD3D_SHADER_WARNING_PP_INVALID_DIRECTIVE,
                        "Ignoring #endif without prior #if.");
        }
#line 2389 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 50: /* directive: "#error" T_NEWLINE  */
#line 607 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            preproc_error(ctx, &(yyloc), VKD3D_SHADER_ERROR_PP_ERROR_DIRECTIVE, "Error directive.");
        }
#line 2397 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 51: /* directive: "#error" T_STRING T_NEWLINE  */
#line 611 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            preproc_error(ctx, &(yyloc), VKD3D_SHADER_ERROR_PP_ERROR_DIRECTIVE, "Error directive: %s", (yyvsp[-1].string));
            vkd3d_free((yyvsp[-1].string));
        }
#line 2406 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 52: /* directive: "#include" T_STRING T_NEWLINE  */
#line 616 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            PFN_vkd3d_shader_open_include open_include = ctx->preprocess_info->pfn_open_include;
            struct vkd3d_shader_code code;
            char *filename;
            int result;

            if (!(filename = vkd3d_malloc(strlen((yyvsp[-1].string)) - 1)))
                YYABORT;

            if (!open_include)
                open_include = default_open_include;

            memcpy(filename, (yyvsp[-1].string) + 1, strlen((yyvsp[-1].string)) - 2);
            filename[strlen((yyvsp[-1].string)) - 2] = 0;

            if (!(result = open_include(filename, (yyvsp[-1].string)[0] == '"', get_parent_data(ctx),
                    ctx->preprocess_info->include_context, &code)))
            {
                if (!preproc_push_include(ctx, filename, &code))
                {
                    preproc_close_include(ctx, &code);
                    vkd3d_free(filename);
                }
            }
            else
            {
                preproc_error(ctx, &(yyloc), VKD3D_SHADER_ERROR_PP_INCLUDE_FAILED, "Failed to open %s.", (yyvsp[-1].string));
                vkd3d_free(filename);
            }
            vkd3d_free((yyvsp[-1].string));
        }
#line 2442 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 53: /* directive: "#line" T_INTEGER T_NEWLINE  */
#line 648 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            FIXME("#line directive.\n");
            vkd3d_free((yyvsp[-1].string));
        }
#line 2451 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 54: /* directive: "#line" T_INTEGER T_STRING T_NEWLINE  */
#line 653 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            FIXME("#line directive.\n");
            vkd3d_free((yyvsp[-2].string));
            vkd3d_free((yyvsp[-1].string));
        }
#line 2461 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 55: /* primary_expr: T_INTEGER  */
#line 661 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = vkd3d_parse_integer((yyvsp[0].string));
            vkd3d_free((yyvsp[0].string));
        }
#line 2470 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 56: /* primary_expr: T_IDENTIFIER  */
#line 666 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = 0;
            vkd3d_free((yyvsp[0].string));
        }
#line 2479 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 57: /* primary_expr: "defined" T_IDENTIFIER  */
#line 671 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = !!preproc_find_macro(ctx, (yyvsp[0].string));
            vkd3d_free((yyvsp[0].string));
        }
#line 2488 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 58: /* primary_expr: "defined" '(' T_IDENTIFIER ')'  */
#line 676 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = !!preproc_find_macro(ctx, (yyvsp[-1].string));
            vkd3d_free((yyvsp[-1].string));
        }
#line 2497 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 59: /* primary_expr: '(' expr ')'  */
#line 681 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-1].integer);
        }
#line 2505 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 61: /* unary_expr: '+' unary_expr  */
#line 688 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[0].integer);
        }
#line 2513 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 62: /* unary_expr: '-' unary_expr  */
#line 692 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = -(yyvsp[0].integer);
        }
#line 2521 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 63: /* unary_expr: '!' unary_expr  */
#line 696 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = !(yyvsp[0].integer);
        }
#line 2529 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 65: /* mul_expr: mul_expr '*' unary_expr  */
#line 703 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) * (yyvsp[0].integer);
        }
#line 2537 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 66: /* mul_expr: mul_expr '/' unary_expr  */
#line 707 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            if (!(yyvsp[0].integer))
            {
                preproc_warning(ctx, &(yylsp[0]), VKD3D_SHADER_WARNING_PP_DIV_BY_ZERO, "Division by zero.");
                (yyvsp[0].integer) = 1;
            }
            (yyval.integer) = (yyvsp[-2].integer) / (yyvsp[0].integer);
        }
#line 2550 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 68: /* add_expr: add_expr '+' mul_expr  */
#line 719 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) + (yyvsp[0].integer);
        }
#line 2558 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 69: /* add_expr: add_expr '-' mul_expr  */
#line 723 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) - (yyvsp[0].integer);
        }
#line 2566 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 71: /* ineq_expr: ineq_expr '<' add_expr  */
#line 730 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) < (yyvsp[0].integer);
        }
#line 2574 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 72: /* ineq_expr: ineq_expr '>' add_expr  */
#line 734 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) > (yyvsp[0].integer);
        }
#line 2582 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 73: /* ineq_expr: ineq_expr "<=" add_expr  */
#line 738 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) <= (yyvsp[0].integer);
        }
#line 2590 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 74: /* ineq_expr: ineq_expr ">=" add_expr  */
#line 742 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) >= (yyvsp[0].integer);
        }
#line 2598 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 76: /* eq_expr: eq_expr "==" ineq_expr  */
#line 749 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) == (yyvsp[0].integer);
        }
#line 2606 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 77: /* eq_expr: eq_expr "!=" ineq_expr  */
#line 753 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) != (yyvsp[0].integer);
        }
#line 2614 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 79: /* bitand_expr: bitand_expr '&' eq_expr  */
#line 760 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) & (yyvsp[0].integer);
        }
#line 2622 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 81: /* bitxor_expr: bitxor_expr '^' bitand_expr  */
#line 767 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) ^ (yyvsp[0].integer);
        }
#line 2630 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 83: /* bitor_expr: bitor_expr '|' bitxor_expr  */
#line 774 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) | (yyvsp[0].integer);
        }
#line 2638 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 85: /* logicand_expr: logicand_expr "&&" bitor_expr  */
#line 781 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) && (yyvsp[0].integer);
        }
#line 2646 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 87: /* logicor_expr: logicor_expr "||" logicand_expr  */
#line 788 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-2].integer) || (yyvsp[0].integer);
        }
#line 2654 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;

  case 89: /* expr: expr '?' logicor_expr ':' logicor_expr  */
#line 795 "libs/vkd3d/libs/vkd3d-shader/preproc.y"
        {
            (yyval.integer) = (yyvsp[-4].integer) ? (yyvsp[-2].integer) : (yyvsp[0].integer);
        }
#line 2662 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"
    break;


#line 2666 "libs/vkd3d/libs/vkd3d-shader/preproc.tab.c"

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
  yytoken = yychar == PREPROC_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= PREPROC_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PREPROC_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, scanner, ctx);
          yychar = PREPROC_YYEMPTY;
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
  if (yychar != PREPROC_YYEMPTY)
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

