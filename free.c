/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 15:23:39 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:21:31 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		free_ptr(char **ptr)
{
	int i;

	i = -1;
	if (!ptr)
		return ;
	while (ptr[++i] != NULL)
		free(ptr[i]);
	free(ptr);
}

void		free_neigbours(t_neigbours *ptr)
{
	t_neigbours *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

void		free_rooms(t_room *ptr)
{
	t_room *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free_neigbours(tmp->neigbours);
		free(tmp->name);
		free(tmp);
	}
}

void		free_path(t_path *ptr)
{
	t_path *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

void		free_queue(t_queue *ptr)
{
	t_queue *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
