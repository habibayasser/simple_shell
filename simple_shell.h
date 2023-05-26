#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define TOK_DELIM " \t\r\n\v\a"

/**
 * struct list_s - single linked list
 * @dir: string - malloc string
 * @next: pointer to the next node in linked list
 *
 */

typedef struct list_struct
{
	char *dir;
	struct list_struct *next;
} list_s;

/*Functions of the shell*/
void execute_line(char **argv, char **commands, int counter,
		  char **env, int *exit_st, char *line);
char **split_line(char *line);
list_s *list_path(char **env);
int _setenv(const char *name, const char *value, int overwrite);
char *_which(char **commands, char **env);
void built_in_exit(char *line, char **arg, int *exit_st, int counter);
void built_in_env(char **arg, char **env, int *exit_st);
char *_getenv(const char *name, char **env);
void _error(char **argv, char *first, int count, int **exit_st);
int special_case(char *line, ssize_t line_len, int *exit_st);
void print_num(int counter);

/*useful functions*/
int _strlen(char *s);
void add_node_end(list_s **head, const char *str);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void free_loop(char **arr);
void free_list(list_s *head);
char *_strncpy(char *dest, char *src, int n);
#endif /* SHELL_H*/
