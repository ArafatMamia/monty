#include "monty.h"

/* global struct to hold flag for queue and stack length */
var_t var;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *file_in = NULL;
	char *line = NULL, *op = NULL;
	size_t len = 0;

	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lineptr, &line);
	on_exit(free_stack, &stack);
	on_exit(m_fs_close, file_in);
	while (getline(&line, &len, file_in) != -1)
	{
		line_number++;
		op = strtok(line, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
