#include "sort.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * quick_sort - a function that sorts an array of integers in ascending
 *					order using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;

	if (array && size)
		quicksort(array, lo, hi, size);
}

/**
 * quicksort - a function that sorts an array of integers in ascending
 *					order using the Selection sort algorithm.
 * @array: Array to be sorted.
 * @lo: lower index of array.
 * @hi: highter index of array.
 * @size: Size of the array.
 *
 */

void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * partition - a function that sorts an array of integers in ascending
 *					order using the Selection sort algorithm.
 * @A: Array to be sorted.
 * @lo: lower index of array.
 * @hi: highter index of array.
 * @size: Size of the array.
 *
 * Return: Always return the pivot.
 */

int partition(int *A, int lo, int hi, size_t size)
{
	int pivot, i, j, tmp;

	pivot = A[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (A[j] < pivot)
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;

			if (A[j] != A[i])
				print_array(A, size);
			i = i + 1;
		}
	}
	tmp = A[i];
	A[i] = A[hi];
	A[hi] = tmp;

	if (A[j] != A[i])
		print_array(A, size);

	return (i);
}
