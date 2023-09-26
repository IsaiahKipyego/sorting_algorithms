#include "sort.h"

/**
 * swap - swap two elements of a  doubly linked list
 * @current: new current element
 * @old: previous current element
 * @list: list to be swapped
 */
void swap(listint_t *current, listint_t *old, listint_t **list)
{
	listint_t *temp_next = current->next;
	listint_t *temp_prev = old->prev;

	if (temp_next != NULL)
		temp_next->prev = old;
	if (temp_prev != NULL)
		temp_prev->next = current;

	current->prev = temp_prev;
	old->next = temp_next;
	current->next = old;
	old->prev = current;

	/* change head if first element */
	if (*list == old)
		*list = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - cocktail shaker sort algorithm sorts a list
 * @list: of items to sort
 * Description: implement bubble sort algorithm from both ends
 * hence saving time for large sets of numbers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *first, *last, *temp;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;

	temp = *list;
	do {
		/* apply bubble sort from the beginning */
		while (temp->next)
		{
			if (temp->n > temp->next->n)
				swap(temp->next, temp, list);
			else
				temp = temp->next;
		}
		last = temp;
		/* apply bubble sort from the end of list */
		while (temp->prev != first && temp->prev)
		{
			if (temp->n < temp->prev->n)
				swap(temp, temp->prev, list);
			else
				temp = temp->prev;
		}
		first = temp;
	} while (first != last);
}
