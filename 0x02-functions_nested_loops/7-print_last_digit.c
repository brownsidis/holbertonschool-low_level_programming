#include "holberton.h"

/**
 * print_last_digit - prints last digit of integer input
 * @n: integer to modify
 *
 * Return: l
 */


int print_last_digit(int n)
{
	char l, p;

	if (n >= 0)
		l = n % 10;
	else
	{
		n *= -1;
		l = n % 10;
	}
	p = 48 + l;
	_putchar(p);
	return (l);
}
