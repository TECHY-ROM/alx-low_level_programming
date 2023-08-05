#include "main.h"
#include <stdio.h>

/**
 * main - program that prints all arguments it receives.
 * @argc: number count of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Succes)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
