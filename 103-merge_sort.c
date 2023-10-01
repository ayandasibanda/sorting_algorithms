#include "sort.h"
#include <stdio.h>

/**
 * _calloc - Allocates memory for an array, setting all elements to 0.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to the allocated memory, or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i = 0;
    char *p;

    if (nmemb == 0 || size == 0)
        return (NULL);

    /* Allocate memory for the array and initialize to 0 */
    p = malloc(nmemb * size);
    if (p == NULL)
        return (NULL);

    for (i = 0; i < (nmemb * size); i++)
        p[i] = 0;

    return (p);
}

/**
 * merge - Merges two subarrays into one sorted array.
 * @arr: Main array containing the subarrays.
 * @tmp: Temporary array used for merging.
 * @start: Starting index of the first subarray.
 * @mid: Ending index of the first subarray.
 * @end: Ending index of the second subarray.
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
    /* Sizes and temporary arrays */
    int size_left = mid - start + 1, size_right = end - mid;
    int *array_left, *array_right;
    /* Counters */
    int left, right, i = 0;

    array_left = &tmp[0];
    array_right = &tmp[size_right];

    /* Copy data to temporary arrays */
    for (left = 0; left < size_left; left++)
        array_left[left] = arr[start + left];
    for (right = 0; right < size_right; right++)
        array_right[right] = arr[mid + 1 + right];

    left = 0, right = 0, i = start;

    /* Merge the temporary arrays back into the main array */
    while (left < size_left && right < size_right)
    {
        if (array_left[left] <= array_right[right])
            arr[i] = array_left[left], left++;
        else
            arr[i] = array_right[right], right++;
        i++;
    }

    /* Copy the remaining elements of left array, if any */
    while (left < size_left)
        arr[i] = array_left[left], left++, i++;

    /* Copy the remaining elements of right array, if any */
    while (right < size_right)
        arr[i] = array_right[right], right++, i++;

    /* Print the merging process */
    printf("Merging...\n");
    printf("[left]: ");
    print_array(array_left, size_left);
    printf("[right]: ");
    print_array(array_right, size_right);
    printf("[Done]: ");
    print_array(&arr[start], size_left + size_right);
}

/**
 * mergesort - Recursively sorts an array of integers using the Merge sort algorithm.
 * @array: Array to be sorted.
 * @tmp: Temporary array used in the merge process.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * Return: void
 */
void mergesort(int *array, int *tmp, int start, int end)
{
    int mid;

    mid = (start + end) / 2;
    if ((start + end) % 2 == 0)
        mid--;

    if (mid >= start)
    {
        /* Recursively sort the left and right subarrays */
        mergesort(array, tmp, start, mid);
        mergesort(array, tmp, mid + 1, end);

        /* Merge the sorted subarrays */
        merge(array, tmp, start, mid, end);
    }
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (!array || size < 2)
        return;

    /* Allocate memory for the temporary array */
    tmp = _calloc(size, sizeof(int));

    /* Perform the merge sort */
    mergesort(array, tmp, 0, size - 1);

    /* Free the allocated memory for the temporary array */
    free(tmp);
}

