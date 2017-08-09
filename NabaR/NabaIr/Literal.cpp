#include "NabaIrPch.h"
#include "Literal.h"

//--------------------------------------------------------------------------------------------------

namespace NabaIr
{
CLiteral::CLiteral(
    )
{
}
//--------------------------------------------------------------------------------------------------
CLiteral::~CLiteral()
{
}
//--------------------------------------------------------------------------------------------------
int32_t CLiteral::Int32() const
{
    return m_.int32Value;
}
//--------------------------------------------------------------------------------------------------
int64_t CLiteral::Int64() const
{
    return m_.int64Value;
}
//--------------------------------------------------------------------------------------------------
bool CLiteral::Bool() const
{
    return m_.boolValue;
}
//--------------------------------------------------------------------------------------------------
double CLiteral::Double() const
{
    return m_.doubleValue;
}
//--------------------------------------------------------------------------------------------------
eNativeType CLiteral::NativeType() const
{
    return m_nativeType;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CLiteral> CLiteral::MakeInt32(
    int32_t value
    )
{
    Tk::Sp<CLiteral> instance(new CLiteral);
    instance->m_nativeType = ntInt32;
    instance->m_.int32Value = value;
    return instance;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CLiteral> CLiteral::MakeInt64(
    int64_t value
    )
{
    Tk::Sp<CLiteral> instance(new CLiteral);
    instance->m_nativeType = ntInt64;
    instance->m_.int64Value = value;
    return instance;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CLiteral> CLiteral::MakeDouble(
    double value
    )
{
    Tk::Sp<CLiteral> instance(new CLiteral);
    instance->m_nativeType = ntDouble;
    instance->m_.doubleValue = value;
    return instance;
}
//--------------------------------------------------------------------------------------------------
Tk::Sp<const CLiteral> CLiteral::MakeBool(
    bool value
    )
{
    Tk::Sp<CLiteral> instance(new CLiteral);
    instance->m_nativeType = ntBool;
    instance->m_.boolValue = value;
    return instance;
}
}