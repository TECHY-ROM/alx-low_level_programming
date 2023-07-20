#include "main.h"

/**
 * print_line - Straight line
 * @n: Number of times
 * Return: Always 0 (Success)
 */

void print_line(int n)
{
	int a;

	for (a = 0; a < n; a++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
