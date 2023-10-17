#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: string
 * Return: the value of a
*/

int _strlen(char *s)
{
        int a = 0;

        while (*s != '\0')
        {
                a++;
                s++;
        }
        return (a);
}
