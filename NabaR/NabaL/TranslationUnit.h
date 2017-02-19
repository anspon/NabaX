#ifndef NabaL_CTranslationUnit_H
#define NabaL_CTranslationUnit_H

#include "NabalPchHeaders.h"

namespace Ast
{
class CNode;
}

namespace NabaL
{

class TranslationUnit
{
public:
    TranslationUnit(
        const std::list<std::string>& nameSpace,
        Tk::Sp<const Ast::CNode> ast
        );
    
    ~TranslationUnit(
        );

private:
    Tk::Sp<const Ast::CNode> 
        m_ast;

    std::list<std::string> 
        m_nameSpace;
};


}

#endif