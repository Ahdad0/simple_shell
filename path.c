#include "shell.h"

char *path(char **str)
{
	char *PATH = NULL, *cpy = NULL;

	PATH = getenv("PATH");
	
	cpy = strdup(PATH);
}
