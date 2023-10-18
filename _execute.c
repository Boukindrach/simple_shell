#include "shell.h"

/**
 * _execute- Execute a command by forking a child process and invoking execve.
 *
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: The exit status of the executed command.
 */

int _execute(char **command, char **argv, int idx)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getpath(command[0]);
	if (!full_cmd)
	{
		printerror(argv[0], command[0], idx);
		freearray2D(command);
		return (127);
	}

	child = fork();
	if (child == -1)
	{
		perror(argv[0]);
		freearray2D(command);
		return (-1);
	}

	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearray2D(command);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray2D(command);
	}
	return (WEXITSTATUS(status));
}
