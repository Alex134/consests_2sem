struct Stack * stack_create(int size)
{

	struct Stack * stor = (Stack*) calloc(1, sizeof(struct Stack));
	stor -> a = (Data *) calloc(size, sizeof(Data));

    stor -> n    = 0;
	stor -> size = size;



	return stor;
}
