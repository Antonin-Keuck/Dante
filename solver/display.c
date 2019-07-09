/*
** EPITECH PROJECT, 2019
** display information
** File description:
** display
*/

#include <stddef.h>
#include <stdio.h>
#include "solver_list.h"

void disp_maze(char **map)
{
    size_t y = 0;

    while (map[y] != NULL) {
        printf("%s", map[y++]);
        if (map[y] != NULL)
            printf("\n");
    }
}

void print_way(char **map, maze_list_t *tmp)
{
    while (tmp != NULL) {
        map[tmp->y][tmp->x] = 'o';
        tmp = tmp->prev;
    }
}
