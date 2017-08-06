#ifndef NabaL_Ast_CInteger64_H
#define NabaL_Ast_CInteger64_H

#include "Literal.h"

namespace Ast
{
class CInteger64 : public CLiteral 
{
using BaseClass = CLiteral;
public:
    CInteger64(
        const StringToken* stringToken
        );

    int64_t 
        m_value;

    std::string
        m_originalText;
};}


#endif