#include "main.h"

/**
 * print_alphabet - A function that prints the alphabet, in lowercase
 *
 * Return: void (Success)
 */

void print_alphabet(void)
{
	int a;

	for (a = 97; a <= 122; a++)
	{
		_putchar(a);
	}
	_putchar('\n');
}
