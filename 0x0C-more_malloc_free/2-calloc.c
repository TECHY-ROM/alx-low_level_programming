#include "main.h"

/**
 * _calloc - function that allocates memory for an array, using malloc.
 * @nmemb: Number of elements in the array
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int b;

	if (nmemb == 0 || size == 0)
	return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
	return (NULL);

	for (b = 0; b < nmemb * size; b++)
	p[b] = 0;

	return (p);
}
