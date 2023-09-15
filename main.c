#include "shell.h"

/**
 * main - Entry point of the simple shell program.
 *
 * @ac: The number of command-line arguments.
 * @av: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Return: Always returns 0.
 */
int main(int ac, char **av, char **env)
{
	char *str = NULL, **arr = NULL;

	while (1)
	{

		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		str = command_line(env);

		arr = separate(str);
		if (arr[0] == NULL)
		{
			free_s(arr);
			continue;
		}

		if (print_environment(arr, env) == 1)
		{
			continue;
		}

		eexit(arr);

		execute(arr, av[0], env);

		free(arr);
	}
	return (0);
}
