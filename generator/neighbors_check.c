/*
** EPITECH PROJECT, 2019
** dante_generator
** File description:
** neighbors_checking
*/

#include "dante_gen.h"

static bool check_adj_neighbors(maze_t *maze, int x, int y)
{
    if (x - 1 >= 0 && maze->map[y][x - 1] == '*')
        return (true);
    if (x + 1 < maze->x && maze->map[y][x + 1] == '*')
        return (true);
    if (y - 1 >= 0 && maze->map[y - 1][x] == '*')
        return (true);
    if (y + 1 < maze->y && maze->map[y + 1][x] == '*')
        return (true);
    return (false);
}

bool possible_neighbors(maze_t *maze, int x, int y)
{
    maze->or.est = false;
    maze->or.west = false;
    maze->or.north = false;
    maze->or.south = false;
    if (x - 2 >= 0 && maze->map[y][x - 2] == '*' && \
    check_adj_neighbors(maze, x - 2, y) == false)
        maze->or.west = true;
    if (x + 2 < maze->x && maze->map[y][x + 2] == '*' && \
    check_adj_neighbors(maze, x + 2, y) == false)
        maze->or.est = true;
    if (y - 2 >= 0 && maze->map[y - 2][x] == '*' && \
    check_adj_neighbors(maze, x, y - 2) == false)
        maze->or.north = true;
    if (y + 2 < maze->y && maze->map[y + 2][x] == '*' && \
    check_adj_neighbors(maze, x, y + 2) == false)
        maze->or.south = true;
    if (maze->or.est != true && maze->or.west != true && \
    maze->or.north != true && maze->or.south != true )
        return (false);
    return (true);
}

bool possible_neighbors_unperfect(maze_t *maze, int x, int y)
{
    maze->or.est = false;
    maze->or.west = false;
    maze->or.north = false;
    maze->or.south = false;
    if (x - 2 >= 0 && maze->map[y][x - 2] == '*')
        maze->or.west = true;
    if (x + 2 < maze->x && maze->map[y][x + 2] == '*')
        maze->or.est = true;
    if (y - 2 >= 0 && maze->map[y - 2][x] == '*')
        maze->or.north = true;
    if (y + 2 < maze->y && maze->map[y + 2][x] == '*')
        maze->or.south = true;
    if (maze->or.est != true && maze->or.west != true && \
    maze->or.north != true && maze->or.south != true )
        return (false);
    return (true);
}