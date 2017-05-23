#include "holberton.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: value of integer
 */
int _atoi(char *s)
{
	int i, j, n, m, p;

	i = n = m = p = 0;
	while (*(s + i))
	{
		if ((*(s + i) >= '0') && (*(s + i) <= '9'))
		{
			n = n * 10 + (*(s + i) - '0');
			j = i;
			if (*(s + (i + 1)) < '0' || *(s + (i + 1)) > '9')
				break;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (*(s + i) == '-')
			m++;
		else if (*(s + i) == '+')
			p++;
		i++;
	}
	if (m - p > 0)
		n = -n;
	return (n);
}
