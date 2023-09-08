#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * print_environment - Print the environment variables.
 *
 * @env: The array of environment variables to be printed.
 */
void print_environment(char **env)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * main - Entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Return: Always returns 0.
 */
int main(int argc, char **argv, char **env)
{
	while (1)
	{
		printf("$ ");
		char *line = NULL;
		size_t len = 0;

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
		free(line);
	}
	return (0);
}
