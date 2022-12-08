#include "lists.h"

/**
 * dlistint_len - find the size of linked list
 * @h: the first element of the linked list
 * Return: the size of linked list
 */

size_t dlistint_len(const dlistint_t *h)
{
	int size = 0;

	while (h)
	{
		size++;
		h = h->next;
	}
	return (size);
}
