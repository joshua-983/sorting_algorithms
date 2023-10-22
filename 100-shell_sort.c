#include "sort.h"

/**
 * swap_ints - Swapping two integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;  /* Store the value of the first integer in a temporary variable.*/
	*a = *b;   /* Set the value of the first integer to be the same as the second integer.*/
	*b = tmp;  /* Set the value of the second integer to the temp*/
}

/**
 * shell_sort - Sort a array integer in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, z, j;

	if (array == NULL || size < 2) /* Check if the array is empty or one element.*/
		return;  /* No need to sort, so just return.*/

	for (gap = 1; gap < (size / 3);)  /* Calculate the initial gap using the Knuth sequence.*/
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)  /* Reduce the gap in each iteration.*/
	{
		for (z = gap; z < size; z++)  /*Iterate through the array with the current gap.*/
		{
			j = z;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;  /* Move j to the previous position in the current gap.*/
			}
		}
		print_array(array, size); /*Print the array after this iteration.*/
	}
}
