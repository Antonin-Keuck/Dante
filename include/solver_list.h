/*
** EPITECH PROJECT, 2019
** solver list
** File description:
** solver_list
*/

#include <stdbool.h>

#ifndef SOLVER_LIST_H_
#define SOLVER_LIST_H_

typedef struct s_maze_list {
    struct s_maze_list *next;
    struct s_maze_list *prev;
    int x;
    int y;
} maze_list_t;

typedef struct s_solver {
    maze_list_t *maze;
    bool **map_check;
    char **map;
    int x_max;
    int y_max;
} solver_t;

char **my_str_to_word_array(char *str, char sep, solver_t *solver);

#endif /* !SOLVER_LIST_H_ */
