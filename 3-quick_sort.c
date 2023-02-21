#include "sort.h"

/**
 * swap - swaps values of two memory addresses
 * @a: first value to swap with
 * @b: second value to swap with
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - devides an array into two partitions using the lomuto
 * partition scheme
 * @array: is the array to partition
 * @lo: is the lower bound of the portion of the array
 * @hi: is the upper bound of the portion of the array
 * @size: is the length of the array
 * Return: the index of the pivot element
 */
int partition(int *array, int lo, int  hi, unsigned int size)
{
	int pv = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pv)
		{
			i++;
			swap(&array[i], &array[j]);

			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	swap(&array[i], &array[hi]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_helper - sorts an array in ascending order using quick sort
 * @array: is the array to sort
 * @lo: is the lower bound of the array to sort
 * @hi: is the upper bound of the array to sort
 * @size: is the length of the array
 */
void quick_sort_helper(int *array, int lo, int hi, unsigned int size)
{
	int pv;

	if (lo < hi)
	{
		pv = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pv - 1, size);
		quick_sort_helper(array, pv + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array in ascending order using quick sort
 * @array: is the array to sort
 * @size: is the length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
