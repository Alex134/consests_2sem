#include <stdio.h>

typedef union {
    float f;
    unsigned int n;
} fract;



int main()
{
    fract val;

    scanf ("%f", & (val.f));

    if (val.f == 0) {
        printf ("0(0/1)");
        return 0;
    }

    int sign = 0, exponent = 0;
    int numerator = 0, denominator = 0;

    sign = val.n >> 31;

    exponent = ( (val.n >> 23) & 0b11111111) - 127;

    numerator = ( (val.n << 9) >> 9) + (1 << 23);

    int count = 0;

    while ( (numerator & 1) == 0) {
        numerator >>= 1;
        count++;

        if (count >= 23 - exponent)
            break;
    }

    denominator = 1 << (23 - count - exponent);

    if (sign) {
        printf ("-");
    }

    if (exponent >= 0) {
        printf ("%d", numerator / denominator);
        numerator %= denominator;
    } else
        printf ("0");

    printf ("(%d/%d)", numerator, denominator);

    printf ("\n");
    return 0;
}
