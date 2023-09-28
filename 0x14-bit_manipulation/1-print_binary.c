#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number.
 * @n: the number to print in binary
 *
 * Return: No return
 */

void print_binary(unsigned long int n)
{
	int a, m = 0;
	unsigned long int cur;

	for (a = 63; a >= 0; a--)
	{
		cur = n >> a;

		if (cur & 1)
		{
			_putchar('1');
			m++;
		}
		else if (m)
			_putchar('0');
	}
	if (!m)
		_putchar('0');
}
