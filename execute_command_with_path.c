#include "shell.h"

int execute_command(char *command_path, char **command);

int execute_command_with_path(char **command) {
	char *path = getenv("PATH");
	char *path_copy;
	char *dir;
	int status = 1;
	int full_path_len = 0;
	char *command_path = NULL;
	int i = 0, j;

	if (path == NULL)
	{
		write(STDERR_FILENO, "PATH environment variable is not set.\n", 39);
		return (status);
	}

	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		int dir_len = _strlen(dir);
		int cmd_len = _strlen(command[0]);
		full_path_len = dir_len + cmd_len + 2;

		command_path = (char *)malloc(full_path_len);

		if (command_path == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		i = 0;

		for (j = 0; j < dir_len; j++)
		{
			command_path[i++] = dir[j];
		}

		command_path[i++] = '/';

		for (j = 0; j < cmd_len; j++)
		{
			command_path[i++] = command[0][j];
		}

		command_path[i] = '\0';

		if (access(command_path, X_OK) == 0)
		{
			status = execute_command(command_path, command);
			free(command_path);
			break;
		}

		free(command_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (status);
}
