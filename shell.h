#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>



#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/*list*/

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;
/*list*/


/*cmd macros*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/*cmd macros*/

/*getline macros*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/*getline macros*/


/* convert_number() macros*/
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/*conver_number() macros*/


/*read write macros*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
/*read write macros*/


/*shellloop*/
int hsh(info_t *infArray, char **argv);
int find_builtin(info_t *infArray);
void find_cmd(info_t *infArray);
void fork_cmd(info_t *infArray);
/*shellloop*/

/*m*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_setMem(char *s, char b, unsigned int n);
void ffree(char **pp);
int bfree(void **ptr);
/*m*/

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

/*getinfo*/
void clear_info(info_t *infArray);
void set_info(info_t *infArray, char **argv);
void free_info(info_t *infArray, int all);
/*getinfo*/


/*getenv*/
char **get_env(info_t *infArray);
int _unsetenv(info_t *infArray, char *envv);
int _setenv(info_t *infArray, char *envv, char *val);
/*getenv*/

/*history.c*/
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
/*history.c*/

/*variables*/
int replace_vars(info_t *info);
int replace_string(char **old, char *new);
int replace_alias(info_t *info);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int is_chain(info_t *info, char *buf, size_t *p);
/*variables*/


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
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
/*string.c*/


/*tokenz*/
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
/*tokenz*/
#endif
