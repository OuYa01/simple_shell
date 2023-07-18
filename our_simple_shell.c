#include "main.h"
/**
 * main - Entry point
 * @argc : argument count
 * @argv : argument array
 * Return: 0 if scc
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		exe_cmd(char *cmd, char *args[]);
	}
	else
	{
		read_executing_cmds(void);
	}
	return (0);
}
