#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * is_palindrome_recursive - checks if a singly linked list is a palindrome
 * 		with recursion
 * @left: pointer to left of list
 * @right: pointer to right of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome_recursive(listint_t *left, listint_t *right)
{
	return (right->next) ?
		(is_palindrome_recursive(left, right->next)) ?
			(left->n == right->n) ? 1 : 0 : 0 : 0;
}


/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	return (head == NULL) ? 1 : is_palindrome_recursive(*head, *head);
}
