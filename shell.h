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
int _myEnv(info_t *infArray);
char *_get_myEnv(info_t *infArray, const char *call);
int _set_myEnv(info_t *infArray);
int _unset_myEnv(info_t *infArray);
/*env.c*/

/*lists*/
/*I*/
list_t *add_node_start(list_t **hd, const char *strctr, int ni);
list_t *add_node(list_t **hd, const char *strctr, int ni);
size_t list_strPrint(const list_t *pn);
int delete_node(list_t **hd, unsigned int in);
void free_node_list(list_t **hd_ptr);


/*II*/
ssize_t get_node_index(list_t *head, list_t *node);
list_t *node_starts(list_t *node, char *prefix, char c);
size_t list_length(const list_t *h);
size_t print_list(const list_t *h);
char **list_to_strings(list_t *head);
/*lists*/

/*string.h*/
int _strcmp(char *s1, char *s2);

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
