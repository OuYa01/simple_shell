#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 *
 * @s: The string to get the length
 *
 * Return: leng of @s.
 */
int _strlen(char *s)
{
	int leng = 0;

	while (*s != '\0')
	{
		leng++;
		s++;
	}
	return (leng);
}


/**
 * _strcmp - compare string values
 *
 * @s1: input value
 *
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}


/**
 * _strcat - concatenates two strings
 * @dest: input distination
 * @src: input src
 *
 * Return: pointer of dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/*Find the length of the destination string*/
	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	/*append the source string to the end of the destinatioon of string*/
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	/*Return the pointer*/
	return (dest);
}


/**
 * starts_with - checks if a string starts with a specific prefix
 *
 * @haystack: string to search for per
 *
 * @needle: the substring to find per
 *
 * Return: address of next char
 * if the prefix is found; otherwise, returns NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle != '\0')
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
