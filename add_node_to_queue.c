#include "monty.h"

/**
 * set_queue - Sets the stack mode to queue (FIFO).
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void set_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	global.lifo = 1;
}

/**
 * add_node_to_queue - Adds a node to the end of the stack.
 * @head: Pointer to the head of the stack.
 * @n: New value to be added.
 * Return: No return value.
 */
void add_node_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *tail;

	tail = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (tail)
	{
		while (tail->next)
		{
			tail = tail->next;
		}
	}

	if (!tail)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
	}
}
