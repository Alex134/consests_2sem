#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef int Data;



struct Node {
    struct Node* next;
    struct Node* prev;
    Data data;
};


void list_init (struct Node* list);

void list_insert (struct Node* list, struct Node* t);
void list_insert_before (struct Node* list, struct Node* t);
void list_remove (struct Node* t);

struct Node* list_push_front (struct Node* list, Data d);
struct Node* list_push_back (struct Node* list, Data d);

Data list_pop_front (struct Node* list);
Data list_pop_back (struct Node* list);
Data list_delete (struct Node* t);

void list_print (struct Node* list);
int list_is_empty (struct Node* list);

void list_clear (struct Node* list);
void program_game (struct Node* pl1, struct Node* pl2);
Data compare (int a, int b);

int main()
{
    struct Node* qe1 = (struct Node*) calloc (1, sizeof (struct Node));
    struct Node* qe2 = (struct Node*) calloc (1, sizeof (struct Node));
    list_init (qe1);
    list_init (qe2);

    for (int i = 0; i < 5; i++) {
        int temp = 0;
        scanf ("%d", &temp);
        list_push_back (qe1, temp);

    }

    for (int count = 0; count < 5; count++) {
        int temp = 0;
        scanf ("%d", &temp);
        list_push_back (qe2, temp);

    }

    program_game (qe1, qe2);


    list_clear (qe1);
    list_clear (qe2);
    free (qe1);
    free (qe2);

    return 0;
}

void program_game (struct Node* qe1, struct Node* qe2)
{
    for (int count = 0; count < 1000000; count ++) {
        Data dat1 = list_pop_front (qe1);
        Data dat2 = list_pop_front (qe2);

        if (compare (dat1, dat2) > 0) {
            list_push_back (qe1, dat1);
            list_push_back (qe1, dat2);
        }

        else {
            list_push_back (qe2, dat1);
            list_push_back (qe2, dat2);

        }

        if (list_is_empty (qe1)) {
            printf ("second %d", count + 1);
            break;
        }

        else if (list_is_empty (qe2)) {
            printf ("first %d", count + 1);
            break;
        }

    }

}

Data compare (int a, int b)
{
    if (a == 0 && b == 9) {
        return 1;
    } else if (a == 9 && b == 0) {
        return -1;
    } else {
        return a - b;
    }

}

void list_clear (struct Node* list)
{
    while (!list_is_empty (list)) 
        list_pop_front (list);
}



int list_is_empty (struct Node* list)
{
    if ( (list -> next == list) && (list -> prev == list)) 
        return 1;
    else                                                  
    return 0;
}



void list_print (struct Node* list)
{
    for (Node* count = list -> next; count != list; count = count -> next)
        printf ("%d ", count -> data);

    printf ("\n");
}



Data list_pop_back (struct Node* list)
{
    return list_delete (list -> prev);
}



Data list_pop_front (struct Node* list)
{
    return list_delete (list -> next);
}



Data list_delete (struct Node* t)
{
    Data result = t -> data;

    list_remove (t);

    return result;
}



struct Node* list_push_back (struct Node* list, Data d)
{
    Node* new_element = (Node*) calloc (1, sizeof (Node));
    new_element -> data = d;

    list_insert_before (list, new_element);

    return new_element;
}



struct Node* list_push_front (struct Node* list, Data d)
{
    Node* new_element = (Node*) calloc (1, sizeof (Node));
    new_element -> data = d;

    list_insert (list, new_element);

    return new_element;
}



void list_remove (struct Node* t)
{
    Node* temp_next = t -> next;
    Node* temp_prev = t -> prev;

    if (temp_prev) 
        temp_prev -> next = t -> next;

    if (temp_next) 
        temp_next -> prev = t -> prev;

    free (t);
}



void list_init (struct Node* list)
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



void list_insert_before (struct Node* list, struct Node* t)
{
    list_insert (list -> prev, t);
}
