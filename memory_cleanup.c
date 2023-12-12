#include "main.h"

/**
 * cleanup - Frees the memory allocated for argv and cmd_path
 * @argv: The argument vector
 * @cmd_path: The command path
 */
void cleanup(char **argv, char *cmd_path)
{
	int i;

	if (argv)
	{
		for (i = 0; argv[i]; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}

	if (cmd_path)
	{
		free(cmd_path);
	}
}

/**
 * cleanup_our_env - Frees the memory allocated for our_env
 * @our_env: The environment
 */
void cleanup_our_env(char ***our_env)
{
	if (*our_env)
	{
		int i;

		for (i = 0; (*our_env)[i]; i++)
		{
			free((*our_env)[i]);
		}
		free(*our_env);
		*our_env = NULL;
	}
}

