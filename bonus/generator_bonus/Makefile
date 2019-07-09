##
## EPITECH PROJECT, 2019
## dante_generator
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	../../generator/main.c	\
		../../generator/maze_ut.c	\
		../../generator/stack_ut.c	\
		../../generator/errors_gestion.c	\
		../../generator/neighbors_check.c	\
		../../generator/generation_init.c	\
		../../generator/perfect_unperfect.c \
		display_maze.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	../../generator_bonus

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-I../../include

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re generator
