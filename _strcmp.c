#include "shell.h"

int _strcmp(char *s1, char *s2)
{
	int i;

	i = (int)*s1 - (int)*s2;

	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		i = (int)*s1 - (int)*s2;
	}

	return (i);
}
