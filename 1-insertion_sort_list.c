#include "sort.h"
/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp1, *temp2;

	if (!list || !(*list) || !((*list)->next))
		return;

	i = (*list)->next;
	while (i)
	{
		j = i;
		while (j->prev && j)
		{
			temp1 = j->prev;
			temp2 = j;
			if (temp2->n < temp1->n)
			{
				if (temp1->prev)
					temp1->prev->next = temp2;

				if (temp2->next)
					temp2->next->prev = temp1;

				temp1->next = temp2->next;
				temp2->prev = temp1->prev;
				temp1->prev = temp2;
				temp2->next = temp1;

				if (!j->prev)
					*list = j;

				print_list((const listint_t *) *list);
			}
			else
			{
				j = j->prev;
			}
		}

		i = i->next;
	}
}
