#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending order using the
 * shell sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    if (!array || size < 2)
        return;

    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    shell_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
