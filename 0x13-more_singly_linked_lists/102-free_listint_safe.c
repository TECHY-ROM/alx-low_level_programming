#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _ra - reallocates memory for an array of pointers
 * to the nodes in a linked list
 * @list: old list to append
 * @size: size of the new list
 *
 * Return: pointer to the new list
 */

listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newlist;
	size_t n;

	newlist =  malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (n = 0; n < size - 1; n++)
		newlist[n]  = list[n];
	newlist[n] = new;
	free(list);
	return (newlist);
}

/**
 * free_listint_safe - function that frees a listint_t list.
 * @head: double pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */

size_t free_listint_safe(listint_t **head)
{
	size_t n, m = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (m);
	while (*head != NULL)
	{
		for (n = 0; n < m; n++)
		{
			if (*head == list[n])
			{
				*head = NULL;
				free(list);
				return (m);
			}

		}
		m++;
		list = _ra(list, m, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (m);
}
