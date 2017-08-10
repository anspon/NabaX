#include "NabaIrPch.h"
#include "Parameter.h"

namespace Naba
{
namespace Ir
{

//--------------------------------------------------------------------------------------------------
CParameter::CParameter(
    Tk::Sp<const CVariable> variable,
    eParameterType parameterType
    ):
    m_variable(variable),
    m_parameterType(parameterType)
{
}
//--------------------------------------------------------------------------------------------------
CParameter::~CParameter()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CVariable>  CParameter::Variable(
    )const
{
    return m_variable;
}
//--------------------------------------------------------------------------------------------------
eParameterType CParameter::ParameterType(
    )const
{
    return m_parameterType;
}

}
}
