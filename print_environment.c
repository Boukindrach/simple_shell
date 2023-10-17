#include "shell.h"


void print_environment()
{
	extern char **environ;
	char **env;
	for (env = environ; *env != NULL; env++)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}
