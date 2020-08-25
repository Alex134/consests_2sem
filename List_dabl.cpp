#include<stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};

void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);



void list_clear(struct Node * list)
{
    while (!list_is_empty(list)) list_pop_front (list);
}



int list_is_empty(struct Node * list)
{
    if ((list -> next == list) && (list -> prev == list)) return 1;
    else                                                  return 0;
}



void list_print (struct Node * list)
{
    for (Node *count = list -> next; count != list; count = count -> next)
            printf("%d ", count -> data);

    printf("\n");
}



Data list_pop_back(struct Node * list)
{
    return list_delete (list -> prev);
}



Data list_pop_front(struct Node * list)
{
    return list_delete (list -> next);
}



Data list_delete(struct Node * t)
{
    Data result = t -> data;

    list_remove (t);

    return result;
}



struct Node * list_push_back(struct Node * list, Data d)
{
    Node *new_element = (Node *) calloc (1, sizeof(Node));
    new_element -> data = d;

    list_insert_before (list, new_element);

    return new_element;
}



struct Node * list_push_front(struct Node * list, Data d)
{
    Node *new_element = (Node *) calloc (1, sizeof(Node));
    new_element -> data = d;

    list_insert (list, new_element);

    return new_element;
}



void list_remove(struct Node * t)
{
    Node *temp_next = t -> next;
    Node *temp_prev = t -> prev;

    if (temp_prev) temp_prev -> next = t -> next;
    if (temp_next) temp_next -> prev = t -> prev;

    free (t);
}



void list_init(struct Node * list)
{
    list -> prev = list -> next = list;
}



void list_insert (struct Node* list, struct Node* t)
{
        t -> next = list -> next;
        t -> prev = list;

        list -> next->prev = t;
        list -> next = t;

}



void list_insert_before (struct Node * list, struct Node * t)
{
    list_insert (list -> prev, t);
}



int main()
{
    struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));

	list_init(a);
	list_init(b);
	// End of test 1

	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);   // 9 8 7 6 5 4 3 2 1 0
	// End of test 2

	list_remove(&x[5]);
	list_print(a);
	list_remove(&x[0]);
	list_print(a);
	list_remove(&x[9]);
	list_print(a);
	// End of test 3

	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	// End of test 4

	while(!list_is_empty(a))
		list_remove(a->next);
	// End of test 5

	for(i=0; i<10; i++)
		list_push_back(a, i);
	list_print(a);
	// End of test 6

	for(i=0; i<10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	// End of test 7

	for(i=0; i<10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);
	// End of test 8

	for(i=0; i<10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	// End of test 9

	list_clear(a);
	list_clear(b);
	// End of test 10
}
