#include "monty.h"

global_t global = {NULL, NULL, NULL, 0};

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t line_length = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	global.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_length > 0)
	{
		line_content = NULL;
		line_length = getline(&line_content, &buffer_size, monty_file);
		global.content = line_content;
		line_num++;

		if (line_length > 0)
		{
			execute_opcode(line_content, &stack, line_num, monty_file);
		}
		free(line_content);
	}

	deallocate_stack(stack);
	fclose(monty_file);
	return (0);
}
