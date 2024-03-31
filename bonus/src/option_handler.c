/*
** EPITECH PROJECT, 2024
** mini-shell-1
** File description:
** option_handler
*/

#include "../include/minishell.h"


int (*fm[7])(struct shell_s *, char **) = {
    &cmd_env, &exit_func, &cd_handler, &set_env, &unset_env, &alias_func};

void fill_str(shell_t *shell)
{
    char *fun = my_strdup(shell->l);
    char *token = strtok(fun, " \t\n");
    int i = 0;
    int j = 0;
    char *sleep = NULL;

    while (token != NULL) {
        i++;
        token = strtok(NULL, " \t\t");
    }
    shell->str = malloc((i + 1) * sizeof(char *));
    sleep = strtok(shell->l, " \t\n");
    while (sleep != NULL) {
        shell->str[j] = my_strdup(sleep);
        j++;
        sleep = strtok(NULL, " \t\n");
    }
    free(fun);
    shell->str[i] = NULL;
}

int is_empty(shell_t *shell)
{
    if (shell->l == NULL)
        return 1;
    for (int i = 0; shell->l[i] != '\0'; i++) {
        if (shell->l[i] != ' ' && shell->l[i] != '\t') {
            return 0;
        }
    }
    return 1;
}

void option(shell_t *shell)
{
    char *flag_m[6] = {"env", "exit", "cd", "setenv", "unsetenv", "alias"};

    shell->result = 0;
    if (is_empty(shell) == 1)
        return;
    fill_str(shell);
    for (int index = 0; index <= 5; index++) {
        if (strcmp_my(shell->str[0], flag_m[index]) == 1) {
            fm[index](shell, shell->env);
            return;
        }
    }
    last_exec(shell, shell->env);
}
