#include "NabaIrPch.h"
#include "StandardType.h"

namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CStandardType::CStandardType(
    const std::string& typeName,
    eNativeType nativeType,
    eStandardType standardType
    ):
    BaseClass(typeName, nativeType),
    m_standardType(standardType)
{
}
//--------------------------------------------------------------------------------------------------
CStandardType::~CStandardType()
{
}
//--------------------------------------------------------------------------------------------------
}