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

/**
 * pop_top - pops the top element from the stack
 * @stack: pointer to the stack
 * @line_num: line number
 * Return: no return
 */
void pop_top(stack_t **stack, unsigned int line_num)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	free(top);
}

/**
 * swap_top_two - swaps the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_num: line number
 * Return: no return
 */
void swap_top_two(stack_t **stack, unsigned int line_num)
{
	stack_t *top;
	int length = 0, temp;

	top = *stack;
	while (top)
	{
		top = top->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(global.file);
		free(global.content);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	temp = top->n;
	top->n = top->next->n;
	top->next->n = temp;
}

/**
 * custom_add - adds the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_num: line number
 * Return: no return
 */
void custom_add(stack_t **stack, unsigned int line_num)
{
    stack_t *current, *aux;
    int stack_size = 0, result;

    current = *stack;
    aux = current;
    
    while (aux)
    {
        aux = aux->next;
        stack_size++;
    }

    if (stack_size < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
        fclose(global.file);
        free(global.content);
        deallocate_stack(*stack);
        exit(EXIT_FAILURE);
    }

    result = current->n + current->next->n;
    current->next->n = result;

    aux = current->next;
    aux->prev = NULL;
    *stack = aux;
    free(current);
}

/**
 * custom_nop - Does nothing.
 * @stack: Pointer to the stack
 * @line_num: Line number
 * Return: No return
 */
void custom_nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
