##
## EPITECH PROJECT, 2019
## dante_generator
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	main.c	\
		maze_ut.c	\
		stack_ut.c	\
		errors_gestion.c	\
		neighbors_check.c	\
		generation_init.c	\
		perfect_unperfect.c	\
		display_maze.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS	=	-Wall -Wextra -g

CPPFLAGS	=	-I../include

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re generator
