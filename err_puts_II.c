#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *str)
{
	int i = 0;
	unsigned long int rslt = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			rslt *= 10;
			rslt += (str[i] - '0');
			if (rslt > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (rslt);
}

/**
 * print_error - prints an error message
 * @infArray: the parameter & return info struct
 * @errstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *infArray, char *errstr)
{
	_eputs(infArray->fname);
	_eputs(": ");
	print_d(infArray->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(infArray->argv[0]);
	_eputs(": ");
	_eputs(errstr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @in: the input
 * @fileDesc: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int in, int fileDesc)
{
	int (*__putchar)(char) = _putchar;
	int i, cnt = 0;
	unsigned int _abs_, current;

	if (fileDesc == STDERR_FILENO)
		__putchar = _eputchar;
	if (in < 0)
	{
		_abs_ = -in;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = in;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			cnt++;
		}
		current %= i;
	}
	__putchar('0' + current);
	cnt++;

	return (cnt);
}

/**
 * convert_number - converter function, a clone of itoa
 * @n: number
 * @bs: base
 * @fl: argument flags
 *
 * Return: string
 */
char *convert_number(long int n, int bs, int fl)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long num = n;

	if (!(fl & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		sign = '-';

	}
	array = fl & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % bs];
		num /= bs;
	} while (num != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buff[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
