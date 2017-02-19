/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2058 of yacc.c  */
#line 38 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"


#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif



/* Line 2058 of yacc.c  */
#line 56 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.hpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENTIFIER = 258,
     T_I32 = 259,
     T_I64 = 260,
     TDOUBLE = 261,
     TSTRUCT = 262,
     TCEQ = 263,
     TCNE = 264,
     TCLT = 265,
     TCLE = 266,
     TCGT = 267,
     TCGE = 268,
     TEQUAL = 269,
     TLPAREN = 270,
     TRPAREN = 271,
     TLBRACE = 272,
     TRBRACE = 273,
     TCOMMA = 274,
     TDOT = 275,
     TPLUS = 276,
     TMINUS = 277,
     TMUL = 278,
     TDIV = 279,
     TSEMICOLON = 280
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 53 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.y"

    Ast::CNode* m_node;
    Ast::CBlock* block;
    Ast::CBlock* blockParts;
    Ast::CExpression* expr;
    Ast::CBlockPart* blockPart;
    Ast::CIdentifier* ident;
    Ast::CVariableDeclaration* var_decl;
    Ast::CFunctionParameter* func_param;
    Tk::SpList<const Ast::CVariableDeclaration>* varvec;
    Tk::SpList<const Ast::CFunctionParameter>* funcParList;
    Tk::SpList<const Ast::CExpression>* exprvec;
    std::string *string;
    int token;

    Ast::CStructPart*     structPart;
    Tk::SpList<const Ast::CStructPart>* structParts;


/* Line 2058 of yacc.c  */
#line 116 "C:\\dev\\NabaX\\NabaR\\NabaL\\Parser\\Parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (Ast::CNode **expression, yyscan_t scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_C_DEV_NABAX_NABAR_NABAL_PARSER_PARSER_HPP_INCLUDED  */
