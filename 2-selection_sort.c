#include "sort.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * selection_sort - a function that sorts an array of integers in ascending
 *					order using the Selection sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, aux;
	size_t min;

	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			min = i;
			aux = 0;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
					min = j,
					aux = 1;
			}
			if (aux == 1)
			{
				aux = array[i];
				array[i] = array[min];
				array[min] = aux;
				print_array(array, size);
			}
		}
	}
}
