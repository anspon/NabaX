%{
#define YY_NO_UNISTD_H 1
#define YYERROR_VERBOSE 1



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
#include "Ast/While.h"
#include "Ast/For.h"

#include "Ast/BinaryOperator.h"
#include "Tk/SharedPtr.h"
#include "Ast/Node.h"
#include "CompileError.h"

#include "Parser/Parser.hpp"
#include "Parser/Tokens.h"


extern void 
    ReportError(
        YYLTYPE* location,
        const filesystem::path& pathFile, 
        Tk::Sp<const Naba::Lng::CCompileError>& errorOut, 
        Tk::Sp<const Naba::Lng::Ast::CNode>& expressionOut,
        const char* msg
        );

int yyerror (
    YYLTYPE* location,
    yyscan_t scanner, 
    const filesystem::path& pathFile, 
    Tk::Sp<const Naba::Lng::CCompileError>& errorOut, 
    Tk::Sp<const Naba::Lng::Ast::CNode>& expressionOut,
    const char* msg
    )
{
    ReportError( location, pathFile, errorOut, expressionOut, msg );
    return 0;
}


%}

%code requires {

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

}

%locations
%define api.pure full
%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner }
%parse-param { const filesystem::path& pathFile }
%parse-param { Tk::Sp<const Naba::Lng::CCompileError>& errorOut }
%parse-param { Tk::Sp<const Naba::Lng::Ast::CNode>& expressionOut }

/* Represents the many different ways we can access our data */
%union {
    Naba::Lng::Ast::CNode* m_node;
    Naba::Lng::Ast::CBlock* block;
    Naba::Lng::Ast::CBlock* blockParts;
    Naba::Lng::Ast::CExpression* expr;
    Naba::Lng::Ast::CBlockPart* blockPart;
    Naba::Lng::Ast::CIdentifier* ident;
    Naba::Lng::Ast::CVariableDeclaration* var_decl;
    Naba::Lng::Ast::CFunctionParameter* func_param;
    Tk::SpList<const Naba::Lng::Ast::CVariableDeclaration>* varvec;
    Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>* funcParList;
    Tk::SpList<const Naba::Lng::Ast::CExpression>* exprvec;
    StringToken* stringToken;
    int token;

    Naba::Lng::Ast::CStructPart*     structPart;
    Tk::SpList<const Naba::Lng::Ast::CStructPart>* structParts;
}


/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <stringToken> TIDENTIFIER T_I32 T_I64 TDOUBLE TSTRUCT
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL TWHILE TFOR TVAR
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT 
%token <token> TPLUS TMINUS TMUL TDIV TSEMICOLON TCOLON

%type <ident> ident
%type <expr> numeric expr functionCall
%type <funcParList> func_decl_args
%type <exprvec> call_args
%type <blockParts> blockParts 
%type <blockPart> var_decl func_decl struct blockPart fileScope block assignment exprStatement while for
%type <func_param> func_param
%type <token> binaryOperation
%type <structPart> structPart
%type <structParts> structParts

/* Operator precedence for mathematical operators */
%left TPLUS TMINUS
%left TMUL TDIV

%start fileScope

%%

fileScope : 
    blockParts { expressionOut = Tk::AttachSp($1); }
    ;
      
blockParts : 
    blockPart { $$ = new Naba::Lng::Ast::CBlock(); $$->AddBlockPart($<blockPart>1); } | 
    blockParts blockPart { $1->AddBlockPart($<blockPart>2); }
    ;

blockPart : 
    var_decl | 
    func_decl | 
    struct | 
    exprStatement |
	assignment |
    block |
	while |
	for
    ;

exprStatement : 
	expr TSEMICOLON { $$ = new Naba::Lng::Ast::CExpressionStatement($1); } 

block : 
    TLBRACE blockParts TRBRACE { $$ = $2; } | 
    TLBRACE TRBRACE { $$ = new Naba::Lng::Ast::CBlock(); }
    ;

struct :  
    TSTRUCT ident TLBRACE structParts TRBRACE TSEMICOLON { $$ = new Naba::Lng::Ast::CStruct($2, $4); } |
    TSTRUCT ident TLBRACE TRBRACE TSEMICOLON { $$ = new Naba::Lng::Ast::CStruct($2, nullptr); }
    ;

while:
	TWHILE TLPAREN expr TRPAREN block { $$ = new Naba::Lng::Ast::CWhile(nullptr, $3, $5); } |
	TVAR ident TEQUAL TWHILE TLPAREN expr TRPAREN block { $$ = new Naba::Lng::Ast::CWhile($2, $6, $8); }

for:
	TFOR TLPAREN ident TCOLON expr TRPAREN block { $$ = new Naba::Lng::Ast::CFor(nullptr, $3, $5, $7 ); } | 
	TVAR ident TEQUAL TFOR TLPAREN ident TCOLON expr TRPAREN block { $$ = new Naba::Lng::Ast::CFor($2, $6, $8, $10 ); }

structPart : 
    ident ident TSEMICOLON { $$ = new Naba::Lng::Ast::CStructVariable($1, $2, nullptr); } |
    ident ident TEQUAL expr TSEMICOLON { $$ = new Naba::Lng::Ast::CStructVariable($1, $2, $4); }
    ;

structParts: 
    structPart { $$ = new Tk::SpList<const Naba::Lng::Ast::CStructPart>; $$->push_back(Tk::AttachSp($<structPart>1)); } | 
    structParts structPart { $1->push_back(Tk::AttachSp($<structPart>2)); }
    ;

func_decl : 
    ident ident TLPAREN func_decl_args TRPAREN block { $$ = new Naba::Lng::Ast::CFunction($1, $2, $4, $6); }
    ;
    
func_decl_args : 
    /*blank*/  { $$ = new Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>; } | 
    func_param { $$ = new Tk::SpList<const Naba::Lng::Ast::CFunctionParameter>; $$->push_back(Tk::AttachSp($<func_param>1)); } | 
    func_decl_args TCOMMA func_param { $1->push_back(Tk::AttachSp($<func_param>3)); }
    ;

func_param:
    ident ident { $$ = new Naba::Lng::Ast::CFunctionParameter($1, $2, nullptr); } 
    ;

var_decl : 
    TVAR ident ident TSEMICOLON { $$ = new Naba::Lng::Ast::CVariableDeclaration($2, $3, nullptr); } | 
    TVAR ident TEQUAL expr TSEMICOLON { $$ = new Naba::Lng::Ast::CVariableDeclaration(nullptr, $2, $4); } |
    TVAR ident ident TEQUAL expr TSEMICOLON { $$ = new Naba::Lng::Ast::CVariableDeclaration($2, $3, $5); }
    ;

ident : 
    TIDENTIFIER { $$ = new Naba::Lng::Ast::CIdentifier($1); }
    ;

numeric : 
	T_I64 { $$ = new Naba::Lng::Ast::CInteger64($1);} | 
    T_I32 { $$ = new Naba::Lng::Ast::CInteger32($1);} | 
    TDOUBLE { $$ = new Naba::Lng::Ast::CDouble($1);}
    ;

assignment :
	ident TEQUAL expr TSEMICOLON{ $$ = new Naba::Lng::Ast::CAssignment($<ident>1, $3); } 
	;

    
expr : 
    functionCall | 
    ident { $<ident>$ = $1; } | 
    numeric | 
    expr binaryOperation expr{ $$ = new Naba::Lng::Ast::CBinaryOperator($1, $2, $3); } | 
    TLPAREN expr TRPAREN { $$ = $2; }
    ;




functionCall:
	ident TLPAREN call_args TRPAREN { $$ = new Naba::Lng::Ast::CMethodCall($1, $3); }
    
call_args : 
    /*blank*/  { $$ = new Tk::SpList<const Naba::Lng::Ast::CExpression>; } | 
    expr { $$ = new Tk::SpList<const Naba::Lng::Ast::CExpression>; $$->push_back(Tk::AttachSp($1)); } | 
    call_args TCOMMA expr  { $1->push_back(Tk::AttachSp($3) ); }
    ;

binaryOperation : 
    TCEQ | 
    TCNE | 
    TCLT | 
    TCLE | 
    TCGT | 
    TCGE | 
    TPLUS | 
    TMINUS | 
    TMUL | 
    TDIV
    ;

%%