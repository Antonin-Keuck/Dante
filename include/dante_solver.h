/*
** EPITECH PROJECT, 2019
** dante_solver
** File description:
** solver_header
*/

#include "solver_list.h"

#ifndef _DANTE_SOLV_H_
#define _DANTE_SOLV_H_

int solver(char **av);
void disp_maze(char **map);
void free_all(solver_t *solver, char **map);
void print_way(char **map, maze_list_t *tmp);
void free_maze_list(maze_list_t **maze_list);
char **charge_map(char *filepath, solver_t *solver);
maze_list_t *gestion_adding(solver_t *solver, int x, int y, maze_list_t *list);
maze_list_t *add_in_maze_list(maze_list_t *list, maze_list_t *current\
, int x, int y);

#endif /* _DANTE_SOLV_H_ */
