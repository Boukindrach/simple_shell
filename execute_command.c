#include "shell.h"

/**
 * execute_command- Execute a command given its path and arguments.
 * @command_path: The path to the executable command.
 * @command: An array of strings containing the command and its arguments.
 *
 * Return: returns the exit status of the executed command.
*/

int execute_command(char *command_path, char **command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Fork failed");
		return (1);
	}

	if (child_pid == 0)
	{
		execve(command_path, command, NULL);

		perror("Execution error");
		_exit(EXIT_FAILURE);
	}

	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (WEXITSTATUS(status));
}
