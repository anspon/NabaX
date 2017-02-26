
%{
#define YY_NO_UNISTD_H 1
#include "CompileError.h"
#include "Ast/Node.h"
#include "Ast/Block.h"
#include "Ast/Identifier.h"
#include "Ast/Struct.h"
#include "Ast/StructVariable.h"
#include "Ast/ExpressionStatement.h"
#include "Ast/Function.h"
#include "Ast/FunctionParameter.h"
#include "Ast/Integer32.h"
#include "Ast/Integer64.h"
#include "Ast/Double.h"
#include "Ast/VariableDeclaration.h"
#include "Ast/MethodCall.h"
#include "Ast/Assignment.h"
#include "Ast/BinaryOperator.h"
#include "Parser/Parser.hpp"
extern void NewLine( YYSTYPE* yylval, unsigned int line , int col );
extern void SaveToken( YYSTYPE* yylval, const char* text , int len );
#define SAVE_TOKEN SaveToken( yylval, yytext, yyleng)
#define NEW_LINE NewLine( yylval, yylineno, yycolumn)
#define TOKEN(t) (yylval->token = t)
//extern "C" int yywrap() { }

#define YY_USER_ACTION \
    {\
        yylloc->first_line = yylineno; \
        yylloc->first_column = yycolumn;\
        yylloc->last_column=yycolumn;\
        yylloc->last_line = yylineno;\
    }

%}


/*%option outfile="Lexer.c" header-file="Lexer.h"
*/
%option warn nodefault
%option yylineno
%option reentrant noyywrap never-interactive nounistd
%option bison-bridge
%option bison-locations 
%%

[\n]                 NEW_LINE;
[ \t]                 ;
"struct"                return TOKEN(TSTRUCT);
[a-zA-Z_][a-zA-Z0-9\_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9][0-9\_]*(\.)?[0-9\_]*d      SAVE_TOKEN; return TDOUBLE;
[0-9][0-9\_]*i32             SAVE_TOKEN; return T_I32;
[0-9][0-9\_]*i64               SAVE_TOKEN; return T_I64;
[0-9][0-9\_]*               SAVE_TOKEN; return T_I32;
";"                     return TOKEN(TSEMICOLON);
"="                     return TOKEN(TEQUAL);
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);
"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"."                     return TOKEN(TDOT);
","                     return TOKEN(TCOMMA);
"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
.                       printf("Unknown token!n"); yyterminate();

%%
