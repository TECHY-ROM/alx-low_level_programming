#include <stdio.h>
#include "main.h"

/**
 * main - program that prints its name, followed by a new line.
 * @argc: number count  of arguments
 * @argv: array of argumnets
 *
 * Return: Always 0 (Success)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
