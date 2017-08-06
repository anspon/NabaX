#include "NabaIrPch.h"
#include "Function.h"

namespace NabaIr
{

CFunction::CFunction(
    const std::string& name,
    const Tk::SpList<const CParameter>& parameters
    ):
    m_name(name),
    m_parameters(parameters)
{
}
//--------------------------------------------------------------------------------------------------
CFunction::~CFunction()
{
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