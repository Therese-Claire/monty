#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void push(stack_t **top, unsigned int line_number)
{
	int n, i = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		while (bus.arg[i] != '\0')
		{
		if (bus.arg[i] < 48 || bus.arg[i] > 57)
		{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.line);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
		i++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.setter == 0)
		addnode(top, n);
	else
		add_queue_node(top, n);
}

/**
 * pall - print all values on the stack starting from the top
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	(void)line_number;

	if (!current)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
