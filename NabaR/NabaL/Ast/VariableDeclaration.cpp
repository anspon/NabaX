#include "NabaLPch.h"
#include "VariableDeclaration.h"
#include "Assignment.h"
#include "Identifier.h"

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


}