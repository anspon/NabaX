#include "NabaLPch.h"
#include "VariableDeclaration.h"
#include "Assignment.h"
#include "Identifier.h"

#include "Tk/Exception.h"

#include "NabaIr/BlockBuilder.h"
#include "NabaIr/Literal.h"
#include "NabaIr/TypeManager.h"
#include "NabaIr/Type.h"

namespace Naba
{
namespace Lng
{
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
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    Tk::Sp<const Ir::CType> irType;

    if( m_type )
    {
        irType = typeManager->Type(m_type->m_name);
    }
    else
    {
        if( m_assignmentExpr )
        {
            irType = m_assignmentExpr->Type(typeManager);
        }
        else
        {
            TK_THROW( "If a variable declaration does not have a type, it must be assigned");
        }
    }
       
    auto variable = blockBuilder.AddLocalVariable( irType->TypeName(), m_id->m_name );
    if( m_assignmentExpr )
    {
        Tk::Sp<const Ir::CVariable> rhsVar = m_assignmentExpr->MakeExpressionIr(typeManager, blockBuilder);
        blockBuilder.AssignVariable(variable, rhsVar);
    }
    else
    {
        blockBuilder.ZeroVariable(variable);
    }
}

}
}
}