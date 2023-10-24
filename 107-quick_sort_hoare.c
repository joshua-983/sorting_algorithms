#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition - finds the partition for the quicksort.
 * @array: array to sort
 * @lo: lowest partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int swap, pivot;

	pivot = array[hi];
	while (lo <= hi)
	{
		/* Find the elements that need to be swapped */
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;

		if (lo <= hi)
		{
			if (lo != hi)
			{
				/* Swap the elements */
				swap = array[lo];
				array[lo] = array[hi];
				array[hi] = swap;

				/* Print the array after swapping */
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi); /* Return the index of the partition */
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowest partition to sort
 * @hi: highest partition to sort
 * @size: Array size
 *
 * Return: void
 */
void quicksort(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		/* Find the pivot index using the partition function */
		pivot = partition(array, lo, hi, size);

		/* Recursively sort the sub-arrays before and after the pivot */
		quicksort(array, lo, pivot, size);
		quicksort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order.
 * @array: The array to sort
 * @size: Array size
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Call the quicksort function to sort the entire array */
	quicksort(array, 0, size - 1, size);
}

