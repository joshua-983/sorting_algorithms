#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, n = size;
	int temp;
	int new;

	do {
	new = 0;

	for (i = 1; i < n; i++)
	{
	if (array[i - 1] > array[i])
	{
	temp = array[i - 1];
	array[i - 1] = array[i];
	array[i] = temp;
	new = i;
	print_array(array, size); /*Print the array after each swap.*/
	}
	}
	n = new;
	} while (n >= 1);
}

