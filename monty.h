#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 4096

/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct info_s - Holds information on the current program state
 * @buffer: Input buffer
 * @op: Operation code
 * @argument: Argument for the operation
 * @stack: Stack data structure
 * @ln: Line number being processed
 */
typedef struct info_s
{
char *buffer;
char *op;
char *argument;
stack_t *stack;
unsigned int ln;
} info_t;

/* Stack Operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* Program Logic and Execution */
void state_init(void);
void state_clear(void);
void process_line(char *line);
void (*get_func(char *op))(stack_t **stack, unsigned int line_number);
void runner(void);

/* Extern variable */
extern info_t *state;

/* String operation */
int _strcmp(char *s1, char *s2);

#endif
