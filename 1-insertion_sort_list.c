#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @a: Pointer to the first node
* @b: Pointer to the second node
* @head: Pointer to the head of the linked list
* Return: void
*/
void swap_nodes(listint_t **a, listint_t **b, listint_t **head)
{
	listint_t *temp;

	if (!*a || !*b)
	{
		return;
	}

	if ((*a) == (*b))
	{
		return;
	}

	if ((*a)->prev == (*b))
	{
		swap_nodes(b, a, head);
		print_list(*head);
		return;
	}

	temp = (*a)->prev;
	(*a)->prev = (*b)->prev;
	(*b)->prev = temp;
	temp = (*a)->next;
	(*a)->next = (*b)->next;
	(*b)->next = temp;

	if ((*a)->prev != NULL)
		(*a)->prev->next = (*a);
	if ((*a)->next != NULL)
		(*a)->next->prev = (*a);
	if ((*b)->prev != NULL)
		(*b)->prev->next = (*b);
	if ((*b)->next != NULL)
		(*b)->next->prev = (*b);

	if (*a == *head)
		*head = *b;
	else if (*b == *head)
		*head = *a;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort
 * @list: is a pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;
			temp->prev = prev->prev;
			prev->next = next;
			if (next != NULL)
				next->prev = prev;

			prev->prev = temp;
			temp->next = prev;

			prev = temp->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
