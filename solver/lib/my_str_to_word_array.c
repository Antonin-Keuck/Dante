/*
** EPITECH PROJECT, 2019
** put a char * on char **
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "solver_list.h"
#include <stdio.h>

int nbr_sep(char *str, char sep)
{
    int space = 0;
    int n = 0;

    while (str[n] != '\0') {
        if (str[n] == sep)
            space += 1;
        n += 1;
    }
    return (space + 1);
}

void update_size(solver_t *solver, int x, int y)
{
    solver->x_max = x;
    solver->y_max = y;
}

char *malloc_line(int *size_char, int *size_normal)
{
    char *dest;

    if (*size_normal == 0)
        *size_normal = *size_char;
    if (*size_char != *size_normal)
        return (NULL);
    dest = malloc(sizeof(char) * (*size_char + 1));
    dest[*size_char] = '\0';
    *size_char = 0;
    return (dest);
}

char **malloc_dest(char *str, char sep, solver_t *solver)
{
    int n = 0;
    int count = 0;
    int size_normal = 0;
    int count_char = 0;
    int space = nbr_sep(str, sep);
    char **dest = NULL;

    dest = malloc(sizeof(char *) * (space + 1));
    dest[space] = NULL;
    while (n < space) {
        if (str[count] == sep || str[count] == '\0') {
            dest[n++] = malloc_line(&count_char, &size_normal);
            count += 1;
            count_char = 0;
        }
        count += 1;
        count_char += 1;
    }
    update_size(solver, size_normal, n);
    return (dest);
}

char **my_str_to_word_array(char *str, char sep, solver_t *solver)
{
    int n = 0;
    int x = 0;
    int y = 0;
    char **dest = malloc_dest(str, sep, solver);

    while (str[n] != '\0') {
        if ((dest[y] == NULL) || (y > 0 && dest[y - 1] == NULL) || \
        (str[n] != '*' && str[n] != 'X' && str[n] != sep && str[n] != 127)) {
            return (NULL);
        }
        if (str[n] == sep) {
            dest[y++][x] = '\0';
            x = 0;
        } else
            dest[y][x++] = str[n];
    n += 1;
    }
    dest[++y] = NULL;
    return (dest);
}