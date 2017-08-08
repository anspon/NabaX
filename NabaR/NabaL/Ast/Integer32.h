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

    Tk::Sp<const NabaIr::CVariable>
        MakeExpressionIr(
            Tk::Sp<NabaIr::CTypeManager> typeManager,
            NabaIr::CBlockBuilder& blockBuilder
            )const;

    int32_t 
        m_value;

};

}


#endif