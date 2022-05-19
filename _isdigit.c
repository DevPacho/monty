#include "monty.h"
/**
* _isdigit - is a one fuction to prints the lower character.
*@c: letter being tested
* Return: Always 0 (Success)
*/
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
