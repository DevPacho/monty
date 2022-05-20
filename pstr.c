#include "monty.h"

/**
* pstr - function that prints the string starting at the top of the stack.
* @head: head of the stack.
* @line_number: line number for errors.
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse_to_print = *stack;
	(void)line_number;

	while (traverse_to_print && isprint(traverse_to_print->n) && traverse_to_print->n != 0)
	{
		printf("%c\n", traverse_to_print->n);
		traverse_to_print = traverse_to_print->next;
	}
}
