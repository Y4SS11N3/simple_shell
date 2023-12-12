#include "main.h"

/**
 * count_tokens - Counts the number of tokens in a string.
 * @str: String to count tokens in.
 *
 * Return: Number of tokens.
 */
static int count_tokens(char *str)
{
	char *copy, *token;
	int count = 0;

	copy = _strdup(str); /* Duplicate string to avoid modification */
	if (!copy)
		return (0);

	token = strtok(copy, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}

	free(copy);
	return (count);
}

/**
 * parse_command - Parses input into tokens.
 * @input: Input string to be parsed.
 * @num_tokens: Pointer to store the number of tokens.
 *
 * Return: Array of tokens or NULL if an error occurs.
 */
char **parse_command(char *input, int *num_tokens)
{
	char *token;
	char **argv;
	int i;

	*num_tokens = count_tokens(input);

	if (*num_tokens == 0)
		return (NULL);
	/* Allocate memory for tokens array */
	argv = malloc(sizeof(char *) * (*num_tokens + 1));
	if (!argv)
		return (NULL);

	token = strtok(input, " \t\n"); /* Get the first token */
	for (i = 0; i < *num_tokens; i++)
	{
		argv[i] = _strdup(token); /* Duplicate and store each token in the array */
		if (!argv[i])
		{
			while (i--) /* Clean up if memory allocation fails */
				free(argv[i]);
			free(argv);
			return (NULL);
		}
		token = strtok(NULL, " \t\n"); /* Get the next token */
	}
	argv[*num_tokens] = NULL;

	return (argv);
}
