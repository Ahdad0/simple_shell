#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt_user(void);
void execute_command(char *cmd);
void tokenize(char *input, char *tokens[], int *num_tokens);
int execute(char *args[]);
void print_environment(char **env);

#endif
