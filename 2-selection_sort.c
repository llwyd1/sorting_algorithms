#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_index;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* find index of smallest item in the unsorted array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/**
		 * if the index of the item is not the same as the current smallest
		 * then swap the items.
		 */
		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
