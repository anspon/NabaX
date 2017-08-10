#include "NabaLPch.h"
#include "Module.h"
#include "TranslationUnit.h"

#include "NabaIr/Module.h"
#include "NabaIr/TranslationUnit.h"

namespace Naba
{ 
namespace Lng 
{
namespace Ast
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
Tk::Sp<const Ir::CModule> CModule::MakeIr() const
{
    Tk::SpList<const Ir::CTranslationUnit> irUnits;

    for( Tk::Sp<const CTranslationUnit> unit : m_translationUnits )
    {
        irUnits.push_back( unit->MakeIr() );
    }
    return Tk::MakeSp<Ir::CModule>("HelloWorld", irUnits);
}

}
}
}