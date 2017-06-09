#include "holberton.h"
#include <stdlib.h>

/**
 * move_left - moves a string one place to the left and prints the string
 * @str - string to move
 * @l: size of string
 *
 * Return: void
 */
void move_left(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
	{
		str[i] = str[i + 1];
		if (str[i])
			_putchar(str[i]);
	}
	_putchar('\n');
	free(str);
}

/**
 * add - adds two strings together
 * @s1: first string
 * @l1: index of last non-null character of s1
 * @s2: second string and location of answer
 * @l2: index of start place for addition
 *
 * Return: void
 */
void add(char *s1, int l1, char *s2, int l2)
{
	int a, r;

	for (; l1 >= 0 || s1[l1]; l1--, l2--)
	{
		a = (s1[l1] - '0') + (s2[l2] - '0') + r;
		s2[l2] = a % 10;
		r = a / 10;
	}
	if (r)
		s2[l2] += r;
	free(s1);
}

/**
 * mul - multiplies a char with a string
 * @b: char to multiply
 * @a: string to multiply
 * @i: size of a
 *
 * Return: pointer to newly allocated memory, or NULL on failure
 */
char *mul(char b, char *a, int i)
{
	char *m;
	int j, k, c, d;

	m = malloc(sizeof(char) * (i + 1));
	if (m == NULL)
		return (NULL);
	for (j = i - 1, k = i; j >= 0; j--, k--)
	{
		c = (b - '0') * (a[j] - '0') + d;
		m[k] = c / 10 + '0';
		d = c % 10;
	}
	if (d)
		m[k] = d;
	else
		m[k] = '\0';
	return (m);
}
/**
 * check_for_digits - checks the arguments to ensure they are digits
 * @av: pointer to arguments
 *
 * Return: 0 if digits, 1 if not
 */
int check_for_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

/**
 * init - initializes a string
 * @str: sting to initialize
 * @l: length of strinf
 *
 * Return: void
 */
void init(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - multiply two numbers
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: zero, or exit status of 98 if failure
 */
int main(int argc, char *argv[])
{
	int l1, l2, ln, ti;
	char *a;
	char *t;
	char e[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	for (l1 = 0; argv[1]; l1++)
		;
	for (l2 = 0; argv[2]; l2++)
		;
	ln = l1 + l2 + 1;
	a = malloc(ln * sizeof(char));
	if (a == NULL)
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	init(a, ln);
	for (ti = l2 - 1; ti >= 0; ti--)
	{
		t = mul(argv[2][ti], argv[1], l1);
		if (t == NULL)
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			free(a);
			exit(98);
		}
		add(t, l1, a, (ln - (l2 - ti)));
	}
	if (a[0] == '\0')
		move_left(a, ln);
	return (0);
}
