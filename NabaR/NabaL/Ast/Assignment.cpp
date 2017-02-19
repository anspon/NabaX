#include "NabaLPch.h"

#include "Assignment.h"
#include "Identifier.h"
#include "Expression.h"

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

}