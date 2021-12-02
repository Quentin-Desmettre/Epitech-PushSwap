##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
## File description:
## Makefile
##

SRC = \
	get_numbers.c \
	int_utilities.c \
	my_getnbr.c \
	pushswap.c \
	tim_sort.c

OBJ = $(SRC:.c=.o)

all:
	make -s -C ops/
	gcc -Wall -Wextra -c -g $(SRC) -I ../include/
	mv *.o ../
