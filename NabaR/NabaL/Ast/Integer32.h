#ifndef Naba_Lng_Ast_CInteger32_H
#define Naba_Lng_Ast_CInteger32_H

#include "Literal.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
class CInteger32 : public CLiteral 
{
    using BaseClass = CLiteral;
public:
    CInteger32(
        const StringToken* value
        );

    Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const;

    int32_t 
        m_value;

};

}
}
}


#endif