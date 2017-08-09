#include "NabaLPch.h"
#include "VariableDeclaration.h"
#include "Assignment.h"
#include "Identifier.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CVariableDeclaration::CVariableDeclaration(
    const CIdentifier* type, 
    const CIdentifier* id, 
    const CExpression* assignmentExpr
    )
{
    m_type = Tk::AttachSp(type);
    m_id = Tk::AttachSp(id);
    m_assignmentExpr = Tk::AttachSp(assignmentExpr);
}
//--------------------------------------------------------------------------------------------------
void CVariableDeclaration::MakeIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder,
    Tk::SpList<const NabaIr::CFunction>& functions
    ) const
{
   
    auto variable = blockBuilder.AddLocalVariable( m_type->m_name, m_id->m_name );
    if( m_assignmentExpr )
    {
        Tk::Sp<const NabaIr::CVariable> rhsVar = m_assignmentExpr->MakeExpressionIr(typeManager, blockBuilder);
        blockBuilder.AssignVariable(variable, rhsVar);
    }
    else
    {
        blockBuilder.ZeroVariable(variable);
    }
}


}