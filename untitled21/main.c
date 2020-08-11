#include <stdio.h>

void sex()
{
    int sex_prop;
    scanf("%x", &sex_prop);

    if (sex_prop&1) printf("ma\n");
    else     printf("fe\n");
}

void print_color()
{
    int prop = 0;
    scanf ("%x", &prop);

    prop = (prop & 0x30) >> 4;

    if (prop == 0) printf("bn\n");
    if (prop == 1) printf("rd\n");
    if (prop == 2) printf("bw\n");
    if (prop == 3) printf("bk\n");
}

void printf_color_1()
{
    int prop = 0;
    scanf ("%x", &prop);

    switch ((prop & 0x30) >> 4)
    {
        case 0: printf("bn\n"); break;

        case 1: printf("rd\n"); break;

        case 2: printf("bw\n"); break;

        case 3: printf("bk\n"); break;
    }
}

void print_color_2()
{
    int prop = 0;
    scanf ("%x", &prop);

    char *prop_names[4] = {"bn", "rd", "bw", "bk"};

    printf ("%s", prop_names[(prop & 0x30) >> 4]);
}

void print_color_3()
{
    struct bit_prop
    {
        unsigned int sex      : 1;
        unsigned int smart    : 1;
        unsigned int cap      : 1;
        unsigned int trousers : 1;
        unsigned int color    : 2;
        unsigned int eyes     : 2;

        unsigned int vacuum   : 24;
    };

    struct bit_prop prop = {};
    scanf("%x", &prop);

    char *prop_names[4] = {"bn", "rd", "bw", "bk"};

    printf ("%s\n", prop_names[prop.color]);
}

void all_param()
{
    int prop = 0;
    scanf ("%x", &prop);

    char *sex_names    [2] = {"fe", "ma"};
    char *smart_names  [2] = {"du", "cl"};
    char *hat_names    [2] = {"nh", "ha"};
    char *skirt_names  [2] = {"sk", "tr"};
    char *color_names  [4] = {"bn", "rd", "bw", "bk"};
    char *eyes_names   [4] = {"bu", "ge", "gy", "da"};

    printf ("%s ", sex_names  [prop & 0x01]);
    printf ("%s ", smart_names[(prop & 0x02) >> 1]);
    printf ("%s ", hat_names  [(prop & 0x04) >> 2]);
    printf ("%s ", skirt_names[(prop & 0x08) >> 3]);
    printf ("%s ", color_names[(prop & 0x30) >> 4]);
    printf ("%s ", eyes_names [(prop & 0xC0) >> 6]);
}

int main ()
{
    all_param();

    return 0;
}
