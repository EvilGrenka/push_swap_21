# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:35:32 by rnoriko           #+#    #+#              #
#    Updated: 2021/10/20 02:12:46 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			=	libft.h

SRCS			=	ft_isdigit.c  ft_split.c ft_putendl_fd.c ft_atoi.c ft_strlen.c \
					ft_putnbr_fd.c ft_putchar_fd.c ft_strcmp.c

OBJS			=	$(patsubst %.c,%.o,$(SRCS))

CC				= clang
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -c

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(SRCS)
				ar rc $(NAME) $(OBJS)

%.o : %.c 		$(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
