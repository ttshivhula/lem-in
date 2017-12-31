/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:26:51 by ttshivhu          #+#    #+#             */
/*   Updated: 2017/12/31 17:05:08 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			bfs(t_farm *farm)
{
	farm->current = get_room(farm->rooms, farm->start);
    farm->current->visited = 1;
    enqueue(&farm->queue, farm->current);
	while (farm->queue != NULL)
	{
		farm->current = dequeue(&farm->queue);
        if (ft_strcmp(farm->current->name, farm->end) == 0)
        {
            create_path(farm->current, &(farm->path));
            break ;
        }
        while (farm->current->neigbours)
        {
            farm->child = (t_room *)farm->current->neigbours->room;
            if (!farm->child->visited)
            {
                farm->child->parent = farm->current;
                farm->child->visited = 1;
                enqueue(&farm->queue, farm->child);
            }
            farm->current->neigbours = farm->current->neigbours->next;
        }
    }
}
