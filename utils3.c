/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:36:54 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/31 14:30:58 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head ->next;
		free(temp);
	}
	free(stack);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static bool	ft_is_repeat(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (true);
		i++;
	}
	return (false);
}

static bool	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;	

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
			exit(0);
	}
	else
		i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error_msg("Error: Only numbers are allowed!");
		if (ft_is_repeat(tmp, argv, i))
			ft_error_msg("Error: Numbers should not be repeated!");
		if (tmp < INT32_MIN || tmp > INT32_MAX)
			ft_error_msg("Error: The entered number is too big!");
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}
