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

typedef struct {
    c_d_linked_list_t *list;
    c_d_linked_list_t *colors;
    int size;
    float max;
} array_t;

#endif
