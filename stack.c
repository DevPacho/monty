#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO).
 * @stack: head of the stack.
 * @line_number: line number for errors.
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.is_stack = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: head of the stack.
 * @line_number: line number for errors.
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global.is_stack = 2;
}
