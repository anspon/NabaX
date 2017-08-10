#include "NabaLPch.h"
#include "Node.h"


namespace Naba
{
namespace Lng
{
namespace Ast
{
CNode::~CNode()
{
    int i=0; i++;
}
//--------------------------------------------------------------------------------------------------
const CPosition& CNode::Position()const
{
    return m_position;
}
//--------------------------------------------------------------------------------------------------
void CNode::MakeIr(
    Tk::Sp<Ir::CTypeManager> typeManager,
    Ir::CBlockBuilder& blockBuilder,
    Tk::SpList<const Ir::CFunction>& functions
    ) const
{
}

}
}
}


