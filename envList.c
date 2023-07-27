#include "shell.h"

/**
 * pop_envList - populates env linked list
 * @infArray: Str contains args, to maintain const funct prototype.
 * Return: Always 0
 */
int pop_envList(info_t *infArray)
{
	list_t *nd = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node(&nd, environ[i], 0);
	infArray->env = nd;
	return (0);
}

/**
 * _myEnv - prints current environment
 * @infArray: Str contains potential args, to maintain const funct prototype.
 * Return: Always 0
 */
int _myEnv(info_t *infArray)
{
	_list_strPrint(infArray->env);
	return (0);
}

/**
 * _get_myEnv - gets the value of an environ variable
 * @infArray: Structure containing potential arguments. Used to maintain.
 * @call: env var name
 *
 * Return: the value
 */

char *_get_myEnv(info_t *infArray, const char *call)
{
	list_t *nd = infArray->env;
	char *a;

	while (nd)
	{
		a = starts_with(nd->str, call);
		if (a && *a)
			return (a);
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _set_myEnv - Initialize new env var, or modify existing one
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: Always 0
 */
int _set_myEnv(info_t *infArray)
{
	if (infArray->argc != 3)
	{
		_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(infArray, infArray->argv[1], infArray->argv[2]))
		return (0);
	return (1);
}

/**
 * _unset_myEnv - Remove an environment variable
 * @infArray: Str contain potential args, to maintain const function prototype.
 *  Return: Always 0
 */
int _unset_myEnv(info_t *infArray)
{
	int i;

	if (infArray->argc == 1)
	{
		_puts("Few arguements.\n");
		return (1);
	}
	for (i = 1; i <= infArray->argc; i++)
		_unsetenv(infArray, infArray->argv[i]);

	return (0);
}
