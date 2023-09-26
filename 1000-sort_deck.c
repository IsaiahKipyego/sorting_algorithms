#include "deck.h"

/**
 * get_value - get card in numerical way to compare
 * @node: card to get its value
 *
 * Return: value of the card in int form
 */
int get_value(deck_node_t *node)
{
	int value, i = 0;
	int card_val[13] = {'A', '2', '3', '4', '5', '6', '7',
			    '8', '9', '1', 'J', 'Q', 'K'};
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	while (i < 13)
	{
		if (node->card->value[0] == card_val[i])
			value = num[i];
		i++;
	}

	return (value);
}

/**
 * kind_sort - sorts deck of card according to type
 * @deck: deck of cards to be sorted
 * Description: implemented using insertion sort algorithm
 */
void kind_sort(deck_node_t **deck)
{
	deck_node_t *current, *next, *temp;

	for (next = (*deck)->next; next != NULL; next = temp)
	{
		temp = next->next;
		current = next->prev;

		while (current != NULL &&
		       current->card->kind > next->card->kind)
		{
			current->next = next->next;
			if (next->next)
				next->next->prev = current;
			next->prev = current->prev;
			next->next = current;
			if (current->prev)
				current->prev->next = next;
			else
				*deck = next;
			current->prev = next;
			current = next->prev;
		}
	}
}

/**
 * value_sort - sort deck on card acording to value and type
 * @deck: deck of cards to be sorted
 * Description: implemented using insertion sort algorithm
 */
void value_sort(deck_node_t **deck)
{
	deck_node_t *current, *next, *temp;

	for (next = (*deck)->next; next != NULL; next = temp)
	{
		temp = next->next;
		current = next->prev;

		while (current != NULL &&
		       current->card->kind == next->card->kind &&
		       get_value(current) > get_value(next))
		{
			current->next = next->next;
			if (next->next)
				next->next->prev = current;
			next->prev = current->prev;
			next->next = current;
			if (current->prev)
				current->prev->next = next;
			else
				*deck = next;
			current->prev = next;
			current = next->prev;
		}
	}
}

/**
 * sort_deck - sort deck on card acording to value and type
 * Description: implements insertion sort method to sort deck of cards
 * @deck: of cards to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck) || !((*deck)->next))
		return;

	kind_sort(deck);
	value_sort(deck);
}
