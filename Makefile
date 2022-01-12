# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:03:43 by ybestrio          #+#    #+#              #
#    Updated: 2022/01/10 10:51:10 by ybestrio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME1 = So_long

SRCS1 = thirderror.c seconderror.c error.c conditions.c check.c\
		keyhandler.c main.c retry.c get_next_line_utils.c get_next_line.c\
		so_long.c render.c datafiller.c\

OBJS1 = $(SRCS1:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME1): $(OBJS1)
	$(CC) $(OBJS1) -lmlx -framework OpenGL -framework AppKit -o $(NAME1)

all:	$(NAME1)

clean:
		$(RM) $(OBJS1)

fclean:	clean
		$(RM) $(NAME1)

re:		fclean all

.PHONY: all clean fclean re
