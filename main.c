#include "monty.h"


/**
 * main - Entry point of the program.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
    char opcode[256];
    unsigned int line_number = 1;
	stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    freopen(argv[1], "r", stdin);

    while (fgets(opcode, sizeof(opcode), stdin) != NULL)
    {
        if (strcmp(opcode, "push\n") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(opcode, "pall\n") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: Unknown instruction: %s", line_number, opcode);
            return EXIT_FAILURE;
        }
        line_number++;
    }

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
