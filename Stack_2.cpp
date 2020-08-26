#include <stdio.h>
#include <stdlib.h>



typedef int Data;

struct Stack {
    int n;
    int size;
    Data * a;
};

struct Stack * stack_create(int size);
void stack_push(struct Stack * s, Data x);
Data stack_pop(struct Stack * s);
Data stack_get(struct Stack * s);
void stack_print(struct Stack * s);
int  stack_size(struct Stack * s);
int  stack_is_empty(struct Stack * s);
void stack_clear(struct Stack * s);
void stack_destroy(struct Stack * s);

void stack_destroy(struct Stack * s)
{
    free(s->a);
	free(s);

}

void stack_clear(struct Stack * s)
{
    free(s->a);

    s -> n    = 0;
	s -> size = 0;
	s -> a    = NULL;
}

int  stack_is_empty(struct Stack * s)
{
    if (s -> n == 0) return 1;
    else             return 0;
}

void stack_print(struct Stack * s)
{
    //printf("start\n");
    if (s->n == 0) {
		printf("Empty stack\n");
	}

	for (int count = 0; count < (s->n); count++)
		printf("%d ", s -> a[count]);

    //printf("end\n");

	printf("\n");
}

int  stack_size(struct Stack * s)
{
    int size = s -> n --;

    return size;
}

Data stack_get(struct Stack * s)
{
	return s->a[s->n];

}
Data stack_pop(struct Stack * s)
{
	Data temp;
	s -> n --;
	temp = s -> a[s -> n];
	s -> size = s -> n;
	s -> a = (Data *) realloc(s -> a, s -> size * sizeof(Data));

	return temp;
}

void stack_push(struct Stack * s, Data x)
{
    //printf("start\n");
	if (s -> n == s -> size)
	{
		s -> size += s -> n;
		s -> a = (Data *) realloc(s -> a, s -> size * sizeof(Data));
	}

	s -> a[s -> n] = x;
	s -> n ++;
	//printf("end\n");
}

struct Stack * stack_create(int size)
{
    //printf("start\n");
	struct Stack * stor = (Stack*) calloc(1, sizeof(struct Stack));
	stor -> a = (Data *) calloc(size, sizeof(Data));

    stor -> n    = 0;
	stor -> size = size;


	//printf("end\n");

	return stor;
}


int main()
{
struct Stack * sp = stack_create(3);

stack_push(sp, 5);
stack_push(sp, 19);
stack_push(sp, -2);
stack_print(sp);
// 5 19 -2

stack_push(sp, 27);
stack_print(sp);
// 5 19 -2 27
printf("is_empty=%d\n", stack_is_empty(sp));
// is_empty=0
int x;
x = stack_pop(sp);
printf("x=%d\n", x);
// x=27

x = stack_pop(sp);
printf("x=%d\n", x);
// x=-2

stack_print(sp);
// 5 19

while (!stack_is_empty(sp)) {
    stack_pop(sp);
    stack_print(sp);
}
// 5
// Empty stack

stack_destroy(sp);

return 0;

}

