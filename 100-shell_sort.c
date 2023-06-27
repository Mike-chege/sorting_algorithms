#include <stdio.h>
#include "sort.h"

/**
 * swap_array - swaps the two elements in the array
 * @ele_i: The first element to swap
 * @ele_j: The second element to swap
 */
void swap_array(int *ele_i, int *ele_j)
{
	int temp;

	temp = *ele_i;
	*ele_i = *ele_j;
	*ele_j = temp;
}

/**
 * shell_sort - sorts an array of integers -
 * using the the Knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t start, i, j;

	if (array == NULL)
		return;
	if (size < 2)
		return;

	for (start = 1; start < (size / 3);)
		start = start * 3 + 1;

	for (; start >= 1; start /= 3)
	{
		for (i = start; i < size; i++)
		{
			j = i;
			while (j >= start && array[j - start] > array[j])
			{
				swap_array(array + j, array + (j - start));
				j -= start;
			}
		}
		print_array(array, size);
	}
}
