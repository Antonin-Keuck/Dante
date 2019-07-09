##
## EPITECH PROJECT, 2019
## dante_generator
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	lib/my_str_to_word_array.c	\
		maze_list_ut.c	\
		solver_init.c	\
		init_maze.c	\
		display.c	\
		free_ut.c	\
		main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS	=	-Wall -Wextra

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
