#include "main.h"

/**
 * handle_env - Prints the current environment variables.
 * @our_env: The environment variables array.
 *
 * Description: Iterates through the environment variables array and prints
 * each variable. Uses the printing function for output.
 */
void handle_env(char **our_env)
{
	int i;

	for (i = 0; our_env[i] != NULL; i++)
	{
		printing(our_env[i]);
		printing("\n");
	}
}
