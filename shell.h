#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int execute_command(char *command_path, char **command);
char *read_user_input();
char **tokenize_input(const char *line);
void print_environment();
int execute_command_with_path(char **command);
int _strlen(char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
#endif
