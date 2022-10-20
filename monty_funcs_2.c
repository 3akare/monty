#include "monty.h"
/**
 * monty_swap - Swaps the top two elements of the stack
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * monty_add - adds the top two elements of the stack
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int new;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	new = tmp->n + tmp->next->n;
	monty_pop(stack, line_number);
	tmp->next->n += new;
	(*stack) = tmp;
}

/**
 * monty_sub - subtracts the top element from the element below it on the stack
 *
 * @stack: A doubly linked list
 * @line_number: An integer
 */

void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int new;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack);
	new = tmp->n - tmp->next->n;
	monty_pop(stack, line_number);
	tmp->next->n += new;
	(*stack) = tmp;
}

/**
 * monty_nop - does nothing
 *
 * @stack: A doubly linked list
 * @line_numb: An integer
 */

void monty_nop(stack_t __attribute__((unused))**stack, unsigned int line_numb)
{
	line_numb += 0;
}
