#include "monty.h"

/**
* pchar - function that prints the char at the top of the stack.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isprint((*stack)->n))
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c", (*stack)->n);
}
