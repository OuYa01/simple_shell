#include "shell.h"
/**
 * _getline - it reads the entire line from stream
 * @buffptr: pointer to the buffer that will hold the line
 * @sptr: pointer to the size of the buffer
 * @stream: file to read from
 * Return: number of characters read, or -1 on error or EOF
 */
ssize_t _getline(char **buffptr, size_t *sptr, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t start, end;

	if (buffptr == NULL || sptr == NULL || stream == NULL)
		return (-1);
	if (*buffptr == NULL)
	{
		*sptr = BUFFER_SIZE;
		*buffptr = malloc(*sptr);
			return (-1);
	}
	for (size_t i = 0;;)
	{
		if (start >= end)
		{
			ssize_t read_size = read(fileno(stream), buffer, BUFFER_SIZE);

			if (read_size <= 0)
				return (read_size);
			start = 0;
			end = read_size;
		}
		for (; start < end; start++)
		{
			if (i >= *sptr - 1)
			{
				*sptr *= 2;
				*buffptr = realloc(*buffptr, *sptr);
				if (*buffptr == NULL)
					return (-1);
			}
			(*buffptr)[i++] = buffer[start];
			if ((*buffptr)[i - 1] == '\n')
			{
				(*buffptr)[i] = '\0';
				return (i);
			}
		}
	}
}
