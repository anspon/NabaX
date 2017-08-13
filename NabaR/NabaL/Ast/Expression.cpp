#include "NabaLPch.h"

#include "Expression.h"

#include "NabaIr/TypeManager.h"
#include "NabaIr/StandardType.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
CExpression::CExpression(
    ):BaseClass(bptExpressionStatement)
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ir::CType> CExpression::Type(
    Tk::Sp<Ir::CTypeManager> typeManager
    ) const
{
    return typeManager->StandardType(Ir::stInt32);
}
//--------------------------------------------------------------------------------------------------
void CExpression::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    MakeExpressionIr(typeManager, blockBuilder);
}

}
}
}

