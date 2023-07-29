#include "shell.h"

/**
 * _eputs - prints a string
 *
 * @str: The string to print
 *
 * Return: nothing
 */
void _eputs(char *str)
{
	int i;

	if (!str)
	{
		return;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		_eputchar(str[i]);
	}

}


/**
 * _eputchar - writes the character c
 *
 * @c: The character to print
 *
 * Return:  1 to succ. On error, -1 is returned.
 */
int _eputchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}


/**
 *_putsfd - prints an input string
 *
 * @str: the strin to be print
 *
 * @fd: the filede scriptor to write
 *
 * Return: the number of charachters
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i = i + _putfd(*str++, fd);
	}
	return (i);
}



/**
 * _putfd - to writes the character c to given fd
 *
 * @c: The char to print
 *
 * @fd: The filede scriptor to write
 *
 * Return: On success 1. On error, -1 is returned.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

