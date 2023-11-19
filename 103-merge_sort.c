#include "sort.h"

/**
* merge - merges two subarrays of integers
* @array: the original array
* @left: the left subarray
* @right: the right subarray
* @size: the size of the original array
*/
void merge(int *array, int *left, int *right, size_t size)
{
int i = 0, j = 0, k = 0;
int left_size, right_size;

left_size = size / 2;
right_size = size - left_size;

printf("Merging...\n");
printf("[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);

/* Merge the left and right subarrays in sorted order */
while (i < left_size && j < right_size)
{
	if (left[i] < right[j])
		array[k++] = left[i++];
	else
		array[k++] = right[j++];
}

/* Copy the remaining elements of the left subarray */
while (i < left_size)
	array[k++] = left[i++];

/* Copy the remaining elements of the right subarray */
while (j < right_size)
	array[k++] = right[j++];

printf("[Done]: ");
print_array(array, size);
}

/**
* merge_sort - sorts an array of integers in ascending order
* using the Merge sort algorithm
* @array: the array to be sorted
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
size_t mid, i;
int *left, *right;

if (array == NULL || size < 2)
	return;

/* Find the middle point of the array */
mid = size / 2;

/* Allocate memory for the left and right subarrays */
left = malloc(sizeof(int) * mid);
right = malloc(sizeof(int) * (size - mid));
if (left == NULL || right == NULL)
{
	free(left);
	free(right);
	return;
}

/* Copy the elements from the array to the subarrays */
for (i = 0; i < mid; i++)
	left[i] = array[i];
for (i = mid; i < size; i++)
	right[i - mid] = array[i];

/* Recursively sort the left and right subarrays */
merge_sort(left, mid);
merge_sort(right, size - mid);

/* Merge the sorted subarrays */
merge(array, left, right, size);

/* Free the allocated memory */
free(left);
free(right);
}
