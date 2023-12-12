#include "monty.h"

/**
  * f_rotr - Rotates the stack to the bottom
  * @head: Pointer to the stack head
  * @counter: Line number
  * Return: No return value
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (copy->next)
	{
		copy = copy->next;
	}

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
