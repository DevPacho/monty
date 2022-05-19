#include "monty.h"

/**
* mod - function that computes the rest of the division of the
* second top element of the stack by the top element of the stack.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void mod(stack_t **stack, unsigned int line_number)
{
	int to_mod;

	if (!*stack || !(*stack)->next)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	to_mod = (*stack)->next->n % (*stack)->n;
	(*stack)->n = to_mod;
}
