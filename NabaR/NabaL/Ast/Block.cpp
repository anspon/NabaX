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
}
