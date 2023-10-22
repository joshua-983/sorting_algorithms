#include "sort.h" /* Include the "sort.h" header file.*/
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, v;

	/*Initialize max with the first element of the array.*/
	for (max = array[0], v = 1; v < size; v++)
	{
		if (array[v] > max)
			max = array[v];
	}

	return (max);
}

/**
 * counting_sort - Sorting an array of integers in ascending order
 * @array: An array of integers.
 * @size: size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, v;

	if (array == NULL || size < 2)
		return;

	/* Allocate memory for the sorted array.*/
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	/*Find the maximum value in the input array.*/
	max = get_max(array, size);

	/* Allocate memory for the counting array with size (max + 1).*/
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	/* Initialize the counting array elements to 0.*/
	for (v = 0; v < (max + 1); v++)
		count[v] = 0;

	/* Count the occurrences of each value in the input array.*/
	for (v = 0; v < (int)size; v++)
		count[array[v]] += 1;

	/*Perform cumulative summation on the counting array.*/
	for (v = 0; v < (max + 1); v++)
		count[v] += count[v - 1];

	/* Print the counting array.*/
	print_array(count, max + 1);

	/* Populate the sorted array using the counting array.*/
	for (v = 0; v < (int)size; v++)
	{
		sorted[count[array[v]] - 1] = array[v];
		count[array[v]] -= 1;
	}

	/* Copy the sorted array back into the original array.*/
	for (v = 0; v < (int)size; v++)
		array[v] = sorted[v];

	/* Free dynamically allocated memory.*/
	free(sorted);
`	free(count);
}
