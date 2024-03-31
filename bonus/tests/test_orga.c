/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-organized-albane.merian
** File description:
** test_organize
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../libshell/shell.h"


static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (add_functin, error_result)
{
    linked_list_t *list = NULL;
    char *args[] = {"DATA1", "data2", "data3", "value", NULL};
    int result = add(&list, args);

    cr_assert_eq(result, 84, "function doesn't work correctly");
}

Test(error_gestion, not_enough_args)
{
    char *args[] = {NULL};
    int result = error_gestion(args);

    cr_assert_eq(result, 84, "error not enough argument");
}

Test(incorect_ard, eroor_arg)
{
    char *arg = "GYKTR";
    int result = add_list(arg);

    cr_assert_eq(result, 84, "wrong type");
}

Test(list_add, normal_case)
{
    linked_list_t* list = NULL;
    char* args[] = {"TYPE1", "NAME1", "TYPE2", "NAME2", NULL};
    linked_list_t* new_node = malloc(sizeof(linked_list_t));
    int result = list_add(0, new_node, args, &list);

    cr_assert_eq(result, 0, "list_add should return 0 for normal case");
}

Test(add, normal_case)
{
    linked_list_t* list = NULL;
    char* args[] = {"WIRE", "WIRE", "SENSOR", "DEVICE", NULL};
    int result = add(&list, args);

    cr_assert_eq(result, 0, "add should return 0 for normal case");
}

Test(add, incorect_ard)
{
    linked_list_t *list = NULL;
    char *args[] = {"SENSOR", "DEVICE", "TENcsDOR", NULL};
    int result = add(&list, args);

    cr_assert_eq(result, 84,"add should retunr 84 incorect inptut");
}

Test(disp, normal_case)
{
    linked_list_t* list = NULL;
    char* args[] = {"arg1", "arg2", NULL};
    int result = disp(&list, args);

    cr_assert_eq(result, 0, "disp should return 0 for normal case");
}

Test(check_list, lsit)
{
    linked_list_t *list = NULL;
    linked_list_t *current;
    int result = error_type(&list, current);

    cr_assert_eq(result, 84, "list is empty");
}

Test(curren_empt, list)
{
    linked_list_t *list = NULL;
    linked_list_t *current = NULL;
    int result = error_type(&list, current);

    cr_assert_eq(result, 84, "current node is empty");
}

