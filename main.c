#include "shell.h"

int main(int ac, char **av, char **env)
{
        char *str, **arr;
        int i = 0;

        while (ac < 2)
        {
                printf("$ ");

                str = command_line();

                arr = separate(str);

                if (arr[0] == NULL)  /*continue if there is an empty input*/
                {
                        continue;
                }

                execute(arr, av[0], env);
        }
}