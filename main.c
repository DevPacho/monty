#include "monty.h"
/**
 * main - monty
 * @argc: is the number of arguments of input
 * @argv: is the name of file executable
 * Return: 1 if successful, 0 if not, 0 otherwise
 */

FILE *file = NULL;

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *copy = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);
	int cont = 1;
	stack_t *stack;
	(void)argc;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(-1);
	}

	stack = NULL;
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (-1);
	}

	while ((read = getline(&line, &len, file) != -1))
	{
		copy = strdup(line);
		strtok(copy, DELIMITER);
		f = match_operations(copy);
		if (f)
		{
			printf("pilas");
			f(&stack,_atoi(line));
		}
		else
			fprintf(stderr, "L%d: unknown instruction %s\n", cont, copy);
		cont ++;
	}

	return (0);
}
