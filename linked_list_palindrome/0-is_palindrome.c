#include "lists.h"


int listint_len(listint_t *head)
{
	listint_t *current = head;
	size_t i = 0;

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
	int i = 0, result = 1;
	int length = listint_len(*head);
	listint_t *current = *head;

	int *array = (int *)malloc(sizeof(int) * length);

	while (current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}

	for (i = 0; i < length; i++)
	{
		if (array[i] != array[length - 1 - i])
			result = 0;
	}

	free(array);
	return (result);
}
