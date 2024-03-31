/*
** EPITECH PROJECT, 2024
** mini-shell-1
** File description:
** env
*/


#include "../include/minishell.h"


int check_str(shell_t *shell)
{
    char *str = my_strdup(shell->str[1]);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=') {
            print("setenv: Variable name must contain ");
            print("alphanumeric characters.\n");
            shell->status = 1;
            return 1;
        }
    }
    return 0;
}

void free_tab(shell_t *shell, char **fun)
{
    for (int i = 0; fun[i] != NULL; i++)
        free(fun[i]);
    free(fun);
}

static void envv_sett(shell_t *shell, struct list *head,
    struct list *new_node)
{
    char *env_temp = 0;

    env_temp = my_cat(shell->str[1], "=");
    new_node->str = env_temp;
    new_node->str = my_cat(new_node->str, shell->str[2]);
    new_node->next = NULL;
    if (shell->current == NULL) {
        shell->current = new_node;
    } else {
        head = shell->current;
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = new_node;
    }
}

static void fill_env(shell_t *shell, struct list *head,
    char **fun, struct list *new_node)
{
    char *temp_arg = NULL;
    char *temp_arg2 = NULL;

    while (head != NULL) {
        fun = my_str_to_word_array(head->str);
        if (strcmp_my(fun[0], shell->str[1]) == 1) {
            temp_arg = my_cat(fun[0], "=");
            temp_arg2 = my_strdup(shell->str[2]);
            temp_arg = my_cat(temp_arg, temp_arg2);
            head->str = temp_arg;
            free(temp_arg2);
            free_tab(shell, fun);
            return;
        }
        head = head->next;
    }
    envv_sett(shell, head, new_node);
}

static void env_set(shell_t *shell, char **env, char **fun)
{
    struct list *head = shell->current;
    struct list *new_node = malloc(sizeof(struct list));

    if (new_node == NULL)
        exit(84);
    fill_env(shell, head, fun, new_node);
    return;
}

static void arg_count(shell_t *shell)
{
    int counter = 0;

    for (int i = 0; shell->str[i] != NULL; i++)
        counter++;
    if (counter > 3) {
        print("setenv: Too many arguments.\n");
        shell->status = 1;
        return;
    }
}

void two_arg(shell_t *shell, char **env)
{
    char **fun = 0;

    if (check_str(shell) == 1)
        return;
    if (!(my_al(shell->str[1][0]))) {
        print("setenv: Variable name must begin with a letter.\n");
        shell->status = 1;
        return;
    }
    env_set(shell, env, fun);
    shell->status = 0;
    return;
}

int set_env(shell_t *shell, char **env)
{
    arg_count(shell);
    if (shell->str[0] != NULL && shell->str[1] == NULL) {
        cmd_env(shell, env);
        shell->status = 0;
        return 0;
    }
    if (shell->str[1] != NULL && shell->str[2] == NULL) {
        if (!(my_al(shell->str[1][0]))) {
            print("setenv: Variable name must begin with a letter.\n");
            shell->status = 1;
            return 1;
        }
        if (check_str(shell) == 1)
            return 1;
        env_alone(shell, env);
        shell->status = 0;
    } else {
        two_arg(shell, env);
    }
    return 0;
}

static void pwd_env(shell_t *shell, char **fun,
    char *temp_arg, struct list *head)
{
    char cwd[1024];

    if (str_my(fun[0], "PWD") == 1) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            temp_arg = my_cat(fun[0], "=");
            temp_arg = my_realoc(temp_arg, cwd);
            temp_arg = my_cat(temp_arg, cwd);
            head->str = temp_arg;
            shell->status = 0;
            return;
        }
    }
}

void env_pwd(shell_t *shell)
{
    char **fun = 0;
    char *temp_arg = 0;
    struct list *head = shell->current;
    struct list *new_node = malloc(sizeof(struct list));

    if (new_node == NULL)
        exit(84);
    while (head != NULL) {
        fun = my_array(head->str);
        pwd_env(shell, fun, temp_arg, head);
        head = head->next;
    }
    return;
}
