##
## EPITECH PROJECT, 2019
## dante_generator
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	../../solver/lib/my_str_to_word_array.c	\
		../../solver/maze_list_ut.c	\
		../../solver/solver_init.c	\
		../../solver/init_maze.c	\
		../../solver/free_ut.c	\
		../../solver/main.c	\
		display.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	../../solver_bonus

CFLAGS	=	-Wall -Wextra

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
