#ifndef Tk_MapFindOrThrow_H
#define Tk_MapFindOrThrow_H

namespace Tk
{

template<class T>
const T::value_type& 
    MapFindOrThrow(
        const T& map,
        const T::key_type& key,
        const char* exceptionText
        )
{
    auto it = map.find(key);
    TK_ASSERT( it != map.end(), exceptionText );
    return it->second;
}

}
