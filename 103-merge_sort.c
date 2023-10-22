#include "sort.h" /*Include the "sort.h" header file.*/
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t b, j, k = 0;

	/*Print the left and right subarrays before merging.*/
	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	/*Merge the subarrays into the buffer.*/
	for (b = front, j = mid; b < mid && j < back; k++)
		buff[k] = (subarr[b] < subarr[j]) ? subarr[b++] : subarr[j++];

	/* Copy any remaining elements from the left subarray.*/
	for (; b < mid; b++)
		buff[k++] = subarr[b];

	/*Copy any remaining elements from the right subarray.*/
	for (; j < back; j++)
		buff[k++] = subarr[j];

	/*Copy the sorted subarray back into the original array.*/
	for (b = front, k = 0; b < back; b++)
		subarr[b] = buff[k++];

	/*Print the merged subarray.*/
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store.
 * @front: front index of subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;

		/*Recursively sort the left and right subarrays.*/
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);

		/*Merge the sorted subarrays.*/
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	/*Allocate memory for a buffer*/
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	/*Call the recursive merge sort function.*/
	merge_sort_recursive(array, buff, 0, size);

	/*Free the buffer memory.*/
	free(buff);
}

