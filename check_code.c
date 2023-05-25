#include "monty.h"

/**
 * check_code - check code in script if in function list or not
 * @line: pointer to line
 * @stack: pointer to pointer of top of stack
 * @line_num: line number where code is in
 * Return: nothing
 */

void check_code(char *line, stack_t **stack, unsigned int line_num)
{
	int i = 0;
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
		{NULL, NULL}
	};

	line_arr = code_from_line(line);
	if (line_arr == NULL || line_arr[0][0] == '#')
		return;
	while (func_list[i].opcode)
	{
		if (strcmp(line_arr[0], "push") == 0)
		{
			push(stack, line_num, line_arr[1]);
			break;
		}
		if (strcmp(line_arr[0], func_list[i].opcode) == 0)
		{
			func_list[i].f(stack, line_num);
			break;
		}
		i++;
	}
	if (sizeof(func_list) / sizeof(instruction_t) == ++i)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line_arr[0]);
		exit(EXIT_FAILURE);
	}
	free(line_arr);
}
