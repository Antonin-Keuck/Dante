/*
** EPITECH PROJECT, 2019
** maze generaator
** File description:
** generator
*/

#include <stdbool.h>

#ifndef GENERATOR_H_
#define GENERATOR_H_

typedef struct s_generator_maze {
    char **map;
    int size_x;
    int size_y;
    bool ouest;
    bool south;
    bool north;
    bool est;
    bool moove;
} maze_gen_t;

#endif /* !GENERATOR_H_ */
