#ifndef NabaIr_CType_H
#define NabaIr_CType_H

#include "eNativeType.h"

namespace NabaIr
{
class CType
{
public:

    CType(
        const std::string& typeName,
        eNativeType nativeType
        );
    
    const std::string& 
        TypeName(
            )const;

    eNativeType
        NativeType(
            )const;


    ~CType();

private:
    const std::string
        m_typeName;

    const eNativeType 
        m_nativeType;
};


}

#endif
