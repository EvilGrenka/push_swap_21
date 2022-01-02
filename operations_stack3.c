/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_stack3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:23:12 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:24:25 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (false);
	ft_shift_down(stack_a);
	ft_shift_down(stack_b);
	ft_putendl_fd("rrr", 1);
	return (true);
}

bool	ft_push(t_node **stack_from, t_node **stack_dst)
{
	t_node	*tmp;

	if (ft_stack_size(*stack_from) == 0)
		return (false);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	ft_add_node_front(stack_dst, tmp);
	return (true);
}

bool	ft_swap(t_node **stack)
{
	t_node	*temp;

	if (ft_stack_size(*stack) < 2)
		return (false);
	temp = (*stack)->next;
	(*stack)->next = temp -> next;
	temp -> next = *stack;
	*stack = temp;
	return (true);
}

bool	ft_shift_up(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (ft_stack_size(*stack) < 2)
		return (false);
	tail = ft_get_last(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
	return (true);
}

bool	ft_shift_down(t_node **stack)
{
	t_node	*prev_tail;
	t_node	*tail;

	if (ft_stack_size(*stack) < 2)
		return (false);
	prev_tail = *stack;
	while (prev_tail->next->next)
		prev_tail = prev_tail -> next;
	tail = prev_tail -> next;
	prev_tail -> next = NULL;
	tail -> next = *stack;
	*stack = tail;
	return (true);
}
