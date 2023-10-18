#include "shell.h"

/**
 * _getenv- retrieving the value of a specified environment variable
 * @v: A pointer to a string
 * Return: Null or env
*/

char *_getenv(char *v)
{
	char *tmp, *k, *value, *env;
	int j;

	for (j = 0; environ[j]; j++)
	{
		tmp = _strdup(environ[j]);
		k = strtok(tmp, "=");

		if (_strcmp(k, v) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);

			return (env);
		}

		free(tmp);
	}

	return (NULL);

}
