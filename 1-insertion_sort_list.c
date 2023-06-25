#include <stdio.h>
#include "sort.h"

listint_t *get_list_end(listint_t *list);
size_t list_len(const listint_t *list);

/**
 * insertion_sort_list - sorts doubly linked list integers
 * @list: The linked list of integers to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *unsorted, *prev, *next, *ele;

	sorted = unsorted = prev = next = ele = NULL;
	if (!list || !(*list) || !((*list)->next))
		return;

	sorted = *list;
	unsorted = get_list_end(*list);
	while (sorted && unsorted)
	{
		ele = sorted;
		while (ele->prev && ele->n < ele->prev->n)
		{
			prev = ele->prev;
			next = ele->next;
			ele->prev = prev->prev;
			ele->next = prev;
			if (prev->prev)
				prev->prev->next = ele;
			prev->prev = ele;
			prev->next = next;
			if (next)
				next->prev = prev;

			if (!ele->prev)
				*list = ele;
			print_list(*list);
		}
		sorted = sorted->next;
	}
}

/**
 * list_len - gets the size of the doubly linked list
 * @list: list of integers measured
 * Return: The size of list
 */
size_t list_len(const listint_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * get_list_end - gets the pointer to end of linked list
 * @list: list of integers
 * Return: The pointer to end of list
 */
listint_t *get_list_end(listint_t *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
