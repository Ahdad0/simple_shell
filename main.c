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
	char *str, **arr;
<<<<<<< HEAD
	char *line = NULL;
	/*size_t len = 0;*/
=======
>>>>>>> 7239f053f059196593ee86595b2f5bd1e2e41f96

	while (1)
	{
<<<<<<< HEAD
		printf("$ ");
		/*getline(&line, &len, stdin);*/
		line = _getline();
		line[strlen(line) - 1] = '\0';
=======
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
>>>>>>> 7239f053f059196593ee86595b2f5bd1e2e41f96

		str = command_line(env);

		arr = separate(str);

		if (arr[0] == NULL)
		{
<<<<<<< HEAD
			/*str = command_line();*/
			str = strdup(line);
			arr = separate1(str);
			if (arr[0] == NULL)  /*continue if there is an empty input*/
			{
				free(str);
				free(arr);
				continue;
			}
			execute(arr, av[0], env);
			/*Free the dynamically allocated memory for str and arr*/
=======
>>>>>>> 7239f053f059196593ee86595b2f5bd1e2e41f96
			free(str);
			continue;
		}
		print_environment(arr, env);

		eexit(arr);

		execute(arr, av[0], env);

		free(str);
	}
	return (0);
}
