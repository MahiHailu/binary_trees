#include <stdio.h>
#include <stdlib.h>

/* Definition for a binary tree node */
struct binary_tree_s {
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Function to find the LCA of two nodes */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second) {
    if (first == NULL || second == NULL)
        return NULL;

    /* Create sets to store ancestors of each node */
    binary_tree_t *ancestors1[1000] = {NULL};
    binary_tree_t *ancestors2[1000] = {NULL};

    /* Traverse from first node to root and store ancestors */
    int count1 = 0;
    while (first != NULL) {
        ancestors1[count1++] = (binary_tree_t *)first;
        first = first->parent;
    }

    /* Traverse from second node to root and store ancestors */
    int count2 = 0;
    while (second != NULL) {
        ancestors2[count2++] = (binary_tree_t *)second;
        second = second->parent;
    }

    /* Compare the ancestor sets to find the LCA */
    for (int i = count1 - 1; i >= 0; i--) {
        for (int j = count2 - 1; j >= 0; j--) {
            if (ancestors1[i] == ancestors2[j])
                return ancestors1[i];
        }
    }

    /* No common ancestor found */
    return NULL;
}

/* Example usage */
int main() {
    /* Create a sample binary tree */
    binary_tree_t *root = malloc(sizeof(binary_tree_t));
    root->n = 1;
    root->left = malloc(sizeof(binary_tree_t));
    root->left->n = 2;
    root->left->parent = root;
    root->right = malloc(sizeof(binary_tree_t));
    root->right->n = 3;
    root->right->parent = root;

    /* Set up nodes for testing */
    binary_tree_t *node1 = root->left;
    binary_tree_t *node2 = root->right;

    /* Find the LCA */
    binary_tree_t *lca = binary_trees_ancestor(node1, node2);
    if (lca)
        printf("Lowest Common Ancestor: %d\n", lca->n);
    else
        printf("No common ancestor found.\n");

    /* Clean up memory */
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
