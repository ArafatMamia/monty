#include "monty.h"

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: array of argument strings
 *
 * Return: exit code
 */
int main(int argc, char *argv[])
{
FILE *file_in;

if (argc != 2)
{
	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
	exit(EXIT_FAILURE);
}
     /* open file */
file_in = fopen(argv[1], "r");
if (file_in == NULL)
{
	fprintf(stderr, "Error: Can't open file %s", argv[1]);
	exit(EXIT_FAILURE);
}
get_line(file_in);
fclose(file_in);
exit(EXIT_SUCCESS);
}
