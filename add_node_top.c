#include "monty.h"

/**
 * add_node_top - Adds a node to the top of the stack.
 * @head: Pointer to the head of the stack.
 * @n: The value to be added.
 * Return: No return value.
 */
void add_node_top(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
