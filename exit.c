#include "shell.h"

/**
 * eexit - function that execute exit
 *
 * @string: string
 */
void eexit(char **string)
{
	unsigned int i = 0, len = 0;

	while(string[len] != NULL)
	{
		len++;
	}

	if (len == 1 && compare(string[0], "exit") == 0)
	{
		exit(EXIT_FAILURE);
	}
}
