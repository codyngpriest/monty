#include "monty.h"

/**
 * _add - Adds the first two elements in the stack, removes the top element,
 *        and stores the sum in the second element.
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 */
void _add(stack_t **stack, unsigned int line_number)
{
if (state->size < 2)
{
fprintf(stderr, "L%u: can't add, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

(*stack)->next->n += (*stack)->n;
delete_dnodeint_at_index(stack, 0);
state->size--;
}

/**
 * _sub - Subtracts the value of the top element from the second top element
 * @stack: Address of the stack
 * @line_number: Line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
if (state->size < 2)
{
fprintf(stderr, "L%u: can't sub, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

(*stack)->next->n -= (*stack)->n;
delete_dnodeint_at_index(stack, 0);
state->size--;
}

/**
 * _mul - Multiplies the first two elements on the stack,
 *        removes the top element, and stores the product in the second element
 * @stack: Address of the stack
 * @line_number: Line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
if (state->size < 2)
{
fprintf(stderr, "L%u: can't mul, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

(*stack)->next->n *= (*stack)->n;
delete_dnodeint_at_index(stack, 0);
state->size--;
}

/**
 * _div - Divides the secon top element by the top element in the stack
 *        removes the top element and stores the quotient in the second element
 * @stack: Address of the stack
 * @line_number: Line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
if (state->size < 2)
{
fprintf(stderr, "L%u: can't div, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

(*stack)->next->n /= (*stack)->n;
delete_dnodeint_at_index(stack, 0);
state->size--;
}

/**
 * _mod - Computes the modulo operation of the second top element
 *        by the top element in the stack, removes the top element,
 *        and stores the remainder in the second element.
 * @stack: Address of the stack
 * @line_number: Line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
if (state->size < 2)
{
fprintf(stderr, "L%u: can't mod, stack too short\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

(*stack)->next->n %= (*stack)->n;
delete_dnodeint_at_index(stack, 0);
state->size--;
}

