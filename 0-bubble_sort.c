#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in ascending order
  * using the bubble sort algorithm
  * @array: array of integers
  * @size: size of array
  * Return: none
  */

void bubble_sort(int *array, size_t size)
{
	int tmp = 0;
	int sort = 1;
	unsigned int itr;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (sort != 0)
	{
		sort = 0;

		for (itr = 0; itr < size - 1; itr++)
		{
			if (array[itr] > array[itr + 1])
			{
				tmp = array[itr];
				array[itr] = array[itr + 1];
				array[itr + 1] = tmp;
				sort = 1;
				print_array(array, size);
			}
		}
	}
}
