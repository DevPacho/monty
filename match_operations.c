#include "monty.h"

/**
* get_operations - function that checks the validity of an opcode.
* @stack: opcode to check.
* Return: pointer to the operation function.
*/

void (*match_operations(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t match_ops[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}
	};

	int a = 0;

	for (; match_ops[a].opcode; a++)
	{
		if (*(match_ops[a].opcode) == *opcode)
		{
			return (match_ops[a].f);
		}
	}
	return (NULL);
}
