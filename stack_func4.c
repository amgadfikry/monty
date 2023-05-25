#include "monty.h"

/**
 * rotl - rotate top to last and second top become top
 * @stack: pointer to pointer of stack
 * @line_num: line number where code is exec
 * Return :  nothing
 */

void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;
	(void) line_num;

	if (*stack != NULL || (*stack != NULL && (*stack)->next != NULL))
	{
		while (ptr)
		{
			if (ptr->next == NULL)
			{
				ptr->next = *stack;
				(*stack)->prev = ptr;
				*stack = (*stack)->next;
				(*stack)->prev = NULL;
				ptr->next->next = NULL;
				break;
			}
			ptr = ptr->next;
		}
	}
}
