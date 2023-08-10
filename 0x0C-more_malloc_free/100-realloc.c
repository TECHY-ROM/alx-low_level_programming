#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block to reallocate
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block otherwise NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	char *oldp = ptr;
	unsigned int a;
	unsigned int min_size;

	if (new_size == 0)
	{
	free(ptr);
	return (NULL);
	}

	if (ptr == NULL)
	return (malloc(new_size));

	if (new_size == old_size)
	return (ptr);

	p = malloc(new_size);

	if (p == NULL)
	return (NULL);

	min_size = (old_size < new_size) ? old_size : new_size;

	for (a = 0; a < min_size; a++)
	p[a] = oldp[a];

	free(ptr);

	return (p);
}
