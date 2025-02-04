#include <stdio.h>
#include <stdlib.h>


typedef char Data;

struct Stack {
    int n;
    int size;
    Data* a;
};

struct P {
    char first;
    char last;
} st_skob[] = {
    {'(', ')'},
    {'[', ']'},
    {'<', '>'},
    {'{', '}'}
};

struct Stack* stack_create (int size);
void stack_push (struct Stack* s, Data x);
Data stack_pop (struct Stack* s);
Data stack_get (struct Stack* s);
void stack_print (struct Stack* s);
int  stack_size (struct Stack* s);
int  stack_is_empty (struct Stack* s);
void stack_clear (struct Stack* s);
void stack_destroy (struct Stack* s);

void stack_destroy (struct Stack* s)
{
    free (s->a);
    free (s);

}

void stack_clear (struct Stack* s)
{
    free (s->a);

    s -> n    = 0;
    s -> size = 0;
    s -> a    = NULL;
}

int  stack_is_empty (struct Stack* s)
{
    if (s -> n == 0) return 1;
    else             return 0;
}

void stack_print (struct Stack* s)
{
    //printf("start\n");
    if (s->n == 0) {
        printf ("Empty stack\n");
    }

    for (int count = 0; count < (s->n); count++)
        printf ("%d ", s -> a[count]);

    //printf("end\n");

    printf ("\n");
}

int  stack_size (struct Stack* s)
{
    int size = s -> n --;

    return size;
}

Data stack_get (struct Stack* s)
{
    return s->a[s->n];

}
Data stack_pop (struct Stack* s)
{
    Data temp;
    s -> n --;
    temp = s -> a[s -> n];
    s -> size = s -> n;
    s -> a = (Data*) realloc (s -> a, s -> size * sizeof (Data));

    return temp;
}

void stack_push (struct Stack* s, Data x)
{
    //printf("start\n");
    if (s -> n == s -> size) {
        s -> size += s -> n;
        s -> a = (Data*) realloc (s -> a, s -> size * sizeof (Data));
    }

    s -> a[s -> n] = x;
    s -> n ++;
    //printf("end\n");
}

struct Stack* stack_create (int size)
{
    //printf("start\n");
    struct Stack* stor = (Stack*) calloc (1, sizeof (struct Stack));
    stor -> a = (Data*) calloc (size, sizeof (Data));

    stor -> n    = 0;
    stor -> size = size;


    //printf("end\n");

    return stor;
}


int main()
{
    struct Stack* s = stack_create (5);
    Data sim, temp;
    int res_scanf = 1, flag = 1;

    while (res_scanf == 1) {
        if (scanf ("%c", &sim) != 1) {
            res_scanf = 0;
            break;
        }

        for (int first_count = 0; first_count < 4; first_count++) {
            if (sim == st_skob[first_count].first)
                stack_push (s, sim);

        }

        for (int count = 0; count < 4; count++) {
            if ((sim == st_skob[count].last) && (stack_is_empty (s) == 0)) {
            temp = stack_pop (s);

                if (temp != st_skob[count].first) flag = 0;
            }
        }
    }

    if ((flag == 1) && (stack_is_empty (s) == 1)) printf ("YES\n");
            else                                  printf ("NO \n");

                stack_destroy (s);

                return 0;
    }
