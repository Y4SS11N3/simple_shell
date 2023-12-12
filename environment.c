#include "main.h"

/**
 * init_our_env - Initializes our environment.
 * @our_env: The environment variables.
 *
 * Return: None.
 */
void init_our_env(char ***our_env)
{
	int count = 0;
	int i;
	int j;
	/* Count the number of environment variables in the 'environ' array */
	while (environ[count])
	{
		count++;
	}

	*our_env = malloc(sizeof(char *) * (count + 1));
	if (!(*our_env))
	{
		exit(1);
	}

	for (i = 0; i < count; i++)
	{
		(*our_env)[i] = strdup(environ[i]);
		if (!(*our_env)[i])
		{
			for (j = 0; j < i; j++)
			{
				free((*our_env)[j]);
			}
			free(*our_env);
			exit(1);
		}
	}

	(*our_env)[count] = NULL;
}

