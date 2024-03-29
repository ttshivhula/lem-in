/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:50:47 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:50:03 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		enqueue(t_queue **q, t_room *room)
{
	t_queue *current;

	current = *q;
	if (*q == NULL)
	{
		*q = (t_queue *)malloc(sizeof(t_queue));
		(*q)->room = room;
		(*q)->next = NULL;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = (t_queue *)malloc(sizeof(t_queue));
		current->next->room = room;
		current->next->next = NULL;
	}
}

t_room		*dequeue(t_queue **q)
{
	t_room		*room;
	t_queue		*que;

	if (*q == NULL)
		return (NULL);
	que = *q;
	*q = que->next;
	room = que->room;
	free(que);
	return (room);
}

char		*ignore_comments(char *ptr)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (ptr) ? (char *)malloc(sizeof(char) * (ft_strlen(ptr) + 1)) : NULL;
	if (ptr)
	{
		while (ptr[i] && (ptr[i] != '#'))
		{
			ret[i] = ptr[i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
