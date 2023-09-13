#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *command_line(char **env);
char **separate(char *string);
int execute(char **string, char *av, char **en);
void print_environment(char **string, char **env);
void free_s(char **string);
int len_str(char *string);
int compare(char *s, char *c);
void str_cpy(char *de, char *c);
void eexit(char **string);

#endif
