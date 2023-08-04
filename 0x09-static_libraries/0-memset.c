#include "main.h"

/**
 * _memset - function that fills memory with a constant byte.
 * @s: the memory address to be filled
 * @n: number of bytes to be changed
 * @b: the desired constant value
 *
 * Return: changed array with new value of n byte
 */

char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
