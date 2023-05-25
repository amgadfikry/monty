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

/**
 * rotr - rotate last to top in stack
 * @stack: pointer to pointer of stack
 * @line_num: line number where code is exec
 * Return :  nothing
 */

void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *ptr = *stack;
	(void) line_num;

	if (stack_len(*stack) > 1)
	{
		while (ptr)
		{
			if (ptr->next == NULL)
			{
				(*stack)->prev = ptr;
				ptr->prev->next = NULL;
				ptr->next = *stack;
				ptr->prev = NULL;
				*stack = ptr;
				break;
			}
			ptr = ptr->next;
		}
	}
}

/**
 * num_or_not - function check if number is number or not
 * @data: string to check
 * Return: 0 if not num or 1 is is num
 */

int num_or_not(char *data)
{
	size_t i = 0;

	while (data[i])
	{
		if (data[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (data[i] < 48 || data[i] > 57)
			break;
		i++;
	}
	if (strlen(data) == 0 || strlen(data) != i)
		return (0);

	return (1);
}
