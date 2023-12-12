#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stddef.h>

/* Global environment variables */
extern char **environ;
extern int lexit_stat;

/* Function prototypes */

/* Utility functions for output and string manipulation */
void printing(char *msg);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_getenv(const char *name);
char *_memcpy(char *dest, char *src, unsigned int n);
int _atoi(char *s);
int _strlen(const char *s);
char *_strchr(const char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);

/* Function to search for command paths */
char *search_command(char *command);

/* Command parsing and execution functions */
char *read_and_trim_input();
char **parse_command(char *input, int *num_tokens);
void execute_command(char **argv, int *lexit_stat, char ***our_env);
int handle_builtin_commands(char **argv, int *lexit_stat, char ***our_env);
void exter_cmd(char **argv, char *cmd_path, int *lexit_stat, char **our_env);

/* Environment handling functions */
void handle_env(char **our_env);
void init_our_env(char ***our_env);
void cleanup_our_env(char ***our_env);
char **duplicate_environment(char **env);

/* Built-in shell command functions */
int handle_exit_command(char **argv, int *lexit_stat, char ***our_env);
int handle_env_command(char **argv, int *lexit_stat, char ***our_env);
int handle_setenv_command(char **argv, int *lexit_stat, char ***our_env);
int handle_unsetenv(char **argv, int *lexit_stat, char ***our_env);
void handle_cd(char **argv, char ***our_env);

/* Custom utility function */
int _isnumber(char *s);

/* Cleanup functions */
void cleanup(char **argv, char *cmd_path);

/* Environment variable manipulation functions */
int _setenv(const char *name, const char *value, char ***our_env);
int _unsetenv(const char *name, char ***our_env);

#endif /* MAIN_H */
