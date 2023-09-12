#include "shell.h"

int execute(char **str, char *av, char **en)
{
	pid_t piid;
	int statu;

	if (access(str[0], X_OK) == 0)
	{
		piid = fork();

		if (piid == -1)
		{
			perror("Fork");
			exit (EXIT_FAILURE);
		}
		else if (piid == 0)
		{
			if (execve(str[0], str, en) == -1)
			{
				perror(av);
				return (EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(piid, &statu, WUNTRACED);
		}
	}
	else
	{
		perror(av);
	}

	return (1);
}
