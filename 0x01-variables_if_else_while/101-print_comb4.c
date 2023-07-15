#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Prints all possible different combinations of three digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	int m;
	int u;

	for (n = '0'; n < '9'; n++)
	{
	for (m = n + 1; m <= '9'; m++)
	{
	for (u = m + 1; u <= '9'; u++)
	{
	if ((m != n) != u)
	{
	putchar(n);
	putchar(m);
	putchar(u);
	if (n == '7' && m == '8')
	continue;
	putchar(',');
	putchar(' ');
	}
	}
	}
	}
	putchar('\n');
	return (0);
}
