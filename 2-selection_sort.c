#include "sort.h"

/**
  * selection_sort - sorts an array of integers in ascending order
  * using the selection sort algorithm.
  * @array: array of integers
  * @size: size of array
  * Return: none
  */

void selection_sort(int *array, size_t size)
{
	size_t int1, int2, intc, ints;

	if (!array || size < 2)
	{
		return;
	}

	for (int1 = 0; int1 < (size - 1); int1++)
	{
		int2 = int1;

		for (intc = int1 + 1; intc < size; intc++)
		{
			if (array[intc] < array[int2])
			{
				int2 = intc;
			}
		}

		if (int2 != int1)
		{
			ints = array[int1];
			array[int1] = array[int2];
			array[int2] = ints;

			print_array(array, size);
		}
	}
}
