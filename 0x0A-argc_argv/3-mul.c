#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that multiplies two numbers.
 * @argc: number count arguments
 * @argv: argument array
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	int a;
	int b;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("%d\n", a * b);

	return (0);
}
