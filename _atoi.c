#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string or if there is an error, converted number otherwise
 */
int _atoi(char *s)
{
    int sign = 1;
    int result = 0;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            result = result * 10 + (*s - '0');
            s++;
        }
        else
            return -1;
    }
    return sign * result;
}
