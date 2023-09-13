#include "shell.h"

/**
 * command_line - Read a line of input from the user.
 *
 * Return: A dynamically allocated string containing the user's input.
 *
 * This string should be freed when no longer needed.
 */
char *command_line(char **env)
{
	char *li = NULL;
	size_t buf = 0;
	ssize_t re;

	re = getline(&li, &buf, stdin);

	if (re == -1)
	{
		free(li);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}

	return (li);
}
