#include <stdio.h>
#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int lenght_array = size;

	if (array == NULL || size == 0)
		return

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, lenght_array);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i], array, lenght_array);
		heapify(array, i, 0, lenght_array);
	}
}

/**
 * swap - swap the position of two elements
 * @a: first element to swap
 * @b: second element to swap
 * @array: array concerned
 * @lenght_array: lenght of the array
 * Return: no return
 */
void swap(int *a, int *b, int *array, int lenght_array)
{
	int temp = *a;

	print_array(array, lenght_array);

	*a = *b;
	*b = temp;
}

/**
 * heapify - Heapify a subtree with root node i
 * @array: array to sort
 * @size: size of heap
 * @i: root node
 * @lenght_array: lenght of the initial array
 * Return: no return
 */
void heapify(int *array, int size, int i, int lenght_array)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest], array, lenght_array);
		heapify(array, size, largest, lenght_array);
	}
}
