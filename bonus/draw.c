/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** draw.c
*/

#include "array.h"

int sf_color_to_int(sfColor color)
{
    int value;
    unsigned char red = color.r;
    unsigned char green = color.g;
    unsigned char blue = color.b;

    value = red << 16;
    value += green << 8;
    value += blue;
    return value;
}

sfColor int_to_sf_color(int color)
{
    sfColor c;

    c.a = 255;
    c.r = (color & 0b00000000111111110000000000000000) >> 16;
    c.g = (color & 0b00000000000000001111111100000000) >> 8;
    c.b = color & 0b00000000000000000000000011111111;
    return c;
}

void draw_list(sfRenderWindow *window, array_t *array, int const type, sfRectangleShape *shape)
{
    c_d_linked_list_t *start = array->list;
    c_d_linked_list_t *start_color = array->colors;
    float const height = 580.0 / array->size;
    int i = 0;
    int x = 25 + 375 * type;

    if (!array || !array->colors)
        return;
    do {
        sfRectangleShape_setFillColor(shape, int_to_sf_color(array->colors->data));
        sfRectangleShape_setSize(shape,
        (sfVector2f){350.0 / (array->max / array->list->data), height});
        sfRectangleShape_setPosition(shape, (sfVector2f){x, i * height + 10});
        sfRenderWindow_drawRectangleShape(window, shape, NULL);
        array->list = array->list->next;
        array->colors = array->colors->next;
        i++;
    } while (array->list != start);
    array->list = start;
    array->colors = start_color;
}
