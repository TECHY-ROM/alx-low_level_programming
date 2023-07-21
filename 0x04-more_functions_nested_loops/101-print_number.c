#include "main.h"

/**
 * print_number - that prints an integer
 * @n: input integer parameter
 *
 * Return: Always 0 (Success)
 */

void print_number(int n)
{
	unsigned int a = n;

	if (n < 0)
	{
		_putchar(45);
		a = -a;
	}
	if (a / 10)
	{
		print_number(a / 10);
	}
	_putchar(a % 10 + '0');
}
