#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

char *command_line(char **env);
char **separate(char *string);
int execute(char **str, char *av, char **en);
int print_environment(char **string, char **env);
void free_s(char **string);
size_t len_str(const char *string);
int compare(const char *s, const char *c);
char *str_dup(const char *str);
void eexit(char **string);
char *_getline(void);
char **separate1(char *string);
int split(char *s);

#endif
