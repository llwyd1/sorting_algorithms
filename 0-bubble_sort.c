#include "sort.h"

/**
 * swap - swaps values in two memory locations.
 *
 * @a: the address of the first value to be swapped.
 * @b: the address of the second value to be swapped.
 *
 * Return: nothing.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts a given array using the bubble sort technique.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Returns: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, new_n;

	n = size;
	while (n > 1)
	{
		new_n = 0;

		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				new_n = i;
			}
		}
		n = new_n;
	}
}
