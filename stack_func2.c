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
