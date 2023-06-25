#include <stdio.h>
#include "sort.h"

void swap(int *array, size_t array_i, size_t array_j);

/**
 * bubble_sort - sorts the given array
 * @array: what is to be printed after swapping
 * @size: The input size of the array
 */
void bubble_sort(int *array, size_t size)
{
	BOOL sorted = FALSE;
	size_t i, sorted_i = size - 1;

	if (!array || size <= 1)
		return;
	while (!sorted)
	{
		sorted = TRUE;
		for (i = 0; i < sorted_i; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array, i, i + 1);
				sorted = FALSE;
				print_array(array, size);
			}
		}
		sorted_i--;
	}
}

/**
 * swap - swaps array's adjacent elements
 * @array: The array to store swapped numbers
 * @array_i: array_i to swap with array_j
 * @array_j: array_j to swap with array_i
 */
void swap(int *array, size_t array_i, size_t array_j)
{
	int temp;

	temp = array[array_i];
	array[array_i] = array[array_j];
	array[array_j] = temp;
}
