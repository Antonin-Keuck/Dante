/*
** EPITECH PROJECT, 2019
** dante's generator
** File description:
** dante's gen header
*/

#include <stddef.h>
#include <stdbool.h>

#ifndef _DANTE_GEN_H_
#define _DANTE_GEN_H_

typedef struct cell_s
{
    int up;
    int down;
    int right;
    int left;
} cell_t;

void connect_cell(cell_t *parent, cell_t *child);

#endif /* _DANTE_GEN_H_ */

#ifndef _L_LIST_H_
#define _L_LIST_H_

typedef struct l_list_s
{
    size_t x;
    size_t y;
    struct l_list_s *next;
    struct l_list_s *prev;
} l_list_t;

#endif /* _L_LIST_H_ */

#ifndef _MAZE_H_
#define _MAZE_H_

typedef struct direction_s
{
    size_t up;
    size_t down;
    size_t right;
    size_t left;
} direction_t;

typedef struct orientation_s
{
    bool north;
    bool est;
    bool west;
    bool south;
} orientation_t;

typedef struct maze_s
{
    l_list_t *stack;
    int x;
    int y;
    unsigned short int direction;
    direction_t dir;
    orientation_t or;
    char **map;
} maze_t;

bool possible_neighbors_unperfect(maze_t *maze, int x, int y);
int put_in_stack(l_list_t **head, size_t x, size_t y);
bool possible_neighbors(maze_t *maze, int x, int y);
l_list_t *delete_stack_frame(l_list_t *stack);
char **alloc_maze(size_t x, size_t y);
int unperfect_generator(maze_t *maze);
int perfect_generator(maze_t *maze);
int error_gestion(char *av[]);
void free_maze(maze_t *maze);
void disp_maze(char **map);
int dante_gen(char *av[]);

#endif /* _MAZE_H_ */