#include "NabaIrPch.h"
#include "Function.h"

namespace NabaIr
{

CFunction::CFunction(
    const std::string& name,
    const Tk::SpList<const CParameter>& parameters,
    Tk::Sp<const CBlock> block
    ):
    m_name(name),
    m_parameters(parameters),
    m_block(block)
{
}
//--------------------------------------------------------------------------------------------------
CFunction::~CFunction()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CBlock> CFunction::Block(
    )const
{
    return m_block;
}
//--------------------------------------------------------------------------------------------------
const std::string& CFunction::Name(
    )const
{
    return m_name;
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CParameter>& CFunction::Parameters(
    )const
{
    return m_parameters;
}

}