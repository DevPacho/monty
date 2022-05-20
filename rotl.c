#include "monty.h"

/**
* rotl - rotates the stack to the top.
* @stack: head of the stack.
* @line_number: line number for errors.
*/

void rotl(stack_t **stack, unsigned int line_number)
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
			p_aux->n = tmp;
			break;
		}
		p_aux->n = p_aux->next->n;
		p_aux = p_aux->next;
	}
}
