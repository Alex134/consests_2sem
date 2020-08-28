#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;
    Data level;            // данные в узле
    struct Node* left;   // левый ребенок
    struct Node* right;  // правый ребенок
};

struct Node* tree_add (struct Node* tree, Data x);
void tree_print (struct Node* tree);
void tree_destroy (struct Node* tree);
int tree_high (struct Node* tree);
void tree_lists (struct Node* tree);
int balans (struct Node* tree);
int max (int x, int y);
void tree_print_lvl (struct Node * tree, int n);

struct Node* tree_add (struct Node* tree, Data x)
{
    if (tree == NULL) {
        tree = (struct Node*) calloc (1, sizeof (struct Node));
        tree->val = x;
        tree->level = 0;
        tree->left = NULL;
        tree->right = NULL;
    } else {
        if (x - tree->val > 0) {
            tree-> right = tree_add (tree->right, x);
            tree->right->level = tree->level + 1;
        } else {
            if (x - tree->val < 0) {
                tree-> left = tree_add (tree->left, x);
                tree->left->level = tree->level + 1;
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

void tree_lists (struct Node* tree)
{
    if (tree != NULL) {
        if (tree->left != NULL || tree->right != NULL) {
            tree_lists (tree->left);
            tree_lists (tree->right);
        } else {
            printf ("%d ", tree->val);
        }
    }
}

void tree_print_lvl (struct Node * tree, int n) {
        if(tree != NULL && tree->level <= n) {
                tree_print_lvl(tree->left, n);
                if(tree->level == n) {
                        printf("%d ", tree->val);
                }
                tree_print_lvl(tree->right, n);
                
        }
}

int tree_high (struct Node* tree)
{
    if (tree == NULL) {
        return 0;
    } else {
        if (tree_high (tree->left) > tree_high (tree->right)) return tree_high (tree->left)  + 1;
        else                                                  return tree_high (tree->right) + 1;
    }
}

int main () {
        struct Node * tree = NULL;
        int val;
        scanf("%d", &val);
        while(val) {
                tree = tree_add(tree, val);

                scanf("%d", &val);
        }
        //scanf("%d", &d);
        for (int count = 0; count <= tree_high(tree); count ++) {
                tree_print_lvl(tree, count);
        }
        tree_destroy(tree);
}