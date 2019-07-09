/*
** EPITECH PROJECT, 2019
** maze_solver
** File description:
** free_utilities
*/

#include <stdlib.h>
#include "dante_solver.h"

void free_maze_list(maze_list_t **maze_list)
{
    maze_list_t *act = *maze_list;
    maze_list_t *next = NULL;

    while (act != NULL) {
        next = act->next;
        free(act);
        act = next;
    }
    *maze_list = NULL;
}

static void free_map(char **map)
{
    size_t z = 0;

    while (map[z] != NULL) {
        free(map[z++]);
    }
}

void free_all(solver_t *solver, char **map)
{
    free_map(solver->map);
    free(map);
    free(solver);
}