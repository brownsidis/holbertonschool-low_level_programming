#include <stdio.h>

/**
 * main - print fibonacci
 *
 * Return: always 0
 */
int main(void)
{
	unsigned long int a, b, c, d;

	a = 1;
	b = 2;
	c = a + b;

	printf("%lu, ", a);
	printf("%lu, ", b);
	for (d = 3; d < 98; d++)
	{
		printf("%lu, ", c);
		a = b;
		b = c;
		c = a + b;
	}
	printf("%lu\n", c);
	return (0);
}
