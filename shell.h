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

#define DELIM " \t\n"

extern char **environ;
void freearray2D(char **arr);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_string(char *str, int len);
int _atoi(char *str);
int is_positive_number(char *str);

void handle_builtin(char **command, char **argv, int *status, int idx);
int is_builtin(char *command);
void exit_shell(char **command, int *status, char **argv, int idx);
void print_env(char **command, int *status);

int execute_command(char **command, char **argv, int idx);
char **tokenizer(char *line);
char *read_user_input(void);
char *_getpath(char *command);
char *_getenv(char *v);

int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

#endif
