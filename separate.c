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
 * separate - Split a string into an array of substrings.
 *
 * @string: The string to be split.
 *
 * Return: An array of substrings.
 */
char **separate(char *string)
{
	char *mv;
	char **arr;
	int i = 0;

	arr = malloc(sizeof(char *) * 32);

<<<<<<< HEAD
	if (arr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	mv = strtok(string, " \t\n");

	while (mv != NULL)
	{
		arr[i] = strdup(mv);
		mv = strtok(NULL, " \t\n");
		i++;
	}
	arr[i] = NULL;
	return (arr);
=======
	if (strcmp(arr[0], "ls") == 0)
	{
		arr[0] = "/bin/ls";
	}
	arr[i] = NULL;

        return (arr);
>>>>>>> f1de23ceb83a407740cfdff1d333b21484f3360e
}
