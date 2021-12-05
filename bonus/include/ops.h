/*
** EPITECH PROJECT, 2021
** push_swap
** File description:
** short file description
*/

#ifndef INCLUDE_OPS_H
    #define INCLUDE_OPS_H
    #define RUN 32
    #define min(a, b) (((a) < (b)) ? (a) : (b))
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

typedef struct {
    int *i;
    int *j;
    int *k;
    int *arr;
} vector_4_ptr;

typedef struct {
    int *mask;
    char *print;
    int *index;
} mask_print_index;

typedef struct {
    int l;
    int m;
    int r;
} vector_3_int;

typedef struct c_d_linked_list_t {
    int data;
    struct c_d_linked_list_t *next;
    struct c_d_linked_list_t *prev;
} c_d_linked_list_t;

c_d_linked_list_t *get_numbers(int ac, char **av, int *size);
char *my_strdup(char const *str);
void simplify(c_d_linked_list_t *l_a, int size);
int my_log2(int nb);
int my_getnbr(char const *str, int **n);
int main(int ac, char **av);
void tim_sort(int *arr, int n);
char *pa_list(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b);
char *pb_list(c_d_linked_list_t **l_a, c_d_linked_list_t **l_b);
char *ra_list(c_d_linked_list_t **l_a);
void append_node_c(c_d_linked_list_t **begin, int data);
char *pushswap(int ac, char **av);
int is_sort(c_d_linked_list_t *tab, int size);
void my_strcpy(char *src, char *ap);

#endif
