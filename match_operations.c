#include "monty.h"

/**
* match_operations - function that checks the validity of an opcode.
* @opcode: opcode to check.
* @stack: head of the stack.
* @line_number: node or line number for errors.
* Return: pointer to the operation function.
*/

void match_operations(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t match_ops[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{NULL, NULL},
	};
	int a;
	(void)line_number;

	for (a = 0; match_ops[a].opcode; a++)
	{
		if (_strcmp(opcode, match_ops[a].opcode) == 0)
		{
			match_ops[a].f(stack, global.line_error);
			return;
		}
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", global.line_error, opcode);
	exit(EXIT_FAILURE);
}
