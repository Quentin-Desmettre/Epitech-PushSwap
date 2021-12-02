##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
## File description:
## Makefile
##

SRC = draw.c \
	main.c

OBJ = $(SRC:.c=.o)

all:
	make -s -C ../src/
	gcc -c -g -Wall -Wextra $(SRC) -I ../include/ -lcsfml-graphics
	mv ../*.o ./
	gcc -o window *.o -lcsfml-graphics -lcsfml-system