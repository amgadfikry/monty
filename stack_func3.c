#include "monty.h"

/**
 * _div - divide second top element by top one in stack
 * @stack: pointer to pointer in stack
 * @line_num: line number which exce
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	ptr->prev = *stack;
	ptr->n = (ptr->n / (*stack)->n);
	free(*stack);
	*stack = ptr;
}

/**
 * mul - mul second top element by top one in stack
 * @stack: pointer to pointer in stack
 * @line_num: line number which exce
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	ptr->prev = *stack;
	ptr->n = (ptr->n * (*stack)->n);
	free(*stack);
	*stack = ptr;
}

/**
 * mod - rest of divition second top element by top one in stack
 * @stack: pointer to pointer in stack
 * @line_num: line number which exce
 * Return: nothing
 */

void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	ptr = (*stack)->next;
	ptr->prev = *stack;
	ptr->n = (ptr->n % (*stack)->n);
	free(*stack);
	*stack = ptr;
}

/**
 * pchar - print the char at the top of stack accord to ascii
 * @stack: pointer to pointer of stack
 * @line_num: line number of code exce
 * Return: nothing
 */

void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
