#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: singly linked list to check
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
listint_t *hare = list, *turtle = list;

while (hare && hare->next)
{
	if (turtle == hare->next)
		return (1);
	turtle = turtle->next;
	hare = hare->next->next;
}
return (0);
}
