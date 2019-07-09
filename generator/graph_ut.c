/*
** EPITECH PROJECT, 2019
** date's generator
** File description:
** graph_utitilies
*/

#include "dante_gen.h"

void connect_cell(cell_t *parent, cell_t *child)
{
    link_t  *ptr_to_begin = parent->link;
    link_t  *new_link = malloc(sizeof(link_t));

    if (new_link == NULL)
        return (84);
    new_link->cell = child;
    new_link->next = NULL;
    if (parent->link == NULL) {
        parent->link = new_link;
    } else {
        while (parent->link->next != NULL) {
            parent->link = parent->link->next;
        }
        parent->link->next = new_link;
        parent->link = ptr_to_begin;
    }
    return (0);
}
