/*
** EPITECH PROJECT, 2021
** B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
** File description:
** merge_sort.c
*/

#include "ops.h"

static void insertion_sort(int *arr, int left, int right)
{
    int temp;
    int j;

    for (int i = left + 1; i <= right; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

static void pre_process(int *left, int *right, int *arr, vector_3_int v)
{
    int len1 = v.m - v.l + 1;
    int len2 = v.r - v.m;

    for (int i = 0; i < len1; i++)
        left[i] = arr[v.l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[v.m + 1 + i];
}

static void split(int *left, int *right, vector_3_int lens, vector_4_ptr ptrs)
{
    while (*(ptrs.i) < lens.l && *(ptrs.j) < lens.m) {
        if (left[*(ptrs.i)] <= right[*(ptrs.j)]) {
            ptrs.arr[*ptrs.k] = left[*(ptrs.i)];
            (*(ptrs.i))++;
        } else {
            ptrs.arr[*ptrs.k] = right[*(ptrs.j)];
            (*(ptrs.j))++;
        }
        (*(ptrs.k))++;
    }
}

static int merge(int *arr, int const l, int const m, int const r)
{
    int left[m - l + 1];
    int right[r - m];
    int i = 0;
    int j = 0;
    int k = l;

    pre_process(left, right, arr, (vector_3_int){l, m, r});
    split(left, right, (vector_3_int){m - l + 1, r - m, 0},
    (vector_4_ptr){&i, &j, &k, arr});
    while (i < m - l + 1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < r - m) {
        arr[k] = right[j];
        k++;
        j++;
    }
    return 0;
}

void tim_sort(int *arr, int n)
{
    int mid;
    int right;

    for (int i = 0; i < n; i += RUN)
        insertion_sort(arr, i, min((i + RUN - 1), (n - 1)));
    for (int size = RUN; size < n; size = 2 * size)
        for (int left = 0; left < n; left += 2 * size) {
            mid = left + size - 1;
            right = min((left + 2 * size - 1), (n - 1));
            mid = (mid < right) ? merge(arr, left, mid, right) : 0;
        }
}
