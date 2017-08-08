#include "NabaLPch.h"
#include "Module.h"
#include "TranslationUnit.h"

#include "NabaIr/Module.h"
#include "NabaIr/TranslationUnit.h"

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
Tk::Sp<const NabaIr::CModule> CModule::MakeIr() const
{
    Tk::SpList<const NabaIr::CTranslationUnit> irUnits;

    for( Tk::Sp<const CTranslationUnit> unit : m_translationUnits )
    {
        irUnits.push_back( unit->MakeIr() );
    }
    return Tk::MakeSp<NabaIr::CModule>("HelloWorld", irUnits);
}

}
