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
void Main(
    )
{
    int32_t i;
    int32_t anonymous1;
    int64_t j;
    int32_t anonymous2;
    int32_t anonymous3;
    void* apa;
    int32_t anonymous4;
    anonymous1 = int32_t(1);
    i = anonymous1;
    j = 0;
    Banana(i);
    anonymous2 = int32_t(7);
    Banana(anonymous2);
    anonymous3 = int32_t(99);
    Banana(anonymous3);
    apa = 0;
    anonymous4 = int32_t(7);
    j = anonymous4;
}
//--------------------------------------------------------------------------------------------------
int main(int argv, const char** argc ){Main();return 0;}