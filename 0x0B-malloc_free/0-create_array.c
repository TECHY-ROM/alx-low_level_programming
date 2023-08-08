#include "main.h"
#include <stdlib.h>

/**
 * create_array - function that creates an array of chars,
 * and initializes it with a specific char.
 * @size: The size of the array
 * @c: The char to fill in the array
 * Return: the array filled
 */

char *create_array(unsigned int size, char c)
{
	char *ptArray;
	unsigned int count;

	/* allocating space for arraay */

	ptArray = malloc(size * sizeof(char));

	/* put a char c in each of the memory locaton*/

	for (count = 0; count < size; count++)
	{
		ptArray[count] = c;
	}

	return (ptArray);
}
