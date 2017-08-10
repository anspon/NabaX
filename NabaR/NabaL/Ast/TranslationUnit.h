#ifndef Naba_Lng_CTranslationUnit_H
#define Naba_Lng_CTranslationUnit_H

#include "NabalPchHeaders.h"



namespace Naba
{
namespace Ir
{
class CTranslationUnit;
}

namespace Lng
{
class CCompileError;

namespace Ast
{
class CNode;


class CTranslationUnit
{
public:

    CTranslationUnit(
        const std::list<std::string>& nameSpace,
        Tk::Sp<const Ast::CNode> ast,
        const filesystem::path& completePathFile,
        const Tk::SpList<const CCompileError>& errors
        );

    Tk::Sp<const Ast::CNode> 
        Ast(
            )const;

    Tk::Sp<const Ir::CTranslationUnit> 
        MakeIr(
            )const;
            
    ~CTranslationUnit(
        );

    const filesystem::path&
        CompletePathFile(
            )const;

    const Tk::SpList<const CCompileError>& 
        Errors(
            )const;

private:
    
    const std::list<std::string> 
        m_nameSpace;

    const Tk::Sp<const Ast::CNode> 
        m_ast;

    const filesystem::path 
        m_completePathFile;

    const Tk::SpList<const CCompileError> 
        m_errors;
};

}
}
}

#endif