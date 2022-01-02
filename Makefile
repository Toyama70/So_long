# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 17:03:43 by ybestrio          #+#    #+#              #
#    Updated: 2022/01/01 12:08:40 by yasinbest        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME1 = So_long

SRCS1 =  Hello.c

OBJS1 = $(SRCS1:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME1): $(OBJS1)
	$(CC) $(OBJS1) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:	$(NAME1)

clean:
		$(RM) $(OBJS1)

fclean:	clean
		$(RM) $(NAME1)

re:		fclean all

.PHONY: all clean fclean re
