#include "shell.h"

#define PROMPT "#cisfun$ "

/**
 * prompt_user - Display the shell prompt to the user.
 */
void prompt_user(void)
{
	write(STDOUT_FILENO, PROMPT, 10);
}

/**
 * execute_command - Execute a command entered by the user.
 * @cmd: The command to execute.
 */
void execute_command(char *cmd)
{
	if (access(cmd, X_OK) == 0)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			char *argv[2];
			argv[0] = cmd;
			argv[1] = NULL;

			if (execve(cmd, argv, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		perror(cmd);
	}
}

/**
 * main - Entry point for the simple shell program
 * @ac: The number of command-line arguments.
 * @av: An array of command-line argument strings.
 *
 * Return: Always returns EXIT_SUCCESS.
 */
int main(int ac, char **av)
{
	if (ac != 1)
	{
		fprintf(stderr, "Usage: %s\n", av[0]);
		return (EXIT_FAILURE);
	}

	char *cmd = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		prompt_user();
		read = getline(&cmd, &len, stdin);
		if (read == -1)
		{
			free(cmd);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (read > 1)
		{
			cmd[read - 1] = '\0';
			execute_command(cmd);
		}
	}
	return (EXIT_SUCCESS);
}
