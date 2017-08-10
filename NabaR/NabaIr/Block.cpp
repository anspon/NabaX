#include "NabaIrPch.h"
#include "Block.h"

namespace Naba
{
namespace Ir
{

//--------------------------------------------------------------------------------------------------
CBlock::CBlock(
    const Tk::SpList<const CVariable>& variables,
    const Tk::SpList<const CInstruction>& instructions
    ):
    m_variables(variables),
    m_instructions(instructions)
{
}
//--------------------------------------------------------------------------------------------------
CBlock::~CBlock()
{
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CVariable>& CBlock::Variables(
    )const
{
    return m_variables;
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CInstruction>& CBlock::Instructions() const
{
    return m_instructions;
}


}
}
