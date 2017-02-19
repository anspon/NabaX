#include "NabaLPch.h"

#include "BinaryOperator.h"

namespace Ast
{
//--------------------------------------------------------------------------------------------------
CBinaryOperator::CBinaryOperator(
    const CExpression* lhs, 
    int op, 
    const CExpression* rhs
    )
{
    m_lhs = Tk::AttachSp(lhs);
    m_op = op;
    m_rhs = Tk::AttachSp(rhs);
}
}