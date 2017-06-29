#include "holberton.h"

/**
 * _pow - calculates a base raides to the exponent power
 * @base: base of the exponential expression
 * @power: exponent
 *
 * Return: result of (base ^ power)
 */
unsigned int _pow(unsigned int base, unsigned int power)
{
	unsigned int i;
	unsigned int num;

	num = 1;
	for (i = 1; i <= power; i++)
	{
		num *= base;
	}
	return (num);
}

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string containing a binary number
 *
 * Return: unsigned int with decimal value of binsry number, or 0 if error
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int num, base, power;

	num = 0;
	power = 0;
	base = 2;
	if (!b)
		return (0);
	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}
	for (i -= 1; i >= 0; i--, power++)
	{
		num += (b[i] - '0') * _pow(base, power);
	}
	return (num);
}
