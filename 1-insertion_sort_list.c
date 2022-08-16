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
	n1 = *head;
	n2 = (*head)->next;

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
	listint_t *n1, *n2;

	if (list == NULL)
	{
		return;
	}

	n1 = *list;

	for (; n1->next != NULL; n1 = n1->next)
	{
		if (n1->n > n1->next->n)
		{
			node_swap(&n1, list);
			print_list(*list);

			n2 = n1->prev;

			for (; n2 != NULL; n2 = n2->prev)
			{
				if (n2->n > n2->next->n)
				{
					node_swap(&n2, list);
					print_list(*list);
				}

				else
				{
					break;
				}
			}
		}
	}
}
