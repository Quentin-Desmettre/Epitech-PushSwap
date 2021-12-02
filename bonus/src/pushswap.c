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
