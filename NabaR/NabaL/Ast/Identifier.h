#ifndef NabaL_Ast_CIdentifier_H
#define NabaL_Ast_CIdentifier_H

#include "Expression.h"

namespace Ast
{
class CIdentifier : public CExpression 
{
using BaseClass = CExpression;

public:
        CIdentifier(
            const StringToken* stringToken
            );
    
    const std::string 
        m_name;
};

}


#endif