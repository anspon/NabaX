#include "NabaLPch.h"

#include "Block.h"

#include "NabaIr/BlockBuilder.h"

namespace Naba
{
namespace Lng
{
namespace Ast
{
//--------------------------------------------------------------------------------------------------
void CBlock::AddBlockPart(
    const CBlockPart* part
    )
{
    m_blockParts.push_back( Tk::AttachSp(part) );
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

}
}
}
