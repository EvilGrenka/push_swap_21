/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:31:58 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:36:34 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i = 1;
	while (argv[i])
	{
		new = ft_create_node(ft_atoi(argv[i]));
		ft_add_node_back(stack, new);
		i++;
	}
	ft_index_stack(stack);
	if (argc == 2)
		ft_free(argv);
}

int	ft_stack_size(t_node *head)
{
	int	stack_size;

	stack_size = 0;
	while (head)
	{
		stack_size++;
		head = head -> next;
	}
	return (stack_size);
}

void	ft_error_msg(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

bool	ft_is_sorted_stack(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head -> next)
	{
		if (head->number > head -> next -> number)
			return (false);
		head = head -> next;
	}
	return (true);
}

int	ft_get_distance_node(t_node **stack, int index)
{
	t_node	*head;
	int		distance_node;

	distance_node = 0;
	head = *stack;
	while (head)
	{
		if (head -> index == index)
			break ;
		distance_node++;
		head = head -> next;
	}
	return (distance_node);
}
