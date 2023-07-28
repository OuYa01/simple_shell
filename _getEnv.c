#include "shell.h"

/**
 * get_env - returns string array copy of the environ
 * @infArray: Str contains potential args, to maintain const funct prototype.
 * Return: Always 0
 */
char **get_env(info_t *infArray)
{
	if (!infArray->environ || infArray->environ_changed)
	{
		infArray->environ = listOfStrings(infArray->env);
		infArray->environ_changed = 0;
	}

	return (infArray->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: 1 on delete, 0 otherwise
 * @envv: the string env var property
 */
int _unsetenv(info_t *infArray, char *envv)
{
	list_t *nd = infArray->env;
	size_t i = 0;
	char *a;

	if (!nd || !envv)
		return (0);

	while (nd)
	{
		a = starts_with(nd->strctr, envv);
		if (a && *a == '=')
		{
			infArray > environ_changed = delete_node(&(infArray->env), i);
			i = 0;
			nd = infArray->env;
			continue;
		}
		nd = nd->next;
		i++;
	}
	return (infArray->environ_changed);
}

/**
 * _setenv - Initialize an env var, or modify an existing one
 * @infArray: Str contains potential args, to maintain const funct prototype.
 * @envv: the string env var property
 * @val: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *infArray, char *envv, char *val)
{
	char *buff = NULL;
	list_t *nd;
	char *a;

	if (!envv || !val)
		return (0);

	buff = malloc(_strlen(envv) + _strlen(val) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, envv);
	_strcat(buff, "=");
	_strcat(buff, val);
	nd = infArray->env;
	while (nd)
	{
		a = starts_with(nd->strctr, envv);
		if (a && *a == '=')
		{
			free(nd->strctr);
			nd->strctr = buff;
			infArray->environ_changed = 1;
			return (0);
		}
		nd = nd->next;
	}
	add_node(&(infArray->env), buff, 0);
	free(buff);
	infArray->environ_changed = 1;
	return (0);
}
