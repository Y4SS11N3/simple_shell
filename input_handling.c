#include "main.h"

/**
 * read_and_trim_input - Reads a line from the standard input and
 *                       trims trailing spaces.
 *
 * Return: Trimmed input string or NULL if an error occurs.
 */
char *read_and_trim_input()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t n;

	n = getline(&input, &len, stdin); /* Read a line from standard input */

	if (n <= 0)
	{
		if (input)
		{
			free(input);
		}
		return (NULL);
	}
	return (input);
}
