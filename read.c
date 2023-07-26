#include "shell.h"

/**
 * read_line - read input from user
 *
 * Return: buffer
 */
char *read_line()
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t char_read;

	char_read = getline(&buffer, &len, stdin);

	if (char_read == -1)
	{
		if (isatty(STDIN_FILENO))
			perror("error");
		if (buffer != NULL)
		free(buffer);
		return (NULL);
	}

	return (buffer);
}
