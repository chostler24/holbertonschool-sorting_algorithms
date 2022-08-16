#include "sort.h"

/**
  * node_swap - swaps the first two nodes in a list
  * @head: head node
  * @list: list of nodes
  * Return: none
  */

void node_swap(listint_t **head, listint_t **list)
{
	listint_t *n1, *n2;
	*n1 = *head;
	*n2 = (*head)->next;

	n1->next = n2->next;
	n2->next = n1;
	n2->prev = n1->prev;
	n1->prev = n2;

	if (n2->prev != NULL)
	{
		n2->prev->next = n2;
	}

	if (n1->next != NULL)
	{
		n1->next->prev = n1;
	}

	*head = n2;

	if (n2->prev == NULL)
	{
		*list = n2;
	}
}

/**
  * insertion_sort_list - sorts a list of integers in ascending order
  * using the insertion sort algorithm
  * @list: list of integers
  * Return: none
  */

void insertion_sort_list(listint_t **list)
{
}
