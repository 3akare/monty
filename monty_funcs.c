#include "monty.h"

/**
 * monty_push - pushes a value into a linked list
 * @stack: a linked list
 * @line_number: an integer
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;

	new = malloc(sizeof(stack_t));

	if (!isdigit(op_int))
	{
		if (!new)
			monty_error_malloc("Error: malloc failed");
		new->n = op_int;
		if (check_mode(stack) == QUEUE)
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			new->prev = temp;
			new->next = NULL;
			temp->next = new;
		}
		else
		{
			temp = (*stack)->next;
			new->prev = *stack;
			new->next = temp;
			if (temp)
				temp->prev = new;
			(*stack)->next = new;
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_pall - prints all integer on the stack
 * @stack: a linked list
 * @line_number: an integer
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pop - removes the top elemnt of the stack
 * @stack: a linked list
 * @line_number: an integer
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->next;
	free((*stack)->next);
	if (tmp)
		tmp->prev = *stack;
	(*stack)->next = tmp;
}

/**
 * monty_pint - prints the integer at the top of the stack
 * @stack: a linked list
 * @line_number: an integer
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(tmp->n))
		printf("%d\n", tmp->n);
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pint\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void)line_number;
}

