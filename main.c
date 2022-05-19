#include "monty.h"
global_variable global = {0, 1, NULL, NULL};
/**
 * main - monty
 * @argc: is the number of arguments of input
 * @argv: is the name of file executable
 * Return: 1 if successful, 0 if not, 0 otherwise
 */

int main(int argc, char **argv)
{
	char *token = NULL;
	size_t len = 0, read;
	stack_t *stack;
	(void)argc;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&global.line, &len, global.file) != -1))
	{
		if (*(global.line) != 10)
		{
			global.n = _atoi(global.line);
			token = strtok(global.line, DELIMITER);
			match_operations(token, &stack, global.n);
		}
		global.line_error++;
	}
	fclose(global.file);
	free(global.line);
	return (EXIT_SUCCESS);
}
