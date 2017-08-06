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
}

