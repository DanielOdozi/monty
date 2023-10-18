#include "monty.h"


/**
 * main - pushes an element to the stack
 *
 * @void: to void statement
 * Return: no return
 */
int main(void)
{
	char opcode[256];
	unsigned int line_number = 1;
	char *line = NULL;

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
			exit(EXIT_FAILURE);
		}
		line_number++;
	}

	free(line);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (0);
}
