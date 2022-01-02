/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:30:21 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/24 16:31:43 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> number = number;
	new_node -> index = -1;
	new_node -> next = NULL;
	return (new_node);
}

t_node	*ft_get_last(t_node *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

void	ft_add_node_front(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node -> next = *stack;
	*stack = new_node;
}

void	ft_add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = ft_get_last(*stack);
		temp -> next = new_node;
	}
	else
		*stack = new_node;
}

void	ft_print_linked_list(t_node *head)
{
	while (head)
	{
		ft_putnbr_fd(head->number, 1);
		ft_putendl_fd("", 1);
		head = head -> next;
	}
}
