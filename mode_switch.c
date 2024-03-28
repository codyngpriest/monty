#include "monty.h"

/**
 * stack - Switch the mode to stack (LIFO)
 * @stack: Address of the stack
 * @line_number: Line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;

state->mode = MOD_STK;
}

/**
 * queue - Switch the mode to queue (FIFO)
 * @stack: Address of the stack
 * @line_number: Line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;

state->mode = MOD_QUE;
}
