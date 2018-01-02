/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:52:22 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:18:07 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			push_path(t_path **head, char *room)
{
	t_path *current;

	current = *head;
	if (*head == NULL)
	{
		(*head) = (t_path *)malloc(sizeof(t_path));
		(*head)->room = room;
		(*head)->next = NULL;
		return ;
	}
	while (current->next != NULL)
		current = current->next;
	current->next = (t_path *)malloc(sizeof(t_path));
	current->next->room = room;
	current->next->next = NULL;
}

void				create_path(t_room *room, t_path **path)
{
	if (room == NULL)
		return ;
	create_path(room->parent, path);
	push_path(path, room->name);
}

static int			move_ant(t_path *path, t_farm *farm, int ant, int b)
{
	int		print;

	print = b - ant;
	if ((b >= ant - 1) && (path != NULL))
	{
		while (path != NULL && print)
		{
			if (print == 1)
			{
				ft_putchar('L');
				ft_putnbr(ant + 1);
				ft_putchar('-');
				ft_putstr(path->room);
				ft_putchar(' ');
				if (((ant + 1) == farm->ants) &&
						(ft_strcmp(path->room, farm->end) == 0))
					return (1);
			}
			path = path->next;
			print--;
		}
	}
	return (0);
}

void				print_path(t_farm *farm)
{
	int		f;
	int		i;
	int		done;
	t_path	*path;

	path = farm->path->next;
	f = 1;
	done = 0;
	ft_putchar('\n');
	while (!done)
	{
		i = -1;
		while (++i < farm->ants)
			done = move_ant(path, farm, i, f);
		ft_putchar('\n');
		f++;
	}
}
