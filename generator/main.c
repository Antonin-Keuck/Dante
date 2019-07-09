/*
** EPITECH PROJECT, 2019
** date's generator
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "dante_gen.h"

int main(int ac, char *av[])
{
    if (ac != 3) {
        if (ac == 2 && strcmp("-h", av[1]) == 0) {
            printf("Usage: ./generator [width] [height]\n Generate a maze map\n");
            return (0);
        }
        fprintf(stderr, "Wrong number of arguements\nFor more information please try again with -h\n");
        return (84);
    } else {
        printf("marche pas ... '%s\n'", av[1]);
    }
    if (error_gestion(av) != 0 || dante_gen(av) != 0) {
        return (84);
    }
    return (0);
}
