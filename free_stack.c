#include "monty.h"

/**
* free_stack - function that frees a stack.
* @head: head of the stack.
*/

void free_stack(stack_t *head)
{
		stack_t *to_free;

		while (head)
		{
			to_free = head;
			head = head->next;
			free(to_free);
		}
}
