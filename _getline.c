#include "shell.h"

char *_getline()
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    characters = getline(&line, &bufsize, stdin);

    if (characters == -1)
    {
        write(STDOUT_FILENO, "\n", 1);
        exit(EXIT_FAILURE);
    }
    return (line);
}
