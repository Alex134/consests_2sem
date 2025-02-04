#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;
    Data level;            // ������ � ����
    struct Node* left;   // ����� �������
    struct Node* right;  // ������ �������
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

int main () {
        struct Node * tree = NULL;
        int d;
        scanf("%d", &d);
        while(d) {
                tree = tree_add(tree, d);
                scanf("%d", &d);
        }
        scanf("%d", &d);
        
        tree_print_lvl(tree, d);
        tree_destroy(tree);
}