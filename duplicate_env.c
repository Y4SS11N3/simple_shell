#include "main.h"

/**
 * duplicate_environment - Creates a duplicate of the given environment.
 * @env: The original environment to duplicate.
 *
 * Return: A pointer to the new environment array.
 */
char **duplicate_environment(char **env)
{
	int i, count;
	char **new_env;

	for (count = 0; env[count] != NULL; count++)
		;
	 /* Duplicate each environment variable */
	new_env = malloc((count + 1) * sizeof(char *));
	if (new_env == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < count; i++)
	{
		new_env[i] = _strdup(env[i]);
		if (new_env[i] == NULL)
		{
			while (i > 0)
			{
				free(new_env[--i]);
			}
			free(new_env);
			return (NULL);
		}
	}
	/* Set the last element of the new environment array to NULL */
	new_env[count] = NULL;

	return (new_env);
}

