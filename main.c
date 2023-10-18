#include "shell.h"

/**
 * main-  entry point of the simple shell program.
 * @argc: the number of command-line arguments
 * @argv: pointer to an array of strings
 * Return: return status
*/

int main(int argc, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, idx = 0;
	(void)argc;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if(isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return status;
		}
		idx++;

		command = tokenizer(line);
		if (!command)
			continue;

		status = _execute(command, argv, idx);
	}

}
