#include "monty.h"
/**
 * add_node_to_queue - Adds a new node to the end of the stack.
 *
 * @n: The new value to be added.
 * @head: The head of the stack.
 * Return: No return value.
 */
void add_node_to_queue(stack_t **head, int n)
{
    stack_t *new_node, *tail;

    tail = *head;
    new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        printf("Error\n");
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
