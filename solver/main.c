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
#include <unistd.h>
#include "solver_list.h"
#include "dante_solver.h"

int main(int ac, char **av)
{
    if (ac == 2 && solver(av) == 0)
        return (0);
    return (84);
}