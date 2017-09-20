#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * get_val - gets the relative value of a card from it's string value
 * @str: string value of the card
 *
 * Return: relative value of the card (0 through 12)
 */
int get_val(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
 * comp_val - compares the value in node with the next card
 * @node: card to compare against next card
 *
 * Return: 1 if next card has a smaller value, 0 otherwise
 */
char comp_val(deck_node_t *node)
{
	if (get_val(node->card->value) > get_val(node->next->card->value))
		return (1);
	return (0);
}

/**
 * comp_kind - compares the kind in node with the next card
 * @node: card to compare against next card
 *
 * Return: 1 if next card has a "smaller" kind, 0 otherwise
 */
char comp_kind(deck_node_t *node)
{
	if (node->card->kind > node->next->card->kind)
		return (2);
	else if (node->card->kind == node->next->card->kind)
		return (1);
	return (0);
}

/**
 * swap_node - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap_node(deck_node_t **list, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * sort_deck - sorts a linked list deck of cards
 * @deck: double pointer to the deck to sort
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	char swapped = 1, k, v;
	deck_node_t *current;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	current = *deck;
	while (swapped != 0)
	{
		swapped = 0;
		while (current->next != NULL)
		{
			k = comp_kind(current);
			v = comp_val(current);
			if (k == 2 || (k == 1 && v == 1))
			{
				swap_node(deck, current);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev != NULL)
		{
			k = comp_kind(current->prev);
			v = comp_val(current->prev);
			if (k == 2 || (k == 1 && v == 1))
			{
				swap_node(deck, current->prev);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
