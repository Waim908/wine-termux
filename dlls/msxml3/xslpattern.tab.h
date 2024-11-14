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

#ifndef YY_XSLPATTERN_DLLS_MSXML3_XSLPATTERN_TAB_H_INCLUDED
# define YY_XSLPATTERN_DLLS_MSXML3_XSLPATTERN_TAB_H_INCLUDED
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


#endif /* !YY_XSLPATTERN_DLLS_MSXML3_XSLPATTERN_TAB_H_INCLUDED  */
