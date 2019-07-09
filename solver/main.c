/*
** EPITECH PROJECT, 2019
** main function
** File description:
** main
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "solver_list.h"
#include "dante_solver.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Wrong number of arguements\nFor more information please try again with -h\n");
    } else if (strcmp("-h", av[1]) == 0) {
        printf("Usage: ./solver [maze_filepath]\n Solve and find the shortest way of a maze\n");
        return (0);
    } else if (solver(av) == 0)
        return (0);
    return (84);
}
