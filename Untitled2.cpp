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
    if (s->n == 0) {
		printf("Empty stack");
	}

	for (int count = 0; count < (s->n); count++)
		printf("%d ", s -> a[count]);


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
	if (s -> n == s -> size)
	{
		s -> size += s -> n;
		s -> a = (Data *) realloc(s -> a, s -> size * sizeof(Data));
	}

	s -> a[s -> n] = x;
	s -> n ++;
}

struct Stack * stack_create(int size)
{
	struct Stack * stor = (struct Stack*) calloc(1, sizeof(struct Stack));
	stor -> a = (Data *) calloc(size, sizeof(Data));

    stor -> n    = 0;
	stor -> size = size;

	return stor;
}