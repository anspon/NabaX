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
        Tk::Sp<const NabaL::CCompileError>& errorOut, 
        Tk::Sp<const Ast::CNode>& expressionOut,
        const char* msg
        );

int yyerror (
    YYLTYPE* location,
    yyscan_t scanner, 
    const filesystem::path& pathFile, 
    Tk::Sp<const NabaL::CCompileError>& errorOut, 
    Tk::Sp<const Ast::CNode>& expressionOut,
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
%parse-param { Tk::Sp<const NabaL::CCompileError>& errorOut }
%parse-param { Tk::Sp<const Ast::CNode>& expressionOut }

/* Represents the many different ways we can access our data */
%union {
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
    StringToken* stringToken;
    int token;

    Ast::CStructPart*     structPart;
    Tk::SpList<const Ast::CStructPart>* structParts;
}


/* Define our terminal symbols (tokens). This should
   match our tokens.l lex file. We also define the node type
   they represent.
 */
%token <stringToken> TIDENTIFIER T_I32 T_I64 TDOUBLE TSTRUCT
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT 
%token <token> TPLUS TMINUS TMUL TDIV TSEMICOLON

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */
%type <ident> ident
%type <expr> numeric expr 
%type <funcParList> func_decl_args
%type <exprvec> call_args
%type <blockParts> blockParts 
%type <blockPart> var_decl func_decl struct blockPart fileScope block assignment exprStatement
%type <func_param> func_param
%type <token> comparison
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
    blockPart { $$ = new Ast::CBlock(); $$->AddBlockPart($<blockPart>1); } | 
    blockParts blockPart { $1->AddBlockPart($<blockPart>2); }
    ;

blockPart : 
    var_decl | 
    func_decl | 
    struct | 
    exprStatement |
	assignment |
    block 
    ;

exprStatement : 
	expr TSEMICOLON { $$ = new Ast::CExpressionStatement($1); } 

block : 
    TLBRACE blockParts TRBRACE { $$ = $2; } | 
    TLBRACE TRBRACE { $$ = new Ast::CBlock(); }
    ;

struct :  
    TSTRUCT ident TLBRACE structParts TRBRACE TSEMICOLON { $$ = new Ast::CStruct($2, $4); } |
    TSTRUCT ident TLBRACE TRBRACE TSEMICOLON { $$ = new Ast::CStruct($2, nullptr); }
    ;

structPart : 
    ident ident TSEMICOLON { $$ = new Ast::CStructVariable($1, $2, nullptr); } |
    ident ident TEQUAL expr TSEMICOLON { $$ = new Ast::CStructVariable($1, $2, $4); }
    ;

structParts: 
    structPart { $$ = new Tk::SpList<const Ast::CStructPart>; $$->push_back(Tk::AttachSp($<structPart>1)); } | 
    structParts structPart { $1->push_back(Tk::AttachSp($<structPart>2)); }
    ;

func_decl : 
    ident ident TLPAREN func_decl_args TRPAREN block { $$ = new Ast::CFunction($1, $2, $4, $6); }
    ;
    
func_decl_args : 
    /*blank*/  { $$ = new Tk::SpList<const Ast::CFunctionParameter>; } | 
    func_param { $$ = new Tk::SpList<const Ast::CFunctionParameter>; $$->push_back(Tk::AttachSp($<func_param>1)); } | 
    func_decl_args TCOMMA func_param { $1->push_back(Tk::AttachSp($<func_param>3)); }
    ;

func_param:
    ident ident { $$ = new Ast::CFunctionParameter($1, $2, nullptr); } 
    ;

var_decl : 
    ident ident TSEMICOLON { $$ = new Ast::CVariableDeclaration($1, $2, nullptr); } | 
    ident ident TEQUAL expr TSEMICOLON { $$ = new Ast::CVariableDeclaration($1, $2, $4); }
    ;

ident : 
    TIDENTIFIER { $$ = new Ast::CIdentifier($1); }
    ;

numeric : 
	T_I64 { $$ = new Ast::CInteger64($1);} | 
    T_I32 { $$ = new Ast::CInteger32($1);} | 
    TDOUBLE { $$ = new Ast::CDouble($1);}
    ;

assignment :
	ident TEQUAL expr TSEMICOLON{ $$ = new Ast::CAssignment($<ident>1, $3); } 
	;
    
expr : 
    ident TLPAREN call_args TRPAREN { $$ = new Ast::CMethodCall($1, $3); } | 
    ident { $<ident>$ = $1; } | 
    numeric | 
    expr comparison expr{ $$ = new Ast::CBinaryOperator($1, $2, $3); } | 
    TLPAREN expr TRPAREN { $$ = $2; }
    ;
    
call_args : 
    /*blank*/  { $$ = new Tk::SpList<const Ast::CExpression>; } | 
    expr { $$ = new Tk::SpList<const Ast::CExpression>; $$->push_back(Tk::AttachSp($1)); } | 
    call_args TCOMMA expr  { $1->push_back(Tk::AttachSp($3) ); }
    ;

comparison : 
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