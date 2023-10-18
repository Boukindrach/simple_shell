#include "shell.h"

/**
 * read_line- Read a line of input from the user and allocate memory for it.
 *
 * Return: A dynamically allocated string containing the user's input line.
 *         Returns NULL if memory allocation or input read fails.
*/

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDOUT_FILENO))
		write(STDOUT_FILENO, "$", 2);

	n = getline(&line, &len, stdin);

	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
