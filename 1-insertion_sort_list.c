#include "sort.h"

/**
 * get_head - Get the head of a doubly linked list
 * @tmp: node in linked list
 * Return: head of linked list
 */
listint_t *get_head(listint_t *tmp)
{
	while (tmp->prev)
		tmp = tmp->prev;

	return (tmp);
}

/**
 * insertion_sort_list - fucntion that implement the insertion algorithms.
 * @list: the given list to be sorted.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *pcurr, *holder;

	if (list == NULL)
		return;

	curr = get_head(*list);
	for (curr = curr->next; curr;)
	{
		holder = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			pcurr = curr->prev;
			pcurr->next = curr->next;
			curr->next = pcurr;
			curr->prev = pcurr->prev;
			pcurr->prev = curr;
			if (curr->prev)
				curr->prev->next = curr;
			if (pcurr->next)
				pcurr->next->prev = pcurr;
			print_list(get_head(*list));
		}
		curr = holder;
	}
	*list = get_head(*list);
}
