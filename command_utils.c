#include "main.h"

/**
 * search_command - Searches for a command in the system's PATH.
 * @command: Command to search for.
 *
 * Return: Full path to the command or NULL if not found.
 */
char *search_command(char *command)
{
	struct stat st;
	char *path, *directory, *full_path;

	if (!command || _strchr(command, '/'))
		return (_strdup(command));

	path = _strdup(_getenv("PATH")); /* Get the PATH environment variable */
	if (!path)
		return (NULL);

	for (directory = strtok(path, ":"); directory; directory = strtok(NULL, ":"))
	{
		full_path = malloc(_strlen(directory) + _strlen(command) + 2);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		_strcpy(full_path, directory); /* Copy directory path to full_path */
		_strcat(full_path, "/"); /* Concatenate '/' to full_path */
		_strcat(full_path, command); /* Concatenate the command name to full_path */

		if (stat(full_path, &st) == 0) /* Check if the full path exists */
		{
			free(path);
			return (full_path);
		}
		free(full_path);
	}
	free(path);
	return (NULL);
}

/**
 * printing - Prints a message to the standard output.
 * @msg: Message to print.
 *
 * Return: None.
 */
void printing(char *msg)
{
	/* Write the message to standard output */
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * _getenv - Gets an environment variable.
 * @str: Name of the environment variable to get.
 *
 * Return: Value of the environment variable or NULL if not found.
 */
char *_getenv(const char *str)
{
	char **env;
	size_t len;

	if (str == 0 || environ == 0)
		return (0);
	len = _strlen((char *)str);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, (char *)str, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
	}
	return (0);
}
