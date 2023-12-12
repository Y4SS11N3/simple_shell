#include "main.h"

/**
 * main - Entry point of the program
 * Return: lexit_stat, the exit status of the program
 */
int main(void)
{
	int lexit_stat = 0;
	char *input;
	char **argv;
	int num_tokens;
	char **our_env;

	our_env = duplicate_environment(environ); /* Duplicate the environment */

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printing("$ "); /* Print the prompt if it's an interactive session */
		}

		input = read_and_trim_input();
		if (!input)
		{
			if (isatty(STDIN_FILENO))
			{
				printing("\n"); /*Print a newline if the input is empty/an EOF is reached*/
			}
			break;
		}

		argv = parse_command(input, &num_tokens);
		free(input);

		if (argv)
		{
			execute_command(argv, &lexit_stat, &our_env);
			cleanup(argv, NULL);
			argv = NULL;
		}
	}
	cleanup_our_env(&our_env);
	return (lexit_stat);
}
