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
 * code_from_line - function that split line to array of first
 * two string or null if it is null or space only
 * @line: pointer to line
 * Return: pointer to array of strings
 */

char **code_from_line(char *line)
{
	char **arr, *token, *ptr;
	int x = 0;

	if (line == NULL || strlen(line) == 0)
		return (NULL);

	remove_char(line, '\n');
	remove_char(line, '\t');

	ptr = malloc(sizeof(char) * (strlen(line) + 1));
	strcpy(ptr, line);
	remove_char(ptr, ' ');
	if (strlen(ptr) == 0)
	{
		free(ptr);
		return (NULL);
	}
	free(ptr);

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		if (x == 2)
			break;
		remove_char(token, '$');
		arr[x] = token;
		x++;
		token = strtok(NULL, " ");
	}
	arr[x] = "\0";

	return (arr);
}
