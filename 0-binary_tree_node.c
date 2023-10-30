#include "binary_trees.h"

/**
 * binary_tree_node - Function to creates a binary tree node.
 * @parent: Pointer the parent node being created.
 * @value: The value to insert into the new node.
 *
 * Return: Pointer the new node, or NULL in case of error.
 *
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
