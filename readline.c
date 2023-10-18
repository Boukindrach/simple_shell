#include "shell.h"

/**
 * read_user_input- Read a line of input
 * from the user and allocate memory for it.
 * Return: A dynamically allocated string containing the user's input line.
 *         Returns NULL if memory allocation or input read fails.
*/

char *read_user_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t x;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	x = getline(&line, &len, stdin);

	if (x == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
