#include "monty.h"

/**
 * get_opcodes - returns a function pointer based on the opcode
 *
 * @opcode: the opcode to look up
 * Return: a function pointer to the opcode handler
 */
void (*get_opcodes(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, op) == 0)
			break;
	}

	return (instruct[i].f);
}
