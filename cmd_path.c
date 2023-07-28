#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @infArray: the info struct
 * @pth: path to the file
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *infArray, char *pth)
{
	struct stat stats;

	(void)infArray;
	if (!pth || stat(pth, &stats))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pthStr: the PATH string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *pthStr, int start, int stop)
{
	static char buff[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pthStr[i] != ':')
			buff[k++] = pthStr[i];
	buff[k] = 0;
	return (buff);
}

/**
 * find_path - finds this cmd in the PATH string
 * @infArray: the info struct
 * @pthStr: the PATH string
 * @cmd: the cmd to find
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *infArray, char *pthStr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *pth;

	if (!pthStr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(infArray, cmd))
			return (cmd);
	}
	for (int i = 0; ; )
	{
		if (!pthStr[i] || pthStr[i] == ':')
		{
			pth = dup_chars(pthStr, curr_pos, i);
			if (!*pth)
				_strcat(pth, cmd);
			else
			{
				_strcat(pth, "/");
				_strcat(pth, cmd);
			}
			if (is_cmd(infArray, pth))
				return (pth);
			if (!pthStr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
