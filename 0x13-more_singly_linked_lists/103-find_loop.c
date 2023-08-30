#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: pointer to the beginning of the list
 *
 * Return: address of the node where the loop starts or NULL if there's no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *n, *m;

	n = m = head;
	while (n && m && m->next)
	{
		n = n->next;
		m = m->next->next;
		if (n == m)
		{
			n = head;
			break;
		}
	}
	if (!n || !m || !m->next)
		return (NULL);
	while (n != m)
	{
		n = n->next;
		m = m->next;
	}
	return (m);
}
