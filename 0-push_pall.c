#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty byte code file
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *argument;
    int value;

    stack_t *new_node;

    /* Read the argument from the Monty byte code */
    argument = strtok(NULL, " \n\t");

    /* Check if the argument is missing or not an integer */
    if (argument == NULL || !is_numeric(argument))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer */
    value = atoi(argument);

    /* Create a new stack node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous of the current top node */
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack to point to the new node */
    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty byte code file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    /* Suppress unused parameter warning */
    (void)line_number;

    /* Print all elements in the stack */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * is_numeric - checks if a string is a numeric value
 * @str: string to check
 *
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(const char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}
