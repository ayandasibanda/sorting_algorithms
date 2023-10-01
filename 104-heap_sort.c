#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 **/
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * maxHeapify - Maintains the max-heap property for a subtree rooted at index idx.
 * @array: Array to be heapified.
 * @size: Size of the array for printing.
 * @idx: Index of the root of the subtree.
 * @n: Size of the heap to consider.
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
    int largest = idx;      /* Initialize largest as the root */
    int left = 2 * idx + 1; /* Calculate the left child's index */
    int right = 2 * idx + 2; /* Calculate the right child's index */

    /* Check if the left child is greater than the root */
    if (left < (int)n && array[left] > array[largest])
        largest = left;

    /* Check if the right child is greater than the largest so far */
    if (right < (int)n && array[right] > array[largest])
        largest = right;

    /* If the largest is not the root, swap and recursively heapify the affected subtree */
    if (largest != idx)
    {
        swap(&array[idx], &array[largest]);
        print_array(array, size);
        maxHeapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Sorts an array of integers using the Heap Sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 **/
void heap_sort(int *array, size_t size)
{
    int i;

    /* Build a max heap from the given array */
    for (i = (size - 2) / 2; i >= 0; --i)
        maxHeapify(array, size, i, size);

    /**
     * Extract elements from the heap one by one.
     * The largest element is always at the root after maxHeapify, so swap it with the last element,
     * reduce the heap size, and heapify the root.
     */
    for (i = (size - 1); i > 0; --i)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        maxHeapify(array, size, 0, i);
    }
}

