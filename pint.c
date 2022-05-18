#include "monty.h"

/**
* pint - function that prints the value at the top of the stack.
* @stack: head of the stack.
* @line_number: node or line number for errors.
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = NULL;

	if (!*stack || !stack)
	{
		free(*stack);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(-1);
	}
	else
		printf("%d\n", traverse->n);
}
