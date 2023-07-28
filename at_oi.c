#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @infArray: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *infArray)
{
	return (isatty(STDIN_FILENO) && infArray->readfileDesc <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @chr: the char to check
 * @del: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char chr, char *del)
{
	for (; *del; del++)
	{
		if (*del++ == chr)
			return (1);
	}
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@chr: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int chr)
{
	if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@str: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *str)
{
	int i, sign = 1, fl = 0, out;
	unsigned int rslt = 0;

	for (i = 0;  str[i] != '\0' && fl != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			fl = 1;
			rslt *= 10;
			rslt += (str[i] - '0');
		}
		else if (fl == 1)
			fl = 2;
	}

	if (sign == -1)
		out = -rslt;
	else
		out = rslt;

	return (out);
}
