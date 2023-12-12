#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @stack: double pointer to the stack
 * @line_number: line number
 * Return: no return
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int stack_len = 0, sum;

	while (current)
	{
		current = current->next;
		stack_len++;
	}

	if (stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*stack = current->next;
	free(current);
}
