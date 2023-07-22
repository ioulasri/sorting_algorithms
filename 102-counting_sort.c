#include "sort.h"

/**
 * make_counting - make a counting array
 *
 * @max: max value in array
 * @size: size of array
 * @array: array of integers
 * Return: pointer to counting array
 */

int *make_counting(int max, int size, int *array)
{
	int *counting;
	int i;

	counting = malloc(sizeof(int) * (max + 1));
	if (!counting)
		return (NULL);
	for (i = 0; i <= max; i++)
		counting[i] = 0;

	i = 0;
	while (i < size)
	{
		counting[array[i]] += 1;
		i++;
	}
	i = 1;
	while (i <= max)
	{
		counting[i] = counting[i] + counting[i - 1];
		i++;
	}
	return (counting);
}

/**
 * counting_sort - sort an array of integers in ascending order using the
 * counting sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int *counting, *new_array;
	int max;
	size_t i;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counting = make_counting(max, size, array);
	if (!counting)
	{
		free(counting);
		return;
	}

	print_array(counting, max + 1);
	new_array = malloc(sizeof(int) * (size));
	i = size - 1;
	while (i >= 0)
	{
		new_array[counting[array[i]] - 1] = array[i];
		counting[array[i]]--;
		if (i != 0)
			i--;
		else
			break;
	}
	i = 0;
	while (i < size)
	{
		array[i] = new_array[i];
		i++;
	}
	free(new_array);
	free(counting);
}
