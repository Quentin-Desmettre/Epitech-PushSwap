/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** main.c
*/

#include "array.h"

sfColor hsv(int hue, float sat, float val)
{
    if(sat<0.f) sat = 0.f;
    if(sat>1.f) sat = 1.f;

    if(val<0.f) val = 0.f;
    if(val>1.f) val = 1.f;

    int h = hue/60;
    float f = (float)(hue)/60-h;
    float p = val*(1.f-sat);
    float q = val*(1.f-sat*f);
    float t = val*(1.f-sat*(1-f));

    switch(h)
    {
        default:
        case 0:
        case 6: return (sfColor){val*255, t*255, p*255, 255};
        case 1: return (sfColor){q*255, val*255, p*255, 255};
        case 2: return (sfColor){p*255, val*255, t*255, 255};
        case 3: return (sfColor){p*255, q*255, val*255, 255};
        case 4: return (sfColor){t*255, p*255, val*255, 255};
        case 5: return (sfColor){val*255, p*255, q*255, 255};
    }
}

int pos_to_color(int pos, int size)
{
    sfColor t = hsv(360 / ((float)size / (pos + 1)), 1.2, 1.3);
    return sf_color_to_int(t);
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
    if (list) {
        max = get_max(list);
        for (int i = 0; i < size; i++) {
            append_node_c(&ar->colors,
            pos_to_color(binary_search(tmp, 0,  size - 1, list->data), size));
            list = list->next;
        }
    }
    ar->max = max;
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

int main(int ac, char **av)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "Push_swap", sfClose, NULL);
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
    int max;

    if (!list || !size)
        return 84;
    init_array(&array_a, list, size);
    init_array(&array_b, list_b, size);
    get_instructions(&instructions, ac, av);
    save = 0;
    if (!instructions)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_requestFocus(window);
    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    max = array_a.max;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 1000.0 / size) {
            do_instruction(&instructions, save, &array_a, &array_b);
            if (!save)
                save = instructions->prev;
            sfClock_restart(clock);
        }
        array_a.max = max;
        array_b.max = max;
        sfRenderWindow_clear(window, sfBlack);
        draw_list(window, &array_a, 0, shape);
        draw_list(window, &array_b, 1, shape);
        sfRenderWindow_display(window);
    }
}
