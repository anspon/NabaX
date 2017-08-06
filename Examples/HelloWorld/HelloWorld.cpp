#include <stdint.h>
void MyFirstFunction(
    const int32_t& in1
    )
{
    int32_t i;
    int64_t j;
    i = 0;
    j = 0;
    i = in1;
}
//--------------------------------------------------------------------------------------------------
void Main(
    )
{
    int32_t i;
    int64_t j;
    int32_t k;
    int32_t loop;
    loop = int32_t(-10);
    while( loop )
    {
        loop += int32_t(1);
    }
    k = int32_t(10);
    i = 0;
    j = 0;
    i = int32_t(33);
    j = int64_t(55);
    i += k;
    MyFirstFunction(i);
}
//--------------------------------------------------------------------------------------------------
int main(int argv, const char** argc ){Main();return 0;}