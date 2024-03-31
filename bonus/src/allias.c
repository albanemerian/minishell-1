/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-albane.merian
** File description:
** allias
*/

#include "minishell.h"

int alias_func(shell_t *shell, char **env)
{
    if (strcmp_my(shell->str[1], "-p") == 1)
        print("No recorde alias\n");
    return 0;
}
