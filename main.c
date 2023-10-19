#include "monty.h"

/**
 * Declaration of global variable vglo.
 */
global_t vglo;

/**
 * Initializes the global variables.
 */
void initialize_globals(FILE *fd) {
    vglo.lifo = 1;
    vglo.cont = 1;
    vglo.arg = NULL;
    vglo.head = NULL;
    vglo.fd = fd;
    vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
    FILE *fd;

    if (argc == 1 || argc > 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    fd = fopen(argv[1], "r");

    if (fd == NULL)
    {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return (fd);
}

/**
 * Frees the global variables.
 */
void cleanup_globals() {
    free_dlistint(vglo.head);
    free(vglo.buffer);
    if (vglo.fd) {
        fclose(vglo.fd);
    }
}

/**
 * Main function.
 */
int main(int argc, char *argv[]) {
    void (*f)(stack_t **stack, unsigned int line_number);
    FILE *fd;
    size_t size = 256;
    ssize_t nlines = 0;
    char *lines[2] = {NULL, NULL};

    initialize_globals(NULL);

    fd = check_input(argc, argv);
    vglo.fd = fd;
    initialize_globals(fd);

    nlines = getline(&vglo.buffer, &size, fd);
    while (nlines != -1) {
        lines[0] = strtok(vglo.buffer, " \t\n");
        if (lines[0] && lines[0][0] != '#') {
            f = get_opcodes(lines[0]);
            if (!f) {
                dprintf(2, "L%u: ", vglo.cont);
                dprintf(2, "unknown instruction %s\n", lines[0]);
                cleanup_globals();
                exit(EXIT_FAILURE);
            }
            vglo.arg = strtok(NULL, " \t\n");
            f(&vglo.head, vglo.cont);
        }
        nlines = getline(&vglo.buffer, &size, fd);
        vglo.cont++;
    }

    cleanup_globals();

    return (0);
}
