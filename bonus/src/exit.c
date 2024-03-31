/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-albane.merian
** File description:
** exit
*/

#include "../include/minishell.h"

void free_func_for_exit_value(shell_t *shell)
{
    print("exit\n");
    free(shell->l);
    shell->l = NULL;
    for (int i = 0; shell->path[i] != NULL; i++) {
        free(shell->path[i]);
        shell->path[i] = NULL;
    }
    free(shell->path);
    free(shell->current);
    exit(my_getnbr(shell->str[1]));
}

void free_func_for_exit(shell_t *shell)
{
    print("exit\n");
    free(shell->l);
    shell->l = NULL;
    for (int i = 0; shell->str[i] != NULL; i++) {
        free(shell->str[i]);
        shell->str[i] = NULL;
    }
    free(shell->str);
    shell->str = NULL;
    for (int i = 0; shell->path[i] != NULL; i++) {
        free(shell->path[i]);
        shell->path[i] = NULL;
    }
    free(shell->path);
    free(shell->current);
    exit(0);
}

int exit_func(shell_t *shell, char **env)
{
    int count = 0;

    for (int i = 0; shell->str[i] != NULL; i++)
        count++;
    if (count != 1) {
        if (my_isnum(shell->str[1]) == 0) {
            print("exit: Expression Syntax.\n");
            shell->status = 1;
            return 1;
        } else
            free_func_for_exit_value(shell);
    } else {
        free_func_for_exit(shell);
    }
    return 0;
}

static int check_if_as_slash(shell_t *shell)
{
    for (int i = 0; shell->str[1][i] != '\0'; i++) {
        if (shell->str[1][i] == '/') {
            print("env: '%s': Permission denied.\n", shell->str[1]);
            shell->status = 126;
            return 0;
        }
    }
    return 1;
}

static int wrong_arg_env(shell_t *shell, struct stat *path_stat, int i)
{
    if ((S_ISDIR(path_stat->st_mode) == 1)) {
        if (check_if_as_slash(shell) == 0)
            return 1;
        print("env: '%s': No such file or directory.\n", shell->str[i]);
        shell->status = 127;
        return 1;
    } else {
        print("env: '%s': No such file or directory.\n", shell->str[i]);
        shell->status = 127;
        return 1;
    }
    return 0;
}

static void env_multiple_args(shell_t *shell, struct list *head)
{
    struct stat path_stat;

    for (int i = 0; shell->str[i] != NULL; i++) {
        stat(shell->str[i], &path_stat);
        if (strcmp_my(shell->str[i], "env") == 1)
            continue;
        if (wrong_arg_env(shell, &path_stat, i) == 1)
            return;
    }
    while (head != NULL) {
        print("%s\n", head->str);
        head = head->next;
    }
    shell->status = 0;
    return;
}

int cmd_env(shell_t *shell, char **env)
{
    int count = 0;
    struct list *head = shell->current;

    for (int i = 0; shell->str[i] != NULL; i++)
        count++;
    if (count == 1) {
        while (head != NULL) {
            print("%s\n", head->str);
            head = head->next;
        }
        shell->status = 0;
        return 0;
    } else {
        env_multiple_args(shell, head);
    }
    return 0;
}
