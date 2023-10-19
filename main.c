#include <stdio.h>
#include "monty.h"
global_t figo = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty fd location
* Return: 0 on success
*/
int main(int argc, char *argv[]) {
    char *line;
    FILE *file;
    size_t buffer_size = 0;
    ssize_t line_length = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty fd\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    figo.fd = file;

    if (!file) {
        fprintf(stderr, "Error: Can't open fd %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (line_length > 0) {
        line = NULL;
        line_length = getline(&line, &buffer_size, file);
        figo.buffer = line;
        line_number++;

        if (line_length > 0) {
            run_opcode(line, &stack, line_number, file);
        }

        free(line);
    }

    deallocate_stack(stack);
    fclose(file);

    return (EXIT_SUCCESS);
}
