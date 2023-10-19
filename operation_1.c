#include "monty.h"

/**
 * is_number - Check if the element is number
 *
 * @str: The argument
 * Return: no return
 */
int is_number(const char *str)
{
    if (*str == '-')
        str++;
    for (; *str; str++)
    {
        if (*str < '0' || *str > '9')
            return 0;
    }
    return 1;
}

/**
 * push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *value = strtok(NULL, " \n");
    stack_t *new_node;

    FILE *input_file = NULL;
    
    if (value == NULL || !is_number(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "L%u: Memory allocation error\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(value);
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
    free(input_file);
}

/**
 * pall- pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("L%u: %d\n", line_number, current->n);
        current = current->next;
    }
}
