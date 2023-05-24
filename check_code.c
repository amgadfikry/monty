#include "monty.h"

/**
 * check_code - check code in script if in function list or not
 * @line_arr: pointer to array of code
 * @stack: pointer to pointer of top of stack
 * @line_num: line number where code is in
 * Return: nothing
 */

char *data = NULL;

void check_code(char *line, stack_t **stack, unsigned int line_num)
{
	int i = 0;
	char **line_arr;
	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	line_arr = code_from_line(line);
	if (strlen(line_arr[0]) == 0)
		return;
	while (func_list[i].opcode)
	{
		if (strcmp(line_arr[0], func_list[i].opcode) == 0)
		{
			if (strcmp(line_arr[0], "push") == 0)
				data = line_arr[1];
			func_list[i].f(stack, line_num);
			data = NULL;
			break;
		}
		i++;
	}
	if (sizeof(func_list) / sizeof(instruction_t) == ++i)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (line_arr)
		free_array(line_arr);
}
