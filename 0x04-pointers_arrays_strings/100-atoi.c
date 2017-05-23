#include "holberton.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: value of integer
 */
int _atoi(char *s)
{
	int i, j, n, m;

	i = n = 0;
	m = 1;
	while (*(s + i))
	{
		if ((*(s + i) >= '0') && (*(s + i) <= '9'))
		{
			n = n * 10 + (*(s + i) - '0');
			j = i;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (*(s + i) == '-')
			m *= -1;
		i++;
	}
	return (n * m);
}
