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

int _execute(char **command, char **argv);
char **tokenizer(char *line);
char *read_line(void);
char *_getpath(char *command);

int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

#endif
