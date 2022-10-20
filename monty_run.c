#include "monty.h"

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to Match.
 *
 * Return: A pointer to the corresponding function
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	int i = 0;
	instruction_t commands[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{"nop", monty_nop},
		{NULL,  NULL}
	};

	while (commands[i].opcode != NULL)
	{
		if (!strcmp(commands[i].opcode, opcode))
		{
			return (commands[i].f);
		}
		i++;
	}

	return (NULL);
}

/**
 * monty - The core of the interpreter
 * Desc: Opens a file, read it a line at a time an checks
 * for opcode
 *
 * @filename: The File to opened
 * Return: Always Successful
 */

int monty(char *filename)
{
	FILE *file;
	stack_t *stack = NULL;
	void (*op_func)(stack_t**, unsigned int);
	char *str = malloc(30);
	char *new_str = malloc(30);
	size_t size = 30;
	int line_no = 1;

	if (!str || !new_str)
		monty_error_malloc("Error: malloc failed");
	file = fopen(filename, "r");
	if (!file)
		monty_error_malloc_file("Can't open file", str, new_str, filename);
	init_stack(&stack);
	while (getline(&str, &size, file) != -1)
	{
		if (str[0] == '#')
		{
			line_no++;
			continue;
		}
		strcpy(new_str, str);
		if (strcmp("pall", str) == 0)
			monty_pall(&stack, line_no);
		else
		{
			op_int = get_int(str);
			str = get_string(str);
			op_func = get_op_func(str);
			if (op_func == NULL)
				monty_error_close_file(new_str, line_no, file);
			op_func(&stack, line_no);
		}
		line_no++;
	}
	free(str);
	free(new_str);
	free_stack(&stack);
	fclose(file);
	return (0);
}
