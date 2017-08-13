#ifndef Tk_SharedPtr_H
#define Tk_SharedPtr_H

#include "TkPchHeaders.h"

namespace Tk
{

template<typename T>
using Sp = std::shared_ptr<T>;

template<typename T>
using WeakSp = std::weak_ptr<T>;

template<typename T>
using EnableSharedSp = std::enable_shared_from_this<T>;

#define DECLARE_SHARED_FROM_THIS(T)\
    Tk::Sp<T> SharedThis(){return std::static_pointer_cast<T>(shared_from_this());}

template<class _Ty1, class _Ty2>
Sp<_Ty1> DynamicCast(const Sp<_Ty2>& _Other)
{	
    return std::dynamic_pointer_cast<_Ty1, _Ty2>(_Other);
}

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
