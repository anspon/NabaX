#include "NabaLPch.h"

#include "Assignment.h"
#include "Identifier.h"
#include "Expression.h"

#include "NabaIr/BlockBuilder.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CAssignment::CAssignment(
    const CIdentifier* lhs, 
    const CExpression* rhs
    )
{
    m_lhs = Tk::AttachSp(lhs);
    m_rhs = Tk::AttachSp(rhs);
}
//--------------------------------------------------------------------------------------------------
void CAssignment::MakeFunctionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    )const
{
    Tk::Sp<const NabaIr::CVariable> lhsVar = blockBuilder.GetVariable(m_lhs->m_name);
    Tk::Sp<const NabaIr::CVariable> rhsVar = m_rhs->MakeExpressionIr(typeManager, blockBuilder);
    blockBuilder.AssignVariable(lhsVar, rhsVar);
}

}