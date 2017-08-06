#ifndef NabaIr_CType_H
#define NabaIr_CType_H

#include "eNativeType.h"

namespace NabaIr
{
class CType
{
public:
    
    eNativeType
        NativeType(
            )const;

    CType(
        eNativeType nativeType
        );

    ~CType();

private:
    const eNativeType 
        m_nativeType;
};


}

#endif
