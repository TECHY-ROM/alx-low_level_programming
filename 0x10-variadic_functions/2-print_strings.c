#include "variadic_functions.h"

/**
 * print_strings - function to print strings
 * @separator: separator between strings
 * @n: number of arguments to be passed into function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int a;
	char *str;

	va_list args;

	va_start(args, n);

	for (a = 0; a < n; a++)
	{
		str = va_arg(args, char *);

		if (str != NULL)
		{
			printf("%s", str);
		}

		else
		{
			printf("(nil)");
		}

		if (a < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	printf("\n");

	va_end(args);
}
