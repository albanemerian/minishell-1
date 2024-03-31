/*
** EPITECH PROJECT, 2024
** mini-shell-1
** File description:
** minishell
*/

#include "struct.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#include <ncurses.h>

#ifndef MINISHELL_H_
    #define MINISHELL_H_

int set_env(shell_t *shell, char **env);
int cmd_env(shell_t *shell, char **env);
void error_handling(shell_t *shell, char **env, char **argv, int argc);
void get_path(int argc, char **argv, char **env, shell_t *shell);
int cd_handler(shell_t *shell, char **env);
void option(shell_t *shell);
void option_handler(shell_t *shell, char **env, char **fun);
int exit_func(shell_t *shell, char **env);
int unset_env(shell_t *shell, char **env);
char **my_array(const char *str);
int last_exec(shell_t *shell, char **env);
int env_alone(shell_t *shell, char **env);
void env_pwd(shell_t *shell);
void env_oldpwd(shell_t *shell, char *cwd);
char **list_to_array(shell_t *shell, char **env);
void free_tab(shell_t *shell, char **fun);
int check_str(shell_t *shell);
int alias_func(shell_t *shell, char **env);
int arrow(shell_t *shell);

#endif /* !MINISHELL_H_ */
