#include "function_pointers.h"

/**
 * print_name - to a print a name
 * @name: the name to print
 * @f: a pointer to a function that points a name
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
