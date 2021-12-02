##
## EPITECH PROJECT, 2021
## B-CPE-110-LIL-1-1-bspushswap-quentin.desmettre
## File description:
## Makefile
##

all:
	make -s -C src/
	gcc -o push_swap *.o

clean:
	rm -f *.o

fclean:
	$(MAKE) clean
	rm -f push_swap

re:
	$(MAKE) fclean
	$(MAKE) all
