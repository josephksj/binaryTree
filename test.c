#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//========= Binary Tree ============
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if(ptr == NULL)
        return NULL;
    ptr->value = value;
    ptr->left = ptr->right = NULL;

    return ptr;
}

Node *insert_node(Node *root, int value)
{
    if(root == NULL) {
        return newNode(value);
    }
    if(root->value > value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    return root;
}

int contains(const Node *root, int value)
{
    int count=0;
    if(root == NULL) return 0;
    if(root->value == value) return 1;
    if(root->value > value) {
        return contains(root->left, value);
    } else {
        return contains(root->right, value);
    }
}
void traverse_tree(Node *root)
{
    if(root == NULL) return;
    traverse_tree(root->left);
    printf("%d  ", root->value);
    traverse_tree(root->right);
}

int main()
{
    Node *root=NULL;

    int arr[] = {5, 7, 6, 9, 8, 11, 10, 12, 3, 4, 1, 2, 0};
    int len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++) {
        root = insert_node(root, arr[i]);
    }

    traverse_tree(root);
    printf("\n");
    return 0;
 }


