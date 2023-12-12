#include "main.h"

/**
 * create_new_var - Creates a new environment variable.
 * @name: Name of the environment variable to create.
 * @value: Value of the environment variable to create.
 *
 * Return: Pointer to the new environment variable or NULL if failed.
 */
char *create_new_var(const char *name, const char *value)
{
	int name_len = _strlen(name);
	char *new_var = malloc(name_len + _strlen(value) + 2);

	if (new_var == NULL)
		return (NULL);

	_strcpy(new_var, name);
	new_var[name_len] = '='; /* Add the '=' character */
	_strcpy(new_var + name_len + 1, value);

	return (new_var);
}

/**
 * create_new_environ - Creates a new environment array.
 * @our_env: The original environment array.
 * @new_var: The new environment variable to add.
 * @i: The index to add the new variable at.
 *
 * Return: Pointer to the new environment array or NULL if failed.
 */
char **create_new_environ(char **our_env, char *new_var, int i)
{
	int j;
	char **new_environ = malloc(sizeof(char *) * (i + 2));

	if (new_environ == NULL)
	{
		free(new_var);
		return (NULL);
	}

	for (j = 0; j < i; j++)
		new_environ[j] = our_env[j]; /* Copy existing environment variables */

	new_environ[i] = new_var; /* Add the new environment variable */
	new_environ[i + 1] = NULL;

	return (new_environ);
}

/**
 * _setenv - Sets an environment variable.
 * @name: Name of the environment variable to set.
 * @value: Value of the environment variable to set.
 * @our_env: The environment variables.
 *
 * Return: 0 if successful, otherwise returns -1.
 */
int _setenv(const char *name, const char *value, char ***our_env)
{
	int i, len, name_len;
	char *new_var;
	char **new_environ;

	if (!name || !value || _strchr(name, '=') != NULL)
		return (-1);

	name_len = _strlen(name);
	for (i = 0; (*our_env)[i]; i++)
	{
		len = _strchr((*our_env)[i], '=') - (*our_env)[i];
		if (_strncmp((*our_env)[i], name, len) == 0 && len == name_len)
		{
			new_var = create_new_var(name, value);
			if (new_var == NULL)
				return (-1);

			free((*our_env)[i]);
			(*our_env)[i] = new_var; /* Replace it with the new one */
			return (0);
		}
	}

	new_var = create_new_var(name, value);
	if (new_var == NULL)
		return (-1);

	new_environ = create_new_environ(*our_env, new_var, i);
	if (new_environ == NULL)
		return (-1);

	free(*our_env);
	*our_env = new_environ; /* Update the environment array */

	return (0);
}

/**
 * _unsetenv - Unsets an environment variable.
 * @name: Name of the environment variable to unset.
 * @our_env: The environment variables.
 *
 * Return: 0 if successful, otherwise returns -1.
 */
int _unsetenv(const char *name, char ***our_env)
{
	int i, len, name_len;

	if (!name || _strchr(name, '=') != NULL)
		return (-1);

	name_len = _strlen(name);
	for (i = 0; (*our_env)[i]; i++)
	{
		len = _strchr((*our_env)[i], '=') - (*our_env)[i];
		if (_strncmp((*our_env)[i], name, len) == 0 && len == name_len)
		{
			free((*our_env)[i]);
			while (((*our_env)[i] = (*our_env)[i + 1]) != NULL)
				i++; /* Shift the remaining variables */
			return (0);
		}
	}
	return (-1);
}

