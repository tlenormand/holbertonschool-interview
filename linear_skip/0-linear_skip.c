#include <stdio.h>
#include <stdlib.h>

#include "search.h"


skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *prev = NULL;

	if (!list)
		return (NULL);

	while (current->express)
	{
		prev = current;
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

		if (current->n >= value)
			break;
	}

	if (!current->express && current->n < value)
	{
		prev = current;

		while (current->next)
			current = current->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev->index, current->index);

	while (prev)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		if (prev->n > value)
			return (NULL);

		prev = prev->next;
	}

	return (NULL);
}
