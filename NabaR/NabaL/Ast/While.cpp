#include "NabaLPch.h"

#include "While.h"
#include "Expression.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CWhile::CWhile(
    const CIdentifier* blockName,
    const CExpression* expression,
    const CBlockPart* block
    ):
    BaseClass(bptWhile)
{
    m_expression = Tk::AttachSp(expression);
    m_block = Tk::AttachSp(block);
}
//--------------------------------------------------------------------------------------------------
void CWhile::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
    auto var = blockBuilder.AddLocalVariable("bool", "" );

    auto exprVar1 = m_expression->MakeExpressionIr(typeManager, blockBuilder);
    blockBuilder.AssignVariable(var, exprVar1);

    Ir::CBlockBuilder whileBlock(typeManager, &blockBuilder);
    m_block->MakeIr(typeManager, whileBlock, functions);
    auto exprVar2 = m_expression->MakeExpressionIr(typeManager, whileBlock);
    whileBlock.AssignVariable(var, exprVar2);

    blockBuilder.While(var, whileBlock.Flush() );

    
}
//--------------------------------------------------------------------------------------------------
CWhile::~CWhile()
{
}

}
}
}
