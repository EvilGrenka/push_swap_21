/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:18:39 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:22:15 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_ra(t_node **stack_a)
{
	if (!ft_shift_up(stack_a))
		return (false);
	ft_putendl_fd("ra", 1);
	return (true);
}

bool	ft_rb(t_node **stack_b)
{
	if (!ft_shift_up(stack_b))
		return (false);
	ft_putendl_fd("rb", 1);
	return (true);
}

bool	ft_rr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (false);
	ft_shift_up(stack_a);
	ft_shift_up(stack_b);
	ft_putendl_fd("rr", 1);
	return (true);
}

bool	ft_rra(t_node **stack_a)
{
	if (!ft_shift_down(stack_a))
		return (false);
	ft_putendl_fd("rra", 1);
	return (true);
}

bool	ft_rrb(t_node **stack_b)
{
	if (!ft_shift_down(stack_b))
		return (false);
	ft_putendl_fd("rrb", 1);
	return (true);
}
