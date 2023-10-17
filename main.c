#include "shell.h"

int main(void)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	int exit_shell = 0;

	while (!exit_shell)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		line = read_user_input();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}

		command = tokenize_input(line);

		if (command == NULL)
		{
			continue;
		}

		if (_strcmp(command[0], "exit") == 0)
		{
			exit_shell = 1;
		}

		else if (_strcmp(command[0], "env") == 0)
		{
			print_environment();
		}
		else
		{
			status = execute_command_with_path(command);
		}

		free(line);
		free(command);
	}

    return (0);
}
