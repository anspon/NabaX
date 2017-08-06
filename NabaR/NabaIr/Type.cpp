#include "NabaIrPch.h"
#include "Type.h"


namespace NabaIr
{

//--------------------------------------------------------------------------------------------------
CType::CType(
    eNativeType nativeType
    ):
    m_nativeType(nativeType)
{
}
//--------------------------------------------------------------------------------------------------
CType::~CType()
{
}
//--------------------------------------------------------------------------------------------------
eNativeType CType::NativeType(
    )const
{
    return m_nativeType;
}

}