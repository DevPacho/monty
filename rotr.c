#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: head of the stack.
 * @line_number: line number for errors.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse_latest = NULL;
	(void)line_number;

	if (!*stack)
		return;
	
	traverse_latest = *stack;
	while (traverse_latest->next)
	{
		traverse_latest = traverse_latest->next;
	}
	traverse_latest->next = *stack;
	(*stack)->prev = traverse_latest;
	traverse_latest->prev->next = NULL;
	traverse_latest->prev = NULL;
	*stack = traverse_latest;
}
