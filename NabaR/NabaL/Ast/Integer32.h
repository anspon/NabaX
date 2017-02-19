#ifndef NabaL_Ast_CInteger32_H
#define NabaL_Ast_CInteger32_H

#include "Literal.h"

namespace Ast
{

class CInteger32 : public CLiteral 
{
public:
    CInteger32(
        const std::string* value
        );

    int32_t 
        m_value;

};

}


#endif