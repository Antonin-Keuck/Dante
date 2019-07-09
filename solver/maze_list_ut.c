/*
** EPITECH PROJECT, 2019
** dante_solver
** File description:
** maze_list_utilities
*/

#include <stdlib.h>
#include "dante_gen.h"
#include "solver_list.h"

maze_list_t *add_in_maze_list(maze_list_t *list, \
maze_list_t *current, int x, int y)
{
    maze_list_t *tmp = list;
    maze_list_t *new = malloc(sizeof(maze_list_t));

    if (new == NULL)
        return (NULL);
    new->next = NULL;
    new->x = x;
    new->y = y;
    if (list == NULL) {
        new->prev = NULL;
        list = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        new->prev = current;
        tmp->next = new;
    }
    return (list);
}

maze_list_t *update_way(solver_t *solver, int x, int y, maze_list_t *current)
{
    maze_list_t *list = solver->maze;

    list = add_in_maze_list(list, current, x, y);
    solver->map_check[y][x] = 1;
    return (list);
}

maze_list_t *gestion_adding(solver_t *solver, \
int x, int y, maze_list_t *list)
{
    maze_list_t *current = list;
    solver->maze = list;
    char **map = solver->map;

    while (current != NULL && (current->x != x || current->y != y))
        current = current->next;
    if (x - 1 >= 0 && map[y][x - 1] == '*' && \
    solver->map_check[y][x - 1] == 0)
        solver->maze = update_way(solver, x - 1, y, current);
    if (y - 1 >= 0 && map[y - 1][x] == '*' && \
    solver->map_check[y - 1][x] == 0)
        solver->maze = update_way(solver, x, y - 1, current);
    if (x + 1 <= solver->x_max && map[y][x + 1] == '*' && \
    solver->map_check[y][x + 1] == 0)
        solver->maze = update_way(solver, x + 1, y, current);
    if (y + 2 <= solver->y_max && map[y + 1][x] == '*' && \
    solver->map_check[y + 1][x] == 0)
        solver->maze = update_way(solver, x, y + 1, current);
    return (solver->maze);
}