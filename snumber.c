#include "main.h"

/**
 * _isnumber - Checks if a string is a number.
 * @s: The string to check.
 *
 * Return: 1 if the string is a number, otherwise returns 0.
 */
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		/* Check if each character is between '0' and '9' */
		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

