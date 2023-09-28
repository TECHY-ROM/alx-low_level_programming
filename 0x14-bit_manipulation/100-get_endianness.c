#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 * Return: 0 for big and 1 for little
 */

int get_endianness(void)
{
	unsigned int m = 1;
	char *c = (char *) &m;

	return (*c);
}
