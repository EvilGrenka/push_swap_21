/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:17:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:18:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sa(t_node **stack_a)
{
	if (!ft_swap(stack_a))
		return (false);
	ft_putendl_fd("sa", 1);
	return (true);
}

bool	ft_sb(t_node **stack_b)
{
	if (!ft_swap(stack_b))
		return (false);
	ft_putendl_fd("sb", 1);
	return (true);
}

bool	ft_ss(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (false);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (true);
}

bool	ft_pa(t_node **stack_b, t_node **stack_a)
{
	if (!ft_push(stack_b, stack_a))
		return (false);
	ft_putendl_fd("pa", 1);
	return (true);
}

bool	ft_pb(t_node **stack_a, t_node **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (false);
	ft_putendl_fd("pb", 1);
	return (true);
}
