#ifndef NabaIr_CFunction_H
#define NabaIr_CFunction_H

namespace Naba
{
namespace Ir
{

class CParameter;
class CBlock;

class CFunction
{
public:
    CFunction(
        const std::string& name,
        const Tk::SpList<const CParameter>& parameters,
        Tk::Sp<const CBlock> block
        );
    ~CFunction();

    Tk::Sp<const CBlock> 
        Block(
            )const;

    const std::string& 
       Name(
        )const;
    
    const Tk::SpList<const CParameter>& 
        Parameters(
            )const;

private:
    const std::string 
        m_name;

    const Tk::SpList<const CParameter> 
        m_parameters;

    const Tk::Sp<const CBlock> 
        m_block;
};


}
}

#endif
