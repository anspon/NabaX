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
void CExpressionStatement::MakeFunctionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    ) const
{
    m_expression->MakeExpressionIr(typeManager, blockBuilder );
}


}
