#include "shell.h"

/**
 * Tokenize- a string into an array of strings using a specified delimiter.
 * @line: The input string to be tokenized.
 * Return: An array of strings obtained by splitting the input string.
 *         Returns NULL if memory allocation or tokenization fails.
*/

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0, j;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}

	token = strtok(tmp, DELIM);
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	tmp = _strdup(line);
	if (!tmp)
	{
		free(line);
		free(command);
		return (NULL);
	}

	token = strtok(tmp, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		if (!command[i])
		{
			for (j = 0; j < i; j++)
			{
				free(command[j]);
			}
			free(command);
			free(line);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	free(tmp);
	free(line);
	command[i] = NULL;
	return (command);
}

