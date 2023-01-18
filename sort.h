#ifndef SORT_H
#define SORT_H

/*Libraries*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Data Structure*/
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

/*Function Prototypes*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void node_swap(listint_t **head, listint_t **list);

/*Merge Sort prototypes*/
void merge_sort(int *array, size_t size);
void array_print(int *array, int start, int end);
void split_it(int *tmp, int *array, int start, int end);
void arr_cp(int *array, int *tmp, int start, int end);
void big_merger(int *array, int *tmp, int start, int half, int end);

/*Heap Sort Prototypes*/
void heap_sort(int *array, size_t size);
void swappy_boi(int *x, int *y);
void heap_it_up(int *array, size_t size, int idx);

#endif
