#include "shell.h"

/**
 * _myexit - exits the shell
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: exits with a given exit status (0) if inf.argv[0] != "exit"
 */
int _myexit(info_t *infArray)
{
	int exitcheck;

	if (infArray->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(infArray->argv[1]);
		if (exitcheck == -1)
		{
			infArray->status = 2;
			print_error(infArray, "Illegal number: ");
			_eputs(infArray->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infArray->err_num = _erratoi(infArray->argv[1]);
		return (-2);
	}
	infArray->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @infArray: Str contains potential args, to maintain const funct prototype.
 *  Return: Always 0
 */
int _mycd(info_t *infArray)
{
	char *a, *dir, buffer[1024];
	int chdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infArray->argv[1])
	{
		dir = _get_myEnv(infArray, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _get_myEnv(infArray, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(infArray->argv[1], "-") == 0)
	{
		if (!_get_myEnv(infArray, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_get_myEnv(infArray, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _get_myEnv(infArray, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(infArray->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(infArray, "can't cd to ");
		_eputs(infArray->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _get_myEnv(infArray, "PWD="));
		_setenv(infArray, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @infArray: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *infArray)
{
	char **arg_arr;

	arg_arr = infArray->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr); /* temp att_unused workaround */
	return (0);
}
