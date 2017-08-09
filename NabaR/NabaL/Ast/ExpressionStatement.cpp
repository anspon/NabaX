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
//--------------------------------------------------------------------------------------------------
void CExpressionStatement::MakeIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder,
    Tk::SpList<const NabaIr::CFunction>& functions
    ) const
{
    m_expression->MakeExpressionIr(typeManager, blockBuilder );
}


}
