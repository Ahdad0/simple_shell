#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt_user(void);
void execute_command(char *cmd);
void tokenize(char *input, char *tokens[], int *num_tokens);
int execute(char *args[]);

#endif
