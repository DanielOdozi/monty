#include "monty.h"

/**
 * deallocate_stack - Frees a doubly linked list.
 * @start: Head of the stack.
 */
void deallocate_stack(stack_t *start)
{
	stack_t *current, *temp;

	current = start;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
