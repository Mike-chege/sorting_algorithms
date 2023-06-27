#include <stdio.h>
#include "deck.h"

int cmp_str(const char *str1, const char *str2);
char card_value(deck_node_t *card);
void insert_deck(deck_node_t **deck);
void insert_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * cmp_str - Compares two strings
 * @str1: The first string to be compared with str2
 * @str2: The second string to be compared with str3
 * Return: 0 if positive byte difference, otherwise
 * negative byte difference if s1 < s2
 */
int cmp_str(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * card_value - gets the value of the selected card
 * @card: points to the deck_node_t card
 * Return: The value of the selected card
 */
char card_value(deck_node_t *card)
{
	if (cmp_str(card->card->value, "Ace") == 0)
		return (0);
	if (cmp_str(card->card->value, "1") == 0)
		return (1);
	if (cmp_str(card->card->value, "2") == 0)
		return (2);
	if (cmp_str(card->card->value, "3") == 0)
		return (3);
	if (cmp_str(card->card->value, "4") == 0)
		return (4);
	if (cmp_str(card->card->value, "5") == 0)
		return (5);
	if (cmp_str(card->card->value, "6") == 0)
		return (6);
	if (cmp_str(card->card->value, "7") == 0)
		return (7);
	if (cmp_str(card->card->value, "8") == 0)
		return (8);
	if (cmp_str(card->card->value, "9") == 0)
		return (9);
	if (cmp_str(card->card->value, "10") == 0)
		return (10);
	if (cmp_str(card->card->value, "Jack") == 0)
		return (11);
	if (cmp_str(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insert_deck - Sort a deck of card using insertion sort
 * @deck: points to the head of the doubly-linked list.
 */
void insert_deck(deck_node_t **deck)
{
	deck_node_t *loop, *insert, *temp;

	for (loop = (*deck)->next; loop != NULL; loop = temp)
	{
		temp = loop->next;
		insert = loop->prev;
		while (insert != NULL && insert->card->kind > loop->card->kind)
		{
			insert->next = loop->next;
			if (loop->next != NULL)
				loop->next->prev = insert;
			loop->prev = insert->prev;
			loop->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = loop;
			else
				*deck = loop;
			insert->prev = loop;
			insert = loop->prev;
		}
	}
}

/**
 * insert_deck_value - Sort a deck of cards using insertion sort
 * @deck: points to the head of the doubly-linked list
 * Return: Void
 */
void insert_deck_value(deck_node_t **deck)
{
	deck_node_t *loop, *insert, *temp;

	for (loop = (*deck)->next; loop != NULL; loop = temp)
	{
		temp = loop->next;
		insert = loop->prev;
		while (insert != NULL &&
		       insert->card->kind == loop->card->kind &&
		       card_value(insert) > card_value(loop))
		{
			insert->next = loop->next;
			if (loop->next != NULL)
				loop->next->prev = insert;
			loop->prev = insert->prev;
			loop->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = loop;
			else
				*deck = loop;
			insert->prev = loop;
			insert = loop->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: points to the head of the doubly-linked list
 * Return: Void
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insert_deck(deck);
	insert_deck_value(deck);
}
