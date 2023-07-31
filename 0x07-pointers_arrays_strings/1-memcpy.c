#include "main.h"

/**
 * _memcpy - function that copies memory area
 * @dest: memory area where it is stored
 * @src: memory area where it is copied
 * @n: number of bytes to be copied
 *
 * Return: copied memory with n byte changed
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int a = 0;
	int b = n;

	for (; a < b; a++)
	{
		dest[a] = src[a];
		n--;
	}
	return (dest);
}
