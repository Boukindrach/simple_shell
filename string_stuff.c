#include "shell.h"

/**
 * _strdup- duplicates a given string
 * and returns a dynamically allocated copy of the string.
 * @s: string
 * Return: new or Null
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen- calculates the length of a string
 * @s: string
 * Return: len
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}
/**
 * _strcat- appends the content of the source string
 * to the destination string
 * @dest: copied string
 * @src: original string
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *_strcpy- copies the source string into the destination string
 * @dest: copied string
 * @src: original string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp- compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0, 1 or -1
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
