#include "monty.h"

/**
* pall - function that prints all the values on the stack,
* starting from the top of the stack.
* @stack: head of the stack.
* @line_number: node or line number for errors.
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse_to_print = NULL;
	(void)line_number;
	traverse_to_print = *stack;

	while (traverse_to_print)
	{
		printf("%d\n", traverse_to_print->n);
		traverse_to_print = traverse_to_print->next;
	}
}
