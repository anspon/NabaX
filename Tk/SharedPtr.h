#ifndef Tk_SharedPtr_H
#define Tk_SharedPtr_H

#include "TkPchHeaders.h"

namespace Tk
{

template<typename T>
using Sp = std::shared_ptr<T>;

template<typename T, class... _Types>
Sp<T> MakeSp(_Types&&... _Args)
{
    return std::make_shared<T>(std::forward<_Types>(_Args)...);
}

template<typename T>
using SpList = std::list< Sp<T> >;

template<typename TKey, typename TValue>
using SpMap = std::map< TKey, Sp<TValue> >;

template<class T>
Sp<T> AttachSp( T* naked )
{
    return Sp<T>(naked);
}


}


#endif
