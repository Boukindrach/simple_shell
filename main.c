#include "shell.h"

int main(void)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;

	while (1)
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
			return status;
		}

		command = tokenize_input(line);

		if (command == NULL)
		{
			continue;
		}

		status = execute_command(command);

		free(line);
		free(command);
	}

    return 0;
}
