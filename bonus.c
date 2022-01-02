/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:54:10 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:58:05 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_operations_stack_one(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		ft_swap(stack_a);
		return (true);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		ft_swap(stack_b);
		return (true);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
		return (true);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		ft_push(stack_b, stack_a);
		return (true);
	}
	return (ft_operations_stack_two(line, stack_a, stack_b));
}

bool	ft_operations_stack_two(char *line, t_node **stack_a, t_node **stack_b)
{
	if (!(ft_strcmp(line, "pb")))
	{
		ft_push(stack_a, stack_b);
		return (true);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		ft_shift_up(stack_a);
		return (true);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		ft_shift_up(stack_b);
		return (true);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		ft_shift_up(stack_a);
		ft_shift_up(stack_b);
		return (true);
	}
	return (ft_operations_stack_three(line, stack_a, stack_b));
}

bool	ft_operations_stack_three(char *line, t_node **stack_a,
		t_node **stack_b)
{
	if (!(ft_strcmp(line, "rra")))
	{
		ft_shift_down(stack_a);
		return (true);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		ft_shift_down(stack_b);
		return (true);
	}	
	if (!(ft_strcmp(line, "rrr")))
	{
		ft_shift_down(stack_a);
		ft_shift_down(stack_b);
		return (true);
	}
	return (false);
}

static void	print_checker_result(t_node **stack_a, t_node **stack_b)
{
	if (ft_is_sorted_stack(stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	ft_init_stack(stack_a, argc, argv);
	while (get_next_line(&line))
	{
		if (!ft_operations_stack_one(line, stack_a, stack_b))
		{
			ft_error_msg("Error operations stack!");
			return (-1);
		}
		free(line);
	}
	print_checker_result(stack_a, stack_b);
	return (0);
}
