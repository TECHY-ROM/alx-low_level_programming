#include "variadic_functions.h"
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int num, i = 0;
	char c, *s;
	float f;

	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			c = va_arg(args, int);
				printf("%c", c);
		}
		else if (format[i] == 'i')
		{
			num = va_arg(args, int);
				printf("%d", num);
		}
		else if (format[i] == 'f')
		{
			f = va_arg(args, double);
				printf("%f", f);
		}
		else if (format[i] == 's')
		{
			s = va_arg(args, char *);
		if (s != NULL)
			printf("%s", s);
		else
			printf("(nil)");
		}
		if (format[i + 1] != '\0' && (format[i] == 'c' ||
			format[i] == 'i' || format[i] == 'f' || format[i] == 's')){
			printf(", ");
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
