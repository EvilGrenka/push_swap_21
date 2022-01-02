/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:15:57 by rnoriko           #+#    #+#             */
/*   Updated: 2021/12/29 22:50:28 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isspace(char c)
{
	return (c == '\f' || c == '\r' || c == ' '
		|| c == '\t' || c == '\n' || c == '\v');
}

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		result = (result * 10) + (*str++ - '0');
	return ((long long)(result * sign));
}
