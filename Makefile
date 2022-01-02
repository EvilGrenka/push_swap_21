# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 15:04:45 by rnoriko           #+#    #+#              #
#    Updated: 2021/12/24 15:04:46 by rnoriko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker
LIBFT		=	libft/libft.a
GNL			=	get_next_line/gnl.a
HEADER		=	push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = clang

SRCS		=	add_functions.c main.c operations_stack1.c \
				operations_stack2.c operations_stack3.c push_swap.c \
				utils1.c utils2.c utils3.c

BONUS_SRCS	=	add_functions.c bonus.c operations_stack1.c \
				operations_stack2.c operations_stack3.c push_swap.c \
				utils1.c utils2.c utils3.c

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS_SRCS))

all : $(NAME) 

$(NAME):$(OBJS)
	@$(MAKE) all -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus : $(BONUS)

$(BONUS):$(BONUS_OBJS)
	@$(MAKE) all -C libft
	@$(MAKE) all -C get_next_line
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(GNL) -o $(BONUS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./get_next_line

fclean : clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./get_next_line

re : fclean all

.PHONY : all clean bonus fclean re