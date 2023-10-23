#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - Finds the partition for the quicksort using the Hoare scheme.
 * @array: Array to sort.
 * @lo: Lowest index partition
 * @hi: Highest index partion
 * @size: Array size
 * Return: Index partition.
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;
				print_array(array, size); /* Print the array after each swap.*/
			}
			lo++;
			hi--;
		}
	}
	return (hi);
}

/**
 * quicksort - Sorts a partition of an array int.
 * @array: Array
 * @lo: Lowest index partition
 * @hi: Highest index partition
 * @size: Array size
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - AN array int to be sorted
 * @array: The array to sort.
 * @size: Array size
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*Start the quicksort process with the entire array.*/
	quicksort(array, 0, size - 1, size);
}

