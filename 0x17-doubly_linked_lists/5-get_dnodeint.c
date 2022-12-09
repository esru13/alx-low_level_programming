#include "lists.h"

/**
 * get_dnodeint_at_index - get the nth from a dlinked list
 * @head: head of the list
 * @index: integer to find
 *
 * Return: none
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int node_data = 0;

	if (head == NULL)
		return (NULL);
	tmp = head;

	while (tmp != NULL)
	{
		if (node_data == index)
		{
			return (tmp);
		}
		node_data++;
		tmp = tmp->next;
	} return (NULL);
}
