#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_PATH_SIZE 1024

/**
 * tokenize - Tokenizes an input string into an array of tokens.
 * @input: The input string to be tokenized.
 * @tokens: An array to store the resulting tokens.
 * @num_tokens: A pointer to an integer to store the number of tokens.
 */
void tokenize(char *input, char *tokens[], int *num_tokens)
{
	char *token = strtok(input, " \t\n\r");
	*num_tokens = 0;

	while (token != NULL)
	{
		tokens[(*num_tokens)++] = token;
		token = strtok(NULL, " \t\n\r");
	}
	tokens[*num_tokens] = NULL;
}

/**
 * execute - Executes a command with arguments in a child process.
 * @args: An array of strings representing the command and its arguments.
 *
 * Return: 1 after successful execution.
 */
int execute(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * main - Entry point of the simple shell program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARG_SIZE];
	int num_args;

	while (1)
	{
		printf(":)");
		fflush(stdout);
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}
		tokenize(input, args, &num_args);
		if (num_args > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				execute(args);
			}
		}
	}
	return (0);
}
