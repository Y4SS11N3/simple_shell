#include "main.h"

/**
 * exter_cmd - Executes an external command.
 * @argv: Array of command arguments.
 * @cmd_path: Path to the command to execute.
 * @lexit_stat: Pointer to store the last exit status.
 * @our_env: The environment variables.
 *
 * Return: None.
 */
void exter_cmd(char **argv, char *cmd_path, int *lexit_stat, char **our_env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error in forking"); /* Handle forking error */
		cleanup(argv, cmd_path);
		*lexit_stat = EXIT_FAILURE;
		exit(*lexit_stat);
	}
	else if (pid == 0)
	{
		execve(cmd_path, argv, our_env); /*Execute the command in the child process*/
		perror("execve"); /* Handle execution error */
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED); /* Wait for the child process to complete*/
		if (WIFEXITED(status))
		{
			*lexit_stat = WEXITSTATUS(status);
		}
	}
}

/**
 * handle_builtin_commands - Handles builtin commands.
 * @argv: Array of command arguments.
 * @lexit_stat: Pointer to store the last exit status.
 * @our_env: The environment variables.
 *
 * Return: 1 if a builtin command is executed, 0 otherwise.
 */
int handle_builtin_commands(char **argv, int *lexit_stat, char ***our_env)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		handle_exit_command(argv, lexit_stat, our_env);
		return (1);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		handle_env_command(argv, lexit_stat, our_env);
		return (1);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		handle_setenv_command(argv, lexit_stat, our_env);
		return (1);
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		handle_unsetenv(argv, lexit_stat, our_env);
		return (1);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		handle_cd(argv, our_env);
		return (1);
	}

	return (0);
}

/**
 * execute_command - Main function to execute a command.
 * @argv: Array of command arguments.
 * @lexit_stat: Pointer to store the last exit status.
 * @our_env: The environment variables.
 *
 * Return: None.
 */
void execute_command(char **argv, int *lexit_stat, char ***our_env)
{
	char *cmd_path;
	char error_msg[256];

	if (!argv || !argv[0])
	{
		*lexit_stat = 127;
		return;
	}

	if (handle_builtin_commands(argv, lexit_stat, our_env))
	{
		return;
	}

	cmd_path = search_command(argv[0]);
	if (!cmd_path)
	{
		_strcpy(error_msg, "./hsh: 1: ");
		_strcat(error_msg, argv[0]);
		_strcat(error_msg, ": not found\n");
		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		*lexit_stat = 127;
		return;
	}

	exter_cmd(argv, cmd_path, lexit_stat, *our_env);
	free(cmd_path);
}

