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
int tree_high (struct Node* tree);
void tree_lists (struct Node* tree);
int balans (struct Node* tree);
int max (int x, int y);

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

int balans (struct Node* tree)
{
    int left, right;

    if (tree == NULL) {
        return - 1;
    } else {
        if (tree->left == NULL && tree->right == NULL) {
            return 0;
        } else {
            left = balans (tree->left);
            right = balans (tree->right);

            if (left == -5 || right == - 5) {
                return -5;
            } else {
                if (left - right <= 1 && right - left <= 1) {
                    return max (left, right) + 1;
                } else {
                    return - 5;
                }
            }
        }
    }
}

int max (int x, int y)
{
    if (x > y) return x;
    else       return y;
}

int main () {
        struct Node * tree = NULL;
        int val;
        scanf("%d", &val);
        while(val) {
                tree = tree_add(tree, val);
                scanf("%d", &val);
        }
        if(balans(tree) == -5) {
                printf("NO\n");
        }
        else {
                printf("YES\n");
        }
        tree_destroy(tree);
}
