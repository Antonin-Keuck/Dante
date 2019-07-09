##
## EPITECH PROJECT, 2019
## dante_star
## File description:
## Makefile
##

GEN_NAME = generator_bonus

all:
	make -C generator_bonus/
	make -C solver_bonus/

clean:
	make clean -C generator_bonus/
	make clean -C solver_bonus/

fclean: clean
	make fclean -C generator_bonus/
	make fclean -C solver_bonus/


re: fclean all

.PHONY: clean fclean re all generator_bonus solver_bonus
