#include "monty.h"

/**
 * stack_len - function that count number of element in stack
 * @stack: pointer to stack
 * Return: number of element
 */

int stack_len(stack_t *stack)
{
	stack_t *ptr = stack;
	int i = 0;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}

	return (i);
}

/**
 * swap - function that swap first two elements in stack
 * @stack: pointer to pointer of stack list
 * @line_num: line number of code executed
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	(*stack)->prev = ptr;
	ptr->next = *stack;
	ptr->prev = NULL;
	*stack = ptr;
}

/**
 * add - function add two first elemnt in stack
 * save result in second one and remove top
 * @stack: pointer to pointer of stack
 * @line_num: number of line where code exce
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	ptr->prev = NULL;
	ptr->n = ((*stack)->n + ptr->n);
	free(*stack);
	*stack = ptr;
}

/**
 * nop - function do nothing
 * @stack: pointer to pointer of stack
 * @line_num: line number of code exec
 * Return: nothing
 */

void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}

/**
 * sub - function sub top element from second top in stack
 * save result in second one and remove top
 * @stack: pointer to pointer of stack
 * @line_num: number of line where code exce
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	ptr->prev = NULL;
	ptr->n = (ptr->n - (*stack)->n);
	free(*stack);
	*stack = ptr;
}
