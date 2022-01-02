/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:02:50 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/27 16:23:20 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_stack(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) <= 5)
		ft_simple_sort(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_init_stack(stack_a, argc, argv);
	if (ft_is_sorted_stack(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
