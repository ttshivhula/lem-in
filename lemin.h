/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:27:17 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/01/02 15:31:38 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# define BUFF_SIZE 10

typedef struct			s_neigbours
{
	void				*room;
	struct s_neigbours	*next;
}						t_neigbours;

typedef struct			s_room
{
	char				*name;
	t_neigbours			*neigbours;
	int					visited;
	struct s_room		*parent;
	struct s_room		*next;
	int					x;
	int					y;
}						t_room;

typedef struct			s_path
{
	char				*room;
	struct s_path		*next;
}						t_path;

typedef struct			s_queue
{
	t_room				*room;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_farm
{
	char				*start;
	t_path				*path;
	t_queue				*queue;
	t_room				*current;
	t_room				*child;
	char				*end;
	int					error;
	int					ants;
	t_room				*rooms;
}						t_farm;

int						get_next_line(const int fd, char **line);
t_room					*get_room(t_room *rooms, char *room);
void					enqueue(t_queue **q, t_room *room);
t_room					*dequeue(t_queue **q);
void					create_path(t_room *room, t_path **path);
void					add_room(t_farm **head, char *name, int x, int y);
int						add_neighbour(t_room *r1, t_room *r2);
void					print_path(t_farm *farm);
void					hashtag(t_farm *farm, char *temp);
int						contains_char(char *str, char c);
void					check_room(t_farm *farm, char *temp, int end);
void					get_data(t_farm *farm);
void					free_ptr(char **ptr);
void					free_rooms(t_room *ptr);
void					free_path(t_path *ptr);
void					free_queue(t_queue *ptr);
char					*ignore_comments(char *ptr);
void					bfs(t_farm *farm);

#endif
