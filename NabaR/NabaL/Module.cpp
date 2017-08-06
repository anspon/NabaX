#include "NabaLPch.h"
#include "Module.h"

namespace NabaL
{

CModule::CModule(
    const std::string& moduleName,
    const Tk::SpList<const CTranslationUnit>& translationUnits
    ):
    m_moduleName(moduleName),
    m_translationUnits( translationUnits )
{    
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CTranslationUnit>& CModule::TranslationUnits(
    )const
{
    return m_translationUnits;
}
//--------------------------------------------------------------------------------------------------
CModule::~CModule()
{
}
//--------------------------------------------------------------------------------------------------

}
