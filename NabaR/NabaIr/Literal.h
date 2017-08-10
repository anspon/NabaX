#ifndef NabaIr_CLiteral_H
#define NabaIr_CLiteral_H


#include "eNativeType.h"

namespace Naba
{
namespace Ir
{

class CLiteral
{
public:
    static Tk::Sp<const CLiteral>
        MakeInt32(
            int32_t value
            );
    static Tk::Sp<const CLiteral>
        MakeInt64(
            int64_t value
            );

    static Tk::Sp<const CLiteral>
        MakeDouble(
            double value
            );
    Tk::Sp<const CLiteral> 
        MakeBool(
            bool value
            );

    ~CLiteral();

    int32_t
        Int32(
            )const;

    int64_t
        Int64(
            )const;
    bool
        Bool(
            )const;

    double
        Double(
            )const;
    eNativeType 
        NativeType(
            )const;

protected:
    CLiteral();
private:
    eNativeType 
        m_nativeType;

    union
    {
        int64_t int64Value;
        int32_t int32Value;
        double doubleValue;
        bool boolValue;
    }m_;
};

}
}


#endif