#include "monty.h"

/**
 * deallocate_stack - Frees a doubly linked list.
 * @start: Head of the stack.
 */
void deallocate_stack(stack_t *start)
{
	stack_t *temp;

	temp = start;

	while (start)
	{
		temp = start->next;
		free(start);
		start = temp;
	}
}
