#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order.
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count = NULL, *copy = NULL;
	size_t j, temp, total = 0;

	if (array == NULL || size < 2)
		return;

	/* Create a copy of the original array */
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	/* Find the maximum value in the original array */
	for (j = 0, max = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}

	/* Create an array to store the count of each value */
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}

	/* Initialize the count array */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrences of each value in the original array */
	for (j = 0; j < size; j++)
		count[array[j]] += 1;

	/* Calculate the position of each value in the sorted array */
	for (i = 0; i <= max; i++)
	{
		temp = count[i];
		count[i] = total;
		total += temp;
	}

	/* Rearrange the values in the original array to sort it */
	for (j = 0; j < size; j++)
	{
		array[count[copy[j]]] = copy[j];
		count[copy[j]] += 1;
	}

	/* Print the count array */
	print_array(count, max + 1);

	/* Free allocated memory */
	free(count);
	free(copy);
}

