#include "monty.h"
global_variable global = {0, 1};
/**
 * main - monty
 * @argc: is the number of arguments of input
 * @argv: is the name of file executable
 * Return: 1 if successful, 0 if not, 0 otherwise
 */

int main(int argc, char **argv)
{
	char *line = NULL, *token = NULL;
	size_t len = 0, read;
	stack_t *stack;
	FILE *file;
	(void)argc;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file) != -1))
	{
		if (*line == '\n')
			continue;
		global.n = _atoi(line);
		token = strtok(line, DELIMITER);
		match_operations(token, &stack, global.n);
	}
	return (EXIT_SUCCESS);
}
