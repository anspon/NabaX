#include "NabaLPch.h"

#include "Expression.h"

namespace Ast
{
CExpression::CExpression()
{
}
//--------------------------------------------------------------------------------------------------
void CExpression::MakeIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder,
    Tk::SpList<const NabaIr::CFunction>& functions
    ) const
{
    MakeExpressionIr(typeManager, blockBuilder);
}
//--------------------------------------------------------------------------------------------------
void CExpression::MakeFunctionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder & blockBuilder
    ) const
{
    MakeExpressionIr(typeManager, blockBuilder);
}
}

