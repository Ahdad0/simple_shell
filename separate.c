#include "shell.h"

/**
 * compare- compare between 's' and 'c'
 *
 * @s: string
 * @c: string
 *
 * Return: 0 if they have the same char
 * and 1 if not
 */
int compare(char *s, char *c)
{
	int len_s, len_c, i = 0;

	len_s = len_str(s);
	len_c = len_str(c);

	if (len_s == len_c)
	{
		while (len_s >= i)
		{
			if (s[i] != c[i])
			{
				return (-1);
			}
			i++;
		}
	}
	else
	{
		return (-1);
	}

	return (0);
}

/**
 * len_str - count the lenght of a string
 *
 * @string: string to count
 *
 * Return: number of char
 */
int len_str(char *string)
{
	int len = 0;

	while (string[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * str_cpy - copy content of c to str.
 *
 * @de: destination that need a copy
 * @c: the copy
 */
void str_cpy(char *de, char *c)
{
	while (*c)
	{
		*de = *c;
		de++;
		c++;
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

	if (arr == NULL)
	{
		free(string);
		perror("malloc");
		return (NULL);
	}
	mv = strtok(string, " \t\n");

	while (mv != NULL)
	{
		arr[i] = malloc(len_str(mv) + 1);
		str_cpy(arr[i], mv);
		mv = strtok(NULL, " \t\n");
		i++;
	}

	if (i > 0 && compare(arr[0], "ls") == 0)
	{
		arr[0] = "/bin/ls";
	}

	arr[i] = NULL;

	return (arr);
}
