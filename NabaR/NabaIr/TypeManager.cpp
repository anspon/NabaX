#include "NabaIrPch.h"
#include "TypeManager.h"
#include "Type.h"
#include "StandardType.h"
#include "Parameter.h"

#include "Tk/Exception.h"

namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CTypeManager::CTypeManager()
{
}
//--------------------------------------------------------------------------------------------------
CTypeManager::~CTypeManager()
{
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CTypeManager> CTypeManager::Construct(
    )
{
    Tk::Sp<CTypeManager> instance = Tk::Sp<CTypeManager>(new CTypeManager);

    instance->PrivateConstruct();

    return instance;
}
//--------------------------------------------------------------------------------------------------
void CTypeManager::PrivateConstruct(
    )
{
    m_standardTypes[stInt64] = Tk::Sp<CStandardType>(new CStandardType(ntInt64, stInt64) );
    m_standardTypes[stInt32] = Tk::Sp<CStandardType>(new CStandardType(ntInt32, stInt32) );
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CStandardType> CTypeManager::StandardType(
    eStandardType type
    )const
{
    auto it = m_standardTypes.find(type);
    TK_ASSERT( it != m_standardTypes.end(), "Invalid standard type: " << type );
    return it->second;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CParameter> CTypeManager::MakeStandardParameter(
    eStandardType type,
    const std::string& name,
    eParameterType parameterType
    )const
{
    return Tk::MakeSp<const CParameter>(name, StandardType(type), parameterType );
}

}