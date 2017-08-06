#ifndef NabaIr_CFunction_H
#define NabaIr_CFunction_H

namespace NabaIr
{
class CParameter;

class CFunction
{
public:
    CFunction(
        const std::string& name,
        const Tk::SpList<const CParameter>& parameters
        );
    ~CFunction();

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
};


}

#endif
