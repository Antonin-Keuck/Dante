/*
** EPITECH PROJECT, 2019
** dante_generator
** File description:
** perfect
*/

#include <stdlib.h>
#include "dante_gen.h"

static void rand_direction(maze_t *maze)
{
    maze->direction = rand() % 4;

    if (maze->direction == 0 && maze->or.est != true)
        rand_direction(maze);
    if (maze->direction == 1 && maze->or.west != true)
        rand_direction(maze);
    if (maze->direction == 2 && maze->or.north != true)
        rand_direction(maze);
    if (maze->direction == 3 && maze->or.south != true)
        rand_direction(maze);
}

static void moove_wall(maze_t *maze, size_t *x, size_t *y)
{
    if (maze->direction == 0) {
        maze->map[*y][*x + 1] = '*';
        *x += 2;
    }
    if (maze->direction == 1) {
        maze->map[*y][*x - 1] = '*';
        *x -= 2;
    }
    if (maze->direction == 2) {
        maze->map[*y - 1][*x] = '*';
        *y -= 2;
    }
    if (maze->direction == 3) {
        maze->map[*y + 1][*x] = '*';
        *y += 2;
    }
}

static int end_is_adj(maze_t *maze, size_t x, size_t y) {
    if (x + 2 == (size_t)maze->x && y + 2 == (size_t)maze->y) {
        maze->map[y][x + 1] = '*';
        maze->map[y + 1][x + 1] = '*';
        return (0);
    } else if (x + 2 == (size_t)maze->x && (size_t)maze->y == y + 1) {
        maze->map[y][x + 1] = '*';
        return (0);
    }
    if (y + 2 == (size_t)maze->y && x + 1 == (size_t)maze->x) {
        maze->map[y + 1][x] = '*';
        return (0);
    }
    if (y + 1 == (size_t)maze->y && x + 1 == (size_t)maze->x) {
        return (0);
    }
    return (84);
}

int unperfect_generator(maze_t *maze)
{
    size_t x = 0;
    size_t y = 0;

    while (end_is_adj(maze, x, y) != 0) {
        if (possible_neighbors_unperfect(maze, (int)x, (int)y) == true) {
            rand_direction(maze);
            moove_wall(maze, &x, &y);
        }
    }
    free(maze->stack);
    return (0);
}

int perfect_generator(maze_t *maze)
{
    size_t x = 0;
    size_t y = 0;

    if (put_in_stack(&maze->stack, x, y) != 0)
        return (84);

    while (maze->stack != NULL) {
        if (possible_neighbors(maze, (int)x, (int)y) == true) {
            rand_direction(maze);
            moove_wall(maze, &x, &y);
            put_in_stack(&maze->stack, x, y);
            end_is_adj(maze, x, y);
        } else {
            maze->stack = delete_stack_frame(maze->stack);
            if (maze->stack != NULL) {
                x = maze->stack->x;
                y = maze->stack->y;
            }
        }
    }
    free(maze->stack);
    return (0);
}