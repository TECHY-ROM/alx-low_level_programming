#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * Description: that prints the numbers 1 - 100 w/
 * Fizz for multiples of 3, Buzz for multiples of 5,
 * and FizzBuzz for multiple of both numbers
 *
 * Return: Always 0 (Success
 */

int main(void)
{
	int u;

	for (u = 1; u <= 100; u++)
	{
		if (u % 15 == 0)
			printf("FizzBuzz");
		else if (u % 3 == 0)
			printf("Fizz");
		else if (u % 5 == 0)
			printf("Buzz");
		else
			printf("%u", u);
		if (u < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
