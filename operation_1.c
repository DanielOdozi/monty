#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void push(stack_t **stack) {
    stack_t *new_node;
    char *value = strtok(NULL, " \n");
    if (value == NULL || !is_number(value)) {
        fprintf(stderr, "Usage: push integer\n");
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(value);
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void pall(stack_t **stack) {
    stack_t *current = *stack;
    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int is_number(const char *str) {
    if (*str == '-')
        str++;
    for (; *str; str++) {
        if (*str < '0' || *str > '9')
            return 0;
    }
    return 1;
}