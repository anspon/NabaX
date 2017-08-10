#include "NabaLPch.h"

#include "For.h"
#include "Expression.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CFor::CFor(
    const CIdentifier* blockName,
    const CIdentifier* loopVariable,
    const CExpression* expression,
    const CBlockPart* block
    )
{
    m_expression = Tk::AttachSp(expression);
    m_block = Tk::AttachSp(block);
}
//--------------------------------------------------------------------------------------------------
void CFor::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    auto var = blockBuilder.AddLocalVariable("bool", "" );

    auto exprVar1 = m_expression->MakeExpressionIr(typeManager, blockBuilder);
    blockBuilder.AssignVariable(var, exprVar1);

    Ir::CBlockBuilder ForBlock(typeManager, &blockBuilder);
    m_block->MakeIr(typeManager, ForBlock, functions);
    auto exprVar2 = m_expression->MakeExpressionIr(typeManager, ForBlock);
    ForBlock.AssignVariable(var, exprVar2);

    blockBuilder.While(var, ForBlock.Flush() );
  
}
//--------------------------------------------------------------------------------------------------
CFor::~CFor()
{
}

}
}
}
