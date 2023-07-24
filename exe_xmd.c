#include "shell.h"

/**
 * exe_cmd - executes cmd
 *
 * @args: arg for cmd
 *
 * Return: 0 if scc or -1 if error
 */
int exe_cmd(char **args)
{
	pid_t pid;
	int stat;
	int exe;
	int exit_stat;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		exe = execvp(args[0], args);

		if (exe == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	} else if (pid > 0)
	{
		wait(&stat);
		if (WIFEXITED(stat))
		{
			exit_stat = WEXITSTATUS(stat);
			return (exit_stat);
		}
		else
		{
			perror("error");
			return (-1);
		}
	}
	else
	{
		perror("eroor");
		return (-1);
	}
	return (0);
}
