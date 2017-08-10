#include "NabaLPch.h"

#include "ExpressionStatement.h"
#include "Expression.h"

namespace Naba
{
namespace Lng
{
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
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    m_expression->MakeExpressionIr(typeManager, blockBuilder );
}


}
}
}
