#include <stdint.h>
void Banana(
    const int32_t& k
    )
{
    void* apa2;
    void* apa2_1;
    int32_t j;
    apa2 = 0;
    apa2_1 = apa2;
    j = k;
}
//--------------------------------------------------------------------------------------------------
void Function2(
    const int32_t& k, 
    const int64_t& p
    )
{
    int32_t k1;
    int64_t p1;
    k1 = k;
    p1 = p;
}
//--------------------------------------------------------------------------------------------------
void Main(
    )
{
    int32_t i;
    int32_t anonymous5;
    int32_t k;
    int32_t anonymous6;
    int64_t j;
    int32_t anonymous7;
    int32_t anonymous8;
    void* apa;
    int32_t anonymous9;
    int64_t anonymous10;
    int32_t j2;
    int32_t anonymous11;
    bool isEqual;
    bool anonymous12;
    bool isLess;
    bool anonymous13;
    bool isLarger;
    bool anonymous14;
    bool notEqual;
    bool anonymous15;
    bool anonymous16;
    bool anonymous17;
    anonymous5 = int32_t(1);
    i = anonymous5;
    anonymous6 = int32_t(1);
    k = anonymous6;
    j = 0;
    Banana(i);
    anonymous7 = int32_t(7);
    Banana(anonymous7);
    anonymous8 = int32_t(99);
    Banana(anonymous8);
    apa = 0;
    anonymous9 = int32_t(99);
    anonymous10 = int64_t(17);
    Function2(anonymous9, anonymous10);
    anonymous11 = int32_t(7);
    j2 = anonymous11;
    anonymous12 = ( i == k );
    isEqual = anonymous12;
    anonymous13 = ( i < k );
    isLess = anonymous13;
    anonymous14 = ( i > k );
    isLarger = anonymous14;
    anonymous15 = ( i != k );
    notEqual = anonymous15;
    anonymous17 = ( i < k );
    anonymous16 = anonymous17;

    while( anonymous16 )
    {
        bool anonymous18;
        bool anonymous19;
        int32_t anonymous21;
        int32_t anonymous22;
        bool anonymous23;
        anonymous19 = ( j < k );
        anonymous18 = anonymous19;

        while( anonymous18 )
        {
            bool anonymous20;
            anonymous20 = ( j < k );
            anonymous18 = anonymous20;
        }

        anonymous21 = int32_t(1);
        anonymous22 = i;
        anonymous22 += anonymous21;
        i = anonymous22;
        anonymous23 = ( i < k );
        anonymous16 = anonymous23;
    }

}
//--------------------------------------------------------------------------------------------------
int main(int argv, const char** argc ){Main();return 0;}