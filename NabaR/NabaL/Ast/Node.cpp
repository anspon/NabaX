#include "NabaLPch.h"
#include "Node.h"


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
    Tk::Sp<NabaIr::CTypeManager> typeManager,
    NabaIr::CBlockBuilder& blockBuilder,
    Tk::SpList<const NabaIr::CFunction>& functions
    ) const
{
}
}

