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
	int node;

	token_input = strtok(NULL, DELIMITER);

	if(str_digit(token_input))
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
		new_head_stack->next = *stack;
		new_head_stack->prev = NULL;

		if (*stack != NULL)
				(*stack)->prev = new_head_stack;
		*stack = new_head_stack;
	}
	else
	{
		free_stack(*stack);
		fclose(global.file);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}
