#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: array to print
 * @size: size of array
 *
 * return: void
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		printf(" %d", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("\n");
}

/**
 * binary_search - searches for a value in a sorted array of integers using the
 * Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 on failure
 */
int binary_search(int *array, size_t size, int value)
{
	size_t m;
	int tmp, r;

	r = -1;
	if (array != NULL && size > 0)
	{
		print_array(array, size);
		m = (size - 1) / 2;
		tmp = array[m];
		if (tmp == value)
			r = m;
		else if (size == 1)
			;
		else if (tmp < value)
		{
			r = binary_search(array + (m + 1), size - (m + 1), value);
			if (r >= 0)
				r += m + 1;
		}
		else
			r = binary_search(array, m + 1, value);
	}
	return (r);
}
