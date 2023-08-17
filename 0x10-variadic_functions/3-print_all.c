#include "variadic_functions.h"

/**
 * print_all - Prints different types of arguments.
 * @format: Format string containing specifiers for the arguments.
 * Variadic function that supports 'c' (char), 'i' (integer),
 * 'f' (float), and 's' (string) specifiers.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *separator = "";
	char *s;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i + 1])
			separator = ", ";

		switch (format[i])
		{
			case 'c':
				printf("%c%s", va_arg(args, int), separator);
				break;
			case 'i':
				printf("%d%s", va_arg(args, int), separator);
				break;
			case 'f':
				printf("%f%s", (float) va_arg(args, double), separator);
				break;
			case 's':
				s = va_arg(args, char *);
				if (!s)
					s = "(nil)";
				printf("%s%s", s, separator);
				break;
		}
		i++;
	}

	printf("\n");

	va_end(args);
}
