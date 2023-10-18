#include "shell.h"

int main(int argc, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0;
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
		
		command = tokenizer(line);
		if (!command)
			continue;

		status = _execute(command, argv);
	}

}
