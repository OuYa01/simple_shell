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

/* eput.c */
int _eputchar(char c);
void _eputs(char *str);
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

/*getline*/
int _getline(info_t *info, char **ptr, size_t *length);
ssize_t read_buffer(info_t *info, char *buf, size_t *i);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
void sigintHandler(__attribute__((unused))int sig_num);
/*getline*/


/*getenv*/
char **get_env(info_t *infArray);
int _unsetenv(info_t *infArray, char *envv);
int _setenv(info_t *infArray, char *envv, char *val);
/*getenv*/


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

/*string.c*/
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *starts_with(const char *haystack, const char *needle);
/*string.c*/

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
