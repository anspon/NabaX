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

    Tk::Sp<const NabaIr::CVariable>
        MakeExpressionIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder
            )const;

    int64_t 
        m_value;

};}


#endif