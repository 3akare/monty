#include "monty.h"

/**
 * init_stack - initailize a doubly linked list
 * @stack: Address of a doubly linked list
 * Return: Always Successful
 */

int init_stack(stack_t **stack)
{
	stack_t *s_new;

	s_new = malloc(sizeof(stack_t));
	s_new->prev = NULL;
	s_new->next = NULL;
	*stack = s_new;
	return (EXIT_SUCCESS);
}

/**
 * free_stack - frees a doubly linked list
 * @stack: Address of a doubly linked list
 * Return: Always Successful
 */

void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * check_mode - checks the opcode format status
 *
 * @stack: A doubly linked list
 * Return: An integer
 */

int check_mode(stack_t **stack)
{
	if ((*stack)->n == QUEUE)
		return (QUEUE);
	return (STACK);
}
