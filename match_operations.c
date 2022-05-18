#include "monty.h"

/**
* get_operations - function that checks the validity of an opcode.
* @stack: opcode to check.
* Return: pointer to the operation function.
*/

void match_operations(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t match_ops[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}
	};

	int a;

	for (a = 0; match_ops[a].opcode; a++)
	{
		if (*(match_ops[a].opcode) == *opcode)
		{
			printf("%s\n", opcode);
			match_ops[a].f(stack, line_number);
		}
		
	}
}
