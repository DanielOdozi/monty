#include "monty.h"

/**
 * custom_pstr - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * custom_rotl - Rotates the stack to the top.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *aux;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	aux = (*stack)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = aux;
}

/**
 * custom_rotr - Rotates the stack to the bottom.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
