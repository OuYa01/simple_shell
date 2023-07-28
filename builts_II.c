#include "shell.h"

/**
 * _myhistory - displays the history list, 1 cmd by line, start at 0.
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *infArray)
{
	print_list(infArray->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @infArray: parameter struct
 * @st: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *infArray, char *st)
{
	char *n, c;
	int ret;

	n = _strchr(st, '=');
	if (!n)
		return (1);
	c = *n;
	*n = 0;
	ret = delete_node_index(&(infArray->alias),
		get_node_index(infArray->alias, node_starts(infArray->alias, str, -1)));
	*n = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @infArray: parameter struct
 * @st: the string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *infArray, char *st)
{
	char *n;

	n = _strchr(st, '=');
	if (!n)
		return (1);
	if (!*++n)
		return (unset_alias(infArray, st));

	unset_alias(infArray, st);
	return (add_node(&(infArray->alias), st, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @nd: the alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *nd)
{
	char *n = NULL, *b = NULL;

	if (nd)
	{
		n = _strchr(nd->st, '=');
		for (b = nd->st; b <= n; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(n + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: Always 0
 */
int _myalias(info_t *infArray)
{
	int i = 0;
	char *n = NULL;
	list_t *nd = NULL;

	if (infArray->argc == 1)
	{
		nd = infArray->alias;
		for (; nd; nd = nd->next)
		{
			print_alias(nd);
		}
		return (0);
	}
	for (i = 1; infArray->argv[i]; i++)
	{
		n = _strchr(infArray->argv[i], '=');
		if (n)
			set_alias(info, infArray->argv[i]);
		else
			print_alias(node_starts_with(infArray->alias, infArray->argv[i], '='));
	}

	return (0);
}
