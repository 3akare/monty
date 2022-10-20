#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** GLOBAL VARIABLE **/
extern int op_int;

int monty(char *filename);
int get_int(char *str);
char *get_string(char *str);
int compare_opcode(char *str);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int isdigit(int number);

/** MONTY FUNCTIONS**/
void monty_push(stack_t **stack,  unsigned int line_number);
void monty_pall(stack_t **stack,  unsigned int line_number);
void monty_pint(stack_t **stack,  unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/** STACK **/
int init_stack(stack_t **stack);
void free_stack(stack_t **stack);
int check_mode(stack_t **stack);

/** ERROR HANDLERS **/
void monty_error_malloc(char *message);
void monty_error_malloc_free(char *message, char *str);
void monty_error_malloc_file(char *mes, char *str, char *str2, char *file);
void monty_error_close_file(char *op, int num, FILE *ptr);

#endif
