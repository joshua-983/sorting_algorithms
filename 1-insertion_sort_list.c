#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t
 * @h: A pointer pointing to the head of the doubly linked list.
 * @n1: first noe to swap
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Update next and previous pointers to swap the nodes*/
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	/*Update head pointer if necessary*/
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - integer of double linked list to sort.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	/*Check if the input list is NULL or one element (already sorted)*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Iterate through the list starting from the second element*/
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;

	/*Move the current node to its correct position sorted part of the list*/
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);

			/* Print the list after each swap for visualization*/
			print_list((const listint_t *)*list);
		}
	}
}
