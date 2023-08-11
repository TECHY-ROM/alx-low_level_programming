#include "main.h"

/**
 * is_positive_integer - Checks if a string is a positive integer
 * @str: Input string
 *
 * Return: 1 if the string is a positive integer, 0 otherwise
 */

int is_positive_integer(const char *str)
{
	while (*str)
	{
	if (!isdigit(*str))
		return (0);
	str++;
	}
	return (1);
}

/**
 * multiply_strings - Multiplies two strings representing positive integers
 * @str1: First string
 * @str2: Second string
 * @result: Pointer to the result string
 * @len1: Length of the first string
 * @len2: Length of the second string
 */

void multiply_strings(const char *str1, const char *str2,
		char *result, int len1, int len2)
{
	int result_len = len1 + len2;
	int i, j, carry, product;

	for (i = 0; i < result_len; i++)
	result[i] = '0';
	result[result_len] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
	for (j = len2 - 1; j >= 0; j--)
	{
		product = (str1[i] - '0') * (str2[j] - '0')
			+ (result[i + j + 1] - '0') + carry;
		carry = product / 10;
		result[i + j + 1] = (product % 10) + '0';
	}
	result[i] += carry;
	}
}

/**
 * main - positive integer
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *msg, *num1, *num2, *result;
	int i, len1, len2;

	if (argc != 3 || !is_positive_integer(argv[1])
		|| !is_positive_integer(argv[2]))
	{
	for (msg = "Error\n"; *msg; msg++)
		_putchar(*msg);
	return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	len1 = 0;
	while (num1[len1])
	len1++;

	len2 = 0;
	while (num2[len2])
	len2++;

	result = malloc(len1 + len2 + 1);
	if (result == NULL)
	{
	for (msg = "Error\n"; *msg; msg++)
		_putchar(*msg);
	return (98);
	}

	multiply_strings(num1, num2, result, len1, len2);

	for (i = 0; result[i]; i++)
	_putchar(result[i]);
	_putchar('\n');

	free(result);

	return (0);
}
