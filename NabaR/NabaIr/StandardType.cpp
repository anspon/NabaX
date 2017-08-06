#include "NabaIrPch.h"
#include "StandardType.h"

namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CStandardType::CStandardType(
    eNativeType nativeType,
    eStandardType standardType
    ):
    BaseClass(nativeType),
    m_standardType(standardType)
{
}
//--------------------------------------------------------------------------------------------------
CStandardType::~CStandardType()
{
}
//--------------------------------------------------------------------------------------------------
}