#include "monty.h"

int op_int = 0;

/**
 * compare_opcode - compares file input with Opcode options
 * @str: a string
 *
 * Return: an integer
 */

int compare_opcode(char *str)
{
	int i = 0;
	char *vectors[] = {
		"push", "pall", NULL
	};

	str = get_string(str);

	while (vectors[i] != NULL)
	{
		if (!strcmp(vectors[i], str))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/**
 * main - the main function of the monty interpreter
 * Desc: Monty Bytecode Interpreter reads monty
 * bytecode files of and interprets the opcodes contained
 *
 * @argc: No. CMD line arguments <int>
 * @argv: An array of CMD line arguments <char *[]>
 *
 * Return: Always Successful
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
		monty_error_malloc("USAGE: monty file");
	monty(argv[1]);
	return (0);
}

/**
 * monty_stack - sets the format of the data to a stack (LIFO)
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */
void monty_stack(monty_stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - sets the format of the data to a queue (FIFO).
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */
void monty_queue(monty_stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
