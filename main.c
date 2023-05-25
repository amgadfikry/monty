#include "monty.h"

/**
 * main - main function that start program
 * for compile monty script
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 0 on success or 1 for exit failure
 */
int main(int argc, char *argv[])
{
	FILE *script;
	char *line = NULL;
	ssize_t read_line;
	size_t line_len = 0;
	unsigned int line_num = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");
	if (script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&line, &line_len, script)) != -1)
	{
		check_code(line, &stack, line_num);
		line_num++;
	}

	fclose(script);
	free(line);
	free_stack(stack);
	exit(EXIT_SUCCESS);

	return (0);
}
