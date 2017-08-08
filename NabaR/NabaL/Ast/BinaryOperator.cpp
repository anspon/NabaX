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
//--------------------------------------------------------------------------------------------------
Tk::Sp<const NabaIr::CVariable> CBinaryOperator::MakeExpressionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder & blockBuilder
    ) const
{
    return Tk::Sp<const NabaIr::CVariable>();
}
}