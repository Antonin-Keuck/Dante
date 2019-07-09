/*
** EPITECH PROJECT, 2019
** date's generator
** File description:
** main
*/

#include <stdio.h>
#include "dante_gen.h"

int main(int ac, char *av[])
{
    if (ac < 3 || ac > 4) {
        fprintf(stderr, "Wrong number of arguements\n");
        return (84);
    }
    if (error_gestion(av) != 0 || dante_gen(av) != 0) {
        return (84);
    }
    return (0);
}
