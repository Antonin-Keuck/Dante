/*
** EPITECH PROJECT, 2019
** display maze
** File description:
** display_maze
*/

#include <stddef.h>
#include <stdio.h>

void disp_maze(char **map)
{
    size_t y = 0;
    while (map[y] != NULL) {
        printf("%s", map[y++]);
        if (map[y] != NULL)
            printf("\n");
    }
}