#include "monty.h"

/**
 * swap - Swaps the first two elements in the stack
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function swaps the positions of the first two elements
 *in the stack and handles the case when the stack has fewer than
 *two elements.
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *first = NULL, *second = NULL;

if (state->size < 2)
{
fprintf(stderr, "L%u: can't swap, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

first = *stack;
second = first->next;
first->next = second->next;
first->prev = second;
second->prev = NULL;
second->next = first;

if (first->next)
first->next->prev = first;

*stack = second;
}

/**
 * nop - Does nothing (No Operation)
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function does nothing and serves as a placeholder
 *operation. It is not functional in terms of stack manipulation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
stack = stack + 0;
line_number += 0;
}

/**
 * pall - Prints all elements in the stack
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function prints all elements in the stack using the
 *`print_dlistint` function. It does not modify the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
print_dlistint(*stack);
line_number += 0;
}
/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function prints the value at the top of the stack and
 *handles the case when the stack is empty.
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (state->size == 0)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
state_clear();
exit(EXIT_FAILURE);
}

fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function removes the top element of the stack and
 *handles the case when the stack is empty.
 */
void pop(stack_t **stack, unsigned int line_number)
{
if (state->size == 0)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
state_clear();
exit(EXIT_FAILURE);
}

delete_dnodeint_at_index(stack, 0);
state->size--;
}
