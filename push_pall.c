#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the push opcode appears
 *
 * Description: The push opcode pushes an element onto the stack.
 *  If the argument is not an integer or if there is no argument,
 *  it prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, unsigned int line_number)
{
if (!state->argument || !isdigit(*state->argument))
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
state_clear();
exit(EXIT_FAILURE);
}

int value = atoi(state->argument);
push_stack(stack, value);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number where the pall opcode appears
 *
 * Description: The pall opcode prints all the values on the stack,
 *  starting from the top of the stack.
 *  If the stack is empty, it doesn't print anything.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;
(void)line_number;

while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}

