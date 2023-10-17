#include "shell.h"

char *_strdup(const char *str)
{
	char *p;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	p = malloc (sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = str[i];
	return (p);
}
