#include "main.h"

/**
 * _abs - To compute absolute value of an integer
 *
 * @r: input number as an integer
 *
 * Return: absolute value
 */

int _abs(int r)
{
	if (r >= 0)
	{
		return (r);
	}
	else
	{
		return (r * -1);
	}
}
