#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @infArray: struct address
 */
void clear_info(info_t *infArray)
{
	infArray->arg = NULL;
	infArray->argv = NULL;
	infArray->path = NULL;
	infArray->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @infArray: struct address
 * @argv: argument vector
 */
void set_info(info_t *infArray, char **argv)
{
	int i = 0;

	infArray->fname = argv[0];
	if (infArray->arg)
	{
		infArray->argv = strtow(info->arg, " \t");
		if (!infArray->argv)
		{

			infArray->argv = malloc(sizeof(char *) * 2);
			if (infArray->argv)
			{
				infArray->argv[0] = _strdup(info->arg);
				infArray->argv[1] = NULL;
			}
		}
		for (i = 0; infArray->argv && infArray->argv[i]; i++)
			;
		infArray->argc = i;

		replace_alias(infArray);
		replace_vars(infArray);
	}
}

/**
 * free_info - frees info_t struct fields
 * @infArray: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *infArray, int all)
{
	ffree(infArray->argv);
	infArray->argv = NULL;
	infArray->path = NULL;
	if (all)
	{
		if (!infArray->cmd_buf)
			free(infArray->arg);
		if (infArray->env)
			free_list(&(infArray->env));
		if (infArray->history)
			free_list(&(infArray->history));
		if (infArray->alias)
			free_list(&(infArray->alias));
		ffree(infArray->environ);
			infArray->environ = NULL;
		bfree((void **)infArray->cmd_buf);
		if (infArray->readfd > 2)
			close(infArray->readfd);
		_putchar(BUF_FLUSH);
	}
}
