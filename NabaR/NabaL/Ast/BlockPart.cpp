#include "NabaLPch.h"

#include "BlockPart.h"

namespace Naba
{
namespace Lng
{

namespace Ast
{
CBlockPart::CBlockPart(
    eBlockPartType blockPartType
    ):
    m_blockPartType(blockPartType)
{
}
//--------------------------------------------------------------------------------------------------
eBlockPartType CBlockPart::BlockPartType()const
{
    return m_blockPartType;
}

}
}
}

