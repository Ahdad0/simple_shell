#include "shell.h"

/**
 * execute - Execute a command with arguments.
 *
 * @str: An array of strings representing the command and its arguments.
 * @av: The name of the program (used for error messages).
 * @en: The array of environment variables.
 *
 * Return: Returns 1 upon successful execution or -1 on failure.
 */
int execute(char **str, char *av, char **en, char *f)
{
	pid_t piid;
	static int num = 1;
	int statu;
	char num_str[10];

	if (access(f, X_OK) == 0)
	{
		piid = fork();

		if (piid == -1)
		{
			free_s(str);
			perror(av);
			exit(1);
		}
		else if (piid == 0)
		{
			if (execve(f, str, en) == -1)
			{
				free_s(str);
				perror(str[0]);
				exit(127);
			}
		}
		else
		{
			waitpid(piid, &statu, WUNTRACED);
		}
	}
	else
	{
		conv_str(num, num_str);
		write(2, av, len_str(av));
		write(2, ": ", len_str(": "));
		write(2, num_str, len_str(num_str));
		write(2, ": ", len_str(": "));
		write(2, str[0], len_str(str[0]));
		write(2, ": not found\n", len_str(": not found\n"));
		num++;
	}
	free_s(str);

	return (0);
}

void conv_str(int num, char *str)
{
	size_t i = 0;
	int temp = 0;

	temp = num;

	if (i >= sizeof(str))
	{
		str[0] = '\0';
		return;
	}

	while (temp > 0)
	{
		temp /= 10;
		i++;
	}

	str[i] = '\0';

	while (i > 0)
	{
		str[--i] = '0' + (num % 10);
		num /= 10;
	}
}
