#include "shell.h"
/**
 * main - entry point
 *
 * Return: 0  if succ
 *
 */
int main(void)
{
	char *input;
	char **args;
	int stat;

	do

	{
		if (isatty(STDIN_FILENO))
			write(1, "ous&zoh$ ", 9); /*prompt*/
		input = read_line();
		if (input == NULL)
		{
			exit(EXIT_FAILURE);
		}
		args = break_line(input);
		if (args == NULL)
		{
			perror("Error");
			free(input);
			exit(EXIT_FAILURE);
		}
		stat = exe_cmd(args);
		memory(input, args);
	} while (stat != -1); /*Continue until -1 : run until user type exit*/

	return (0);
}
