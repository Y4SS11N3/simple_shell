#include "main.h"

/**
 * get_path - Gets the path for the cd command.
 * @argv: Array of command arguments.
 * @current_dir: The current directory.
 * @oldpwd: The old working directory.
 * @home: The home directory.
 *
 * Return: The path to change to.
 */
char *get_path(char **argv, char *current_dir, char *oldpwd, char *home)
{
	char *path;

	if (!argv[1])
	{
		path = home ? home : current_dir;
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		path = oldpwd ? oldpwd : current_dir;
	}
	else
	{
		path = argv[1];
	}

	return (path);
}

/**
 * change_directory - Changes the current directory.
 * @path: The path to change to.
 * @current_dir: The current directory.
 *
 * Return: The new current directory or NULL if failed.
 */
char *change_directory(char *path, char *current_dir)
{
	if (chdir(path) != 0)
	{
		write(STDERR_FILENO, "./hsh: 1: cd: can't cd to ", 25);
		write(STDERR_FILENO, " ", 1);
		write(STDERR_FILENO, path, _strlen(path));
		write(STDERR_FILENO, "\n", 1);
		free(current_dir);
		return (NULL);
	}

	return (getcwd(NULL, 0));
}

/**
 * handle_cd - Handles the cd command.
 * @argv: Array of command arguments.
 * @our_env: The environment variables.
 *
 * Return: None.
 */
void handle_cd(char **argv, char ***our_env)
{
	char *current_dir = getcwd(NULL, 0);
	char *path;
	char *new_current_dir;
	char *oldpwd;
	char *home;

	if (!current_dir)
	{
		perror("Error getting current directory");
		return;
	}

	oldpwd = _getenv("OLDPWD");
	home = _getenv("HOME");

	path = get_path(argv, current_dir, oldpwd, home);

	new_current_dir = change_directory(path, current_dir);
	if (!new_current_dir)
	{
		return;
	}

	if (_setenv("OLDPWD", current_dir, our_env) != 0
			|| _setenv("PWD", new_current_dir, our_env) != 0)
	{
		perror("Error setting environment variable");
	}

	if (_strcmp(argv[1], "-") == 0)
	{
		write(STDOUT_FILENO, new_current_dir, _strlen(new_current_dir));
		write(STDOUT_FILENO, "\n", 1);
	}

	free(current_dir);
	free(new_current_dir);
}
