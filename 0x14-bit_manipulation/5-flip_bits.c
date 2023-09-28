#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would need
 * to flip to get from one number to another.
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int cur;
	int b, c = 0;
	unsigned long int exclusive = n ^ m;

	for (b = 63; b >= 0; b--)
	{
		cur = exclusive >> b;
		if (cur & 1)
			c++;
	}
	return (c);
}
