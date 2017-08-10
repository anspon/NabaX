#include "NabaLPch.h"

#include "Expression.h"

#include "NabaIr/TypeManager.h"
#include "NabaIr/StandardType.h"
namespace Ast
{
CExpression::CExpression()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CType> CExpression::Type(
    Tk::Sp<NabaIr::CTypeManager> typeManager
    ) const
{
    return typeManager->StandardType(NabaIr::stInt32);
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
}

