#include "NabaLPch.h"
#include "TranslationUnit.h"


namespace NabaL
{


//--------------------------------------------------------------------------------------------------
CTranslationUnit::CTranslationUnit(
    const std::list<std::string>& nameSpace,
    Tk::Sp<const Ast::CNode> ast,
    const filesystem::path& completePathFile,
    const Tk::SpList<const CCompileError>& errors
    ):
    m_nameSpace( nameSpace ),
    m_ast( ast ),
    m_completePathFile( completePathFile ),
    m_errors(errors)
{
}
//--------------------------------------------------------------------------------------------------
CTranslationUnit::~CTranslationUnit()
{
}
//--------------------------------------------------------------------------------------------------
const filesystem::path& CTranslationUnit::CompletePathFile()const
{
    return m_completePathFile;
}
//--------------------------------------------------------------------------------------------------
const Tk::SpList<const CCompileError>& CTranslationUnit::Errors()const
{
    return m_errors;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const Ast::CNode>  CTranslationUnit::Ast(
    )const
{
    return m_ast;
}

}


