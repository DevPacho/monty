#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: head of the stack.
 * @line_number: line number for errors.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;
	stack_t *p_aux = NULL;
	(void)line_number;
	if (!*stack)
		return;
	p_aux = *stack;
	tmp = (*stack)->n;
	while (p_aux)
	{
		if (p_aux->next == NULL)
		{
			(*stack)->n = p_aux->n;
			p_aux->n = tmp;
		}
		p_aux = p_aux->next;
	}
}
