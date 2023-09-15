#include "shell.h"

/**
 * split - split string
 *
 * @s: string
 *
 * Return: number of string
 */
int split(char *s)
{
	int i, src = 1, cm = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && src == 1)
		{
			cm += 1;
			src = 0;
		}
		if (s[i + 1] == ' ')
		{
			src = 1;
		}
	}
	return (cm);
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
	char *mv = NULL;
	char **arr = NULL;
	int i = 0, j, number = 0;

	number = split(string);

	if (!number)
	{
		free(string);
		return (NULL);
	}

	arr = malloc(sizeof(char *) * (number + 1));

	if (arr == NULL)
	{
		free(string);
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	mv = strtok(string, " \t\n");

	while (mv != NULL)
	{
		arr[i] = str_dup(mv);
		mv = strtok(NULL, " \t\n");
		i++;
	}

	if (i > 0 && compare(arr[0], "ls") == 0)
	{
		arr[0] = "/bin/ls";
	}

	arr[i] = NULL;

	free(string);
	return (arr);
}
