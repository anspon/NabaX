#include "NabaLPch.h"

#include "Assignment.h"
#include "Identifier.h"
#include "Expression.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
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
void CAssignment::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    )const
{
    Tk::Sp<const Ir::CVariable> lhsVar = blockBuilder.GetVariable(m_lhs->m_name);
    Tk::Sp<const Ir::CVariable> rhsVar = m_rhs->MakeExpressionIr(typeManager, blockBuilder);
    blockBuilder.AssignVariable(lhsVar, rhsVar);
}

}
}
}
