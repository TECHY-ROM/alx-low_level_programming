#include "variadic_functions.h"

/**
 * print_all - Prints different types of arguments.
 * @format: Format string containing specifiers for the arguments.
 * Variadic function that supports 'c' (char), 'i' (integer),
 * 'f' (float), and 's' (string) specifiers.
 */

void print_all(const char * const format, ...)
{
	va_list list;
	unsigned int a = 0;
	char *str, *sep = "";

	va_start(list, format);

	if (format)
	{
		while (format[a])
		{
			switch (format[a])
			{
				case 'c':
					printf("%s%c", sep, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", sep, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", sep, va_arg(list, double));
					break;
				case 's':
					str = va_arg(list, char *);

					if (!str)
						str = "(nil)";
					printf("%s%s", sep, str);
					break;
				default:
					a++;
					continue;
			}
			sep = ", ";
			a++;
		}
	}

	printf("\n");

	va_end(list);
}
