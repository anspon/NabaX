#include "NabaLPch.h"

#include "ExpressionStatement.h"
#include "Expression.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CExpressionStatement::CExpressionStatement(
    const CExpression* expression
    )
{
    m_expression = Tk::AttachSp(expression);
}


}
