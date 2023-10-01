#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Represents the kind of a playing card
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 *
 * @value: Value of the card (e.g., "Ace" to "King")
 * @kind: Kind of the card (SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a deck of cards
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

/**
 * sort_deck - Sorts a deck of cards
 *
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck);

void print_deck(const deck_node_t *deck);

#endif /* DECK_H */

