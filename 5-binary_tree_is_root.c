#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if the specified node is the root.
 * @node: Pointer to the node to check
 * Return: 1 if the node is the root.
 * Otherwise - return to 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
