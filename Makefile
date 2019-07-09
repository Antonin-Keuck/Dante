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
	make -C bonus/

clean:
	make clean -C generator/
	make clean -C solver/
	make clean -C bonus/


fclean: clean
	make fclean -C generator/
	make fclean -C solver/
	make fclean -C bonus/

re: fclean all

.PHONY: clean fclean re all generator solver bonus
