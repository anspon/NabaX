#ifndef NabaL_CModule_H
#define NabaL_CModule_H


namespace NabaIr
{
class CModule;
}

namespace NabaL
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


    Tk::Sp<const NabaIr::CModule> 
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

#endif
