#include "shell.h"

/**
 * break_line - break a line into array
 *
 * @line: line that will user give
 *
 * Return: args
 */
char **break_line(char *line)
{
	char **args = NULL;
	char *token;
	size_t size = 0;
	size_t i;

	if (line == NULL)
		return (NULL);

	token = strtok(line, DEL);
	for (i = 0; token != NULL; i++)
	{
		if (i == size)
		{
			size = size + 10;
			args = _realloc(args, sizeof(char *) * (size + 1), sizeof(char *));
			if (args == NULL)
				return (NULL);
		}
		args[i] = token;
		token = strtok(NULL, DEL);
	}
	args[i] = NULL;
	return (args);
}
