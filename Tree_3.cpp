#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node* left;   // левый ребенок
    struct Node* right;  // правый ребенок
};

struct Node* tree_add (struct Node* tree, Data x);
void tree_print (struct Node* tree);
void tree_destroy (struct Node* tree);

struct Node* tree_add (struct Node* tree, Data x)
{
    if (tree == NULL) {
        tree = (struct Node*) calloc (1, sizeof (struct Node));
        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (x - tree->val > 0) {
            tree-> right = tree_add (tree->right, x);
        } else {
            if (x - tree->val < 0) {
                tree-> left = tree_add (tree->left, x);
            } 
        }
    }

    return tree;
}

void tree_print (struct Node* tree)
{
    if (tree != NULL) {
        tree_print (tree -> left);
        printf ("%d ", tree -> val);
        tree_print (tree -> right);
    }
}

void tree_destroy (struct Node* tree)
{
    if (tree != NULL) {
        if (tree->left != NULL) {
            tree_destroy (tree->left);
        }

        if (tree->right != NULL) {
            tree_destroy (tree->right);
        }

        free (tree);
    }
}


int main ()
{
    struct Node* tree = NULL;
    int d;
    scanf ("%d", &d);

    while (d) {
        tree = tree_add (tree, d);
        scanf ("%d", &d);
    }

    tree_print (tree);
    tree_destroy (tree);
}
