#include "main.h"

/**
 * times_table - Prints the 9 times table, starting from 0
 *
 * Return: empty output
 */

void times_table(void)
{
	int a, b, c, p, q;

	for (a = 0; a <= 9; a++)
	{
	for (b = 0; b <= 9; b++)
	{
	c = a * b;
	if (c > 9)
	{
	p = c % 10;
	q = (c - p) / 10;
	_putchar(44);
	_putchar(32);
	_putchar(q + '0');
	_putchar(p + '0');
	}
	else
	{
	if (b != 0)
	{
	_putchar(44);
	_putchar(32);
	_putchar(32);
	}
	_putchar(c + '0');
	}
	}
	_putchar('\n');
	}
}
