#include "NabaIrPch.h"
#include "Module.h"


namespace NabaIr
{

CModule::CModule(
    const std::string& name,
    const Tk::SpList<const CTranslationUnit>& translationUnits
    ):
    m_name(name),
    m_translationUnits(translationUnits)
{
}
//--------------------------------------------------------------------------------------------------
CModule::~CModule()
{
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CTranslationUnit>& CModule::TranslationUnits(
    )const
{
    return m_translationUnits;
}
//--------------------------------------------------------------------------------------------------

}