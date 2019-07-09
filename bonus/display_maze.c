/*
** EPITECH PROJECT, 2019
** date's generator
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "dante_gen.h"

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
        if (map[y] != NULL && map[y][index] == '*')
            printf("\033[41;34m \033[0;0m");
        else if (map[y] != NULL)
            printf("\033[47;34m \033[0;0m");
        index++;
    }
}
