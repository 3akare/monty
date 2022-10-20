#include "monty.h"
/**
 * monty_error_malloc - Handles malloc error
 * @message: Error message
 */

void monty_error_malloc(char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * monty_error_malloc_free - Handles malloc error and frees @str
 * @str: A string
 * @message: Error message
 */

void monty_error_malloc_free(char *message, char *str)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	free(str);
	exit(EXIT_FAILURE);
}

/**
 * monty_error_malloc_file - Handles malloc error and prints
 * error message when @filename can't be opened
 *
 * @mes: Error message
 * @str: A string
 * @str2: A string
 * @file: pointer to a file
 */

void monty_error_malloc_file(char *mes, char *str, char *str2, char *file)
{
	dprintf(STDERR_FILENO, "%s %s\n", mes, file);
	free(str);
	free(str2);
	exit(EXIT_FAILURE);
}

/**
 * monty_error_close_file - Handles error. closes file
 * and frees string
 *
 * @op: A string
 * @num: An integer
 * @ptr: a file pointer
 */

void monty_error_close_file(char *op, int num, FILE *ptr)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s", num, op);
	free(op);
	fclose(ptr);
	exit(EXIT_FAILURE);
}
