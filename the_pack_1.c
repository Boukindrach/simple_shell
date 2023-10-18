#include "shell.h"

/**
 * _atoi- int to string
 * @str: string
 * Return: num
*/

int _atoi(char *str)
{
	int i = 0, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}

/**
 * is_positive_number- check number if it's positive
 * @str: string
 * Return: 1 or 0
*/

int is_positive_number(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
