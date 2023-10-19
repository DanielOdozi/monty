#include "monty.h"

/**
 * add_dnodeint_end - add a node at the end of the doubly linked list
 * @head: pointer to the first node of the linked list
 * @n: data to store in the new node
 * Return: a pointer to the newly added node
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		cleanup_globals();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}

/**
 * add_dnodeint - add a node at the beginning of the doubly linked list
 * @head: pointer to the first node of the linked list
 * @n: data to store in the new node
 * Return: a pointer to the newly added node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		cleanup_globals();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * free_dlistint - frees the doubly linked list
 * @head: pointer to the first node of the linked list
 */
void free_dlistint(stack_t *head)
{
	stack_t *current, *next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
