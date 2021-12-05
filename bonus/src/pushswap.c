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

static void clean_stack_b(c_d_linked_list_t **l_b, c_d_linked_list_t **l_a,
char *print, int *index)
{
    char *tmp;

    while (*l_b) {
        tmp = pa_list(l_a, l_b);
        my_strcpy(print + *index, tmp);
        (*index) += 3;
    }
}

static void split_stacks(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b,
int size_a, mask_print_index *mpi)
{
    char *tmp;

    for (int i = 0, n = size_a; i < n; i++) {
        if (!((*l_a)->data & *mpi->mask))
            tmp = pb_list(l_a, l_b);
        else
            tmp = ra_list(l_a);
        my_strcpy(mpi->print + *mpi->index, tmp);
        (*mpi->index) += 3;
        free(tmp);
    }
}

static void global_sort(c_d_linked_list_t *l_a, c_d_linked_list_t *l_b,
mask_print_index *mpi, vector_3_int ints)
{
    int size_a = ints.l;
    int nb_rec = ints.m;

    simplify(l_a, size_a);
    mpi->print[0] = 0;
    if (!is_sort(l_a, size_a))
        for (int k = 0; k < nb_rec; k++) {
            split_stacks(&l_a, &l_b, size_a, mpi);
            clean_stack_b(&l_b, &l_a, mpi->print, mpi->index);
            *(mpi->mask) <<= 1;
        }
}

char *pushswap(int ac, char **av)
{
    int size_a = 0;
    c_d_linked_list_t *l_a = get_numbers(ac, av, &size_a);
    c_d_linked_list_t *l_b = 0;
    int nb_rec = my_log2(size_a) + 1;
    char *print = malloc(sizeof(char) * (size_a * nb_rec * 6 + 1));
    int index = 0;
    int mask = 1;
    mask_print_index mpi = {&mask, print, &index};

    if (!l_a || ac == 1) {
        write(2, "Error: invalid arguments\n", 25);
        return 0;
    }
    global_sort(l_a, l_b, &mpi, (vector_3_int){size_a, nb_rec, 0});
    print[index - 1] = '\n';
    return print;
}
