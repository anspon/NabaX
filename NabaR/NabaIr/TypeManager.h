#ifndef NabaIr_CTypeManager_H
#define NabaIr_CTypeManager_H

#include "eStandardType.h"
#include "eParameterType.h"

namespace NabaIr
{
class CType;
class CStandardType;
class CParameter;

class CTypeManager
{
public:
    ~CTypeManager();

    static Tk::Sp<CTypeManager>
        Construct(
            );

    Tk::Sp<const CStandardType>
        StandardType(
            eStandardType type
            )const;
    
    Tk::Sp<const CType>
        Type(
            const std::string& typeName
            );
    
private:
    void
        PrivateConstruct(
            );
    CTypeManager();

    
    Tk::SpMap<eStandardType, const CStandardType>
        m_standardTypes;

    Tk::SpMap<std::string, const CType>
        m_allTypes;

};

}


#endif