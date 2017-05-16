#include "holberton.h"

/**
 * _islower - entry point
 *
 * Description: Return 1 if lowercase letter and 0 if not
 *
 * Return: 0 or 1
 */


int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
