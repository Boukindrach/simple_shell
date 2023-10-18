#include "shell.h"

/**
 * is_builtin- checks command if is built-in
 * command in a shell program
 * @command: string
 * Return: 0 or 1
*/

int is_builtin(char *command)
{
	char *built_in[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int j;

	for (j = 0; built_in[j]; j++)
	{
		if (_strcmp(command, built_in[j]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_builtin- execute built-in commands within a shell program
 * @command: string
 * @argv: string
 * @status: integer
 * @idx: integer
*/

void handle_builtin(char **command, char **argv, int *status, int idx)
{
	if (_strcmp(command[0], "exit") == 0)
	{
		exit_shell(command, status, argv, idx);
	}

	else if (_strcmp(command[0], "env") == 0)
	{
		print_env(command, status);
	}
}

/**
 * exit_shell- exit a shell program
 * @command: string
 * @argv: string
 * @status: integer
 * @idx: integer
*/

void exit_shell(char **command, int *status, char **argv, int idx)
{
	int exit_value = (*status);
	char *index, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _strlen(index));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freearray2D(command);
			return;
		}
	}
	freearray2D(command);
	exit(exit_value);
}

/**
 * print_env- print the environment variables
 * to the standard output
 * @command: string
 * @status: integer
*/

void print_env(char **command, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}


	freearray2D(command);
	*status = 0;
}
