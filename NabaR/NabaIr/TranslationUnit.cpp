#include "NabaIrPch.h"
#include "TranslationUnit.h"


namespace NabaIr
{
//--------------------------------------------------------------------------------------------------
CTranslationUnit::CTranslationUnit(
    const std::string& name,
    const Tk::SpList<const CFunction>& functions
    ):
    m_name(name),
    m_functions(functions)
{
}
//--------------------------------------------------------------------------------------------------
CTranslationUnit::~CTranslationUnit()
{
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CFunction>& CTranslationUnit::Functions(
    )const
{
    return m_functions;
}

}