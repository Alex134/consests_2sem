#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;            // ������ � ����
    struct Node* left;   // ����� �������
    struct Node* right;  // ������ �������
};

struct Node* tree_add (struct Node* tree, Data x);
void tree_print (struct Node* tree);
void tree_destroy (struct Node * tree);

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
            } else {
                if (x != tree->val) {
                    printf ("EROR\n");
                }
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

void tree_destroy (struct Node * tree) {
        if(tree != NULL) {
                if(tree->left !=NULL) {
                        tree_destroy (tree->left);
                }
                if(tree->right !=NULL) {
                        tree_destroy (tree->right);
                }
                free(tree);
        }
}


int main()
{
    struct Node* tree = NULL;
    tree = tree_add (tree, 7);
    tree = tree_add (tree, 3);
    tree = tree_add (tree, 2);
    tree = tree_add (tree, 1);
    tree = tree_add (tree, 9);
    tree = tree_add (tree, 5);
    tree = tree_add (tree, 4);
    tree = tree_add (tree, 6);
    tree = tree_add (tree, 8);
    tree_print (tree);
    
    tree_destroy(tree);

    return 0;
}