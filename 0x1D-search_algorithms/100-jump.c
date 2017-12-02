#include "search_algos.h"
#include <math.h>

/**
 * minimum_value - finds the minimum of two values
 * @a: first value to compare
 * @b: second value to compare
 *
 * Return: The smaller of the two values, or a if equal
 */
size_t minimum_value(size_t a, size_t b)
{
	if (b < a)
		return (b);
	return (a);
}


/**
 * jump_search - searches for a value in a sorted array of integers using the
 * Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 on failure
 */
int jump_search(int *array, size_t size, int value)
{
	size_t l, r, jump;

	if (array != NULL && size > 0)
	{
		l = r = 0;
		jump = sqrt(size);
		while (l < size && array[l] <= value)
		{
			printf("Value checked array[%lu] = [%d]\n", l, array[l]);
			r = minimum_value(size - 1, l + jump);
			if (array[l] <= value && array[r] >= value)
				break;
			l += jump;
		}
		if (l >= size || array[l] > value)
			return (-1);
		r = minimum_value(size - 1, r);
		printf("Value found between indexes [%lu] and [%lu]\n", l, r);
		for (; l <= r && array[l] <= value; l++)
		{
			printf("Value checked array[%lu] = [%d]\n", l, array[l]);
			if (array[l] == value)
				return (l);
		}
	}
	return (-1);
}

int main(void)
{
	int array[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Found %d at index: %d\n\n", 6, jump_search(array, size, 6));
	printf("Found %d at index: %d\n\n", 1, jump_search(array, size, 1));
	printf("Found %d at index: %d\n", 999, jump_search(array, size, 999));
	return (EXIT_SUCCESS);
}
