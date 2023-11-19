#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the head of the list
* @node1: First node to swap
* @node2: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
	node1->prev->next = node2;
else
	*list = node2;

if (node2->next)
	node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node2->next = node1;
node1->prev = node2;
}

/**
* left_to_right - Traverses the list from left to right
* @list: Pointer to the head of the list
* @swapped: Flag to determine if a swap occurred
*/
int left_to_right(listint_t **list, int *swapped)
{
listint_t *current = *list;

while (current->next)
{
	if (current->n > current->next->n)
	{
		swap_nodes(list, current, current->next);
		*swapped = 1;
		print_list(*list);
	}
	else
	{
		current = current->next;
	}
}

return *swapped;
}

/**
* right_to_left - Traverses the list from right to left
* @list: Pointer to the head of the list
* @swapped: Flag to determine if a swap occurred
*/
int right_to_left(listint_t **list, int *swapped)
{
listint_t *current = *list;

while (current->prev)
{
	if (current->n < current->prev->n)
	{
		swap_nodes(list, current->prev, current);
		*swapped = 1;
		print_list(*list);
	}
	else
	{
		current = current->prev;
	}
}

return *swapped;
}

/**
* cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
* @list: Pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

while (swapped)
{
	swapped = 0;

	if (!left_to_right(list, &swapped))
		break;

	if (!right_to_left(list, &swapped))
		break;
}
}
