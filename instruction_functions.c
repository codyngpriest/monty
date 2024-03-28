#include "monty.h"
#include <string.h>

/**
 * state_init - Initializes the info struct.
 */
void state_init(void)
{
state = malloc(sizeof(info_t));
if (!state)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

state->op = NULL;
state->argument = NULL;
state->stack = NULL;
state->fptr = NULL;
state->mode = MOD_STK;
state->size = 0;
state->ln = 0;

state->buffer = malloc(BUF_SIZE);
if (!state->buffer)
{
fprintf(stderr, "Error: malloc failed\n");
free(state);
exit(EXIT_FAILURE);
}
}

/**
 * state_clear - Frees the memory allocated to the info struct.
 */
void state_clear(void)
{
free(state->buffer);
free_dlistint(state->stack);
if (state->fptr)
fclose(state->fptr);
free(state);
}

/**
 * get_func - Retrieves the operation function associated with the opcode.
 * @opcode: The opcode string.
 *
 * Return: Pointer to the corresponding function, NULL if opcode does not exist
 */
void (*get_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
instruction_t instrs[] = {
{"push", push},
{"pint", pint},
{"pchar", pchar},
{"pstr", pstr},
{"pop", pop},
{"swap", swap},
{"nop", nop},
{"add", _add},
{"sub", _sub},
{"mul", _mul},
{"div", _div},
{"mod", _mod},
{"pall", pall},
{"stack", stack},
{"queue", queue},
{"rotl", rotl},
{"rotr", rotr},
{NULL, NULL}
};
instruction_t *instr = instrs;

while (instr->opcode)
{
if (!_strcmp(opcode, instr->opcode))
return (instr->f);
instr++;
}

return (NULL);
}

/**
 * process_line - Processes a line of input into opcode and argument string.
 * @line: The line of input.
 *
 * Description: This function assigns the opcode and argumen from the input lyn
 *              to the corresponding fields in the state struct. If opcode is
 *              missing, it leaves the fields as NULL.
 */
void process_line(char *line)
{
state->ln++;
state->op = strtok(line, " \n\t");
if (!state->op)
return;

state->argument = strtok(NULL, " \n\t");
}

/**
 * runner - Executes an opcode function.
 */
void runner(void)
{
void (*func)(stack_t **, unsigned int) = get_func(state->op);

if (!func)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
state->ln, state->op);
state_clear();
exit(EXIT_FAILURE);
}
func(&(state->stack), state->ln);
}
