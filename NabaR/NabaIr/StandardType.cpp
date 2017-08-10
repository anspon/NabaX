#include "NabaIrPch.h"
#include "StandardType.h"

namespace Naba
{
namespace Ir
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
}
