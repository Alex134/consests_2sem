#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



typedef int Data;

struct Stack {
    int n;
    int size;
    Data* a;
};

struct ar_struct {
    int number;
    char simvol;
} arr_num [] = {
    { 0, '+' },
    { 1, '-' },
    { 2, '*' },
};

struct Stack* stack_create (int size);
void           stack_push (struct Stack* s, Data x);
Data           stack_pop (struct Stack* s);
Data           stack_get (struct Stack* s);
void           stack_print (struct Stack* s);
int            stack_size (struct Stack* s);
int            stack_is_empty (struct Stack* s);
void           stack_clear (struct Stack* s);
void           stack_destroy (struct Stack* s);
int            multi (int x, int y);
int            plus (int x, int y);
int            minus (int x, int y);

int main()
{
    char simb;
    int (* program_func[5])(int x, int y);
        program_func[0] = &plus;
        program_func[1] = &minus;
        program_func[2] = &multi;
    struct Stack* s = stack_create (7);

    scanf ("%c", &simb);

    while (simb != '=') {
//printf("1");
        if (isdigit (simb) != 0) {
            stack_push (s, simb - '0');
//printf("2");
        } else {
            for (int count = 0; count < 3; count++) {
//printf("3");
                if (simb == arr_num[count].simvol) {
//printf("4");
                    int x = stack_pop (s);
                    int y = stack_pop (s);
//printf("4.5");
                    x = program_func[count] (x, y);
                    stack_push (s, x);
//1
//printf("5");
                }
            }
        }

        scanf ("%c", &simb);
    }

    printf ("%d", stack_pop (s));

    stack_destroy (s);

    return 0;
}





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

int plus (int x, int y)
{
    return x + y;
}

int minus (int x, int y)
{
    return x - y;
}

int multi (int x, int y)
{
    return x*y;
}
