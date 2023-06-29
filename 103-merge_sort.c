#include <stdio.h>
#include "sort.h"

void merge(int *arr, int *buf, size_t first, size_t q, size_t r);
void r_merge(int *arr, int *buf, size_t first, size_t r);
void merge_sort(int *array, size_t size);

/**
 * merge - sorts the subarray's integers
 * @arr: The subarray of the array of integers to sort
 * @buf: The buffer to store the sorted subarray
 * @first: The first index of the array
 * @q: The midpoint index of the array
 * @r: The back index of the array
 */
void merge(int *arr, int *buf, size_t first, size_t q, size_t r)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + first, q - first);

	printf("[right]: ");
	print_array(arr + q, r -  q);

	for (i = first, j = q; i < q && j < r; k++)
		buf[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < q; i++)
		buf[k++] = arr[i];
	for (; j < r; j++)
		buf[k++] = arr[j];
	for (i = first, k = 0; i < r; i++)
		arr[i] = buf[k++];

	printf("Done]: ");
	print_array(arr + first, r - first);
}

/**
 * r_merge - implements recursion for the merge sort algorithm
 * @arr: The subarray of the array of integers to sort
 * @buf: The buffer to store the sorted array
 * @first: The first index of the subarray
 * @r: The last index of the subarray
 */
void r_merge(int *arr, int *buf, size_t first, size_t r)
{
	size_t q;

	if (r - first > 1)
	{
		q = first + (r - first) / 2;
		r_merge(arr, buf, first, q);
		r_merge(arr, buf, q, r);
		merge(arr, buf, first, q, r);
	}
}

/**
 * merge_sort - sorts an array of integers an ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	r_merge(array, temp, 0, size);

	free(temp);
}

