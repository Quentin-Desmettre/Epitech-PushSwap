/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** cast string to integer
*/

#include <stdlib.h>

static void sign_check(int *sign, char const *str, int *range)
{
    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            *sign *= -1;
        *range = i + 1;
    }
}

static int *dup_int(int what)
{
    int *new = malloc(sizeof(int));

    *new = what;
    return new;
}

static int *nbr_check(char const *str, int *range, int *sign)
{
    int my_number = 0;
    for (int i = *range; str[i] >= '0' && str[i] <= '9'; i++) {
        if (my_number > (2147483648 - (str[i] - 48)) / 10)
            return 0;
        if (*sign == 1 && my_number > (2147483647 - (str[i] - 48)) / 10)
            return 0;
        my_number = (my_number * 10) + (str[i] - 48);
    }
    my_number *= *sign;
    return dup_int(my_number);
}

int my_getnbr(char const *str, int **n)
{
    int sign = 1;
    int range = 0;
    sign_check(&sign, str, &range);
    *n = nbr_check(str, &range, &sign);
    return *n ? 0 : 84;
}
