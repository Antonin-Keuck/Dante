##
## EPITECH PROJECT, 2019
## dante_star
## File description:
## Makefile
##

GEN_NAME = generator

all:
	make -C generator/
	make -C solver/

clean:
	make clean -C generator/
	make clean -C solver/

fclean: clean
	make fclean -C generator/
	make fclean -C solver/

re: fclean all

.PHONY: clean fclean re all generator solver
