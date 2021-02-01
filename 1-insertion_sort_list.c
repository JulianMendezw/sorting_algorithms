#include "sort.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * insertion_sort_list - function that sorts an array of integers in ascending
 *						order.
 * @list: List to be sorted.
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *previous = NULL;
	listint_t *current = *list;

	while (current)
	{
		previous = current->prev;
		while (previous->prev && current)
		{
			if (previous->n > current->n)
			{
				if (previous->prev)
					previous->prev->next = current;

				if (current->next)
					current->next->prev = previous;

				previous->next = current->next;
				current->prev = previous->prev;
				previous->prev = current;
				current->next = previous;

				if (!current->prev)
					*list = current;

				print_list((const listint_t *)*list);
			}
			previous = previous->prev;
		}
		current = current->next;
	}
}
