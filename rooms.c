/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:55:28 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/31 16:52:44 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int          in_rooms(t_farm **farm, char *name, int x, int y)
{
    t_room *current;

    current = (*farm)->rooms;
    while (current != NULL)
    {
        if ((ft_strcmp(current->name, name) == 0) ||
            (current->x == x && current->y == y))
        {
            (*farm)->error = 1;
            return (1);
        }
        current = current->next;
    }
    return (0);
}

void				add_room(t_farm **head, char *name, int x, int y)
{
    t_room *new_node;

    if (in_rooms(head, name, x, y))
        return ;
    if ((*head)->rooms == NULL)
    {
        (*head)->rooms = (t_room *)malloc(sizeof(t_room));
        (*head)->rooms->name = name;
        (*head)->rooms->x = x;
        (*head)->rooms->y = y;
        (*head)->rooms->neigbours = NULL;
        (*head)->rooms->parent = NULL;
        (*head)->rooms->visited = 0;
        (*head)->rooms->next = NULL;
        return ;
    }
    new_node = (t_room *)malloc(sizeof(t_room));
    new_node->name = name;
    new_node->x = x;
    new_node->y = y;
    new_node->neigbours = NULL;
    new_node->visited = 0;
    new_node->parent = NULL;
    new_node->next = (*head)->rooms;
    (*head)->rooms = new_node;
}

static void			connect_rooms(t_room **r1, t_room **r2)
{
    t_neigbours *new_node;

    if ((*r1)->neigbours == NULL)
    {
        (*r1)->neigbours = (t_neigbours *)malloc(sizeof(t_neigbours));
        (*r1)->neigbours->room = *r2;
        (*r1)->neigbours->next = NULL;
    }
    else
    {
        new_node = (t_neigbours *)malloc(sizeof(t_neigbours));
        new_node->room = *r2;
        new_node->next = (*r1)->neigbours;
        (*r1)->neigbours = new_node;
    }
}

int					add_neighbour(t_room *r1, t_room *r2)
{
    if (r1 == NULL || r2 == NULL)
        return (-1);
    if (strcmp(r1->name, r2->name) == 0)
        return (-1);
    connect_rooms(&r1, &r2);
    connect_rooms(&r2, &r1);
    return (1);
}

t_room				*get_room(t_room *rooms, char *room)
{
    while (rooms != NULL)
    {
        if (strcmp(rooms->name, room) == 0)
            return rooms;
        rooms = rooms->next;
    }
    return (NULL);
}
