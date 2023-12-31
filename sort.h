#ifndef __SORT__H__
#define __SORT__H__

#include <stdlib.h>

/* Boolean values */
#define FALSE 0
#define TRUE 1

/* Macros values */
#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* BOOL TYPES */
typedef unsigned char BOOL;

/* PRINT ARRAY FUNCTIONS */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/* MAIN SORTING FUNCTIONS */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
#endif /* __SORT__H__*/
