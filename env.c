#include "shell.h"

/**
 * print_environment - Print the environment variables.
 *
 * @string: string
 * @env: The array of environment variables to be printed.
 */
void print_environment(char **string, char **env)
{
	unsigned int i = 0, len = 0;

	while(string[len] != NULL)
	{
		len++;
	}

	if (len == 1 && strcmp(string[0], "env") == 0)
	{

		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], len_str(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
}
