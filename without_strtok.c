#include "shell.h"

/**
 * separate - Split a string into an array of substrings without using strtok.
 *
 * @string: The string to be split.
 *
 * Return: An array of substrings.
 */
char **separate1(char *string)
{
    char *mv, *start;
    char **arr;
    int i = 0;

    arr = malloc(sizeof(char *) * 32);

    if (arr == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    start = string;
    mv = string;

    while (*mv != '\0')
    {
        if (*mv == ' ' || *mv == '\t' || *mv == '\n')
        {
            *mv = '\0';

            if (start != mv)
            {
                arr[i] = strdup(start);
                i++;
            }
            start = mv + 1;
        }
        mv++;
    }

    if (start != mv)
    {
        arr[i] = strdup(start);
        i++;
    }

    arr[i] = NULL;
    return arr;
}
