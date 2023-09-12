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
	int i = 0;
	char *line = NULL;
	size_t len = 0;

	while (ac < 2)
	{
		printf("$ ");
		getline(&line, &len, stdin);
		line[strlen(line) - 1] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}
		else if (strcmp(line, "env") == 0)
		{
			print_environment(env);
		}
		else
		{
			/*str = command_line();*/
			str = strdup(line);
			arr = separate(str);

<<<<<<< HEAD
			if (arr[0] == NULL)  /*continue if there is an empty input*/
			{
				free(str);
				free(arr);
				continue;
			}
			execute(arr, av[0], env);
			/*Free the dynamically allocated memory for str and arr*/
			free(str);
			free(arr);
		}
		free(line);
	}
	return (0);
=======
                arr = separate(str);

                if (arr[0] == NULL)  /*continue if there is an empty input*/
                {
                        continue;
                }

                execute(arr, av[0], env);
        }
>>>>>>> f1de23ceb83a407740cfdff1d333b21484f3360e
}
