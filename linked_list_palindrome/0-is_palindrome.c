#include "lists.h"


int listint_len(listint_t *head)
{
	listint_t *current = head;
	int i = 0;

	while (current != NULL)
	{
		current = current->next;
		i++;
	}

	return (i);
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int i = 0;
	const size_t length = listint_len(*head);
	listint_t *current = *head;

	int array[length];

	while (current->next != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}

	for (i = 0; i < listint_len(*head); i++)
	{
		if (array[i] != array[listint_len(*head) - 1 - i])
			return (0);
	}

	return (1);
}
