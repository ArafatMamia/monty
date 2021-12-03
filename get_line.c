#include "monty.h"
#include <stdlib.h>
/**
 * get_line - read the file line by line
 * @file_in: a file
 *
 * Return: exit code
 */
void get_line(FILE *file_in)
{
char *line = NULL;
size_t len = 0;
stack_t *top = NULL;
unsigned int line_number = 0;
instruction_t *instruction = NULL;

while (getline(&line, &len, file_in) != -1)
{
	line_number++;
	instruction = parse_line(line);

	if (!(instruction->opcode))
	{
		free(instruction);
		if (line)
			free(line);
		line = NULL;
		continue;
		}
	if (instruction->f)
		instruction->f(&top, line_number);
	else
	{
		char *str = "L%d: unknown instruction %s\n";

		fprintf(stderr, str, line_number, instruction->opcode);
		if (line)
			free(line);
		if (top)
			free_stack(top);
		free(instruction);
		exit(EXIT_FAILURE);
		}
	if (line)
		free(line);
	line = NULL;
	free(instruction);
	}

	if (line)
		free(line);
	free_stack(top);
}
