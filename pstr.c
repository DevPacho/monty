#include "monty.h"

/**
* pstr - function that prints the string starting at the top of the stack.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;
	(void)line_number;

	while (traverse && isprint(traverse->n) && traverse->n != 0)
	{
		printf("%c", traverse->n);
		traverse = traverse->next;
	}
	printf("\n");
}
