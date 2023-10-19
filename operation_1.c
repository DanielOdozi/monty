#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the stack of the linked list
 * @line_num: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_num) {
    int value, idx = 0, error_flag = 0;

    if (figo.arg) {
        if (figo.arg[0] == '-') {
            idx++;
        }
        while (figo.arg[idx] != '\0') {
            if (figo.arg[idx] > '9' || figo.arg[idx] < '0') {
                error_flag = 1;
            }
            idx++;
        }
        if (error_flag == 1) {
            fprintf(stderr, "Line %d: Usage: push integer\n", line_num);
            fclose(figo.fd);
            free(figo.buffer);
            deallocate_stack(*stack);
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Line %d: Usage: push integer\n", line_num);
        fclose(figo.fd);
        free(figo.buffer);
        deallocate_stack(*stack);
        exit(EXIT_FAILURE);
    }

    value = atoi(figo.arg);

    if (figo.fifi == 0) {
        add_dnodeint(stack, value);
    } else {
        add_node_to_queue(stack, value);
    }
}
/**
 * pall - prints all values on the stack
 *
 * @stack: pointer to the stack of the linked list
 * @line_number: line number
 * Return: no return
 */
void _pall(stack_t **stack, unsigned int line)
{
    stack_t *current;
    (void)line;

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
 * _pint - prints the value at the top of the stack
 *
 * @stack: stack of the linked list
 * @line_number: line number
 * Return: no return
 */
void print_top(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Line %u: can't print, stack is empty\n", line_number);
        fclose(figo.fd);
        free(figo.buffer);
        deallocate_stack(*stack);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
