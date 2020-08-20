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

struct Node * list_push_front(struct Node * list, Data d)
{

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
    return 0;
}
