#include "main.h"

/**
 * that returns the natural square root of a number.
 * @n: the value to get the square root
 * @m: iterate number
 * Return: natural square root
 */

int _sqrt_recursion(int n)
{
	int m;
	sqrt = m * m;

	if (sqrt > n)
		return (-1);

	if (sqrt == n)
		return (1);

	return (_sqrt_recursion(n, m + 1));
}
