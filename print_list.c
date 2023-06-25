#include "sort.h"
#include <stdio.h>

/**
 * print_list - prints the doubly linked list's sorted integers
 * @list: Pointer to the list to be printed
 */
void print_list(const listint_t *list)
{
	int num;

	num = 0;
	while (list)
	{
		if (num > 0)
			printf(", ");
		printf("%d", list->n);
		++num;
		list = list->next;
	}
	printf("\n");
}
