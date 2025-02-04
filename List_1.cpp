#include <stdio.h>
#include <stdlib.h>


typedef int Data;

struct Node
    {
    Data val;
    struct Node* next;
    };

typedef struct Node* List;

List list_create ();
void list_push (List* plist, Data x);
Data list_pop (List* plist);
Data list_get (List list);
void list_print (List list);
int list_size (List list);
void list_clear (List* plist);
int list_is_empty (List list);

List list_create()
    {
    List tmp = (List) calloc (1, sizeof (struct Node));
    tmp -> next = NULL;
    tmp -> val = 0;
    return tmp;
    }



void list_push (List* plist, Data x)
    {
    List n = (List) calloc (1, sizeof (struct Node));
    n -> val = x;
    n -> next = * plist;
    * plist = n;
    }


Data list_pop (List* plist)
    {
    Data a = (*plist) -> val;
    List temp = *plist;

    * plist = (*plist) -> next;
    free (temp);

    return a;
    }


Data list_get (List list)
    {
    return list -> val;
    }


void list_print (List list)
    {
    if (list -> next == NULL)
        {
        printf ("Empty stack\n");

        return;
        }

    while (list->next != NULL)
        {
        printf ("%d ", list->val);

        list = list->next;
        }

    printf ("\n");
    }

int list_size (List list)
    {
    int count = 0;

    while (list->next != NULL)
        {
        count++;
        list = list -> next;
        }

    return count;
    }


int list_is_empty (List list)
    {
    if (list -> next != NULL)
        return 0;

    return 1;
    }


void list_clear (List* plist)
    {
    List temp = *plist;

    while (temp != NULL)
        {
        *plist = (*plist) -> next;
        free (temp);
        temp = *plist;
        }
    }
