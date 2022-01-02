# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 12:55:06 by rnoriko           #+#    #+#              #
#    Updated: 2021/12/24 13:15:12 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			=	get_next_line.h

SRCS			=	get_next_line.c
OBJS			= $(SRCS:.c=.o)

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -c

NAME			= gnl.a

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(SRCS)
				ar rc $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
