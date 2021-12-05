##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
## File description:
## Makefile
##
SRC = draw.c \
	main.c \
	instruction.c

OBJ = $(SRC:.c=.o)

all:
	make -s -C src/
	gcc -c -g -Wall -Wextra $(SRC) -I ./include/ -lcsfml-graphics
	gcc -o push_swap *.o -lcsfml-graphics -lcsfml-system

clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm -f push_swap

re:
	$(MAKE) fclean
	$(MAKE) all
