/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** ops.c
*/

#include "ops.h"

static void insert_at_beg(c_d_linked_list_t **l_a, c_d_linked_list_t *save)
{
    if (!(*l_a)) {
        *l_a = save;
        l_a[0]->next = save;
        l_a[0]->prev = save;
        return;
    }
    l_a[0]->prev->next = save;
    save->next = l_a[0];
    save->prev = l_a[0]->prev;
    l_a[0]->prev = save;
    l_a[0] = save;
}

static void pop(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b)
{
    c_d_linked_list_t *save = *l_b;

    if (!(l_b[0]))
        return;
    if (l_b[0]->next == l_b[0])
        *l_b = 0;
    else {
        l_b[0]->prev->next = l_b[0]->next;
        l_b[0]->next->prev = l_b[0]->prev;
        *l_b = l_b[0]->next;
    }
    insert_at_beg(l_a, save);
}

char *pa_list(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b)
{
    if (*l_b == 0)
        return my_strdup("");
    pop(l_a, l_b);
    return my_strdup("pa ");
}

char *pb_list(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b)
{
    if (*l_a == 0)
        return my_strdup("");
    pop(l_b, l_a);
    return my_strdup("pb ");
}

char *ra_list(c_d_linked_list_t **l_a)
{
    if (!(*l_a))
        return 0;
    *l_a = l_a[0]->next;
    return my_strdup("ra ");
}
