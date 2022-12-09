#include "lists.h"

/**
 * sum_dlistint - sum all the data to a dlinked l
 * @head: head of the list
 *
 * Return: sum total on success
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;
	int total = 0;

	tmp = head;
	while (tmp != NULL)
	{
		total += tmp->n;
		tmp = tmp->next;
	} return (total);
}
