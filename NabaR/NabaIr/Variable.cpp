#include "NabaIrPch.h"
#include "Variable.h"

namespace Naba
{
namespace Ir
{

//--------------------------------------------------------------------------------------------------
CVariable::CVariable(
    Tk::Sp<const CType> dataType,
    const std::string& name
    ):
    m_dataType(dataType),
    m_name(name)
{
}
//--------------------------------------------------------------------------------------------------
CVariable::~CVariable()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CType> CVariable::DataType(
    )const
{
    return m_dataType;
}
//--------------------------------------------------------------------------------------------------
const std::string& CVariable::Name(
    )const
{
    return m_name;
}
//--------------------------------------------------------------------------------------------------

}
}
