#include "sort.h"
#include <stdlib.h>

/**
 * get_max - maximum value in an array of integers.
 * @array: Array of integers.
 * @size: size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, d;

	/* Initialize max with the first element in the array.*/
	for (max = array[0], d = 1; d < size; d++)
	{
		/*Update max if a larger element is found.*/
		if (array[d] > max)
			max = array[d];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * @array: An array integers.
 * @size: Array size
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t d;

	/* Count the occurrences of each digit in the current significant position.*/
	for (d = 0; d < size; d++)
		count[(array[d] / sig) % 10] += 1;

	/*Update the count array to hold the positions of each digit in the output.*/
	for (d = 0; d < 10; d++)
		count[d] += count[d - 1];

	/* Place elements in the buffer in the correct order based on the digit.*/
	for (d = size - 1; (int)d >= 0; d--)
	{
		buff[count[(array[d] / sig) % 10] - 1] = array[d];
		count[(array[d] / sig) % 10] -= 1;
	}

	/*Copy the sorted elements from the buffer back to the original array.*/
	for (d = 0; d < size; d++)
		array[d] = buff[d];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	/* Allocate memory for a buffer to store sorted elements.*/
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	/*Find the maximum value in the array to determine the number of digits.*/
	max = get_max(array, size);

	/* Perform radix sort for each significant digit (from LSD to MSD).*/
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		/*Sort based on the current significant digit and print the array.*/
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	/*Free the allocated buffer.*/
	free(buff);
}
