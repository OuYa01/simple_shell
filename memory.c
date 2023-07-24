#include "shell.h"

/**
 * memory - to free al memory allocated
 * @line : line to be free
 * @args: args to be free
 */


void memory(char *line, char **args)
{
	if (line != NULL)
		free(line);
	if (args != NULL)
		free(args);
}
