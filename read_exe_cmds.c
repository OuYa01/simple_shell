#include "main.h"

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
		if (char_count == EOF)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
		array = malloc((char_count + 1) * 8);
		//
		if (array == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		//
		
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
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&stat);
		free(array);
	}
	return (EXIT_SUCCESS);
}
