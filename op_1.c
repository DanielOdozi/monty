#include "monty.h"

/**
 * push_top - Adds a node to the stack.
 * @head: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return value.
 */
void push_top(stack_t **head, unsigned int line_number)
{
	int value, i = 0, error_flag = 0;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			i++;
		while (global.arg[i] != '\0')
		{
			if (global.arg[i] > '9' || global.arg[i] < '0')
				error_flag = 1;
			i++;
		}
		if (error_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.content);
			deallocate_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(global.arg);

	if (global.lifo == 0)
		add_node_top(head, value);
	else
		add_node_to_queue(head, value);
}

/**
 * print_stack - Prints the elements in the stack.
 * @stack: Pointer to the stack head.
 * @line_num: Line number (not used).
 * Return: No return value.
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	(void)line_num;

	current = *stack;

	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * print_top - prints the top element of the stack
 * @stack: pointer to the stack
 * @line_num: line number
 * Return: no return
 */
void print_top(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack is empty\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}