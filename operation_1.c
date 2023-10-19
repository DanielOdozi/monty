#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (!vglo.arg)
	{
		print_push_error(line_number);
		cleanup_globals();
		exit(EXIT_FAILURE);
	}

	if (!is_integer(vglo.arg))
	{
		print_push_error(line_number);
		cleanup_globals();
		exit(EXIT_FAILURE);
	}

	value = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint_end(stack, value);
	else
		add_dnodeint(stack, value);
}

/**
 * pall - prints all values on the stack
 *
 * @stack: pointer to the head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		cleanup_globals();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

int is_integer(const char *str)
{
	int i = 0;

	if (str[i] == '-' || isdigit(str[i]))
	{
		i++;
		while (str[i] != '\0')
		{
			if (!isdigit(str[i]))
				return 0;
			i++;
		}
		return 1;
	}

	return 0;
}

void print_push_error(unsigned int line_number)
{
	dprintf(2, "L%u: usage: push integer\n", line_number);
}
