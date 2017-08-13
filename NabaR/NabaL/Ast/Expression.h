#ifndef Naba_Lng_Ast_CExpression_H
#define Naba_Lng_Ast_CExpression_H

#include "BlockPart.h"


namespace Naba
{
namespace Ir
{
class CVariable;
class CTypeManager;
class CBlockBuilder;
class CType;
}

namespace Lng
{
namespace Ast
{
class CExpression : public CBlockPart
{
    using BaseClass = CBlockPart;
public:
        CExpression(
            );
    
    Tk::Sp<const Ir::CType>
        Type(
            Tk::Sp<Ir::CTypeManager> typeManager
            )const;

    void MakeIr(
        Tk::Sp<Ir::CTypeManager> typeManager,
        Ir::CBlockBuilder& blockBuilder,
        Tk::SpList<const Ir::CFunction>& functions
        ) const override;

    virtual Tk::Sp<const Ir::CVariable>
        MakeExpressionIr(
            Tk::Sp<Ir::CTypeManager> typeManager,
            Ir::CBlockBuilder& blockBuilder
            )const = 0;
};

}
}
}


#endif