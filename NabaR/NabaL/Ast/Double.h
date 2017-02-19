#ifndef NabaL_Ast_CDouble_H
#define NabaL_Ast_CDouble_H

#include "Literal.h"

namespace Ast
{
class CDouble : public CLiteral 
{
public:
    CDouble(
        const std::string* value
        );
    
       
private:    
    double 
        m_value;

    std::string 
        m_originalText;    
};

}


#endif