#include "monty.h"

stack_t *stack = NULL;
int main(void) {
    char opcode[256];
    char *line = NULL;

    while (fgets(opcode, sizeof(opcode), stdin) != NULL) {
        if (strcmp(opcode, "push\n") == 0) {
            push(&stack);
        } else if (strcmp(opcode, "pall\n") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "Unknown instruction: %s", opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    while (stack != NULL) {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}