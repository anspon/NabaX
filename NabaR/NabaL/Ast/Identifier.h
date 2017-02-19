#ifndef NabaL_Ast_CIdentifier_H
#define NabaL_Ast_CIdentifier_H

#include "Expression.h"

namespace Ast
{
class CIdentifier : public CExpression 
{
public:
        CIdentifier(
            const std::string* name
            );
    

    std::string 
        m_name;
};

}


#endif