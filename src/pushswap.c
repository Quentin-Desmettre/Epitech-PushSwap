/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** pushswap.c
*/

#include "ops.h"
#include <stdio.h>

void append_node_c(c_d_linked_list_t **begin, int data)
{
    c_d_linked_list_t *new = malloc(sizeof(c_d_linked_list_t));

    new->data = data;
    if (!(*begin)) {
        *begin = new;
        new->next = new;
        new->prev = new;
        return;
    }
    new->next = (*begin);
    new->prev = (*begin)->prev;
    (*begin)->prev->next = new;
    (*begin)->prev = new;
}

static int is_sort(c_d_linked_list_t *tab, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (tab->data > tab->next->data)
            return 0;
        tab = tab->next;
    }
    return 1;
}

static void clean_stack_b(c_d_linked_list_t **l_b, c_d_linked_list_t **l_a,
int k, int nb_rec)
{
    char *tmp;

    while (*l_b) {
        tmp = pa_list(l_a, l_b);
        if (!(k + 1 < nb_rec || *l_b))
            tmp[2] = '\n';
        write(1, tmp, 3);
    }
}

static void split_stacks(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b,
int size_a, int mask)
{
    char *tmp;

    for (int i = 0, n = size_a; i < n; i++) {
        if (!((*l_a)->data & mask))
            tmp = pb_list(l_a, l_b);
        else
            tmp = ra_list(l_a);
        if (i + 1 < n || *l_b)
            write(1, tmp, 3);
        else
            write(1, tmp, 2);
    }
}

int main(int ac, char **av)
{
    int size_a = 0;
    c_d_linked_list_t *l_a = get_numbers(ac, av, &size_a);
    c_d_linked_list_t *l_b = 0;
    int nb_rec = my_log2(size_a) + 1;
    int mask = 1;

    if (!l_a || ac == 1) {
        write(2, "Error: invalid arguments\n", 25);
        return 84;
    }
    simplify(l_a, size_a);
    if (!is_sort(l_a, size_a))
        for (int k = 0; k < nb_rec; k++) {
            split_stacks(&l_a, &l_b, size_a, mask);
            clean_stack_b(&l_b, &l_a, k, nb_rec);
            mask <<= 1;
        }
    return 0;
}
