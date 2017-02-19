#include "NabaLPch.h"
#include "StructVariable.h"

#include "StructVariable.h"
#include "Identifier.h"
#include "Expression.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CStructVariable::CStructVariable(
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