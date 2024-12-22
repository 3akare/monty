#include "monty.h"

/**
 * monty_mul - Multiplies the top two elements of the stack
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_mul(monty_stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
	(void)line_number;
}

/**
 * monty_div - divides the second top element of the stack by the top element
 * of the stack.
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_div(monty_stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod -  computes the rest of the division of the
 *  second top element of the stack by the top element of
 * the stack
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_mod(monty_stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
