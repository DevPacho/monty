#include "monty.h"

/**
* swap - function that swaps the top two elements of the stack.
* @stack: head of the stack.
* @line_number: node or line number for errors.
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int first_node;

	if (!*stack || !stack)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first_node = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = first_node;
}
