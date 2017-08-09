#include "NabaIrPch.h"
#include "Type.h"


namespace NabaIr
{

//--------------------------------------------------------------------------------------------------
CType::CType(
    const std::string& typeName,
    eNativeType nativeType
    ):
    m_typeName(typeName),
    m_nativeType(nativeType)
{
}
//--------------------------------------------------------------------------------------------------
CType::~CType()
{
}
//--------------------------------------------------------------------------------------------------
const std::string & CType::TypeName() const
{
    return m_typeName;
}
//--------------------------------------------------------------------------------------------------
eNativeType CType::NativeType(
    )const
{
    return m_nativeType;
}

}