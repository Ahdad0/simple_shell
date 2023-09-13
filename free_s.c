#include "shell.h"

/**
 * free_s - free array of allocated space
 *
 * @string: string
 */
void free_s(char **string)
{
	int i;

	for (i = 0; string[i] != NULL; i++)
	{
		    free(string[i]);
	}

	free(string);
}
