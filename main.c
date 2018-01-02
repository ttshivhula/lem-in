/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:21:51 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:24:21 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_farm		*init_farm(void)
{
	t_farm *new;

	new = (t_farm *)malloc(sizeof(t_farm));
	new->error = 0;
	new->ants = 0;
	new->start = NULL;
	new->path = NULL;
	new->end = NULL;
	new->rooms = NULL;
	new->queue = NULL;
	return (new);
}

void				hashtag(t_farm *farm, char *temp)
{
	char *tmp;

	tmp = NULL;
	if (ft_strncmp(temp, "##start", 7) == 0)
	{
		if (farm->start)
			farm->error = 1;
		get_next_line(0, &tmp);
		check_room(farm, tmp, 0);
	}
	else if (ft_strncmp(temp, "##end", 5) == 0)
	{
		if (farm->end)
			farm->error = 1;
		get_next_line(0, &tmp);
		check_room(farm, tmp, 1);
	}
	(tmp) ? ft_putendl(tmp) : 0;
	(tmp) ? free(tmp) : 0;
}

int					contains_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void			free_all(t_farm *farm)
{
	(farm->rooms) ? free_rooms(farm->rooms) : 0;
	(farm->path) ? free_path(farm->path) : 0;
	(farm->queue) ? free_queue(farm->queue) : 0;
	(farm->start) ? free(farm->start) : 0;
	(farm->end) ? free(farm->end) : 0;
	free(farm);
}

int					main(void)
{
	t_farm		*farm;

	farm = init_farm();
	get_data(farm);
	if (!farm->error && farm->start && farm->end &&
			(ft_strcmp(farm->start, farm->end) != 0))
		bfs(farm);
	if (farm->path && !farm->error)
		print_path(farm);
	else
		ft_putendl("ERROR");
	free_all(farm);
	return (0);
}
