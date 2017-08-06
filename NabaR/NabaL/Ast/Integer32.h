#ifndef NabaL_Ast_CInteger32_H
#define NabaL_Ast_CInteger32_H

#include "Literal.h"

namespace Ast
{

class CInteger32 : public CLiteral 
{
    using BaseClass = CLiteral;
public:
    CInteger32(
        const StringToken* value
        );

    int32_t 
        m_value;

};

}


#endif