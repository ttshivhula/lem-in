#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: ttshivhu <marvin@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/12/31 16:09:21 by ttshivhu          #+#    #+#             *#
#*   Updated: 2017/12/31 16:09:22 by ttshivhu         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = lem-in

SRC = main.c data.c get_next_line.c queue.c bfs.c move_ants.c rooms.c free.c \

FLAG = -g3 -Wall -Werror -Wextra

SILENT = --no-print-directory

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
	@make -C libft $(SILENT)
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(OBJ)  libft/libft.a -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME) 👍\x1b[0m\n"

clean:
	@make clean -C libft $(SILENT)
	@/bin/rm -f $(OBJ) $(LOBJ) *.o
	@printf "\x1b[31mRemoved object files\x1b[0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft $(SILENT)
	@printf "\x1b[31mRemoved $(NAME)\x1b[0m\n"

re: fclean all