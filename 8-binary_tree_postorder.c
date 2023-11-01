#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse binary tree
 * post-order traversal
 * @tree: Pointer to the root node of the tree being traversed.
 * @func: Pointer to a function to called on each node.
 *
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
