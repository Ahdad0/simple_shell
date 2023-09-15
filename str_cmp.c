#include "shell.h"

/**
 * compare- compare between 's' and 'c'
 *
 * @s: string
 * @c: string
 *
 * Return: 0 if they have the same char
 * and -1 if not
 */
int compare(const char *s, const char *c)
{
	while (*s || *c)
	{
		if (*s != *c)
		{
			return (*s - *c);
		}
		*s++;
		*c++;
	}

	return (0);
}
