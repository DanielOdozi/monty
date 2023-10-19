#include "monty.h"

/**
 * run_opcode - Executes the opcode from the input buffer.
 *
 * @inst: The inst to execute.
 * @stack: The head of the stack.
 * @line_num: The line number.
 * @mon: The Monty file pointer.
 * Return: 0 on success, 1 on failure.
 */
int run_opcode(char *inst, stack_t **stack, unsigned int line_num, FILE *mon)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", print_top},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(inst, " \n\t");
	if (op && op[0] == '#')
		return (0);

	figo.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && op)
	{
		if (strcmp(op, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_num);
			return (0);
		}
		i++;
	}

	if (op && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown inst %s\n", line_num, op);
		fclose(mon);
		free(inst);
		deallocate_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
