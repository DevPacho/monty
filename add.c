#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: head of the stack.
 * @line_number: the line number error
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;

	if (*stack == NULL)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum += (*stack)->n;
	sum += (*stack)->next->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->n = sum;
}
