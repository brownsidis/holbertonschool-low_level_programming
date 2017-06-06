#include "holberton.h"
#include <stdlib.h>

/**
 * _strdup - copy a string to a newly allocated space in memory
 * @str: string to copy
 *
 * Return: pointer to duplicated string or NULL if error
 */
char *_strdup(char *str)
{
	unsigned int i, j;
	char *s;

	if (str == NULL)
		return (NULL);
	for (i = 1; str[i]; i++)
		;
	s = malloc(i * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i - 1; j++)
	{
		s[j] = str[i];
	}
	return (s);
}
