#include <stdio.h>
#include "sort.h"

void sort_array(int *array, size_t size, size_t left, size_t right);
size_t pivot(int *array, size_t first, size_t last);
size_t partition(int *array, size_t size, size_t first, size_t last, int pivot);
void swap_array(int *array, size_t ele_i, size_t ele_j);

/**
 * quick_sort - sorts an array of integers
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;
	sort_array(array, size, 0, size - 1);
}

/**
 * sort_array - Enables recursion for the quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 * @left: The first element in the array
 * @right: The last element in the array
 * Return: void
 */
void sort_array(int *array, size_t size, size_t left, size_t right)
{
	size_t start = 0;
	int pvt = array[pivot(array, left, right)];

	if ((long int) right - (long int)left <= 0)
		return;
	start = partition(array, size, left, right, pvt);
	sort_array(array, size, left, start - 1);
	sort_array(array, size, start + 1, right);
}

/**
 * partition - Enables recursion for the quicksort algorithm
 * @array: The array to sort
 * @size: The size of the array to sort
 * @first: The first element of the array
 * @last: The last element of the array
 * @pivot: The point / value selected
 * Return: The starting point of the subarray
 */
size_t partition(int *array, size_t size, size_t first, size_t last, int pivot)
{
	size_t end;

	end = last;
	first = first - 1;

	for (last = first + 1; last < end; last++)
	{
		if (array[last] < pivot)
		{
			first++;
			if (first != last)
			{
				swap_array(array, first, last);
				print_array(array, size);
			}
		}
	}
	if (first + 1 != end && array[first + 1] > array[end])
	{
		swap_array(array, first + 1, end);
		print_array(array, size);
	}
	return (first + 1);
}

/**
 * pivot - The pivot point of the array
 * @array: The array to get the pivot from
 * @first: The first array element
 * @last: The last array element
 * Return: The index where the pivot points
 */
size_t pivot(int *array, size_t first, size_t last)
{
	(void)array;
	(void)first;
	return (last);
}

/**
 * swap_array - swaps the adjacent array elements
 * @array: The array to that has the elements
 * @ele_i: The ele_i to swap with ele_j
 * @ele_j: The ele_j to swap with ele_i
 */
void swap_array(int *array, size_t ele_i, size_t ele_j)
{
	int temp;

	temp = array[ele_j];
	array[ele_j] = array[ele_i];
	array[ele_i] = temp;
}
