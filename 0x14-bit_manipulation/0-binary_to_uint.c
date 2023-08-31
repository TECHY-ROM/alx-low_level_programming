#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int.
 * @b: the string that contains the binary number
 *
 * Return: Converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int m;
	unsigned int decimal = 0;

	if (!b)
		return (0);
	for (m = 0; b[m]; m++)
	{
		if (b[m] < '0' || b[m] > '1')
			return (0);
		decimal = 2 * decimal + (b[m] - '0');
	}

	return (decimal);
}
