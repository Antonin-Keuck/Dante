/*
** EPITECH PROJECT, 2019
** dante_solver
** File description:
** solver_initiation
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "solver_list.h"
#include "dante_solver.h"

static void free_bool_map(bool **map)
{
    size_t index = 0;

    while (map[index] != NULL) {
        free(map[index]);
        index += 1;
    }
    free(map);
}

static int second_solver_loop(solver_t *solver, int x, int y, maze_list_t *list)
{
    maze_list_t *tmp = list;

    while (x != solver->x_max - 1 || y != solver->y_max - 1) {
        list = gestion_adding(solver, x, y, list);
        if (tmp->next == NULL)
            return (1);
        tmp = tmp->next;
        x = tmp->x;
        y = tmp->y;
    }
    print_way(solver->map, tmp);
    return (0);
}

static int solver_loop(solver_t *solver, char **map)
{
    maze_list_t *list = NULL;

    solver->map = map;
    list = add_in_maze_list(list, list, 0, 0);
    if (second_solver_loop(solver, 0, 0, list) != 0)
        printf("no solution found\n");
    else
        disp_maze(solver->map);
    free_maze_list(&list);
    free_bool_map(solver->map_check);
    return (0);
}

solver_t *init_solver(solver_t *solver)
{
    int y = 0;
    solver->map_check = malloc(sizeof(bool *) * (solver->y_max + 1));
    solver->map_check[solver->y_max] = NULL;

    while (y != solver->y_max) {
        solver->map_check[y] = malloc(sizeof(bool) * (solver->x_max + 1));
        if (solver->map_check[y] == NULL)
            return (NULL);
        solver->map_check[y] = memset(solver->map_check[y], 0, solver->x_max);
        y += 1;
    }
    return (solver);
}

int solver(char **av)
{
    solver_t *solver = malloc(sizeof(solver_t));
    char **map = charge_map(av[1], solver);

    if (map == NULL || solver == NULL)
        return (84);
    solver = init_solver(solver);
    if (solver_loop(solver, map) != 0)
        return (84);
    free_all(solver, map);
    return (0);
}