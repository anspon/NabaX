#ifndef NabaL_Ast_CDouble_H
#define NabaL_Ast_CDouble_H

#include "Literal.h"

namespace Ast
{
class CDouble : public CLiteral
{
using BaseClass = CLiteral;
public:
    CDouble(
        const StringToken* stringToken
        );
    
       
private:    
    double 
        m_value;

    std::string 
        m_originalText;    
};

}


#endif