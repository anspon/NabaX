#include "NullableT.h"
#include "Exception.h"

namespace Tk
{

template<class T>
inline CNullableT<T>::CNullableT(
    const T& t
    )
{
    m_t = t;
    m_hasValue = true;
}
//--------------------------------------------------------------------------------------------------
template<class T>
inline CNullableT<T>::CNullableT()
{
    m_hasValue = false;
    m_t = T();
}
//--------------------------------------------------------------------------------------------------
template<class T>
inline const T & CNullableT<T>::Value() const
{
    TK_ASSERT(m_hasValue, "Value is null");
    return m_t;
}
//--------------------------------------------------------------------------------------------------
template<class T>
inline bool CNullableT<T>::HasValue() const
{
    return m_hasValue;
}
//--------------------------------------------------------------------------------------------------

}