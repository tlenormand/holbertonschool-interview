#include <stdlib.h>
#include "binary_trees.h"


/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: double pointer to the root node of the Heap
* @value: value store in the node to be inserted
* Return: pointer to the inserted node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;

	if (root == NULL)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
		return (*root = new_node);

	parent = find_parent(*root);
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;

	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap_nodes(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}


/**
* find_parent - finds the parent node of the next node to be inserted
* @root: pointer to the root node of the Heap
* Return: pointer to the parent node
*/

heap_t *find_parent(heap_t *root)
{
	heap_t *parent = NULL;
	heap_t *head = NULL;
	heap_t *temp = NULL;

	if (root == NULL)
		return (NULL);

	head = root;
	while (head != NULL)
	{
		if (head->left == NULL || head->right == NULL)
			return (head);

		temp = head->left;
		head->left = head->right;
		head->right = temp;
		head = head->left;
	}

	return (parent);
}


/**
* swap_nodes - swaps the values of two nodes
* @node1: pointer to the first node
* @node2: pointer to the second node
*/

void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	if (node1 == NULL || node2 == NULL)
		return;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}
