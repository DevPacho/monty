#include "monty.h"

/**
 * str_digit - function that checks if a str is a digit.
 * @str: str to check.
 * Return: 1 on succes, 0 if not.
 */

int str_digit(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
