#include "monty.h"

/**
 * monty_pchar - prints the char at the top of the stack
 * @stack: a linked list
 * @line_num: an integer
 */
void monty_pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (tmp->n > 0 && (tmp->n) < 128)
		printf("%c\n", tmp->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	(void)line_num;
}

/**
 * monty_pstr - prints the string startin at top of the stack
 * @stack: a linked list
 * @line_num: an integer
 */
void monty_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = (*stack)->next;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');

	(void)line_num;
}

/**
 * monty_rotl - Rotates the stack to the top
 * @stack: a linked list
 * @line_number: an integer
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
{
		stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Rotates the stack to the bottom
 * @stack: a linked list
 * @line_number: an integer
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

