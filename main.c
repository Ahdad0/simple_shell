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
	int i = 0;

	while (1)
	{
		printf("$ ");

		str = command_line();

		if (no_line(str) == 1)
		{
			free(str);
			continue;
		}

		arr = separate(str);

		if (check(arr, env) == 1)
		{
			continue;
		}

		execute(arr, av[0], env);

	}
	return (0);
}
