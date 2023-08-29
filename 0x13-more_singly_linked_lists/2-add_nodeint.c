#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - function that adds a new node at the beginning
 * of a listint_t list.
 * @head: head of double pointer
 * @n: int add the list
 * Return: NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *pt;

	if (head == NULL)
		return (NULL);
	pt = malloc(sizeof(listint_t));
	if (pt == NULL)
		return (NULL);
	pt->n = n;
	pt->next = *head;
	*head = pt;
	return (pt);
}
