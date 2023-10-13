#include "shell.h"

char *read_user_input()
{
	char *line = NULL;
	size_t bufsize = 0;

	ssize_t chars_read = getline(&line, &bufsize, stdin);

	if (chars_read == -1)
	{
		free(line);
		return NULL;
	}

	return line;
}
