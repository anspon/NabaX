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
Tk::Sp<CTypeManager> CTypeManager::Construct(
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
    m_standardTypes[stDouble] = Tk::Sp<CStandardType>(new CStandardType(ntDouble, stDouble) );
    m_standardTypes[stBool] = Tk::Sp<CStandardType>(new CStandardType(ntBool, stBool) );

    m_allTypes["i64"] = StandardType( stInt64 );
    m_allTypes["i32"] = StandardType( stInt32 );
    m_allTypes["double"] = StandardType( stDouble );
    m_allTypes["bool"] = StandardType( stBool );
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
Tk::Sp<const CType> CTypeManager::Type(
    const std::string& typeName
    )
{
    Tk::Sp<const CType> result;

    auto it = m_allTypes.find(typeName);
    if( it != m_allTypes.end() )
    {
        result = it->second;
    }
    else
    {
        result = Tk::MakeSp<CType>(ntVoidPtr);
        m_allTypes[typeName] = result;
    }
    return result;
}
//--------------------------------------------------------------------------------------------------

}