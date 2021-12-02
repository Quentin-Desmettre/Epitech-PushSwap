/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** get_numbers.c
*/

#include "ops.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

c_d_linked_list_t *str_to_ll_list(char const *str, int *size)
{
    char tmp[12];
    c_d_linked_list_t *list = 0;
    int j = 0;
    int *truc = 0;

    memset(tmp, 0, 12);
    for (int i = 0;; i++) {
        if (str[i] == ' ' || str[i] == '\0' || str[i] == '\n') {
            if (strlen(tmp) == 0 || tmp[0] == '\n')
                break;
            my_getnbr(tmp, &truc);
            append_node_c(&list, *truc);
            memset(tmp, 0, 12);
            (*size)++;
            j = 0;
            if (!str[i] || str[i] == '\n')
                break;
            else
                continue;
        }
        tmp[j] = str[i];
        j++;
    }
    return list;
}

c_d_linked_list_t *get_numbers(int ac, char **av, int *size)
{
    int fd = open(av[1], O_RDONLY);
    c_d_linked_list_t *list;
    char *tmp;
    struct stat st;

    if (stat(av[1], &st))
        exit(84);
    tmp = malloc(sizeof(char) * st.st_size + 1);
    tmp[st.st_size] = 0;
    if (read(fd, tmp, st.st_size) <= 0) {
        printf("ERROR\n");
        perror(NULL);
        exit(0);
    }
    list = str_to_ll_list(tmp, size);
    free(tmp);
    return list;
}
