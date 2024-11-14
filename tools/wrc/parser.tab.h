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

#ifndef YY_PARSER_TOOLS_WRC_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WRC_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    PARSER_EMPTY = -2,
    PARSER_EOF = 0,                /* "end of file"  */
    PARSER_error = 256,            /* error  */
    PARSER_UNDEF = 257,            /* "invalid token"  */
    tNL = 258,                     /* tNL  */
    tNUMBER = 259,                 /* tNUMBER  */
    tLNUMBER = 260,                /* tLNUMBER  */
    tSTRING = 261,                 /* tSTRING  */
    tIDENT = 262,                  /* tIDENT  */
    tRAWDATA = 263,                /* tRAWDATA  */
    tACCELERATORS = 264,           /* tACCELERATORS  */
    tBITMAP = 265,                 /* tBITMAP  */
    tCURSOR = 266,                 /* tCURSOR  */
    tDIALOG = 267,                 /* tDIALOG  */
    tDIALOGEX = 268,               /* tDIALOGEX  */
    tMENU = 269,                   /* tMENU  */
    tMENUEX = 270,                 /* tMENUEX  */
    tMESSAGETABLE = 271,           /* tMESSAGETABLE  */
    tRCDATA = 272,                 /* tRCDATA  */
    tVERSIONINFO = 273,            /* tVERSIONINFO  */
    tSTRINGTABLE = 274,            /* tSTRINGTABLE  */
    tFONT = 275,                   /* tFONT  */
    tFONTDIR = 276,                /* tFONTDIR  */
    tICON = 277,                   /* tICON  */
    tHTML = 278,                   /* tHTML  */
    tAUTO3STATE = 279,             /* tAUTO3STATE  */
    tAUTOCHECKBOX = 280,           /* tAUTOCHECKBOX  */
    tAUTORADIOBUTTON = 281,        /* tAUTORADIOBUTTON  */
    tCHECKBOX = 282,               /* tCHECKBOX  */
    tDEFPUSHBUTTON = 283,          /* tDEFPUSHBUTTON  */
    tPUSHBUTTON = 284,             /* tPUSHBUTTON  */
    tRADIOBUTTON = 285,            /* tRADIOBUTTON  */
    tSTATE3 = 286,                 /* tSTATE3  */
    tGROUPBOX = 287,               /* tGROUPBOX  */
    tCOMBOBOX = 288,               /* tCOMBOBOX  */
    tLISTBOX = 289,                /* tLISTBOX  */
    tSCROLLBAR = 290,              /* tSCROLLBAR  */
    tCONTROL = 291,                /* tCONTROL  */
    tEDITTEXT = 292,               /* tEDITTEXT  */
    tRTEXT = 293,                  /* tRTEXT  */
    tCTEXT = 294,                  /* tCTEXT  */
    tLTEXT = 295,                  /* tLTEXT  */
    tBLOCK = 296,                  /* tBLOCK  */
    tVALUE = 297,                  /* tVALUE  */
    tSHIFT = 298,                  /* tSHIFT  */
    tALT = 299,                    /* tALT  */
    tASCII = 300,                  /* tASCII  */
    tVIRTKEY = 301,                /* tVIRTKEY  */
    tGRAYED = 302,                 /* tGRAYED  */
    tCHECKED = 303,                /* tCHECKED  */
    tINACTIVE = 304,               /* tINACTIVE  */
    tNOINVERT = 305,               /* tNOINVERT  */
    tPURE = 306,                   /* tPURE  */
    tIMPURE = 307,                 /* tIMPURE  */
    tDISCARDABLE = 308,            /* tDISCARDABLE  */
    tLOADONCALL = 309,             /* tLOADONCALL  */
    tPRELOAD = 310,                /* tPRELOAD  */
    tFIXED = 311,                  /* tFIXED  */
    tMOVEABLE = 312,               /* tMOVEABLE  */
    tCLASS = 313,                  /* tCLASS  */
    tCAPTION = 314,                /* tCAPTION  */
    tCHARACTERISTICS = 315,        /* tCHARACTERISTICS  */
    tEXSTYLE = 316,                /* tEXSTYLE  */
    tSTYLE = 317,                  /* tSTYLE  */
    tVERSION = 318,                /* tVERSION  */
    tLANGUAGE = 319,               /* tLANGUAGE  */
    tFILEVERSION = 320,            /* tFILEVERSION  */
    tPRODUCTVERSION = 321,         /* tPRODUCTVERSION  */
    tFILEFLAGSMASK = 322,          /* tFILEFLAGSMASK  */
    tFILEOS = 323,                 /* tFILEOS  */
    tFILETYPE = 324,               /* tFILETYPE  */
    tFILEFLAGS = 325,              /* tFILEFLAGS  */
    tFILESUBTYPE = 326,            /* tFILESUBTYPE  */
    tMENUBARBREAK = 327,           /* tMENUBARBREAK  */
    tMENUBREAK = 328,              /* tMENUBREAK  */
    tMENUITEM = 329,               /* tMENUITEM  */
    tPOPUP = 330,                  /* tPOPUP  */
    tSEPARATOR = 331,              /* tSEPARATOR  */
    tHELP = 332,                   /* tHELP  */
    tTOOLBAR = 333,                /* tTOOLBAR  */
    tBUTTON = 334,                 /* tBUTTON  */
    tBEGIN = 335,                  /* tBEGIN  */
    tEND = 336,                    /* tEND  */
    tDLGINIT = 337,                /* tDLGINIT  */
    tNOT = 338,                    /* tNOT  */
    pUPM = 339                     /* pUPM  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 208 "tools/wrc/parser.y"

	string_t	*str;
	int		num;
	int		*iptr;
	char		*cptr;
	resource_t	*res;
	accelerator_t	*acc;
	bitmap_t	*bmp;
	dialog_t	*dlg;
	font_t		*fnt;
	fontdir_t	*fnd;
	menu_t		*men;
	html_t		*html;
	rcdata_t	*rdt;
	stringtable_t	*stt;
	stt_entry_t	*stte;
	user_t		*usr;
	messagetable_t	*msg;
	versioninfo_t	*veri;
	control_t	*ctl;
	name_id_t	*nid;
	font_id_t	*fntid;
	language_t	lan;
	version_t	ver;
	characts_t	chars;
	event_t		*event;
	menu_item_t	*menitm;
	itemex_opt_t	*exopt;
	raw_data_t	*raw;
	lvc_t		*lvc;
	ver_value_t	*val;
	ver_block_t	*blk;
	ver_words_t	*verw;
	toolbar_t	*tlbar;
	toolbar_item_t	*tlbarItems;
	dlginit_t       *dginit;
	style_pair_t	*styles;
	style_t		*style;
	ani_any_t	*ani;

#line 197 "tools/wrc/parser.tab.h"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif


extern PARSER_STYPE parser_lval;


int parser_parse (void);


#endif /* !YY_PARSER_TOOLS_WRC_PARSER_TAB_H_INCLUDED  */
