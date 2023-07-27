#include "shell.h"
/**
 * main - entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: 0  if succ
 *
 */
int main(int argc, char **argv)
{
	info_t infArray[] = { INFO_INIT };
	int fileDesc = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fileDesc)
		: "r" (fileDesc));

	if (argc == 2)
	{
		fileDesc = open(argv[1], O_RDONLY);
		if (fileDesc == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts(argv[0]);
				_puts(": 0: Can't open ");
				_puts(argv[1]);
				_putchar('\n');
				_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfileDesc = fileDesc;
	}
	pop_envList(infArray);
	read_hist(infArray);
	hsh(infArray, argv);
	return (EXIT_SUCCESS);
}
