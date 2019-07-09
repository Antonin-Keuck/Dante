/*
** EPITECH PROJECT, 2019
** dante_generation
** File description:
** generation_initiation
*/

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dante_gen.h"

static int maze_gestion(maze_t *maze, char *av[])
{
    if (av[3] != NULL && strcmp(av[3], "perfect") == 0) {
        if (perfect_generator(maze) != 0)
            return (84);
    } else if (av[3] == NULL) {
        if (unperfect_generator(maze) != 0)
            return (84);
    } else
        return (84);
    return (0);
}

int dante_gen(char *av[])
{
    maze_t *maze = malloc(sizeof(maze_t));

    srand(time(NULL));
    if (maze == NULL)
        return (84);
    maze->x = atoi(av[1]);
    maze->y = atoi(av[2]);
    maze->stack = NULL;
    maze->map = alloc_maze(maze->x, maze->y);
    if (maze->map == NULL)
        return (84);
    if (maze_gestion(maze, av) != 0)
        return (84);
    disp_maze(maze->map);
    free_maze(maze);
    return (0);
}