#include "lists.h"


int is_palindrome_recursive(listint_t *current, int length)
{
    listint_t *end = current;
    int i = length;

    if (length < 2)
        return (1);

    while (i != 0)
    {
        end = end->next;
        i--;
    }

    if (current->n != end->n)
        return (0);

    return is_palindrome_recursive(current->next, length - 2);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *current, *end;
    int length;

    if (head == NULL || *head == NULL)
        return (1);

    current = *head;
    end = *head;
    for (length = 0; end->next != NULL; length++)
        end = end->next;

    if (length == 1)
        return (1);

    return is_palindrome_recursive(current, length);
}