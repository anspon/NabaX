#include "NabaLPch.h"
#include "Module.h"
#include "Tk/Exception.h"

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
#include "Parser/Tokens.h"

#include "TranslationUnit.h"
#include "CompileError.h"
#include "Tk/FilePosition.h"

void  SaveStringToken(YYSTYPE* yylval, const char* text, int len, unsigned int lineNbr)
{
    yylval->stringToken = new StringToken{std::string(text, len), CPosition(lineNbr) };
}
void  NewLine(YYSTYPE* yylval, unsigned int line, int col)
{
    int i=0;i++;
}

void ReportError(
    YYLTYPE* location,
    const filesystem::path& pathFile, 
    Tk::Sp<const NabaL::CCompileError>& errorOut, 
    Tk::Sp<const Ast::CNode>& expressionOut,
    const char* msg
    )
{
    Tk::Sp<const Tk::CFilePosition>  filePosition = Tk::MakeSp<Tk::CFilePosition>(pathFile, location->first_line+1, location->first_column );
    errorOut = Tk::MakeSp<NabaL::CCompileError>( NabaL::eCompileError::SyntaxError, msg, filePosition );
//    errorOut = error;
}

namespace NabaL
{

Tk::Sp<const Ast::CNode> getAST(
    const filesystem::path& pathFile,
    const std::string& expression
    )
{
    Tk::Sp<const Ast::CNode> rootNode;
    Tk::Sp<const CCompileError> errorOut;

    yyscan_t scanner = 0;
    YY_BUFFER_STATE state = 0;

    if (yylex_init(&scanner))
    {
        // couldn't initialize
        return NULL;
    }
   // yylineno = 0;

    state = yy_scan_string(expression.c_str(), scanner);
    state->yy_bs_lineno =0;
    state->yy_bs_column =0;

    yyparse(scanner, pathFile, errorOut, rootNode);
    yy_delete_buffer(state, scanner);
    yylex_destroy(scanner);

    if( nullptr != errorOut)
    {
        throw errorOut;
    }
    return rootNode;
}

Tk::Sp<const CModule>
    ParseModule(
        const std::string& sourceFolder
        )
{
    Tk::SpList<const CTranslationUnit> translationUnits;

    const filesystem::path sourcePath(sourceFolder.c_str() );
    std::string moduleName = sourcePath.stem().string();

    filesystem::directory_iterator sourceIterator(sourceFolder);
    TK_ASSERT( filesystem::directory_iterator() != sourceIterator, "Invalid source directory '" << sourceFolder << "' ");

    for( const filesystem::directory_entry& entry : sourceIterator )
    {
        const filesystem::path& pathFile = entry.path();
        const filesystem::path fileName = pathFile.stem().string();

        std::list<std::string> nameSpacePath = {};

        if( std::string(".aspp") == pathFile.extension() )
        {
            int i=0;i++;
            std::string completeText;
            {            
                std::ifstream inFile( pathFile );
                TK_ASSERT( !inFile.bad(), "Unable to open file '" << pathFile << "'" );
                char line[1000] = {0};
                while( inFile.getline(line, 999) )
                {
                    completeText += line + std::string("\n");
                }
            }

            Tk::SpList<const CCompileError> errors;

            Tk::Sp<const Ast::CNode> node;
            try
            {
                 node = getAST(pathFile, completeText.c_str() );
            }
            catch( Tk::Sp<const CCompileError> error )
            {
                errors.push_back(error);
            }
            Tk::Sp<const CTranslationUnit> unit = Tk::MakeSp<CTranslationUnit>(nameSpacePath, node, pathFile, errors );
            translationUnits.push_back(unit);
        }        
    }
    return Tk::MakeSp<CModule>(moduleName, translationUnits);
}

}
