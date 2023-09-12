#include "shell.h"

char **separate(char *string)
{
        char *mv;
        char **arr;
        int i = 0;

        arr = malloc(sizeof(char *) * 32);

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
}