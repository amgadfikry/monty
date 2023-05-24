#include "monty.h"

/**
 * free_array - function to free an array memory
 * @arr: input array
 * Return: nothing
 */

void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
