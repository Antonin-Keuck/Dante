/*
** EPITECH PROJECT, 2019
** dante_generator
** File description:
** errors_gestion;c
*/

#include <stdio.h>
#include <stdlib.h>

static int is_number(char *str)
{
    size_t count = 0;

    if (str[0] == '-')
        count = 1;
    while (str[count] != '\0') {
        if (str[count] < '0' || str[count] > '9')
            return (84);
        ++count;
    }
    return (0);
}

int error_gestion(char *av[])
{
    size_t x = 0;
    size_t y = 0;

    if (is_number(av[1]) != 0 || is_number(av[2]) != 0) {
        fprintf(stderr, "one or both of the argument is not a number\n");
        return (84);
    }
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 3 || y < 3) {
        fprintf(stderr, "x or y must be superior to 2\n");
        return (84);
    }
    return (0);
}