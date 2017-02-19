#ifndef NabaL_CTranslationUnit_H
#define NabaL_CTranslationUnit_H

#include "NabalPchHeaders.h"

namespace Ast
{
class CNode;
}

namespace NabaL
{

class CTranslationUnit
{
public:
    CTranslationUnit(
        const std::list<std::string>& nameSpace,
        Tk::Sp<const Ast::CNode> ast
        );
    
    ~CTranslationUnit(
        );

private:
    Tk::Sp<const Ast::CNode> 
        m_ast;

    std::list<std::string> 
        m_nameSpace;
};


}

#endif