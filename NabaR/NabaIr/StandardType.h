#ifndef NabaIr_CInt64_H
#define NabaIr_CInt64_H

#include "Type.h"
#include "eStandardType.h"

namespace NabaIr
{

class CStandardType : public CType
{
    using BaseClass = CType;
    friend class CTypeManager;

public:    
    ~CStandardType();

protected:
    CStandardType(
        eNativeType nativeType,
        eStandardType standardType
        );

    eStandardType 
        Type(
            )const;

private:
    eStandardType 
        m_standardType;
};

}


#endif