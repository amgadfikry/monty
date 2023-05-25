#include "monty.h"

/**
 * push - function that push new data to degin of stack
 * @stack: pointer to pointer of stack top
 * @line_num: number of line which command run
 * @data: num you want to push
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_num, char *data)
{
	stack_t *node;
	int i = 0;

	while (data[i])
	{
		if (data[0] == '-')
		{
			i++;
			continue;
		}
		if (data[i] < 48 || data[i] > 57)
		{
			fprintf(stderr, "L%d:usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->prev = NULL;
	node->next = NULL;
	node->n = atoi(data);

	if (*stack == NULL)
		*stack = node;
	else
	{
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}

/**
 * pall - function that print all data in stack stack
 * @stack: pointer to pointer of stack top
 * @line_num: number of line which command run
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;
	(void) line_num;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - function that print top element on stack
 * @stack: pointer to pointer of stack top
 * @line_num: number of line which command run
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);

}

/**
 * pop - function that remove top element in stack
 * @stack: pointer to pointer of stack top
 * @line_num: number of line which command run
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	if (ptr == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
	ptr->prev = NULL;
	free(*stack);
	*stack = ptr;
	}
}

/**
 * free_stack - function free stack
 * @stack: pointer to stack
 * Return: nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *ptr = stack;

	while (ptr)
	{
		ptr = ptr->next;
		free(stack);
		stack = ptr;
	}
}
