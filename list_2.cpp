#include<stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node {
    Data val;
    struct Node * next;
};

typedef struct Node * List;

List list_create ();
void list_push (List * plist, Data x);
Data list_pop (List * plist);
Data list_get(List list);
void list_print (List list);
int list_size(List list);
void list_clear(List * plist);

List list_create ()
{
    Node  *pointer = calloc (1, sizeof(List));
    ponter = NULL;

    return pointer;
}

int main()
{
    return 0;
}
