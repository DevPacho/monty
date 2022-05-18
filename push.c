#include "monty.h"

/**
* @brief 
* 
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	printf("pilas\n");
	if (!new_stack)
	{
		free(new_stack);
	}

	new_stack->n = line_number;
	new_stack->next = *stack;
	new_stack->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_stack;
	
	*stack = new_stack;
}
