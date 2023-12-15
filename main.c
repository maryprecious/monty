#include "monty.h"

/**
 * main - entry point for the Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Open the file and start processing byte codes */
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    /* Read the file line by line and execute instructions */

    fclose(file); /* Close the file when done processing */
    return EXIT_SUCCESS;
}
