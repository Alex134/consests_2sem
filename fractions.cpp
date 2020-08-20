#include <stdio.h>
#include <stdlib.h>

union U
{
    float f;
    unsigned int i;
};

void check()
{
    union U value {};

    value.f = 0.15625;
    char sign [1 + 1]      = {};
    char power [8 + 1]     = {};
    char mantissa [23 + 1] = {};

    //itoa (value.i >> 31, sign, 2);
    //itoa ((value.i >> 23) & 0xFF, power, 2)
    //itoa ( value.i & 0x3FFFFF, mantissa, 2)

    printf ("sign = (%s), power = (%8s), mantissa = (%23s)\n",
            itoa ( value.i >> 31,         sign,     2),
            itoa ((value.i >> 23) & 0xFF, power,    2),
            itoa ( value.i & 0x3FFFFF,    mantissa, 2));

}

int main ()
{

    check();

    return 0;
}
