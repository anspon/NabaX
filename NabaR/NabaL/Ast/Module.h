#ifndef Naba_Lng_CModule_H
#define Naba_Lng_CModule_H

namespace Naba
{ 
namespace Ir
{
class CModule;
}

namespace Lng 
{

namespace Ast
{
class CTranslationUnit;

class CModule
{
public:
    CModule(
        const std::string& moduleName,
        const Tk::SpList<const CTranslationUnit>& translationUnits
        );
    ~CModule();


    Tk::Sp<const Ir::CModule> 
        MakeIr(
            )const;

    const Tk::SpList<const CTranslationUnit>&
        TranslationUnits(
            )const ;

private:
    const std::string 
        m_moduleName;

    const Tk::SpList<const CTranslationUnit>
        m_translationUnits;
};

}
}
}

#endif
