#ifndef NabaIr_CModule_H
#define NabaIr_CModule_H

#include "NabaIrPchHeaders.h"

namespace Naba
{
namespace Ir
{
class CTranslationUnit;

class CModule
{
public:
    CModule(
        const std::string& name,
        const Tk::SpList<const CTranslationUnit>& translationUnits
    );
    ~CModule();

    const Tk::SpList<const CTranslationUnit>&
        TranslationUnits(
            )const;
private:
    
    const std::string 
        m_name;

    Tk::SpList<const CTranslationUnit>
        m_translationUnits;
};


}
}


#endif