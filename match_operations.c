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
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL},
	};
	int a;

	for (a = 0; match_ops[a].opcode; a++)
	{
		if (strcmp(opcode, match_ops[a].opcode) == 0)
		{
			match_ops[a].f(stack, line_number);
			return;
		}
	}
	
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	fclose(global.file);
	free_stack(*stack);
	free(global.line);
	exit(EXIT_FAILURE);
}
