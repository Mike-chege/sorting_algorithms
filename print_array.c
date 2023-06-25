#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - prints the array integers
 * @array: pointer to the array to be printed
 * @size: The number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t num;

	num = 0;
	while (array && num < size)
	{
		if (num > 0)
			printf(", ");
		printf("%d", array[num]);
		++num;
	}
	printf("\n");
}
