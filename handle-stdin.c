#include "shell.h"

char *command_line()
{
        char *li = NULL;
        size_t buf = 0;
        ssize_t re;

        re = getline(&li, &buf, stdin);

        if (re == -1)
        {
                write(STDOUT_FILENO, "\n", 1);
                exit(EXIT_FAILURE);
        }

        return (li);
}