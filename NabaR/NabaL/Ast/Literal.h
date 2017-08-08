#ifndef NabaL_Ast_CLiteral_H
#define NabaL_Ast_CLiteral_H


#include "Expression.h"

namespace Ast
{
class CLiteral : public CExpression
{
public:
        CLiteral(
            const StringToken* stringToken
            );

private:
    std::string 
        m_originalText;    

};

}


#endif