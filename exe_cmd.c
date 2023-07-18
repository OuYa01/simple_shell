#include "main.h"

/**
 * exe_cmd - execute command with arguments
 * @cmd: command 
 * @args: argument array
 *
 */

void exe_cmd(char *cmd, char *args[])
{
	our_pid = fork();
	if (our_pid == 0)
	{
		if (execvp(array[0], array) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&stat);
	}
}
