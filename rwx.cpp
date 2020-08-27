#include <stdio.h>

struct pravo {
        int number;
        char * enter[2];
} prava[] = {
        {0, {"-", "x"}},
        {1, {"-", "w"}},
        {2, {"-", "r"}},
};


int main () {
        int x;
        scanf ("%o", &x);

        for (int i = 2; i >= 0; i--) 
        {
            for(int count = 2; count >= 0; count--)
            {   
                printf("%s", prava[count].enter[(x >> (3 * i + prava[count].number)) & 1]);
            }
        }
        printf ("\n");
        return 0;
}