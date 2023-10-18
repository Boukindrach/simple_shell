#include "shell.h"

/**
 * _getenv- retrieving the value of a specified environment variable
 * @v: A pointer to a string
 * Return: Null or env
*/

char *_getenv(char *v)
{
	char *tmp, *k, *value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
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
