/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 14:03:28 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:34:40 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	void	ants(t_farm *farm, char *temp)
{
	farm->ants = ft_atoi(temp);
	if (farm->ants <= 0)
		farm->error = 1;
	while (*temp && *temp != '#')
	{
		if (!ft_isdigit(*temp))
		{
			farm->error = 1;
			break ;
		}
		temp++;
	}
}

static	void	check_coord(t_farm *farm, char *x, char *y)
{
	while (*x)
	{
		if (!ft_isdigit(*x))
			farm->error = 1;
		x++;
	}
	while (*y)
	{
		if (!ft_isdigit(*y))
			farm->error = 1;
		y++;
	}
}

void			check_room(t_farm *farm, char *temp, int end)
{
	char **ptr;
	char *test;

	test = ignore_comments(temp);
	ptr = ft_strsplit(test, ' ');
	(test) ? free(test) : 0;
	if (ptr[0] && ptr[1] && ptr[2] && !ptr[3])
	{
		if (ptr[0][0] == 'L')
			farm->error = 1;
		check_coord(farm, ptr[1], ptr[2]);
		add_room(&farm, ft_strdup(ptr[0]), ft_atoi(ptr[1]), ft_atoi(ptr[2]));
		if (!end)
			farm->start = ft_strdup(ptr[0]);
		else if (end == 1)
			farm->end = ft_strdup(ptr[0]);
	}
	else
		farm->error = 1;
	free_ptr(ptr);
}

static	void	join_rooms(t_farm *farm, char *temp)
{
	char		**ptr;
	t_room		*r1;
	t_room		*r2;
	char		*test;

	test = ignore_comments(temp);
	ptr = ft_strsplit(test, '-');
	(test) ? free(test) : 0;
	if (ptr[0] && ptr[1] && !ptr[2])
	{
		if (ptr[0][0] == 'L')
			farm->error = 1;
		r1 = get_room(farm->rooms, ptr[0]);
		r2 = get_room(farm->rooms, ptr[1]);
		if (!r1 || !r2)
			farm->error = 1;
		add_neighbour(r1, r2);
	}
	else
		farm->error = 1;
	free_ptr(ptr);
}

void			get_data(t_farm *farm)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (get_next_line(0, &temp))
	{
		ft_putendl(temp);
		if (farm->start == 0 && i == 0)
			ants(farm, temp);
		else if (temp[0] == '#' && !farm->error)
			hashtag(farm, temp);
		else if (!farm->error && contains_char(temp, ' '))
			check_room(farm, temp, 2);
		else if (!farm->error && contains_char(temp, '-'))
			join_rooms(farm, temp);
		else if (ft_strlen(temp) < 2)
			farm->error = 1;
		free(temp);
		i++;
	}
}
