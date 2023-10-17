#include "shell.h"
#include <string.h>

char **tokenize_input(const char *line)
{
	char **tokens = NULL;
	char *token;
	size_t bufsize = 64;
	size_t count = 0;
    
	tokens = (char **)malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	token = strtok(_strdup(line), " \t\r\n");
	while (token != NULL)
	{
		tokens[count] = _strdup(token);
		count++;

		if (count >= bufsize)
		{
			bufsize += 64;
			tokens = (char **)realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Memory reallocation error");
				return (NULL);
			}
		}

		token = strtok(NULL, " \t\r\n");
	}
	tokens[count] = NULL;

	return (tokens);
}
