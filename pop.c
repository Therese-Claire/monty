/**
 * pop - removes the value at the top of the stack
 *
 * @top: top of the stack(head of doubly linked list)
 * @line_number: current line of monty file being executed
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;

	if (!current)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.line);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	*top = (*top)->next;
	if (*top)
		(*top)->prev = NULL;
	free(current);
}
