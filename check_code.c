#include "monty.h"

/**
 * check_number - function check if code in list of codes
 * @func_list: list of function in stack
 * @line_arr: array of code in script
 * Return: number in list or -1 if push
 */

int check_number(instruction_t func_list[], char **line_arr)
{
	int i = 0;

	while (func_list[i].opcode)
	{
		if (strcmp(line_arr[0], "push") == 0)
			return (-1);
		if (strcmp(line_arr[0], func_list[i].opcode) == 0)
			return (i);
		i++;
	}
	return (++i);
}

/**
 * check_code - check code in script if in function list or not
 * @line: pointer to line
 * @stack: pointer to pointer of top of stack
 * @line_num: line number where code is in
 * Return: nothing
 */

void check_code(char *line, stack_t **stack, unsigned int line_num)
{
	int num;
	char **line_arr;
	instruction_t func_list[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	line_arr = code_from_line(line);

	if (line_arr == NULL || line_arr[0][0] == '#')
	{
		if (line_arr != NULL)
			free(line_arr);
		return;
	}

	num = check_number(func_list, line_arr);

	if (num >= 13)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line_arr[0]);
		exit(EXIT_FAILURE);
	}
	else if (num < 0)
		push(stack, line_num, line_arr[1]);
	else
		func_list[num].f(stack, line_num);

	free(line_arr);
}

