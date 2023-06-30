#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on fail
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int mid;

	if (!array || size < 1)
		return (NULL);

	mid = (size - 1) / 2;

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);

	root->n = array[mid];
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;

	if (mid > 0)
		root->left = sorted_array_to_avl(array, mid);

	if (size - mid - 1 > 0)
		root->right = sorted_array_to_avl(&array[mid + 1], size - mid - 1);

	if (root->left)
		root->left->parent = root;

	if (root->right)
		root->right->parent = root;

	return (root);
}
