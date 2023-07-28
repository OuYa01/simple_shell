#include "shell.h"

/**
 *_eputs - prints an input string
 * @string: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *string)
{
	int i = 0;

	if (!string)
		return;
	while (string[i] != '\0')
	{
		_eputchar(string[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @chr: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char chr)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buff[i++] = chr;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @chr: The character to print
 * @fileDesc: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char chr, int fileDesc)
{
	static int i;
	static char buff[WRITE_BUF_SIZE];

	if (chr == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fileDesc, buff, i);
		i = 0;
	}
	if (chr != BUF_FLUSH)
		buff[i++] = chr;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @st: the string to be printed
 * @fileDesc: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *st, int fileDesc)
{
	int i = 0;

	if (!st)
		return (0);
	for (; *st; st++)
	{
		i += _putfd(*st++, fileDesc);
	}
	return (i);
}
