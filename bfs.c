/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:26:51 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:10:45 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** While the queue isn’t empty … grabs the first room off the queue, mark as
** searched, Check whether the room is a final room, if yes we constract the
** path and break out of the loop... if not then  we add all the non searched
** neigbours to the queue and repeat the loop... if the queue is empty before
** we reach the final room then there is no possible solution.
*/

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
