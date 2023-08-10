#include "main.h"

/**
 * array_range - function that creates an array of integers.
 * @min: Minimum value for the array
 * @max: Maximum value for the array
 *
 * Return: Pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *ptr;
	int a;
	int size;

	if (min > max)
	return (NULL);

	size = max - min + 1;
	ptr = malloc(size * sizeof(int));

	if (ptr == NULL)
	return (NULL);

	for (a = 0; a < size; a++)
	ptr[a] = min++;

	return (ptr);
}
