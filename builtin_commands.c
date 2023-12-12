#include "main.h"

/**
 * handle_exit_command - Handles the exit command
 * @argv: The command line arguments
 * @lexit_stat: The last exit status
 * @our_env: The environment variables
 *
 * Return: 1 if successful, otherwise returns the exit status
 */
int handle_exit_command(char **argv, int *lexit_stat, char ***our_env)
{
	if (argv[1] != NULL && !_isnumber(argv[1]))
	{
		/** Write an error message if the second argument is not a number */
		write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 31);
		write(STDERR_FILENO, " ", 1);
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		*lexit_stat = 2;
	}
	else
	{
		/** Determine exit status from argument or use last exit status */
		int exit_status = (argv[1] != NULL) ? _atoi(argv[1]) : *lexit_stat;

		cleanup(argv, NULL);
		cleanup_our_env(our_env);
		exit(exit_status);
	}
	return (1);
}

/**
 * handle_env_command - Handles the env command
 * @argv: The command line arguments
 * @lexit_stat: The last exit status
 * @our_env: The environment variables
 *
 * Return: 1 if successful
 */
int handle_env_command(char **argv, int *lexit_stat, char ***our_env)
{
	(void) argv; /** Ignore argv as it's not used in this function */
	(void) lexit_stat; /** Ignore lexit_stat as it's not used in this function */

	handle_env(*our_env);
	return (1);
}

/**
 * handle_setenv_command - Handles the setenv command
 * @argv: The command line arguments
 * @lexit_stat: The last exit status
 * @our_env: The environment variables
 *
 * Return: 1 if successful, otherwise returns the exit status
 */
int handle_setenv_command(char **argv, int *lexit_stat, char ***our_env)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		*lexit_stat = 0;
	}
	else
	{
		/** Attempt to set environment variable,update exit status based on result */
		if (_setenv(argv[1], argv[2], our_env) == -1)
		{
			*lexit_stat = 2;
		}
		else
		{
			*lexit_stat = 0;
		}
	}
	return (1);
}

/**
 * handle_unsetenv - Handles the unsetenv command
 * @argv: The command line arguments
 * @lexit_stat: The last exit status
 * @our_env: The environment variables
 *
 * Return: 1 if successful
 */
int handle_unsetenv(char **argv, int *lexit_stat, char ***our_env)
{
	if (argv[1] == NULL)
	{
		*lexit_stat = 0;
	}
	else
	{
		_unsetenv(argv[1], our_env);
		*lexit_stat = 0;
	}
	return (1);
}

