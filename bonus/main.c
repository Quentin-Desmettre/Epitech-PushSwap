/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** main.c
*/

#include "array.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/System.h>

void draw_list(sfRenderWindow *window, array_t *array, int const type, sfRectangleShape *shape);
int *cdl_to_int_array(c_d_linked_list_t *list, int size);
sfColor int_to_sf_color(int color);
int binary_search(int arr[], int l, int r, int x);

int pos_to_color(int pos, int size)
{
    return (16777215 / (size / (pos + 1)));
}

void init_array(array_t *ar, c_d_linked_list_t *list, int size)
{
    int *tmp = list ? cdl_to_int_array(list, size) : 0;
    int max = list ? list->data : 0;

    ar->list = list;
    ar->size = size;
    if (tmp)
        tim_sort(tmp, size);
    ar->colors = 0;
    if (list)
        for (int i = 0; i < size; i++) {
            if (list->data > max)
                max = list->data;
            append_node_c(&ar->colors,
            pos_to_color(binary_search(tmp, 0,  size - 1, list->data), size));
            list = list->next;
        }
    ar->max = max;
}

void get_instructions(c_d_linked_list_t **list)
{
    char tmp[3];
    int c = 0;

    while (c += read(0, tmp + c, 3 - c)) {
        if (c < 0)
            exit(84);
        if (c < 3)
            continue;
        c = 0;
        if (tmp[0] == 'r')
            append_node_c(list, 0);
        else if (tmp[1] == 'a')
            append_node_c(list, 1);
        else
            append_node_c(list, 2);
        if (tmp[2] == '\n')
            return;
    }
}

float get_max(c_d_linked_list_t *l)
{
    float max;
    c_d_linked_list_t *save = l;

    if (!l)
        return 0;
    max = l->data;
    do {
        if (l->data > max)
            max = l->data;
        l = l->next;
    } while (l != save);
    return max;
}

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

int main(int ac, char **av)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32},
    "Push_swap", sfClose | sfResize, NULL);
    int size = 0;
    c_d_linked_list_t *list = get_numbers(ac, av, &size);
    c_d_linked_list_t *list_b = 0;
    c_d_linked_list_t *instructions = 0;
    sfEvent event;
    array_t array_a;
    array_t array_b;
    sfRectangleShape *shape = sfRectangleShape_create();
    c_d_linked_list_t *save;
    sfClock *clock = sfClock_create();

    if (!list || !size || size > 580)
        return 84;
    init_array(&array_a, list, size);
    init_array(&array_b, list_b, size);
    get_instructions(&instructions);
    save = 0;
    if (!instructions)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 144);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 1000.0 / size) {
            do_instruction(&instructions, save, &array_a, &array_b);
            if (!save)
                save = instructions->prev;
            sfClock_restart(clock);
        }
        sfRenderWindow_clear(window, sfBlack);
        draw_list(window, &array_a, 0, shape);
        draw_list(window, &array_b, 1, shape);
        sfRenderWindow_display(window);
    }
}
