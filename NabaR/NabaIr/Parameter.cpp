#include "NabaIrPch.h"
#include "Parameter.h"

namespace NabaIr
{

//--------------------------------------------------------------------------------------------------
CParameter::CParameter(
    const std::string& name,
    Tk::Sp<const CType> dataType,
    eParameterType parameterType
    ):
    m_name(name),
    m_dataType(dataType),
    m_parameterType(parameterType)
{
}
//--------------------------------------------------------------------------------------------------
CParameter::~CParameter()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CType> CParameter::DataType(
    )const
{
    return m_dataType;
}
//--------------------------------------------------------------------------------------------------
const std::string CParameter::Name(
    )const
{
    return m_name;
}
//--------------------------------------------------------------------------------------------------
eParameterType CParameter::ParameterType(
    )const
{
    return m_parameterType;
}

}