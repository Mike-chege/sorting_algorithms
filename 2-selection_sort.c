#include <stdio.h>
#include "sort.h"

void swap(int *array, size_t ele_i, size_t ele_j)

/**
 * selection_sort - sorts an array of elements using selection
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t unsorted_i = 0, ele_pos = 0, sorted_i = 0;

	if (!array || size <= 1)
		return;
	while (sorted_i < size)
	{
		unsorted_i = sorted_i;
		ele_pos = sorted_i;
		while (unsorted_i < size)
		{
			if (array[unsorted_i] < array[ele_pos])
			{
				ele_pos = unsorted_i;
				if (unsorted_i + 1 == size)
					break;
			}
			unsorted_i++;
		}
		if (array[ele_pos] < array[sorted_i])
		{
			swap(array, sorted_i, ele_pos);
			print_array(array, size);
		}
		sorted_i++;
	}
}

/**
 * swap - swaps two adjacent array elements
 * @array: The array to swap
 * @ele_i: The element to swap with ele_j
 * @ele_j: The element to swap with ele_i
 */
void swap(int *array, size_t ele_i, size_t ele_j)
{
	int temp;

	temp = array[ele_j];
	array[ele_j] = array[ele_i];
	array[ele_i] = temp;
}
