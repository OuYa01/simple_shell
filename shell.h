#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define DEL " \t\r\n\a"


char *read_line();
char **break_line(char *line);
int exe_cmd(char **args);
void memory(char *line, char **args);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*string.h*/
int _strcmp(char *s1, char *s2);

#endif
