#include "monty.h"

/**
 * pchar - Prints the top of the stack as a character
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function prints the value at the top of the stack as a
 *character. It handles error cases when the stack is empty or
 *the value is out of the valid ASCII range.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if (state->size == 0)
{
fprintf(stderr, "L%u: can't pchar, stack empty\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}
if ((*stack)->n > 127 || (*stack)->n < 0)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n",
line_number);
state_clear();
exit(EXIT_FAILURE);
}

fprintf(stdout, "%c\n", (*stack)->n);
}

/**
 * pstr - Prints the stack as a string
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function prints the elements in the stack as a string,
 *starting from the top of the stack and stopping when the stack
 *is empty, encounters a value of 0, or encounters a non-ASCII
 *character.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *ptr = *stack;
(void)line_number;

while (ptr && (ptr->n <= 127 && ptr->n > 0))
{
putchar(ptr->n);
ptr = ptr->next;
}

putchar('\n');
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function rotates the elements in the stack to the top,
 *moving the top element to the bottom. It handles cases when
 *the stack has more than one element.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *head = *stack, *tail = *stack;
(void)line_number;

if (state->size > 1)
{
*stack = head->next;
while (tail->next)
tail = tail->next;

head->next->prev = NULL;
head->next = NULL;
head->prev = tail;
tail->next = head;
}
}

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Address of the stack
 * @line_number: Line number of the current processing input
 *
 * Description: This function rotates the elements in the stack to the bottom,
 *moving the bottom element to the top. It handles cases when
 *the stack has more than one element.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *head = *stack, *tail = *stack;
(void)line_number;

if (state->size > 1)
{
while (tail->next)
tail = tail->next;

*stack = tail;
tail->prev->next = NULL;
tail->prev = NULL;
tail->next = head;
head->prev = tail;
}
}
