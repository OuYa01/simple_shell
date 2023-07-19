#include "main.h"
#include <errno.h>
#include <ctype.h>

/**
 * read_executing_cmds - read and execute the commands
 *
 * Return: 0 if scc
 *
 */

int read_executing_cmds(void)
{
	int i, stat;
	char *buffer = NULL;
	size_t size_of_buff;
	int char_count;
	char *token;
	char **array = NULL;
	pid_t our_pid;

	for (;;)
	{
		write(1, "ou&zo$ ", 7);
		char_count = getline(&buffer, &size_of_buff, stdin);
		token = strtok(buffer, " \t\n");
		i = 0;
		if (char_count == EOF)
		{
			if (errno != 0)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}
			else
			{
				exit(EXIT_SUCCESS);
			}
		}
		if (char_count > 0)
		{
			array = malloc((char_count + 1) * sizeof(char*));

			if (array == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			if (token == NULL)
			{
				free(array);
				continue;
			}
			for (i = 0; token; i++)
			{
				array[i] = token;
				token = strtok(NULL, " \t\n");
			}
			array[i] = NULL;
			our_pid = fork();
			if (our_pid == 0)
			{
				if (execve(array[0], array, NULL) == -1)
				{
					perror("error exe");
					free(array);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&stat);
				free(array);
			}
		}
		else
		{
			return (0);
		}
	}
	return (EXIT_SUCCESS);
}
