#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @start: head of the stack
*/
void deallocate_stack(stack_t *start)
{
    stack_t *temp;

    temp = start;

    while (start)
    {
        temp = start->next;
        free(start);
        start = temp;
    }
}