#include "main.h"

/**
 * jack_bauer - prints the minutes of a day
 *
 * Return: no return
 */

void jack_bauer(void)
{
	int p, q, r, s;

	for (p = 0; p <= 2; p++)
	{
		for (q = 0; q <= 9; q++)
		{
			for (r = 0; r <= 5; r++)
			{
				for (s = 0; s <= 9; s++)
				{
					if (p >= 2 && q >= 4)
					break;
					_putchar(p + 48);
					_putchar(q + 48);
					_putchar(58);
					_putchar(r + 48);
					_putchar(s + 48);
					_putchar('\n');
				}
			}
		}
	}

}
