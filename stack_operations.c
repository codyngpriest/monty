#include "monty.h"
int isInt(char *s);

/**
 * push - push an element to the stack/queue
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function pushes an element to the stack if the argument is
 * a valid integer. The mode determines whether the element is added to the top
 * of the stack (LIFO) or the end of the queue (FIFO).
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *ret = NULL;

if (!state->argument || !isInt(state->argument))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
state_clear();
exit(EXIT_FAILURE);
}

if (state->mode == MOD_STK)
ret = add_dnodeint(stack, atoi(state->argument));
else
ret = add_dnodeint_end(stack, atoi(state->argument));

if (!ret)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

state->size++;
}

/**
 * isInt - check if a string represents an integer
 * @s: String to check
 *
 * Return: 0 if the string is not an integer, 1 otherwise
 *
 * Description: This function checks if a given str represents a valid integer
 * It handles positive and negative integers.
 */
int isInt(char *s)
{
if (*s == '-' || *s == '+')
s++;

if (*s == 0)
return (0);

while (*s)
{
if (*s > '9' || *s < '0')
return (0);
s++;
}

return (1);
}
