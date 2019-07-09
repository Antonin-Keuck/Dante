/*
** EPITECH PROJECT, 2019
** dante_generator
** File description:
** maze_utilities
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dante_gen.h"

static char **init_maze(size_t x, size_t y, char **maze)
{
    size_t z = 0;
    size_t w = 0;
    size_t i = 0;

    while (z < y) {
        while (w < x) {
            if (z % 2 == 0 && i % 2 == 0)
                maze[z][w] = '*';
            else
                maze[z][w] = 'X';
            ++w;
            ++i;
        }
        i++;
        w = 0;
        ++z;
    }
    return (maze);
}

char **alloc_maze(size_t x, size_t y)
{
    size_t count = 0;
    char **maze = malloc(sizeof(char *) * (y + 1));

    maze[y] = NULL;
    if (maze == NULL)
        return (NULL);
    while (count < y) {
        maze[count] = malloc(sizeof(char) * (x + 1));
        maze[count][x] = '\0';
        if (maze[count] == NULL)
            return (NULL);
        maze[count] = memset(maze[count], '\0', x + 1);
        ++count;
    }
    maze = init_maze(x, y, maze);
    return (maze);
}

void free_maze(maze_t *maze)
{
    int z = 0;

    while (z < maze->y) {
            free(maze->map[z]);
        ++z;
    }
    free(maze->map);
    free(maze);
}