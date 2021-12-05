/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** instruction.c
*/

#include "array.h"

void graphic_ra(array_t *l_a)
{
    ra_list(&l_a->list);
    ra_list(&l_a->colors);
}

void graphic_pa(array_t *l_a, array_t *l_b)
{
    int tmp;

    if (!l_b->list)
        return;
    tmp = l_b->list->data; 
    pa_list(&l_a->list, &l_b->list);
    if (tmp == (int)l_b->max)
        l_b->max = get_max(l_b->list);
    if (tmp > l_a->max)
        l_a->max = tmp;
    pa_list(&l_a->colors, &l_b->colors);
}

void graphic_pb(array_t *l_a, array_t *l_b)
{
    int tmp;

    if (!l_a->list)
        return;
    tmp = l_a->list->data; 
    pb_list(&l_a->list, &l_b->list);
    if (tmp == (int)l_a->max)
        l_a->max = get_max(l_a->list);
    if (tmp > l_b->max)
        l_b->max = tmp;
    pb_list(&l_a->colors, &l_b->colors);
}

void get_instructions(c_d_linked_list_t **list, int ac, char **av)
{
    char *ins = pushswap(ac, av);
    char tmp[3] = {0, 0, 0};
    int j = 0;

    if (!ins)
        exit(84);
    for (int i = 0; ins[i]; i++) {
        if (ins[i] == '\n' || ins[i] == ' ') {
            if (tmp[0] == 'r')
                append_node_c(list, 0);
            else if (tmp[1] == 'a')
                append_node_c(list, 1);
            else if (tmp[1] == 'b')
                append_node_c(list, 2);
            if (ins[i] == '\n')
                return;
            memset(tmp, 0, 3);
            j = 0;
            continue;
        }
        tmp[j] = ins[i];
        j++;
    }
    printf("\n");
}

void do_instruction(c_d_linked_list_t **instructions,
c_d_linked_list_t *save, array_t *l_a, array_t *l_b)
{
    void (*fnc[3])() = {&graphic_ra, &graphic_pa, &graphic_pb};

    if (*instructions == save)
        return;
    if (instructions[0]->data == 0)
        fnc[0](l_a);
    else
        fnc[instructions[0]->data](l_a, l_b);
    *instructions = instructions[0]->next;
}


