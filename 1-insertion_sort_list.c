#include "sort.h"

void swap_nodes(listint_t *a, listint_t *b, listint_t *list)
{
	listint_t *temp;
	if (!a || !b)
	{
		print_list(list);
		return;
	}

	if (a == b)
	{
		print_list(list);
		return;
	}
	if (a->prev == b)
	{
		swap_nodes(b, a, list);
		print_list(list);
		return;
	}

	 temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;
	temp = a->next;
	a->next = b->next;
	b->next = temp;

	if (a->prev != NULL)
		a->prev->next = a;
	if (a->next != NULL)
		a->next->prev = a;
	if(b->prev != NULL)
		b->prev->next = b;
	if (b->next != NULL)
		b->next->prev = b;

	print_list(list);
}

/*
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort
 * @list: is a pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *i = head->next;
	listint_t *temp;
	listint_t *j;

	while (i)
	{
		int x = i->n;
		j = i->prev;
	
		while (j && j->n > x)
		{
			if (j == i->next)
			{
				temp = j;
				temp->next = i->next;
			}
			j = j->prev;
		}
		/*
		if (!j)
		{
			i->next = head;
			i->prev = NULL;
			print_list(*list);
		}
		i->next = j->next;
		i->prev = j;
		print_list(*list);
		*/
		swap_nodes(i, j, *list);
		i = i->next;
	
	}
}
