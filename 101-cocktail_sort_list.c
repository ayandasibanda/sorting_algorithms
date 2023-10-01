#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swaps a node with its previous one in a doubly linked list.
 * @node: The node to be swapped.
 * @list: The doubly linked list containing the nodes.
 * Return: A pointer to the node after swapping.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
    listint_t *back = node->prev, *current = node;

    /* Update the next pointer of the node before 'current' */
    back->next = current->next;

    /* Update the previous pointer of the node after 'current', if it exists */
    if (current->next)
        current->next->prev = back;

    /* Perform the swap */
    current->next = back;
    current->prev = back->prev;
    back->prev = current;

    /* Update the next pointer of the node before 'current', if it exists */
    if (current->prev)
        current->prev->next = current;
    else
        *list = current;  /* Update the list head if 'current' becomes the new head */

    return current;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker sort algorithm.
 * @list: The doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *node;
    int swap_done = 1;

    /* Check if the list is empty or has only one element */
    if (list == NULL || (*list) == NULL || (*list)->next == NULL)
        return;

    /* Initialize the current node to the beginning of the list */
    node = *list;

    /* Continue sorting until no more swaps are needed */
    while (swap_done == 1)
    {
        swap_done = 0;

        /* Traverse the list from left to right */
        while (node->next)
        {
            if (node->n > node->next->n)
            {
                /* Swap the nodes and update the list */
                node = swap_node(node->next, list);
                swap_done = 1;

                /* Print the list after each swap */
                print_list(*list);
            }

            /* Move to the next node */
            node = node->next;
        }

        /* Break if no swaps were done in this pass */
        if (swap_done == 0)
            break;

        swap_done = 0;

        /* Traverse the list from right to left */
        while (node->prev)
        {
            if (node->n < node->prev->n)
            {
                /* Swap the nodes and update the list */
                node = swap_node(node, list);
                swap_done = 1;

                /* Print the list after each swap */
                print_list(*list);
            }
            else
            {
                /* Move to the previous node */
                node = node->prev;
            }
        }
    }
}

