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
    size_t index = 0;
    size_t y = 0;
    while (map[y] != NULL) {
        if (map[y][index] == '\0') {
            y += 1;
            index = 0;
            if (map[y] != NULL)
                printf("|\n");
        }
        if (map[y] != NULL && map[y][index] == '*') {
            printf("\033[30;34m \033[0;0m");
        } else if (map[y] != NULL && map[y][index] == 'o') {
            printf("\033[43;32m \033[0;0m");
        } else if (map[y] != NULL)
            printf("\033[47;34m \033[0;0m");
        index++;
    }
}

// void disp_maze(char **map)
// {
//     size_t y = 0;

//     while (map[y] != NULL) {
//         printf("%s", map[y++]);
//         if (map[y] != NULL)
//             printf("\n");
//     }
// }

void print_way(char **map, maze_list_t *tmp)
{
    while (tmp != NULL) {
        map[tmp->y][tmp->x] = 'o';
        tmp = tmp->prev;
    }
}
