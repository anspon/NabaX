#ifndef NabaL_CModule_H
#define NabaL_CModule_H


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
