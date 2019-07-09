/*
** EPITECH PROJECT, 2019
** maze_solver
** File description:
** maze_initialization
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "solver_list.h"

static int file_size(char *filepath)
{
    struct stat info_file;
    if (stat(filepath, &info_file) == -1) {
        perror("");
        return (-84);
    }
    return (info_file.st_size);
}

char **charge_map(char *filepath, solver_t *solver)
{
    int fd = open(filepath, O_RDONLY);
    int  size = file_size(filepath);
    char **map = NULL;
    char *buffer = NULL;

    if (size == -84 || fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    if (read(fd, buffer, size) == -1)
        return (NULL);
    map = my_str_to_word_array(buffer, '\n', solver);
    if (map == NULL)
        return (NULL);
    free(buffer);
    return (map);
}