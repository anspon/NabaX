#ifndef Tk_CNullableT
#define Tk_CNullableT

namespace Tk
{

template<class T>
class CNullableT
{
public:
        CNullableT(
            const T& t 
            );
        CNullableT(
            );
    const T&
        Value(
            )const;
    bool 
        HasValue(
        )const;
private:
    T 
        m_t;
    
    bool 
        m_hasValue;
};

}

#endif
