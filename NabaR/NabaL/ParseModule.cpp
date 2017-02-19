#include "NabaLPch.h"
#include "Module.h"
#include "Tk/Exception.h"

#define YY_NO_UNISTD_H 1

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


void  SaveToken(YYSTYPE* yylval, const char* text, int len)
{
    yylval->string = new std::string(text, len);
}

void ReportError(const char* error)
{
    std::cout << error << std::endl;
}

namespace 
{


Tk::Sp<const Ast::CNode> getAST(const std::string& expression)
{
    Ast::CNode* rootNode = 0;
    yyscan_t scanner = 0;
    YY_BUFFER_STATE state = 0;

    if (yylex_init(&scanner))
    {
        // couldn't initialize
        return NULL;
    }

    state = yy_scan_string(expression.c_str(), scanner);

    if( yyparse(&rootNode, scanner) )
    {
        // error parsing
        return NULL;
    }

    yy_delete_buffer(state, scanner);

    yylex_destroy(scanner);

    return Tk::AttachSp(rootNode);
}


}
namespace NabaL
{


Tk::Sp<const CModule>
    ParseModule(
        const std::string& sourceFolder
        )
{
    Tk::Sp<const CModule> module = Tk::MakeSp<CModule>();

    const filesystem::path sourcePath(sourceFolder);


    filesystem::directory_iterator sourceIterator(sourceFolder);
    TK_ASSERT( filesystem::directory_iterator() != sourceIterator, "Invalid source directory '" << sourceFolder << "' ");

    for( const filesystem::directory_entry& entry : sourceIterator )
    {
        const filesystem::path& path = entry.path();
        
        if( std::string(".aspp") == path.extension() )
        {
            int i=0;i++;
            std::string completeText;
            {            
                std::ifstream inFile( path );
                TK_ASSERT( !inFile.bad(), "Unable to open file '" << path << "'" );
                char line[1000] = {0};
                while( inFile.getline(line, 999) )
                {
                    completeText += line + std::string("\n");
                }
            }
            if( Tk::Sp<const Ast::CNode> node = getAST(completeText.c_str() ) )
            {
                int i=0;
                i++;
            }
        }        
    }
    return module;
}

}
