#include "monty.h"
info_t *state = NULL;

/**
 * main - entry point of Monty interpreter
 * @argc: argument count
 * @argv: argument strings array
 *
 * Return: 0 on success, exit with status code on failure
 */
int main(int argc, char **argv)
{
char buffer[BUF_SIZE];
FILE *file;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

state_init();
file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
state_clear();
exit(EXIT_FAILURE);
}

while (fgets(buffer, BUF_SIZE, file))
{
process_line(buffer);

if (state->op)
{
if (state->op[0] != '#')
runner();
}

state->op = NULL;
state->argument = NULL;
}

fclose(file);
state_clear();
return (0);
}
