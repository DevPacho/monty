#include "monty.h"

/**
* _div_ - function that divides the top two elements of the stack.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void _div_(stack_t **stack, unsigned int line_number)
{
	int to_divides;

	if (!*stack || !(*stack)->next)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	to_divides = (*stack)->next->n / (*stack)->n;
	(*stack)->n = to_divides;
}
