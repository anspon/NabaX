#ifndef NabaIr_CTranslationUnit_H
#define NabaIr_CTranslationUnit_H


namespace Naba
{
namespace Ir
{
class CFunction;

class CTranslationUnit
{
public:
    CTranslationUnit(
        const std::string& name,
        const Tk::SpList<const CFunction>& functions
        );
    ~CTranslationUnit();

    const Tk::SpList<const CFunction>& 
        Functions(
            )const;

private:
    const std::string 
        m_name;

    const Tk::SpList<const CFunction> 
        m_functions;
};

}
}

#endif