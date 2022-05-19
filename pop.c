#include "monty.h"

/**
* pop - function that removes the top element of the stack.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse_to_delete = NULL;

	if (!*stack || !stack)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	traverse_to_delete = *stack;
	*stack = (*stack)->next;
	free(traverse_to_delete);
}
