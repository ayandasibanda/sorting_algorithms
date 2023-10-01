#include "sort.h"
#include <stdio.h>

/**
 * getMax - A utility function to get the maximum value in arr[]
 * @arr: The array to find the maximum from.
 * @n: Size of the array.
 * Return: The maximum value.
 */
int getMax(int *arr, int n)
{
    int i, max = arr[0];

    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return (max);
}

/**
 * countSort - A function to perform counting sort of arr[] according to
 * the digit represented by exp.
 * @arr: The array to be sorted.
 * @n: Size of the array.
 * @exp: The current digit place value (1, 10, 100, ...).
 * @output: An array to store temporary values during sorting.
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
    int i;
    int count[10] = {0}; /* Initialize count array for digits 0 to 9. */

    /* Store count of occurrences of each digit in count[] */
    for (i = 0; i < (int)n; i++)
        count[(arr[i] / exp) % 10]++;

    /*
     * Update count[i] so that count[i] now contains the actual
     * position of this digit in output[]
     */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array in sorted order */
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    /*
     * Copy the output array back to arr[], so that arr[] now
     * contains sorted numbers according to the current digit
     */
    for (i = 0; i < (int)n; i++)
        arr[i] = output[i];
    /* Uncomment the line below if you want to print the array at each iteration */
    /* print_array(arr, n); */
}

/**
 * radix_sort - The main function to sort arr[] of size n using Radix Sort.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int exp, maximum = 0;
    int *output = NULL; /* Output array should be of size n */

    if (array == NULL || size < 2)
        return;

    maximum = getMax(array, size);
    output = malloc(size * sizeof(int));
    if (output == NULL)
        return;

    /*
     * Do counting sort for every digit. Note that instead
     * of passing the digit number, exp is passed. exp is 10^i
     * where i is the current digit number.
     */
    for (exp = 1; maximum / exp > 0; exp *= 10)
    {
        countSort(array, size, exp, output);
        print_array(array, size);
    }

    free(output);
}

