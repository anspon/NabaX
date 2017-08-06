#ifndef NabaIr_CTypeManager_H
#define NabaIr_CTypeManager_H

#include "eStandardType.h"
#include "eParameterType.h"

namespace NabaIr
{
class CStandardType;
class CParameter;
class CTypeManager
{
public:
    ~CTypeManager();

    static Tk::Sp<const CTypeManager>
        Construct(
            );

    

    Tk::Sp<const CParameter>
        MakeStandardParameter(
            eStandardType type,
            const std::string& name,
            eParameterType parameterType
            )const;


    Tk::Sp<const CStandardType>
        StandardType(
            eStandardType type
            )const;

private:
    void
        PrivateConstruct(
            );
    CTypeManager();

    
    Tk::SpMap<eStandardType, const CStandardType>
        m_standardTypes;
};

}


#endif