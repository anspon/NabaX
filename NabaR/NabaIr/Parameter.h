#ifndef NabaIr_CParameter_H
#define NabaIr_CParameter_H

#include "eParameterType.h"


namespace Naba
{
namespace Ir
{
class CVariable;

class CParameter
{
public:

    CParameter(
        Tk::Sp<const CVariable> variable,
        eParameterType parameterType
        );
    ~CParameter();


    eParameterType 
        ParameterType(
            )const;

    Tk::Sp<const CVariable> 
        Variable(
            )const;

private:
    const Tk::Sp<const CVariable> 
        m_variable;

    const eParameterType 
        m_parameterType;
};

}
}


#endif