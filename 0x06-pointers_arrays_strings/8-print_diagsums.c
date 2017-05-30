#include "holberton.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer to start of matrix
 * @size: width of matrix column
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i, j, p;
	long int l, r;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			p = (size * i) + j;
			if (i == j)
				l += a[p];
			if (j == (size - 1 - i))
				r += a[p];
		}
	}
	printf("%ld, %ld\n", l, r);
}
