#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _r - to reallocate memory for an array of pointers
 * to the nodes in a linked list
 * @list: old list to append
 * @size: size of the new list
 * @new: new node to add tot the list
 *
 * Return: pointer to the new list
 *
 */

const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
	size_t n;


	newlist = malloc(size * sizeof(listint_t *));
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (n = 0; n < size - 1; n++)
		newlist[n] = list[n];
	newlist[n] = new;
	free(list);
	return (newlist);
}

/**
 * print_listint_safe - function that prints a listint_t linked list
 * @head: pointer to the start of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t n, m = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (n = 0; n < m; n++)
		{
			if (head == list[n])
			{

				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (m);
			}
		}
		m++;
		list = _r(list, m, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (m);
}
