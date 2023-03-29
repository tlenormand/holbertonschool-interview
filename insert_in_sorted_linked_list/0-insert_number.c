#include <stdlib.h>
#include "lists.h"

/**
* insert_node - inserts a number into a sorted singly linked list.
* @head: pointer to the head of the list
* @number: number to insert
* Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current = *head;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	if (current->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}

	while (current->next && current->n < number)
	{
		if (current->next->n >= number)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (*head);
		}

		current = current->next;
	}

	current->next = new_node;
	return (*head);
}
