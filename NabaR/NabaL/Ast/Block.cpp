#include "NabaLPch.h"

#include "Block.h"
#include "Struct.h"
#include "Function.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
CBlock::CBlock(
    ):
    BaseClass(bptBlock)
{
    m_blockType = btUnknown;
}
//--------------------------------------------------------------------------------------------------
void CBlock::SetBlockType(
    eBlockType blockType
    )
{
    m_blockType = blockType;    
}
//--------------------------------------------------------------------------------------------------
void CBlock::AddChildBlock(
    Tk::Sp<CBlock> childBlock
    )
{
    m_ChildBlocks.push_back(childBlock);
}
//--------------------------------------------------------------------------------------------------
void CBlock::Initialize()
{
    for( Tk::Sp<CBlock> childBlock : m_ChildBlocks )
    {
        childBlock->m_parentBlock = SharedThis();
        childBlock->Initialize();
    }
}
//--------------------------------------------------------------------------------------------------
void CBlock::AddBlockPart(
    CBlockPart* part
    )
{
    Tk::Sp<CBlockPart> attached = Tk::AttachSp(part);
    switch( attached->BlockPartType() )
    {
        case bptBlock:
        {
            Tk::Sp<CBlock> block = Tk::DynamicCast<CBlock>(attached);
            block->SetBlockType( btAnonymous );
            AddChildBlock(block);

            break;
        }
        case bptVariableDeclaration:
        {
            break;
        }
        case bptFunctionDeclaration:
        {
            Tk::Sp<CFunction> function = Tk::DynamicCast<CFunction>(attached);

            Tk::Sp<CBlock> block = function->Block();
            block->SetBlockType( btFunctionScope );

            AddChildBlock(block);
            break;
        }
        case bptStruct:
        {
            break;
        }
        case bptExpressionStatement:
        {
            break;
        }
        case bptAssignement:
        {
            break;
        }
        case bptWhile:
        {
            break;
        }
        case bptFor:
        {
            break;
        }
    }
    m_blockParts.push_back( attached );
}
//--------------------------------------------------------------------------------------------------
void CBlock::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
//    Ir::CBlockBuilder localBlockBuilder(typeManager);
    for( Tk::Sp<const CBlockPart> blockPart : m_blockParts )
    {
        blockPart->MakeIr(typeManager, blockBuilder, functions);
    }
}
//--------------------------------------------------------------------------------------------------
void CBlock::ForEachBlock(
    ForEachBlockFunctionT forEachBlockFunction
    )const
{

}
//--------------------------------------------------------------------------------------------------

}
}
}
