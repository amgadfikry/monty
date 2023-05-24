#include "monty.h"

/**
 * remove_char - function that remove char from string
 * @str: string pointer
 * @c: char you want remove
 * Return: nothing
 */

void remove_char(char *str, char c)
{
	int i, j;

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] != c)
			str[j++] = str[i];
	}
	str[j] = '\0';
}

/**
 * code_from_line - convert line to arr contain
 * two first code or null
 * @line: line pointer
 * Return: arr of first two code char
 */

char **code_from_line(char *line)
{
	int x = 0;
	char **arr, *token;

	arr = malloc(sizeof(char *) * 2);
	if (arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	arr[0] = NULL;
	arr[1] = NULL;
	token = strtok(line, " ");
	while (token != NULL)
	{
		if (x == 2)
			break;

		arr[x] = malloc(sizeof(token));
		if (arr[x] == NULL)
		{
			free_array(arr);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		remove_char(token, '$');
		remove_char(token, '\n');
		strcpy(arr[x], token);
		x++;
		token = strtok(NULL, " ");
	}

	return (arr);
}

