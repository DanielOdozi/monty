#include "monty.h"

/**
 * execute_opcode - Execute the Monty opcode.
 * @cont: The instruction to execute.
 * @stack: Pointer to the stack head.
 * @count: Line count.
 * @file: Pointer to the Monty file.
 * Return: 0 on success, 1 on failure.
 */
int execute_opcode(char *cont, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", push_top}, {"pall", print_stack}, {"pint", print_top},
        {"pop", pop_top}, {"swap", swap_top_two},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(cont, " \n\t");
	if (op && op[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && op)
	{
		if (strcmp(op, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(cont);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
