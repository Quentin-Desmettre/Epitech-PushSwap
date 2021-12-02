/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** int_utilities.c
*/

#include "ops.h"

char *my_strdup(char const *str)
{
    char *new = malloc(sizeof(char) * 4);

    new[0] = str[0];
    new[1] = str[1];
    new[2] = str[2];
    new[3] = 0;
    return new;
}

int *cdl_to_int_array(c_d_linked_list_t *list, int size)
{
    int *tab = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        tab[i] = list->data;
        list = list->next;
    }
    return tab;
}

int binary_search(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;

    if (r >= l) {
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binary_search(arr, l, mid - 1, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

void simplify(c_d_linked_list_t *l_a, int size)
{
    int *copy = cdl_to_int_array(l_a, size);

    tim_sort(copy, size);
    for (int i = 0; i < size; i++) {
        l_a->data = binary_search(copy, 0,  size - 1, l_a->data);
        l_a = l_a->next;
    }
}

int my_log2(int nb)
{
    int l = 0;

    while (nb > 1) {
        l++;
        nb /= 2;
    }
    return l;
}
