#ifndef NabaIr_CParameter_H
#define NabaIr_CParameter_H

#include "eParameterType.h"


namespace NabaIr
{
class CType;

class CParameter
{
public:

    CParameter(
        const std::string& name,
        Tk::Sp<const CType> type,
        eParameterType parameterType
        );
    ~CParameter();


    eParameterType 
        ParameterType(
            )const;

    Tk::Sp<const CType> 
        DataType(
            )const;
    
    const std::string 
        Name(
            )const;

private:
    const std::string 
        m_name;
    
    const Tk::Sp<const CType> 
        m_dataType;

    const eParameterType 
        m_parameterType;
};


}

#endif