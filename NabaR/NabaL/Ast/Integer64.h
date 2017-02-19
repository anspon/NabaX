#ifndef NabaL_Ast_CInteger64_H
#define NabaL_Ast_CInteger64_H

#include "Literal.h"

namespace Ast
{
class CInteger64 : public CLiteral 
{
public:
    CInteger64(
        const std::string* value
        );

    int64_t 
        m_value;

    
    std::string
        m_originalText;
};}


#endif