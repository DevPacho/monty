#include "monty.h"

/**
 * push - function that pushes an element to the stack.
 * @stack: head of the stack.
 * @line_number: node or line number for errors.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *token_input = NULL;
	stack_t *new_head_stack = NULL;
	int node = 0;

	token_input = strtok(NULL, DELIMITER);
	if (str_digit(token_input))
	{
		node = atoi(token_input);
		new_head_stack = malloc(sizeof(stack_t));
		if (!new_head_stack)
		{
			free_stack(*stack);
			fclose(global.file);
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		new_head_stack->n = node;
		if (global.is_stack == 0 || global.is_stack == 1)
			add_dnodeint(new_head_stack, stack);
		else
			add_dnodeint_endt(new_head_stack, stack);
	}
	else
	{
		free_stack(*stack);
		fclose(global.file);
		free(global.line);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * add_dnodeint - fuction that add new node
 * @new_head_stack: is a new node
 * @stack: is a head
 */
void add_dnodeint(stack_t *new_head_stack, stack_t **stack)
{
	new_head_stack->next = *stack;
	new_head_stack->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new_head_stack;
	*stack = new_head_stack;
}

/**
 * add_dnodeint_endt - fuction that add new node at the end
 * @new_head_stack: is a new node
 * @stack: is a head
 */
void add_dnodeint_endt(stack_t *new_head_stack, stack_t **stack)
{
	stack_t *p_aux = NULL;

	new_head_stack->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_head_stack;
		new_head_stack->prev = NULL;
		return;
	}
	p_aux = *stack;
	while (p_aux->next != NULL)
		p_aux = p_aux->next;

	new_head_stack->prev = p_aux;
	p_aux->next = new_head_stack;
}
