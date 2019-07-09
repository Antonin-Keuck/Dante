/*
** EPITECH PROJECT, 2019
** dante_generator
** File description:
** stack_utilities
*/

#include <stdlib.h>
#include "dante_gen.h"

l_list_t *delete_stack_frame(l_list_t *stack)
{
    l_list_t *tmp_next = stack->next;
    l_list_t *tmp = stack;

    if (tmp_next == NULL) {
        free(tmp);
        return (NULL);
    }
    tmp_next->prev = NULL;
    free(tmp);
    stack = tmp_next;
    return (stack);
}

int put_in_stack(l_list_t **head, size_t x, size_t y)
{
    l_list_t *element = malloc(sizeof(l_list_t));

    if (element == NULL)
        return (84);
    element->x = x;
    element->y = y;
    element->prev = NULL;
    if (*head == NULL) {
        element->next = NULL;
        *head = element;
        return (0);
    }
    element->next = *head;
    (*head)->prev = element;
    *head = element;
    return (0);
}