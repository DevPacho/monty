#include "monty.h"

/**
* push - function that pushes an element to the stack.
* @stack: head of the stack.
* @line_number: node or line number for errors.
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *p_aux = *stack;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(stack);
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = global.n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = p_aux;
		p_aux->prev = new_node;
	}
	*stack = new_node;
}
