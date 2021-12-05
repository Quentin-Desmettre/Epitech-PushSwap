/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** array.h
*/

#ifndef ARRAY_H
    #define ARRAY_H
    #include "ops.h"
    #include <SFML/Graphics.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/System.h>
    #include <string.h>

typedef struct {
    c_d_linked_list_t *list;
    c_d_linked_list_t *colors;
    int size;
    float max;
} array_t;


void draw_list(sfRenderWindow *window, array_t *array, int const type, sfRectangleShape *shape);
int *cdl_to_int_array(c_d_linked_list_t *list, int size);
sfColor int_to_sf_color(int color);
int binary_search(int arr[], int l, int r, int x);
int sf_color_to_int(sfColor color);
float get_max(c_d_linked_list_t *l);
void do_instruction(c_d_linked_list_t **instructions,
c_d_linked_list_t *save, array_t *l_a, array_t *l_b);
void get_instructions(c_d_linked_list_t **list, int ac, char **av);

#endif
