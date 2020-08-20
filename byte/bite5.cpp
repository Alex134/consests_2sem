#include <stdio.h>
#include <string.h>

int bit5();

int bit5()
{
    int scanf_result = 1;
    unsigned int finish_result = 0;

    for (int i_string = 0; scanf_result == 1; i_string++)
    {
        char string[4] = "";
        scanf_result = scanf ("%s", string);
        if (scanf_result != 1) break;

        if (strcmp(string, "ma") == 0)
            finish_result = finish_result | 0x01;
        else
//      if (strcmp(string, "fe") == 0) finish_result = finish_result | 0x00;
//      else
        if (strcmp(string, "cl") == 0)
            finish_result = finish_result | 0x02;
        else
//      if (strcmp(string, "du") == 0) finish_result = finish_result | 0x00;
//      else
        if (strcmp(string, "ha") == 0)
            finish_result = finish_result | 0x04;
        else
//      if (strcmp(string, "nh") == 0) finish_result = finish_result | 0x00;
//      else
        if (strcmp(string, "tr") == 0)
            finish_result = finish_result | 0x08;
//      else
//      if (strcmp(string, "sk") == 0) finish_result = finish_result | 0x00;
//      printf("error in string : (%s)\n", string);
        if (strcmp(string, "rd") == 0)
            finish_result = finish_result | 0x10;
        else
        if (strcmp(string, "bw") == 0)
            finish_result = finish_result | 0x20;
        else
        if (strcmp(string, "bk") == 0)
            finish_result = finish_result | 0x30;
        else
        if (strcmp(string, "ge") == 0)
            finish_result = finish_result | 0x40;
        else
        if (strcmp(string, "gy") == 0)
            finish_result = finish_result | 0x80;
        else
        if (strcmp(string, "da") == 0)
            finish_result = finish_result | 0xC0;
//      printf ("string - (%s)\n", string);

    }

    return finish_result;
}

int main()
{
    printf ("%x", bit5());

    return 0;
}
