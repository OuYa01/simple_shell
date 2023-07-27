#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define DEL " \t\r\n\a"
#define BUFFER_SIZE 1024


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* put.c */
int _putchar(char c);
void _puts(char *str);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);
/*put.c*/

/*env.c*/
int pop_envList(info_t *info);
/*env.c*/

/*string.h*/
int _strcmp(char *s1, char *s2);

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
