#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - initializes 4 value cards
 * @SPADE: with value of 0
 * @HEART: With value of 1
 * @CLUB: With value of 2
 * @DIAMOND: with value of 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - playing card
 *
 * @value: value of card
 * From "Ace" to "King"
 * @kind: Kind of card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: pointer to the card of the node
 * @prev: pointer to the previous node of the list
 * @next: pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* function prototype */
void sort_deck(deck_node_t **deck);

#endif
