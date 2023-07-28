#include "shell.h"

/**
 * hsh - main shell loop
 * @infArray: the parameter & return info struct
 * @argv: the argument vector from main()
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *infArray, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	for (; r != -1 && builtin_ret != -2;)
	{
		clear_info(infArray);
		if (interactive(infArray))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(infArray);
		if (r != -1)
		{
			set_info(infArray, argv);
			builtin_ret = find_builtin(infArray);
			if (builtin_ret == -1)
				find_cmd(infArray);
		} else if (interactive(info))
			_putchar('\n');
		free_info(infArray, 0);
	}
	write_history(infArray);
	free_info(infArray, 1);
	if (!interactive(infArray) && infArray->status)
		exit(infArray->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(infArray->status);
		exit(infArray->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - finds a builtin command
 * @infArray: the parameter & return info struct
 * Return: -1 if not found, 0 if succ, 1 if found but no succ, -2 if sig exit
 */
int find_builtin(info_t *infArray)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myEnv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _set_myEnv},
		{"unsetenv", _unset_myEnv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(infArray->argv[0], builtintbl[i].type) == 0)
		{
			infArray->line_count++;
			built_in_ret = builtintbl[i].func(infArray);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @infArray: the parameter & return info struct
 *
 * Return: void
 */
void find_cmd(info_t *infArray)
{
	char *path = NULL;
	int i, k;

	infArray->path = infArray->argv[0];
	if (infArray->linecount_flag == 1)
	{
		infArray->line_count++;
		infArray->linecount_flag = 0;
	}
	for (i = 0, k = 0; infArray->arg[i]; i++)
		if (!is_delim(infArray->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(infArray, "PATH="), infArray->argv[0]);
	if (path)
	{
		infArray->path = path;
		fork_cmd(infArray);
	} else
	{
		if ((interactive(infArray) || _get_myEnv(infArray, "PATH=")
			|| infArray->argv[0][0] == '/') && is_cmd(infArray, infArray->argv[0]))
			fork_cmd(infArray);
		else if (*(infArray->arg) != '\n')
		{
			infArray->status = 127;
			print_error(infArray, "Not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @infArray: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *infArray)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(infArray->path, infArray->argv, get_env(infArray)) == -1)
		{
			free_info(infArray, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	} else
	{
		wait(&(infArray->status));
		if (WIFEXITED(infArray->status))
		{
			infArray->status = WEXITSTATUS(infArray->status);
			if (infArray->status == 126)
				print_error(infArray, "Permission denied\n");
		}
	}
}
