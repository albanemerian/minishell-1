/*
** EPITECH PROJECT, 2024
** mini-shell-1
** File description:
** struct
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct shell_s {
    char **env;
    char **path;
    char *l;
    char *home;
    char *oldpwd;
    char **str;
    size_t len;
    ssize_t read;
    int ret;
    int status;
    int env_len;
    int result;
    char **fun;
    char *arg;
    char *temp;
    struct list *current;
} shell_t;

struct list {
    char *str;
    struct list *next;
};

int helper(int argc);
#endif /* !STRUCT_H_ */
