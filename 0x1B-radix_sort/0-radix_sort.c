#include "sort.h"

/**
 * countingSort -  Counting sort will sort the array based on the kth digit
 * @a: The array to be printed
 * @n: Number of elements in @array
 * @div: the kth division digit (1, 10, 100 ..)
 */
void countingSort(int *a, int n, int div)
{
	/**
	 * Making a count array of size 10, for counting
	 * the frequency of digits of array elements.
	 * Making a temporary array for storing the output.
	 */
	int *freq;
	int *temp;
	int init, count, u, t, f;

	freq = malloc(sizeof(int) * (10));
	if (!freq)
		return;
	/* Initializing all of its entries with 0. */
	for (init = 0; init < 10 ; init++)
		freq[init] = 0;
	/* Increasing count of kth  digit of a[i].*/
	for (count = 0; count < n; count++)
		freq[(a[count] / div) % 10]++;
	/* check the algorithm! https://www.youtube.com/watch?v=OKd534EWcdk */
	for (u = 1; u < 10; u++)
		freq[u] += freq[u - 1];
	temp = malloc(sizeof(int) * (n));
	if (!temp)
	{
		free(freq);
		return;
	}
	/* Building the temporary array. */
	for (t = n - 1; t > -1; t--)
	{
		temp[freq[(a[t] / div) % 10] - 1] = a[t];
		freq[(a[t] / div) % 10]--;
	}
	/* Updating the elements in array. */
	for (f = 0; f < n; f++)
		a[f] = temp[f];
	free(temp);
	free(freq);
}
/**
 * radix_sort - sort an array of integers in ascending order
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void radix_sort(int *array, size_t size)
{
	int max = 0;
	size_t i;
	int div;

	if (!array || size < 2)
		return;

	/* Find the max*/
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Calling countingSort */
	for (div = 1; (max / div) > 0; div *= 10)
	{
		countingSort(array, size, div);
		print_array(array, size);
	}
}
