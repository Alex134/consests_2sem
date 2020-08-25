#include <stdio.h>
#include <stdlib.h>

#define N 100
typedef int Data;

struct Stack
    {
    int n;
    Data a[N];
    };

void stack_create (struct Stack* s);
void stack_push (struct Stack* s, Data x);
Data stack_pop (struct Stack* s);
Data stack_get (struct Stack* s);
void stack_print (struct Stack* s);
int  stack_size (struct Stack* s);
void stack_clear (struct Stack* s);

void stack_clear (struct Stack* s)
    {
    for (int count = 0; count < s -> n; count++)
        s -> a[count] = 0;

    s -> n = 0;
    }

int  stack_size (struct Stack* s)
    {
    int size = s -> n--;

    return size;
    }

void stack_print (struct Stack* s)
    {
    if (s -> n == 0) printf ("Empty stack");
    else
    for (int count = 0; count < s -> n; count ++)
        printf ("%d ", s -> a[count]);

    printf ("\n");
    }

Data stack_get (struct Stack* s)
    {
    Data temp = s -> a[s -> n];

    return temp;
    }

Data stack_pop (struct Stack* s)
    {
    Data temp;
    s -> n--;
    temp = s -> a[s -> n];

    return temp;
    }

void stack_push (struct Stack* s, Data x)
    {
    s->a[s->n] = x;
    s->n ++;
    }


void stack_create (struct Stack* s)
    {
    s -> n = 0;
    }

int main()
    {
    int x = 0;
    struct Stack s;
    stack_create (&s);
    stack_push (&s, 5);
    stack_print (&s);
    stack_push (&s, 19);
    stack_print (&s);
    x = stack_size (&s);
    printf ("size=%d\n", x);
    x = stack_pop (&s);
    printf ("x=%d\n", x);
    stack_print (&s);
    x = stack_pop (&s);
    printf ("x=%d\n", x);
    stack_print (&s);
    }
