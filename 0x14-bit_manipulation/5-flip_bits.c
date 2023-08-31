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
	int a, b = 0;
	unsigned long int exclusive = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		cur = exclusive >> a;
		if (cur & 1)
			b++;
	}
	return (b);
}
