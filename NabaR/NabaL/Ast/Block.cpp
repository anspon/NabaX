#include "NabaLPch.h"

#include "Block.h"

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
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder,
    Tk::SpList<const NabaIr::CFunction>& functions
    ) const
{
    for( Tk::Sp<const CBlockPart> blockPart : m_blockParts )
    {
        blockPart->MakeIr(typeManager, blockBuilder, functions);
    }
}
//--------------------------------------------------------------------------------------------------
void CBlock::MakeFunctionIr(
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder
    )const
{
    for( Tk::Sp<const CBlockPart> blockPart : m_blockParts )
    {
        blockPart->MakeFunctionIr(typeManager, blockBuilder);
    }    
}
}
