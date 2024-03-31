/*
** EPITECH PROJECT, 2024
** B-PSU-200-NAN-2-1-minishell1-albane.merian
** File description:
** array_key
*/

#include "minishell.h"

int arrow(shell_t *shell)
{
    int ch = getch();

    print("before switch case %i\n", ch);
    if (ch == '\033') {
        print("in first if\n");
        getch();
        switch(getch()) {
            case 'A':
                print("arrow up\n");
                break;
            case 'B':
                print("arrow down\n");
                break;
            case 'C':
                print("arrow right\n");
                break;
            case 'D':
                print("arrow left\n");
                break;
        }
    }
    return 0;
}
