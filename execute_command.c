#include "shell.h"

/**
 * execute_command- Execute a command
 * by forking a child process and invoking execve.
 * @command: An array of strings
 * @argv: An array of strings
 * @idx: integer
 * Return: The exit status of the executed command.
 */

int execute_command(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		freearray2D(command);
		exit(EXIT_FAILURE);
	}

	child = fork();
	if (child == -1)
	{
		perror(argv[0]);
		freearray2D(command);
		free(full_cmd);
		return (-1);
	}

	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			perror(argv[0]);
			freearray2D(command);
			free(full_cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray2D(command);
		free(full_cmd);
	}
	return (WEXITSTATUS(status));
}
