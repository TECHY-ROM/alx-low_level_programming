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

	va_list list;

	va_start(list, n);

	for (a = 0; a < n; a++)
	{
		str = va_arg(list, char *);
		if (!str)
			str = "nil";
		if (!separator)
			printf("%s", str);
		else if (separator && a == 0)
			printf("%s", str);
		else
			printf("%s%s", separator, str);
	}
	printf("\n");
	va_end(list);
}
