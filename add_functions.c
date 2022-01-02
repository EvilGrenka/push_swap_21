/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:04:53 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:07:11 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	ft_min(t_node **stack, int number)
{
	t_node	*head;
	int		min_index;

	head = *stack;
	min_index = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_index) && head->index != number)
			min_index = head->index;
	}
	return (min_index);
}

void	ft_sort_three(t_node **stack_a)
{
	if ((*stack_a)->index == ft_min(stack_a, -1)
		&& (*stack_a)->next->index != ft_min(stack_a, ft_min(stack_a, -1)))
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->index == ft_min(stack_a, ft_min(stack_a, -1)))
	{
		if ((*stack_a)->next->index == ft_min(stack_a, -1))
			ft_sa(stack_a);
		else
			ft_rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->index == ft_min(stack_a, -1))
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}

void	ft_sort_four(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_node(stack_a, ft_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
		ft_rra(stack_a);
	if (ft_is_sorted_stack(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a);
}

void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	int	distance;

	distance = ft_get_distance_node(stack_a, ft_min(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	else if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (distance == 4)
		ft_rra(stack_a);
	if (ft_is_sorted_stack(stack_a))
		return ;
	ft_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_b, stack_a);
}
