#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

static int lookup(Node* n, int target)
{
    // 1. Base case == empty tree
    //      target is not found so return false
    if (n == NULL) {
        return false;
    } else {
        // 2. see if found here
        if (target == n->data) {
            return true;
        } else {
            // 3. otherwise recur down the correct subtree
            if (target < n->data) {
                return lookup(n->left, target);
            } else {
                return lookup(n->right, target);
            }
        }
    }
}

Node* NewNode(int data)
{
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* n, int data)
{
    if (n == NULL) {
        return NewNode(data);
    } else {
        if (data <= n->data) {
            n->left = insert(n->left, data);
        } else {
            n->right = insert(n->right, data);
        }
        return n;
    }
}
