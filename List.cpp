#include<stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};

struct Node * list_create ();
struct Node * list_push (struct Node * list, Data x);
struct Node * list_pop (struct Node * list, Data * px);
Data list_get(struct Node * list);
void list_print (struct Node * list);
int list_size(struct Node * list);
int list_is_empty(struct Node * list);
struct Node *list_clear(struct Node * list);

struct Node *list_clear(struct Node * list)
{
    //printf ("Clear is start\n");
    Node *pointer = list;

    for (Node *count = list; count != NULL; pointer = count)
    {
        count = pointer -> next;
        free (pointer);
    }
    //printf("clear is finish\n");
    return pointer;
}

int list_is_empty(struct Node * list)
{
    //printf("empty is start\n");
    if (list == NULL) return 1;
    else              return 0;
    //printf("empty is finish");
}

int list_size(struct Node * list)
{
    //printf("size id start\n");
    int size = 0;

    for ( Node * counter = list; counter != NULL; counter = counter -> next)
        size++;
    //printf ("size is finish");
    return size;
}


void list_print (struct Node * list)
{
    //printf("print is start");
    for ( Node * counter = list; counter != NULL; counter = counter -> next)
        printf ("%d ", counter -> val);

    //printf("print is finish\n");
}

Data list_get(struct Node * list)
{
    //printf("get is start and finish\n");
    return list -> val;
}

struct Node *list_create ()
{
    //printf("create is start\n");
    Node *pointer = (Node *) calloc(1, sizeof(Node));
    pointer = NULL;
    //printf("create is finish\n");
    return pointer;
}

struct Node *list_push (struct Node * list, Data x)
{
    //printf("push is start\n");
    Node *temp = (Node *) calloc(1, sizeof(Node));

    temp->next = list;
    temp->val  = x;
     //printf("push is finifh\n");
    return temp;
}

struct Node * list_pop (struct Node * list, Data * px)
{
    //printf("pop is start\n");
    Node *pointer = list -> next;
    *px = list -> val;

    free (list);
    //printf("pop is finish\n");
    return (pointer);
}



int main()
{
    Data x;
        struct Node * list = list_create();
        list = list_push(list, 5);
        list_print(list);
        list = list_pop(list, &x);
        printf("x = %d\n", x);
        list = list_clear(list);
}
