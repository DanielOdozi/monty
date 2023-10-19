#include "monty.h"

/**
 * custom_sub - Subtracts the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current->next->n -= current->n;
	*stack = current->next;
	free(current);
}

/**
 * custom_div - Divides the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_div(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	int len = 0, result;

	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}