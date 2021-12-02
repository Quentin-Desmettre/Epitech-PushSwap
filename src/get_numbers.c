/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** get_numbers.c
*/

#include "ops.h"

static int contain(char const *str, char const c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

static int contain_only(char const *str, char const *check)
{
    for (int i = 0; str[i]; i++)
        if (!contain(check, str[i]))
            return 0;
    return 1;
}

static int is_number(char const *str)
{
    if (!contain("0123456789-", str[0]))
        return 0;
    return contain_only(str + 1, "0123456789");
}

c_d_linked_list_t *get_numbers(int ac, char **av, int *size)
{
    c_d_linked_list_t *list = 0;
    int *tmp = 0;

    *size = 0;
    for (int i = 1; i < ac; i++) {
        if (!is_number(av[i]))
            return 0;
        if (my_getnbr(av[i], &tmp))
            return 0;
        append_node_c(&list, *tmp);
        *size += 1;
    }
    return list;
}
