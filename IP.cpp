#include <stdio.h>

int main()
{
    int a1, a2, a3, a4, m1, m2, m3, m4;
    a1 = a2 = a3 = a4 = m1 = m2 = m3 = m4 = 0;

    scanf ("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
    scanf ("%d.%d.%d.%d", &m1, &m2, &m3, &m4);

    int ip = 0, mask = 0;

    ip = a1;
    ip = (ip << 8) | a2;
    ip = (ip << 8) | a3;
    ip = (ip << 8) | a4;

    mask = m1;
    mask = (mask << 8) | m2;
    mask = (mask << 8) | m3;
    mask = (mask << 8) | m4;

    ip |= (~mask);

    int result[4] = {};

    for (int i = 3; i >= 0; --i) {
        result[i] = ip & 0xFF;
        ip >>= 8;
    }

    printf ("%d", result[0]);

    for (int i = 1; i < 4; ++i)
        printf (".%d", result[i]);

    return 0;
}