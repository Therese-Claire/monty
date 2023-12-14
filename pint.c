#include "monty.h"

/**
 * pint - print the value at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
