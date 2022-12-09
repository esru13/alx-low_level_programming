#include "lists.h"

/**
 * free_dlistint - frees double linked list
 * @head: header
 *
 * Return: none
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	tmp = head;
	while (head !=  NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	} free(head);
}
