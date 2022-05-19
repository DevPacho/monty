#include "monty.h"

/**
 * push - function that pushes an element to the stack.
 * @stack: head of the stack.
 * @line_number: node or line number for errors.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *p_aux = *stack;
	int i;
	(void)line_number;
	global.token = strtok(NULL, DELIMITER);
	for (i = 0; global.token[i] != '\0'; i++)
	{
		if (global.token[i] == '-' && global.token[i+1] == '0')
			break;
		if (_isdigit(global.token[i]) != 1)
		{
			fprintf(stderr, "L%i: usage: push integer", global.line_error);
			fclose(global.file);
			exit(EXIT_FAILURE);
		}

	}
	global.n = atoi(global.token);
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
